#pragma once

#include "float4.hpp"
#include "float3x3.hpp"

namespace hlml {
class quat {
  float4 m = { consts::sfOne, consts::sfZero, consts::sfZero, consts::sfZero };

 public:
  quat() = default;
  explicit quat(float3 v) : quat(0.0f, v) {}
  explicit quat(float4 v) : m(v.wxyz()) {}
  explicit quat(F32* v) : m(v) {}
  explicit quat(F32 scalar) : m(funcs::bxayazaw(funcs::setXXXX(scalar), consts::vzeros)) {}
  quat(F32 w, float3 v) : m(w, v.x(), v.y(), v.z()) {}
  quat(F32 w, F32 x, F32 y, F32 z) : m(w, x, y, z) {}
  quat(float3 axis, F32 degs) {
    //http://www.euclideanspace.com/maths/geometry/rotations/conversions/angleToQuaternion/index.htm
    F32 angleHalf(HLML_DEG2RAD(degs) * 0.5f);
    float4 sc = sincos(float4(angleHalf)), xxyz(axis.m);
    float4 sins(xxyz.xxyz() * sc.xxxx()), coss(sc.yyyy());
    m.m = funcs::bxayazaw(sins.m, coss.m);
  }
  //pitch = X axis, yaw = Y axis, roll = Z axis
  quat(F32 pitch, F32 yaw, F32 roll) {
    float4 angles(pitch, pitch, yaw, roll), sines, coses;
    sincos(angles * 0.5f, sines, coses);
    float4 cxxyz(funcs::bxayazaw(sines.m, coses.m)), sxxyz(funcs::bxayazaw(coses.m, sines.m));;
    float4 left = cxxyz * coses.zzyz() * coses.wwwy(), right = sxxyz * sines.zzyz() * sines.wwwy();
    m = left + (right ^ float4(consts::vsignnpnp));
  }
  explicit quat(float3x3 rot) {
    // https://www.fd.cvut.cz/personal/voracsar/geometriepg/pgr020/matrix2quaternions.pdf
    // http://d3cw3dd2w32x2b.cloudfront.net/wp-content/uploads/2015/01/matrix-to-quat.pdf
    // http://www.euclideanspace.com/maths/geometry/rotations/conversions/matrixToQuaternion/index.htm
    const float3 m00(rot.c0.xxx()), m11(rot.c1.yyy()), m22(rot.c2.zzz()), zero;
    const float4 diag(consts::sfZero, m00.x(), m11.x(), m22.x())
               , left(consts::sfZero, rot.c2.y(), rot.c0.z(), rot.c1.x())
               , right(consts::sfZero, rot.c1.z(), rot.c2.x(), rot.c0.y());
    const float4 s0(consts::vsignppnn), s1(consts::vsignpnpn), s2(consts::vsignpnnp);
    float4 factor(1.0f);
    if (all(m22 < zero)) {
      if (all(m00 > m11)) {
        factor += sumv(diag ^ s0);
        float4 v(left - (right ^ s0));
        v.m = funcs::bxayazaw(v.m, factor.m);
        m = v.yxwz();
      } else {
        factor += sumv(diag ^ s1);
        float4 v(left - (right ^ s1));
        v.m = funcs::bxayazaw(v.m, factor.m);
        m = v.zwxy();
      }
    } else {
      if (all(m00 < -m11)) {
        factor += sumv(diag ^ s2);
        float4 v(left - (right ^ s2));
        v.m = funcs::bxayazaw(v.m, factor.m);
        m = v.wzyx();
      } else {
        factor += sumv(diag);
        float4 v(left - right);
        m.m = funcs::bxayazaw(v.m, factor.m);
      }
    }
    m *= rsqrt(factor) * 0.5f;
  }
  quat(float3 u, float3 v) : quat(dot(u, v), cross(u, v)) {
    //http://lolengine.net/blog/2013/09/18/beautiful-maths-quaternion-from-vectors
    float4 t(length(m));
    m.m = funcs::AaddssB(m.m, t.m);
    m = normalize(m);
  }
  explicit HLML_INLINEF operator float4() const { return m.yzwx(); }
  HLML_INLINEF operator float3x3() const {
    //http://www.euclideanspace.com/maths/geometry/rotations/conversions/quaternionToMatrix/index.htm
    float4 v = (float4)*this;
    float3 c0l(-2.0f, -2.0f, 2.0f), c0r(-2.0f, 2.0f, 2.0f), c1l(2.0f, -2.0f, 2.0f), c1r(-c0r), c2l(-c0l), c2r(-c1l);
    float3 xzy(v.xzy()), wxx(v.wxx());
    float3 col0 = c0l * v.zzy() * v.zww() + c0r * v.yyz() * v.yxx();
    float3 col1 = c1l * xzy * v.yzz() + c1r * wxx * v.zxw();
    float3 col2 = c2l * xzy * v.zyy() + c2r * wxx * v.ywx();
    return float3x3::identity() + float3x3(col0, col1, col2);
  }
  HLML_INLINEF F32 x() const { return m.y(); }
  HLML_INLINEF F32 y() const { return m.z(); }
  HLML_INLINEF F32 z() const { return m.w(); }
  HLML_INLINEF F32 w() const { return m.x(); }
  HLML_INLINEF F32 real() const { return w(); }
  HLML_INLINEF float3 imag() const { return m.yzw(); }
};

HLML_INLINEF quat     operator+  (quat a) { return a; }
HLML_INLINEF quat     operator+  (quat a, quat b) { return quat((float4)a + (float4)b); }
HLML_INLINEF quat     operator+  (quat a, F32 s) { return a + quat(s); }
HLML_INLINEF quat     operator+  (F32 s, quat a) { return a + s; }
HLML_INLINEF quat&    operator+= (quat& a, quat b) { a = a + b; return a; }
HLML_INLINEF quat&    operator+= (quat& a, F32 s) { a = a + quat(s); return a; }
HLML_INLINEF quat     operator-  (quat a) { return quat((float4)a ^ float4(consts::vsignpppn)); }
HLML_INLINEF quat     operator-  (quat a, quat b) { return quat((float4)a - (float4)b); }
HLML_INLINEF quat     operator-  (quat a, F32 s) { return a - quat(s); }
HLML_INLINEF quat     operator-  (F32 s, quat b) { return quat(s) - b; }
HLML_INLINEF quat&    operator-= (quat& a, quat b) { a = a - b; return a; }
HLML_INLINEF quat&    operator-= (quat& a, F32 s) { a = a - quat(s); return a; }
HLML_INLINEF quat     operator*  (quat a, quat b) {
  float4 ai = (float4)a, bi = (float4)b;
  float4 s1 = ai.xyzy() * bi.wwwy() + ai.yzxz() * bi.zxyz();
  s1.m = funcs::AxorB(s1.m, consts::vsignnnnp);
  ai = ai.wwww() * bi - ai.zxyx() * bi.yzxx() + s1;
  return quat(ai);
}
HLML_INLINEF float3   operator*  (quat a, float3 b) {
  float4 i((float4)a);
  float3 axyz(i.xyz()), www(i.www()), bxyz(b);
  float3 t(2.0f * cross(axyz, b)), wwwt(www * t), axyzt(cross(axyz, t));
  return axyzt + wwwt + b;
}
HLML_INLINEF quat     operator*  (quat a, F32 s) { return quat((float4)a * s); }
HLML_INLINEF quat     operator*  (F32 s, quat a) { return a * s; }
HLML_INLINEF quat&    operator*= (quat& a, quat b) { a = a * b; return a; }
HLML_INLINEF quat&    operator*= (quat& a, F32 s) { a = a * s; }
HLML_INLINEF quat     operator/  (quat a, F32 s) { return a * (1.0f / s); }
HLML_INLINEF quat&    operator/= (quat& a, F32 s) { a = a / s; return a; }

HLML_INLINEF bool4    operator== (quat a, quat b) { return (float4)a == (float4)b; }
HLML_INLINEF bool4    operator!= (quat a, quat b) { return (float4)a != (float4)b; }

HLML_INLINEF quat conjugate(quat a) { return -a; }
HLML_INLINEF quat inverse(quat a) { float4 v((float4)a), qc((float4)conjugate(a)); return quat(qc / dotv(v, v)); }
HLML_INLINEF quat normalize(quat a) { return quat(normalize((float4)a)); }

HLML_INLINEF float3   operator*  (float3 b, quat a) { return inverse(a) * b; }
}
