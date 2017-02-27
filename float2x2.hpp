#pragma once

#include "common.hpp"
#include "float4.hpp"

namespace hlml {
struct float2x2 {
  float4 m;

  HLML_INLINEF float2x2() : m() {}
  HLML_INLINEF explicit float2x2(const F32* p) : m(p) {}
  HLML_INLINEF float2x2(F32 x0, F32 y0, F32 x1, F32 y1) : m(x0, y0, x1, y1) {}
  HLML_INLINEF float2x2(float2 col0, float2 col1) : m(funcs::axaybxby(col0.m, col1.m)) {}

  HLML_INLINEF static float2x2 identity() { static float2x2 i( { 1.0f, 0.0f, 0.0f, 1.0f } ); return i; }

  HLML_INLINEF float2x2& operator= (float2x2 rhs) { m = rhs.m; return *this; }
  HLML_INLINEF float2x2& operator= (F32 s) { m = float4(s); return *this; }
};

HLML_INLINEF float2x2 transpose(float2x2 m) { m.m = m.m.xzyw(); return m; }
HLML_INLINEF float2x2 inverse(float2x2 a) {
  float4 neg(-a.m);
  float4 tmp(funcs::awaxbybz(a.m.m, neg.m));
  float4 adj = tmp.xzwy();
  float4 trans = a.m.xzyw();
  float4 lhs = trans * adj;
  float4 rhs = lhs.yxwz();
  float4 dets = lhs + rhs;
  a.m = adj / dets;
  return a;
}

HLML_INLINEF B8         operator==  (float2x2 lhs, float2x2 rhs) { return all(lhs.m == rhs.m); }
HLML_INLINEF B8         operator!=  (float2x2 lhs, float2x2 rhs) { return !(lhs == rhs); }

HLML_INLINEF float2x2   operator+   (float2x2 m) { return m; }
HLML_INLINEF float2x2   operator+   (float2x2 a, float2x2 b) { a.m += b.m; return a; }
HLML_INLINEF float2x2   operator+   (float2x2 a, F32 s) { a.m += s; return a; }
HLML_INLINEF float2x2   operator+   (F32 s, float2x2 a) { return a + s; }
HLML_INLINEF float2x2&  operator+=  (float2x2& a, float2x2 b) { a = a + b; return a; }
HLML_INLINEF float2x2&  operator+=  (float2x2& a, F32 s) { a = a + s; return a; }
HLML_INLINEF float2x2   operator-   (float2x2 m) { m.m = -m.m; return m; }
HLML_INLINEF float2x2   operator-   (float2x2 a, float2x2 b) { a.m -= b.m; return a; }
HLML_INLINEF float2x2   operator-   (float2x2 a, F32 s) { a.m -= s; return a; }
HLML_INLINEF float2x2   operator-   (F32 s, float2x2 a) { float2 tmp(s); return float2x2(tmp, tmp) - a; }
HLML_INLINEF float2x2&  operator-=  (float2x2& a, float2x2 b) { a = a - b; return a; }
HLML_INLINEF float2x2&  operator-=  (float2x2& a, F32 s) { a = a - s; return a; }
HLML_INLINEF float2x2   operator*   (float2x2 a, float2x2 b) {
  a.m = a.m.xyxy() * b.m.xxzz() + a.m.zwzw() * b.m.yyww();
  return a;
}
HLML_INLINEF float2x2   operator*   (float2x2 a, F32 s) { a.m *= s; return a; }
HLML_INLINEF float2x2   operator*   (F32 s, float2x2 a) { return a * s; }
HLML_INLINEF float2     operator*   (float2x2 a, float2 v) { a.m *= shufflef4(v,0,1,0,1); return (a.m + a.m.yxwz()).xz(); }
HLML_INLINEF float2     operator*   (float2 v, float2x2 a) {
  float2 xx(dotv(v, a.m.xy())), yy(dotv(v, a.m.zw()));
  float2 xy(funcs::axbxayby(xx.m, yy.m));
  return xy;
}
HLML_INLINEF float2x2&  operator*=  (float2x2& a, float2x2 b) { a.m = b.m.xyxy() * a.m.xxzz() + b.m.zwzw() * a.m.yyww(); return a; }
HLML_INLINEF float2x2&  operator*=  (float2x2& a, F32 s) { a = a * s; return a; }
}
