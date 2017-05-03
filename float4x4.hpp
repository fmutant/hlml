#pragma once

#include "common.hpp"
#include "float4.hpp"
#include "trig.hpp"

namespace hlml {
struct float4x4 {
  float4 c0, c1, c2, c3;

  HLML_INLINEF float4x4() : c0(), c1(), c2(), c3() {}
  HLML_INLINEF explicit float4x4(const F32* p) : c0(p), c1(p+4), c2(p+8), c3(p+12) {}
  HLML_INLINEF float4x4(F32 x0, F32 y0, F32 z0, F32 w0, F32 x1, F32 y1, F32 z1, F32 w1, F32 x2, F32 y2, F32 z2, F32 w2, F32 x3, F32 y3, F32 z3, F32 w3) : c0(x0, y0, z0, w0), c1(x1, y1, z1, w1), c2(x2, y2, z2, w2), c3(x3, y3, z3, w3) {}
  HLML_INLINEF float4x4(float4 col0, float4 col1, float4 col2, float4 col3) : c0(col0), c1(col1), c2(col2), c3(col3) {}

  HLML_INLINEF static float4x4 identity() { static float4x4 i( { 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f } ); return i; }

  HLML_INLINEF float4x4& operator= (float4x4 b) { c0 = b.c0; c1 = b.c1; c2 = b.c2; c3 = b.c3; return *this; }
  HLML_INLINEF float4x4& operator= (F32 s) { c0 = c1 = c2 = c3 = float4(s); return *this; }
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

HLML_INLINEF float4x4   operator+   (float4x4 m) { return m; }
HLML_INLINEF float4x4   operator+   (float4x4 a, float4x4 b) { a.c0 += b.c0; a.c1 += b.c1; a.c2 += b.c2; a.c3 += b.c3; return a; }
HLML_INLINEF float4x4   operator+   (float4x4 a, F32 s) { a.c0 += s; a.c1 += s; a.c2 += s; a.c3 += s; return a; }
HLML_INLINEF float4x4   operator+   (F32 s, float4x4 a) { return a + s; }
HLML_INLINEF float4x4&  operator+=  (float4x4& a, float4x4 b) { a = a + b; return a; }
HLML_INLINEF float4x4&  operator+=  (float4x4& a, F32 s) { a = a + s; return a; }
HLML_INLINEF float4x4   operator-   (float4x4 m) { m.c0 = -m.c0; m.c1 = -m.c1; m.c2 = -m.c2, m.c3 = -m.c3; return m; }
HLML_INLINEF float4x4   operator-   (float4x4 a, float4x4 b) { a.c0 -= b.c0; a.c1 -= b.c1; a.c2 -= b.c2; a.c3 -= b.c3; return a; }
HLML_INLINEF float4x4   operator-   (float4x4 a, F32 s) { float4 tmp(s); return a - float4x4(tmp, tmp, tmp, tmp); }
HLML_INLINEF float4x4   operator-   (F32 s, float4x4 a) { float4 tmp(s); return float4x4(tmp, tmp, tmp, tmp) - a; }
HLML_INLINEF float4x4&  operator-=  (float4x4& a, float4x4 b) { a = a - b; return a; }
HLML_INLINEF float4x4&  operator-=  (float4x4& a, F32 s) { a = a - s; return a; }
HLML_INLINEF float4x4   operator*   (float4x4 a, float4x4 b) {
  float4 lc0 = a.c0, lc1 = a.c1, lc2 = a.c2, lc3 = a.c3, rc0 = b.c0, rc1 = b.c1, rc2 = b.c2, rc3 = b.c3;
  a.c0 = lc0 * rc0.xxxx() + lc1 * rc0.yyyy() + lc2 * rc0.zzzz() + lc3 * rc0.wwww();
  a.c1 = lc0 * rc1.xxxx() + lc1 * rc1.yyyy() + lc2 * rc1.zzzz() + lc3 * rc1.wwww();
  a.c2 = lc0 * rc2.xxxx() + lc1 * rc2.yyyy() + lc2 * rc2.zzzz() + lc3 * rc2.wwww();
  a.c3 = lc0 * rc3.xxxx() + lc1 * rc3.yyyy() + lc2 * rc3.zzzz() + lc3 * rc3.wwww();
  return a;
}
HLML_INLINEF float4x4   operator*   (float4x4 a, F32 s) { a.c0 *= s; a.c1 *= s; a.c2 *= s; a.c3 *= s; return a; }
HLML_INLINEF float4x4   operator*   (F32 s, float4x4 a) { return a * s; }
HLML_INLINEF float4     operator*   (float4x4 a, float4 v) { return v.xxxx() * a.c0 + v.yyyy() * a.c1 + v.zzzz() * a.c2 + v.wwww() * a.c3; }
HLML_INLINEF float4     operator*   (float4 v, float4x4 a) {
  float4 xxxx(dotv(v, a.c0)), yyyy(dotv(v, a.c1)), zzzz(dotv(v, a.c2)), wwww(dotv(v, a.c3));
  float4 xyxy(funcs::axbxayby(xxxx.m, yyyy.m)), zwzw(funcs::axbxayby(zzzz.m, wwww.m)), xyzw(funcs::axaybxby(xyxy.m, zwzw.m));
  return xyzw;
}
HLML_INLINEF float4x4&  operator*=  (float4x4& a, float4x4 b) { a = a * b; return a; }
HLML_INLINEF float4x4&  operator*=  (float4x4& a, F32 s) { a = a * s; return a; }
HLML_INLINEF float4x4   operator/   (float4x4 a, F32 s) { a.c0 /= s; a.c1 /= s; a.c2 /= s; a.c3 /= s; return a; }
HLML_INLINEF float4x4&  operator/=  (float4x4& a, F32 s) { a = a / s; return a; }

HLML_INLINEF float4x4 ortho(F32 l, F32 r, F32 b, F32 t, F32 zn, F32 zf) {
  F32 invW = 1.0f / (r - l), invH = 1.0f / (t - b), invD = 1.0f / (zn - zf);
  F32 x = 2.0f * invW, y = 2.0f * invH, w = -(l + r) * invW, h = -(t + b) * invH, z = 2.0f * invD, d = (zf + zn) * invD;
  return float4x4(
    x,      0.0f,   0.0f,   0.0f,
    0.0f,   y,      0.0f,   0.0f,
    0.0f,   0.0f,   z,      0.0f,
    w,      h,      d,      1.0f);
}

HLML_INLINEF float4x4 ortho(F32 l, F32 r, F32 b, F32 t, F32 zn) {
  F32 invW = 1.0f / (r - l), invH = 1.0f / (t - b);
  F32 x = 2.0f * invW, y = 2.0f * invH, w = -(l + r) * invW, h = -(t + b) * invH;
  return float4x4(
    x,      0.0f,   0.0f,   0.0f,
    0.0f,   y,      0.0f,   0.0f,
    0.0f,   0.0f,   0.0f,   0.0f,
    w,      h,     -1.0f,   1.0f);
}

HLML_INLINEF float4x4 ortho(F32 w, F32 h, F32 zn, F32 zf) { F32 hw = 0.5f * w, hh = 0.5f * h; return ortho(-hw, hw, -hh, hh, zn, zf); }
HLML_INLINEF float4x4 ortho(F32 w, F32 h, F32 zn) { F32 hw = 0.5f * w, hh = 0.5f * h; return ortho(-hw, hw, -hh, hh, zn); }

HLML_INLINEF float4x4 perspective(F32 l, F32 r, F32 b, F32 t, F32 zn, F32 zf) {
  F32 invW = 1.0f / (r - l), invH = 1.0f / (t - b), invD = 1.0f / (zn - zf);
  F32 dzn = 2.0f * zn, lr = l + r, tb = t + b;
  F32 x = dzn * invW, y = dzn * invH, w = lr * invW, h = tb * invH, z = (zf + zn) * invD, d = 2.0f * zn * zf * invD;
  return float4x4(
    x,      0.0f,   0.0f,   0.0f,
    0.0f,   y,      0.0f,   0.0f,
    w,      h,      z,     -1.0f,
    0.0f,   0.0f,   d,      0.0f);
}

HLML_INLINEF float4x4 perspective(F32 l, F32 r, F32 b, F32 t, F32 zn) {
  F32 invW = 1.0f / (r - l), invH = 1.0f / (t - b);
  F32 dzn = 2.0f * zn, lr = l + r, tb = t + b;
  F32 x = dzn * invW, y = dzn * invH, w = lr * invW, h = tb * invH, d = -2.0f * zn;
  return float4x4(
    x,      0.0f,   0.0f,   0.0f,
    0.0f,   y,      0.0f,   0.0f,
    w,      h,     -1.0f,  -1.0f,
    0.0f,   0.0f,   d,      0.0f);
}
HLML_INLINEF float4x4 perspectiveInvZ(F32 l, F32 r, F32 b, F32 t, F32 zn) {
  F32 invW = 1.0f / (r - l), invH = 1.0f / (t - b);
  F32 dzn = 2.0f * zn, lr = l + r, tb = t + b;
  F32 x = dzn * invW, y = dzn * invH, w = lr * invW, h = tb * invH, d = -2.0f * zn;
  return float4x4(
    x,      0.0f,   0.0f,   0.0f,
    0.0f,   y,      0.0f,   0.0f,
    w,      h,      0.0f,  -1.0f,
    0.0f,   0.0f,   zn,     0.0f);
}

HLML_INLINEF float4x4 perspective(F32 w, F32 h, F32 zn, F32 zf) { F32 hw = 0.5f * w, hh = 0.5f * h; return perspective(-hw, hw, -hh, hh, zn, zf); }
HLML_INLINEF float4x4 perspective(F32 w, F32 h, F32 zn) { F32 hw = 0.5f * w, hh = 0.5f * h; return perspective(-hw, hw, -hh, hh, zn); }

HLML_INLINEF float4x4 perspectiveFov(F32 fovDegs, F32 w2h, F32 zn, F32 zf) {
  const float4 rads(HLML_DEG2RAD(fovDegs) * 0.5f);
  const F32 aspectInv = 1.0f / w2h, t = 1.0f / tan(rads).x(), invD = 1.0f / (zn - zf);
  const F32 x = aspectInv * t, y = t, z = (zf + zn) * invD, d = 2.0f * zn * zf * invD;
  return float4x4(
    x,      0.0f,   0.0f,   0.0f,
    0.0f,   y,      0.0f,   0.0f,
    0.0f,   0.0f,   z,     -1.0f,
    0.0f,   0.0f,   d,      0.0f);
}

HLML_INLINEF float4x4 perspectiveFov(F32 fovDegs, F32 w2h, F32 zn) {
  const float4 rads(HLML_DEG2RAD(fovDegs) * 0.5f);
  const F32 aspectInv = 1.0f / w2h, t = 1.0f / tan(rads).x();
  const F32 x = aspectInv * t, y = t, d = -2.0f * zn;
  return float4x4(
    x,      0.0f,   0.0f,   0.0f,
    0.0f,   y,      0.0f,   0.0f,
    0.0f,   0.0f,  -1.0f,  -1.0f,
    0.0f,   0.0f,   d,      0.0f);
}
HLML_INLINEF float4x4 perspectiveFovInvZ(F32 fovDegs, F32 w2h, F32 zn) {
  const float4 rads(HLML_DEG2RAD(fovDegs) * 0.5f);
  const F32 aspectInv = 1.0f / w2h, t = 1.0f / tan(rads).x();
  const F32 x = aspectInv * t, y = t;
  return float4x4(
    x,      0.0f,   0.0f,   0.0f,
    0.0f,   y,      0.0f,   0.0f,
    0.0f,   0.0f,   0.0f,  -1.0f,
    0.0f,   0.0f,   zn,     0.0f);
}
}
