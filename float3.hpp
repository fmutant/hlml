#pragma once

#include "float2.hpp"
#include "bool3.hpp"
#include "int3.hpp"

namespace hlml {
struct float4;

struct float3 {

  VF128 m = { 0 };

  HLML_INLINEF float3() {}
  HLML_INLINEF float3(f32 x, f32 y, f32 z) : m(funcs::setXYZW(x, y, z, consts::sfZero)) {}
  HLML_INLINEF float3(float2 v, f32 z) : float3(v.x(), v.y(), z) {}
  HLML_INLINEF explicit float3(f32 x) : float3(x, x, x) {}
  HLML_INLINEF explicit float3(const f32 *p) : float3(p[0], p[1], p[2]) {}
  HLML_INLINEF explicit float3(VF128 v) : m(v) {}
  //HLML_INLINEF explicit float3(float4 v) : float3(v.m) {}
  HLML_INLINEF float3& operator=(VF128 v) { m = v; return *this; }
  HLML_INLINEF float3 float3i(i32 x, i32 y, i32 z) { return float3((f32)x, (f32)y, (f32)z); }

  HLML_INLINEF void store(f32 *p) const { p[0] = x(); p[1] = y(); p[2] = z(); }

  HLML_INLINEF void setX(f32 x) { m = insertf(m, x, 0); }
  HLML_INLINEF void setY(f32 y) { m = insertf(m, y, 1); }
  HLML_INLINEF void setZ(f32 z) { m = insertf(m, z, 2); }

  HLML_INLINEF f32 x() const { uiasf res(extractf(m, 0)); return res.asf32; }
  HLML_INLINEF f32 y() const { uiasf res(extractf(m, 1)); return res.asf32; }
  HLML_INLINEF f32 z() const { uiasf res(extractf(m, 2)); return res.asf32; }

  HLML_INLINEF float2 xx() const { return shufflef3tof2(*this, 0, 0); }
  HLML_INLINEF float2 xy() const { return shufflef3tof2(*this, 0, 1); }
  HLML_INLINEF float2 xz() const { return shufflef3tof2(*this, 0, 2); }
  HLML_INLINEF float2 yx() const { return shufflef3tof2(*this, 1, 0); }
  HLML_INLINEF float2 yy() const { return shufflef3tof2(*this, 1, 1); }
  HLML_INLINEF float2 yz() const { return shufflef3tof2(*this, 1, 2); }
  HLML_INLINEF float2 zx() const { return shufflef3tof2(*this, 2, 0); }
  HLML_INLINEF float2 zy() const { return shufflef3tof2(*this, 2, 1); }
  HLML_INLINEF float2 zz() const { return shufflef3tof2(*this, 2, 2); }

  HLML_INLINEF float3 xxx() const { return shufflef3(*this, 0, 0, 0); }
  HLML_INLINEF float3 xxy() const { return shufflef3(*this, 0, 0, 1); }
  HLML_INLINEF float3 xxz() const { return shufflef3(*this, 0, 0, 2); }
  HLML_INLINEF float3 xyx() const { return shufflef3(*this, 0, 1, 0); }
  HLML_INLINEF float3 xyy() const { return shufflef3(*this, 0, 1, 1); }
  HLML_INLINEF float3 xyz() const { return *this; }
  HLML_INLINEF float3 xzx() const { return shufflef3(*this, 0, 2, 0); }
  HLML_INLINEF float3 xzy() const { return shufflef3(*this, 0, 2, 1); }
  HLML_INLINEF float3 xzz() const { return shufflef3(*this, 0, 2, 2); }
  HLML_INLINEF float3 yxx() const { return shufflef3(*this, 1, 0, 0); }
  HLML_INLINEF float3 yxy() const { return shufflef3(*this, 1, 0, 1); }
  HLML_INLINEF float3 yxz() const { return shufflef3(*this, 1, 0, 2); }
  HLML_INLINEF float3 yyx() const { return shufflef3(*this, 1, 1, 0); }
  HLML_INLINEF float3 yyy() const { return shufflef3(*this, 1, 1, 1); }
  HLML_INLINEF float3 yyz() const { return shufflef3(*this, 1, 1, 2); }
  HLML_INLINEF float3 yzx() const { return shufflef3(*this, 1, 2, 0); }
  HLML_INLINEF float3 yzy() const { return shufflef3(*this, 1, 2, 1); }
  HLML_INLINEF float3 yzz() const { return shufflef3(*this, 1, 2, 2); }
  HLML_INLINEF float3 zxx() const { return shufflef3(*this, 2, 0, 0); }
  HLML_INLINEF float3 zxy() const { return shufflef3(*this, 2, 0, 1); }
  HLML_INLINEF float3 zxz() const { return shufflef3(*this, 2, 0, 2); }
  HLML_INLINEF float3 zyx() const { return shufflef3(*this, 2, 1, 0); }
  HLML_INLINEF float3 zyy() const { return shufflef3(*this, 2, 1, 1); }
  HLML_INLINEF float3 zyz() const { return shufflef3(*this, 2, 1, 2); }
  HLML_INLINEF float3 zzx() const { return shufflef3(*this, 2, 2, 0); }
  HLML_INLINEF float3 zzy() const { return shufflef3(*this, 2, 2, 1); }
  HLML_INLINEF float3 zzz() const { return shufflef3(*this, 2, 2, 2); }

  HLML_INLINEF f32 r() const { return x(); }
  HLML_INLINEF f32 g() const { return y(); }
  HLML_INLINEF f32 b() const { return z(); }

  HLML_INLINEF float2 rr() const { return xx(); }
  HLML_INLINEF float2 rg() const { return xy(); }
  HLML_INLINEF float2 rb() const { return xz(); }
  HLML_INLINEF float2 gr() const { return yx(); }
  HLML_INLINEF float2 gg() const { return yy(); }
  HLML_INLINEF float2 gb() const { return yz(); }
  HLML_INLINEF float2 br() const { return zx(); }
  HLML_INLINEF float2 bg() const { return zy(); }
  HLML_INLINEF float2 bb() const { return zz(); }

  HLML_INLINEF float3 rrr() const { return xxx(); }
  HLML_INLINEF float3 rrg() const { return xxy(); }
  HLML_INLINEF float3 rrb() const { return xxz(); }
  HLML_INLINEF float3 rgr() const { return xyx(); }
  HLML_INLINEF float3 rgg() const { return xyy(); }
  HLML_INLINEF float3 rgb() const { return xyz(); }
  HLML_INLINEF float3 rbr() const { return xzx(); }
  HLML_INLINEF float3 rbg() const { return xzy(); }
  HLML_INLINEF float3 rbb() const { return xzz(); }
  HLML_INLINEF float3 grr() const { return yxx(); }
  HLML_INLINEF float3 grg() const { return yxy(); }
  HLML_INLINEF float3 grb() const { return yxz(); }
  HLML_INLINEF float3 ggr() const { return yyx(); }
  HLML_INLINEF float3 ggg() const { return yyy(); }
  HLML_INLINEF float3 ggb() const { return yyz(); }
  HLML_INLINEF float3 gbr() const { return yzx(); }
  HLML_INLINEF float3 gbg() const { return yzy(); }
  HLML_INLINEF float3 gbb() const { return yzz(); }
  HLML_INLINEF float3 brr() const { return zxx(); }
  HLML_INLINEF float3 brg() const { return zxy(); }
  HLML_INLINEF float3 brb() const { return zxz(); }
  HLML_INLINEF float3 bgr() const { return zyx(); }
  HLML_INLINEF float3 bgg() const { return zyy(); }
  HLML_INLINEF float3 bgb() const { return zyz(); }
  HLML_INLINEF float3 bbr() const { return zzx(); }
  HLML_INLINEF float3 bbg() const { return zzy(); }
  HLML_INLINEF float3 bbb() const { return zzz(); }
};
//boolean
HLML_INLINEF bool3    operator==  (float3 a, float3 b) { a.m = funcs::AcmpeqB(a.m, b.m); return bool3(funcs::fasi(a.m)); }
HLML_INLINEF bool3    operator!=  (float3 a, float3 b) { a.m = funcs::AcmpneB(a.m, b.m); return bool3(funcs::fasi(a.m)); }
HLML_INLINEF bool3    operator<   (float3 a, float3 b) { a.m = funcs::AcmpltB(a.m, b.m); return bool3(funcs::fasi(a.m)); }
HLML_INLINEF bool3    operator>   (float3 a, float3 b) { a.m = funcs::AcmpgtB(a.m, b.m); return bool3(funcs::fasi(a.m)); }
HLML_INLINEF bool3    operator<=  (float3 a, float3 b) { a.m = funcs::AcmpleB(a.m, b.m); return bool3(funcs::fasi(a.m)); }
HLML_INLINEF bool3    operator>=  (float3 a, float3 b) { a.m = funcs::AcmpgeB(a.m, b.m); return bool3(funcs::fasi(a.m)); }
//logical
HLML_INLINEF float3   operator~   (float3 a) { a.m = funcs::notAandB(a.m, consts::vnall3); return a; }
HLML_INLINEF float3   operator&   (float3 a, float3 b) { a.m = funcs::AandB(a.m, b.m); return a; }
HLML_INLINEF float3   operator|   (float3 a, float3 b) { a.m = funcs::AorB(a.m, b.m); return a; }
HLML_INLINEF float3   operator^   (float3 a, float3 b) { a.m = funcs::AxorB(a.m, b.m); return a; }
//arithmetic
HLML_INLINEF float3   operator+   (float3 a) { return a; }
HLML_INLINEF float3   operator-   (float3 a) { a.m = funcs::AxorB(a.m, consts::vsignbits_xyz); return a; }
HLML_INLINEF float3   operator+   (float3 a, float3 b) { a.m = funcs::AaddB(a.m, b.m); return a; }
HLML_INLINEF float3   operator-   (float3 a, float3 b) { a.m = funcs::AsubB(a.m, b.m); return a; }
HLML_INLINEF float3   operator*   (float3 a, float3 b) { a.m = funcs::AmulB(a.m, b.m); return a; }
HLML_INLINEF float3   operator/   (float3 a, float3 b) { a.m = funcs::AdivB(a.m, b.m); return a; }
HLML_INLINEF float3&  operator+=  (float3& a, float3 b) { a = a + b; return a; }
HLML_INLINEF float3&  operator-=  (float3& a, float3 b) { a = a - b; return a; }
HLML_INLINEF float3&  operator*=  (float3& a, float3 b) { a = a * b; return a; }
HLML_INLINEF float3&  operator/=  (float3& a, float3 b) { a = a / b; return a; }
HLML_INLINEF float3   operator+   (float3 a, f32 b) { return a + float3(b); }
HLML_INLINEF float3   operator-   (float3 a, f32 b) { return a - float3(b); }
HLML_INLINEF float3   operator*   (float3 a, f32 b) { return a * float3(b); }
HLML_INLINEF float3   operator/   (float3 a, f32 b) { return a / float3(b); }
HLML_INLINEF float3&  operator+=  (float3& a, f32 b) { return a += float3(b); }
HLML_INLINEF float3&  operator-=  (float3& a, f32 b) { return a -= float3(b); }
HLML_INLINEF float3&  operator*=  (float3& a, f32 b) { return a *= float3(b); }
HLML_INLINEF float3&  operator/=  (float3& a, f32 b) { return a /= float3(b); }
HLML_INLINEF float3   operator+   (f32 a, float3 b) { return float3(a) + b; }
HLML_INLINEF float3   operator-   (f32 a, float3 b) { return float3(a) - b; }
HLML_INLINEF float3   operator*   (f32 a, float3 b) { return float3(a) * b; }
HLML_INLINEF float3   operator/   (f32 a, float3 b) { return float3(a) / b; }
//funcs
HLML_INLINEF int3     asint       (float3 a) { return int3(funcs::fasi(a.m)); }
HLML_INLINEF int3     toint       (float3 a) { return int3(funcs::ftoi(a.m)); }
HLML_INLINEF float3   asflt       (int3 a) { return float3(funcs::iasf(a.m)); }
HLML_INLINEF float3   toflt       (int3 a) { return float3(funcs::itof(a.m)); }

HLML_INLINEF float3   abs         (float3 v) { v.m = funcs::notAandB(consts::vsignbits_xyz, v.m); return v; }
HLML_INLINEF float3   ceil        (float3 a) { a.m = funcs::ceil(a.m); return a; }
HLML_INLINEF float3   clamp       (float3 v, float3 a, float3 b) { v.m = funcs::AminB(funcs::AmaxB(v.m, a.m), b.m); return v; }
HLML_INLINEF float3   clamp       (float3 v, f32 a, f32 b) { return clamp(v, float3(a), float3(b)); }
HLML_INLINEF float3   crossv      (float3 a, float3 b) { return (a.yzx() * b - a * b.yzx()).yzx(); }
HLML_INLINEF float3   cross       (float3 a, float3 b) { return crossv(a, b); }
HLML_INLINEF float3   dotv        (float3 a, float3 b) { a.m = funcs::AdotBxyz(a.m, b.m); return a; }
HLML_INLINEF float3   floor       (float3 a) { a.m = funcs::floor(a.m); return a; }
HLML_INLINEF float3   fmod        (float3 a, float3 b) { return a - toflt(toint(a / b)) * b; }
HLML_INLINEF float3   frac        (float3 a) { a.m = funcs::frac(a.m); return a; }
HLML_INLINEF float3   lerp        (float3 a, float3 b, f32 t) { return a + (b - a) * t; }
HLML_INLINEF float3   lerp        (float3 a, float3 b, float3 t) { return a + (b - a) * t; }
HLML_INLINEF float3   mad         (float3 a, float3 b, float3 c) { a.m = funcs::AmulBaddC(a.m, b.m, c.m); return a; }
HLML_INLINEF float3   maxv        (float3 a, float3 b) { a.m = funcs::AmaxB(a.m, b.m); return a; }
HLML_INLINEF float3   minv        (float3 a, float3 b) { a.m = funcs::AminB(a.m, b.m); return a; }
HLML_INLINEF float3   rcp         (float3 v) { v.m = funcs::axayaz00(funcs::rcp(funcs::axayaz11(v.m))); return v; }
HLML_INLINEF float3   reflect     (float3 v, float3 n) { return v - n * dotv(v, n) * 2.0f; }
HLML_INLINEF float3   round       (float3 a) { a.m = funcs::round(a.m); return a; }
HLML_INLINEF float3   rsqrt       (float3 v) { v.m = funcs::axayaz00(funcs::rsqrt(funcs::axayaz11(v.m))); return v; }
HLML_INLINEF float3   saturate    (float3 a) { return clamp(a, 0.0f, 1.0f); }
HLML_INLINEF float3   sumv        (float3 v) { return v += v.zxy() + v.yzx(); }
HLML_INLINEF float3   sqrt        (float3 v) { v.m = funcs::sqrt(v.m); return v; }
HLML_INLINEF float3   trunc       (float3 a) { a.m = funcs::trunc(a.m); return a; }


HLML_INLINEF f32      hmin        (float3 v) { v = minv(v, shufflef3(v, 1, 0, 2)); return minv(v, shufflef3(v, 2, 0, 1)).x(); }
HLML_INLINEF f32      hmax        (float3 v) { v = maxv(v, shufflef3(v, 1, 0, 2)); return maxv(v, shufflef3(v, 2, 0, 1)).x(); }
HLML_INLINEF f32      sum          (float3 v) { return sumv(v).x(); }
HLML_INLINEF f32      dot         (float3 a, float3 b) { return dotv(a, b).x(); }
HLML_INLINEF f32      lengthsq    (float3 v) { return dot(v, v); }
HLML_INLINEF f32      length      (float3 v) { return sqrt(dotv(v, v)).x(); }

HLML_INLINEF float3 normalize(float3 v) { return v * rsqrt(dotv(v, v)); }

HLML_INLINEF float3 refract(float3 v, float3 n, f32 idx) {
  float3 vn = dotv(v, n);
  float3 k = maxv(float3(consts::vzeros), float3(1.0f - idx * idx * (1.0f - vn * vn)));
  return v * idx - (vn * idx + sqrt(k)) * n;
}

HLML_INLINEF float3 sign(float3 v) {
  //https://github.com/g-truc/glm/blob/master/glm/simd/common.h#L99
  VF128 cmp0 = funcs::AcmpltB(v.m, consts::vzeros);
  VF128 cmp1 = funcs::AcmpgtB(v.m, consts::vzeros);
  VF128 and0 = funcs::AandB(cmp0, consts::vnones3);
  VF128 and1 = funcs::AandB(cmp1, consts::vones3);
  v.m = funcs::AorB(and0, and1);
  return v;
}

HLML_INLINEF float3 smoothstep(float3 e0, float3 e1, float3 v) {
  float3 zeros(consts::vzeros), ones(consts::vones);
  float3 t = clamp((v - e0) / (e1 - e0), zeros, ones);
  return (3.0f - 2.0f * t) * t * t;
}

HLML_INLINEF float3 step(float3 e, float3 v) {
  e = sign(v - e);
  return maxv(float3(consts::vzeros), e);
}
}
