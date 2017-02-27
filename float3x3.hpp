#pragma once

#include "common.hpp"
#include "float3.hpp"

namespace hlml {
struct float3x3 {
  float3 c0, c1, c2;

  HLML_INLINEF float3x3() : c0(), c1(), c2() {}
  HLML_INLINEF explicit float3x3(const F32* p) : c0(p), c1(p+3), c2(p+6) {}
  HLML_INLINEF float3x3(F32 x0, F32 y0, F32 z0, F32 x1, F32 y1, F32 z1, F32 x2, F32 y2, F32 z2) : c0(x0, y0, z0), c1(x1, y1, z1), c2(x2, y2, z2) {}
  HLML_INLINEF float3x3(float3 col0, float3 col1, float3 col2) : c0(col0), c1(col1), c2(col2) {}

  HLML_INLINEF static float3x3 identity() { static float3x3 i( { 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f } ); return i; }

  HLML_INLINEF float3x3& operator= (float3x3 rhs) { c0 = rhs.c0; c1 = rhs.c1; c2 = rhs.c2; return *this; }
  HLML_INLINEF float3x3& operator= (F32 s) { c0 = c1 = c2 = float3(s); return *this; }
};

HLML_INLINEF float3x3 transpose(float3x3 m) {
  float3 t0 = m.c0, t1 = m.c1, t2 = m.c2, vT(funcs::azbzawbw(t0.m, t1.m));
  t0.m = funcs::axbxayby(t0.m, t1.m);
  m.c0.m = funcs::axaybxbw(t0.m, t2.m);
  m.c1.m = funcs::azawbybw(t0.m, t2.m);
  m.c2.m = funcs::axaybzbw(vT.m, t2.m);
  return m;
}
HLML_INLINEF float3x3 inverse(float3x3 m) {
  float3 t0 = m.c0, t1 = m.c1, t2 = m.c2;
  float3 dets = rcp(dotv(t0, cross(t1, t2)));
  dets.m = funcs::axaxazaz(dets.m);
  m.c0 = cross(t1, t2) * dets;
  m.c1 = cross(t2, t0) * dets;
  m.c2 = cross(t0, t1) * dets;
  return transpose(m);
}

HLML_INLINEF B8         operator==  (float3x3 lhs, float3x3 rhs) { return all(lhs.c0 == rhs.c0) && all(lhs.c1 == rhs.c1) && all(lhs.c2 == rhs.c2); }
HLML_INLINEF B8         operator!=  (float3x3 lhs, float3x3 rhs) { return !(lhs == rhs); }

HLML_INLINEF float3x3   operator+   (float3x3 m) { return m; }
HLML_INLINEF float3x3   operator+   (float3x3 a, float3x3 b) { a.c0 += b.c0; a.c1 += b.c1; a.c2 += b.c2; return a; }
HLML_INLINEF float3x3   operator+   (float3x3 a, F32 s) { a.c0 += s; a.c1 += s; a.c2 += s; return a; }
HLML_INLINEF float3x3   operator+   (F32 s, float3x3 a) { return a + s; }
HLML_INLINEF float3x3&  operator+=  (float3x3& a, float3x3 b) { a = a + b; return a; }
HLML_INLINEF float3x3&  operator+=  (float3x3& a, F32 s) { a = a + s; return a; }
HLML_INLINEF float3x3   operator-   (float3x3 m) { m.c0 = -m.c0; m.c1 = -m.c1; m.c2 = -m.c2; return m; }
HLML_INLINEF float3x3   operator-   (float3x3 a, float3x3 b) { a.c0 -= b.c0; a.c1 -= b.c1; a.c2 -= b.c2; return a; }
HLML_INLINEF float3x3   operator-   (float3x3 a, F32 s) { float3 tmp(s); return a - float3x3(tmp, tmp, tmp); }
HLML_INLINEF float3x3   operator-   (F32 s, float3x3 a) { float3 tmp(s); return float3x3(tmp, tmp, tmp) - a; }
HLML_INLINEF float3x3&  operator-=  (float3x3& a, float3x3 b) { a = a - b; return a; }
HLML_INLINEF float3x3&  operator-=  (float3x3& a, F32 s) { a = a - s; return a; }
HLML_INLINEF float3x3   operator*   (float3x3 a, float3x3 b) {
  float3 lc0 = a.c0, lc1 = a.c1, lc2 = a.c2, rc0 = b.c0, rc1 = b.c1, rc2 = b.c2;
  a.c0 = lc0 * rc0.xxx() + lc1 * rc0.yyy() + lc2 * rc0.zzz();
  a.c1 = lc0 * rc1.xxx() + lc1 * rc1.yyy() + lc2 * rc1.zzz();
  a.c2 = lc0 * rc2.xxx() + lc1 * rc2.yyy() + lc2 * rc2.zzz();
  return a;
}
HLML_INLINEF float3x3   operator*   (float3x3 a, F32 s) { a.c0 *= s; a.c1 *= s; a.c2 *= s; return a; }
HLML_INLINEF float3x3   operator*   (F32 s, float3x3 a) { return a * s; }
HLML_INLINEF float3     operator*   (float3x3 a, float3 v) { return v.xxx() * a.c0 + v.yyy() * a.c1 + v.zzz() * a.c2; }
HLML_INLINEF float3     operator*   (float3 v, float3x3 a) {
  float3 xxx(dotv(v, a.c0)), yyy(dotv(v, a.c1)), zzz(dotv(v, a.c2));
  float3 xyxy(funcs::axbxayby(xxx.m, yyy.m)), xyz0(funcs::bzbwazaw(zzz.m, xyxy.m));
  return xyz0;
}
HLML_INLINEF float3x3&  operator*=  (float3x3& a, float3x3 b) { a = a * b; return a; }
HLML_INLINEF float3x3&  operator*=  (float3x3& a, F32 s) { a = a * s; return a; }
}
