#pragma once

#include "common.hpp"
#include "float4.hpp"
#include "trig.hpp"
#include "float3x3.hpp"

namespace hlml {
struct float4x4 {
  float4 c0, c1, c2, c3;

  HLML_INLINEF float4x4() : c0(), c1(), c2(), c3() {}
  HLML_INLINEF explicit float4x4(const f32* p) : c0(p), c1(p+4), c2(p+8), c3(p+12) {}
  HLML_INLINEF explicit float4x4(float3x3 m) : c0(m.c0.m), c1(m.c1.m), c2(m.c2.m), c3(consts::vpoint) {}
  HLML_INLINEF float4x4(f32 x0, f32 y0, f32 z0, f32 w0, f32 x1, f32 y1, f32 z1, f32 w1, f32 x2, f32 y2, f32 z2, f32 w2, f32 x3, f32 y3, f32 z3, f32 w3) : c0(x0, y0, z0, w0), c1(x1, y1, z1, w1), c2(x2, y2, z2, w2), c3(x3, y3, z3, w3) {}
  HLML_INLINEF float4x4(float4 col0, float4 col1, float4 col2, float4 col3) : c0(col0), c1(col1), c2(col2), c3(col3) {}

  HLML_INLINEF static float4x4 identity() { static float4x4 i( { 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f } ); return i; }

  HLML_INLINEF float4x4& operator= (float4x4 b) { c0 = b.c0; c1 = b.c1; c2 = b.c2; c3 = b.c3; return *this; }
  HLML_INLINEF float4x4& operator= (f32 s) { c0 = c1 = c2 = c3 = float4(s); return *this; }
};

HLML_INLINEF float4x4 transpose(float4x4 m) {
  float4 t0(funcs::axbxayby(m.c0.m, m.c1.m));
  float4 t2(funcs::azbzawbw(m.c0.m, m.c1.m));
  float4 t1(funcs::axbxayby(m.c2.m, m.c3.m));
  float4 t3(funcs::azbzawbw(m.c2.m, m.c3.m));
  m.c0.m = funcs::axaybxby(t0.m, t1.m);
  m.c1.m = funcs::bzbwazaw(t1.m, t0.m);
	m.c2.m = funcs::axaybxby(t2.m, t3.m);
  m.c3.m = funcs::bzbwazaw(t3.m, t2.m);
  return m;
}

HLML_INLINEF float4x4 inverse(float4x4 m) {
  float4 A(funcs::axbxayby(m.c0.m, m.c1.m)), B(funcs::axbxayby(m.c2.m, m.c3.m)), C(funcs::azbzawbw(m.c0.m, m.c1.m)), D(funcs::azbzawbw(m.c2.m, m.c3.m));
  float4 AB = A.wwxx() * B - A.yyzz() * B.zwxy();
  float4 t0 = AB.xyxy() * C.xxzz() + AB.zwzw() * C.yyww();
  float4 t1 = AB.wxwx() * D - AB.zyzy() * D.yxwz();
  float4 DC = D.wwxx() * C - D.yyzz() * C.zwxy();
  float4 t2 = DC.wxwx() * A - DC.zyzy() * A.yxwz();
  float4 t3 = DC.xyxy() * B.xxzz() + DC.zwzw() * B.yyww();

  float4 dA = A * A.wwyy();
  dA = (dA - dA.zwzw()).xxxx();
  float4 iD = D * dA - t0;
  float4 dB = B.wwyy() * B;
  dB = (dB - dB.zwzw()).xxxx();
  float4 iB = C * dB - t1;
  float4 dC = C.wwyy() * C;
  dC = (dC - dC.zwzw()).xxxx();
  float4 iC = B * dC - t2;
  float4 dD = D.wwyy() * D;
  dD = (dD - dD.zwzw()).xxxx();
  float4 iA = A * dD - t3;

  float4 det = dA * dD + dB * dC - dotv(DC.xzyw(), AB);
  det.m = funcs::AxorB(det.m, consts::vsignpnnp);
  float4 idet = rcp(det);
  iA *= idet;
  iB *= idet;
  iC *= idet;
  iD *= idet;

  m.c0.m = funcs::awazbwbz(iA.m, iC.m);
  m.c1.m = funcs::ayaxbybx(iA.m, iC.m);
  m.c2.m = funcs::awazbwbz(iB.m, iD.m);
  m.c3.m = funcs::ayaxbybx(iB.m, iD.m);

  return m;
}

HLML_INLINEF B8         operator==  (float4x4 lhs, float4x4 rhs) { return all(lhs.c0 == rhs.c0) && all(lhs.c1 == rhs.c1) && all(lhs.c2 == rhs.c2) && all(lhs.c3 == rhs.c3); }
HLML_INLINEF B8         operator!=  (float4x4 lhs, float4x4 rhs) { return !(lhs == rhs); }

template<> HLML_INLINEF float4x4   operator+   (float4x4 a, float4x4 b) { a.c0 += b.c0; a.c1 += b.c1; a.c2 += b.c2; a.c3 += b.c3; return a; }
template<> HLML_INLINEF float4x4   operator+   (float4x4 a, f32 s) { a.c0 += s; a.c1 += s; a.c2 += s; a.c3 += s; return a; }
template<> HLML_INLINEF float4x4   operator-   (float4x4 m) { m.c0 = -m.c0; m.c1 = -m.c1; m.c2 = -m.c2, m.c3 = -m.c3; return m; }
template<> HLML_INLINEF float4x4   operator-   (float4x4 a, float4x4 b) { a.c0 -= b.c0; a.c1 -= b.c1; a.c2 -= b.c2; a.c3 -= b.c3; return a; }
template<> HLML_INLINEF float4x4   operator-   (float4x4 a, f32 s) { float4 tmp(s); return a - float4x4(tmp, tmp, tmp, tmp); }
template<> HLML_INLINEF float4x4&  operator-=  (float4x4& a, f32 s) { a = a - s; return a; }
template<> HLML_INLINEF float4x4   operator*   (float4x4 a, float4x4 b) {
  float4 lc0 = a.c0, lc1 = a.c1, lc2 = a.c2, lc3 = a.c3, rc0 = b.c0, rc1 = b.c1, rc2 = b.c2, rc3 = b.c3;
  a.c0 = lc0 * rc0.xxxx() + lc1 * rc0.yyyy() + lc2 * rc0.zzzz() + lc3 * rc0.wwww();
  a.c1 = lc0 * rc1.xxxx() + lc1 * rc1.yyyy() + lc2 * rc1.zzzz() + lc3 * rc1.wwww();
  a.c2 = lc0 * rc2.xxxx() + lc1 * rc2.yyyy() + lc2 * rc2.zzzz() + lc3 * rc2.wwww();
  a.c3 = lc0 * rc3.xxxx() + lc1 * rc3.yyyy() + lc2 * rc3.zzzz() + lc3 * rc3.wwww();
  return a;
}
template<> HLML_INLINEF float4x4   operator*   (float4x4 a, f32 s) { a.c0 *= s; a.c1 *= s; a.c2 *= s; a.c3 *= s; return a; }
HLML_INLINEF float4     operator*   (float4x4 a, float4 v) { return v.xxxx() * a.c0 + v.yyyy() * a.c1 + v.zzzz() * a.c2 + v.wwww() * a.c3; }
template<> HLML_INLINEF float4x4   operator/   (float4x4 a, f32 s) { a.c0 /= s; a.c1 /= s; a.c2 /= s; a.c3 /= s; return a; }
template<> HLML_INLINEF float4x4&  operator*=  (float4x4& a, float4x4 b) { a = a * b; return a; }
template<> HLML_INLINEF float4x4&  operator*=  (float4x4& a, f32 s) { a = a * s; return a; }
HLML_INLINEF float4x4   operator/   (float4x4 a, f32 s) { a.c0 /= s; a.c1 /= s; a.c2 /= s; a.c3 /= s; return a; }
template<> HLML_INLINEF float4x4&  operator/=  (float4x4& a, f32 s) { a = a / s; return a; }

HLML_INLINEF float4x4 fillortho(f32 x, f32 y, f32 z, f32 w, f32 h, f32 d) {
  return float4x4(
    x,      0.0f,   0.0f,   0.0f,
    0.0f,  -y,      0.0f,   0.0f,
    0.0f,   0.0f,   z,      0.0f,
    -w,     -h,     -d,     1.0f
  );
}
HLML_INLINEF float4x4 ortho(f32 l, f32 r, f32 b, f32 t, f32 zn, f32 zf) {
  f32 invW = 1.0f / (r - l), invH = 1.0f / (t - b), invD = 1.0f / (zf - zn);
  return fillortho(2.0f * invW, 2.0f * invH, -invD, (l + r) * invW, (t + b) * invH, zn * invD);
}
HLML_INLINEF float4x4 orthoinverse(f32 l, f32 r, f32 b, f32 t, f32 zn, f32 zf) {
  return fillortho((r - l) * 0.5f, (t - b) * 0.5f, -(zf - zn), (r + l) * 0.5f, (t + b) * 0.5f, zn);
}
HLML_INLINEF float4x4 ortho(f32 w, f32 h, f32 zn, f32 zf) {
  f32 hw = 0.5f * w, hh = 0.5f * h;
  return ortho(-hw, hw, -hh, hh, zn, zf);
}
HLML_INLINEF float4x4 orthoinverse(f32 w, f32 h, f32 zn, f32 zf) {
  f32 hw = 0.5f * w, hh = 0.5f * h;
  return orthoinverse(-hw, hw, -hh, hh, zn, zf);
}

HLML_INLINEF float4x4 fillpersp(f32 x, f32 y, f32 z, f32 w, f32 h, f32 d) {
  return float4x4(
    x,      0.0f,   0.0f,   0.0f,
    0.0f,  -y,      0.0f,   0.0f,
    w,      h,     -z,      1.0f,
    0.0f,   0.0f,   d,      0.0f
  );
}

HLML_INLINEF float4x4 fillperspinv(f32 x, f32 y, f32 z, f32 w, f32 h, f32 d) {
  return float4x4(
    x,      0.0f,   0.0f,   0.0f,
    0.0f,  -y,      0.0f,   0.0f,
    0.0f,   0.0f,   0.0f,   z,
    w,      h,     -1.0f,   d
  );
}

HLML_INLINEF float4x4 perspective(f32 fovDegs, f32 h2w, f32 zn, f32 zf) {
  const f32 invD = 1.0f / (zn - zf);
  float4 rads(HLML_DEG2RAD(fovDegs) * 0.5f), s, c;
  sincos(rads, s, c);
  f32 invtan = (c / s).x();
  f32 x = invtan * h2w, y = invtan, z = zf * invD, d = zf * zn * invD;
  return fillpersp(x, y, z, 0.0f, 0.0f, d);
}
HLML_INLINEF float4x4 perspective(f32 fovDegs, f32 width, f32 height, f32 zn, f32 zf) { return perspective(fovDegs, height / width, zn, zf); }
HLML_INLINEF float4x4 perspectiveinverse(f32 fovDegs, f32 h2w, f32 zn, f32 zf) {
  const f32 invzn = 1.0f / zn, invzf = 1.0f / zf, invdzn = invzn * 0.5f, invdznzf = invdzn * invzf;
  float4 rads(HLML_DEG2RAD(fovDegs) * 0.5f), s, c;
  sincos(rads, s, c);
  f32 y = (c / s).x(), x = y * h2w, z = (zn - zf) * invzf, d = zn;
  return fillperspinv(x, y, z, 0.0f, 0.0f, d);
}
HLML_INLINEF float4x4 perspectiveZinv(f32 fovDegs, f32 h2w, f32 zn, f32 epsilon = 2.4e-7f) {
  float4 rads(HLML_DEG2RAD(fovDegs) * 0.5f), s, c;
  sincos(rads, s, c);
  f32 diff = (c / s).x() * zn, dzn = 2.0f * zn;
  f32 l = -diff * h2w, r = diff * h2w, b = -h2w, t = h2w;
  f32 x = (r - l) * dzn, y = (t - b) * dzn, z = (epsilon - 2.0f) * zn;
  return fillpersp(x, y, z, 0.0f, 0.0f, epsilon - 1.0f);
}
HLML_INLINEF float4x4 frustum(f32 l, f32 r, f32 b, f32 t, f32 zn, f32 zf) {
  f32 dzn = 2.0f * zn, diffx = 1.0f / (r - l), diffy = 1.0f / (t - b), diffz = 1.0f / (zn - zf);
  f32 x = dzn * diffx, y = dzn * diffy, z = zn * zf * diffz;
  f32 w = (r + l) * diffx, h = (t + b) * diffy, d = zf * diffz;
  return fillpersp(x, y, z, w, h, d);
}
HLML_INLINEF float4x4 frustuminverse(f32 l, f32 r, f32 b, f32 t, f32 zn, f32 zf) {
  f32 invdzn = 1.0f / (2.0f * zn), invdznzf = invdzn / zf, diffx = (r - l), diffy = (t - b), diffz = (zn - zf);
  f32 x = invdzn * diffx, y = invdzn * diffy, z = diffz * invdznzf;
  f32 w = (r + l) * invdzn, h = (t + b) * invdzn, d = (zn + zf) * invdznzf;
  return fillperspinv(x, y, z, w, h, d);
}
}
