#pragma once

#include "common.hpp"
#include "bool2.hpp"
#include "int2.hpp"

namespace hlml {
struct float2 {
  VF128 m = { 0 };

  HLML_INLINEF float2() {}
  HLML_INLINEF float2(f32 x, f32 y) : m(funcs::setXYZW(x, y, consts::sfZero, consts::sfZero)) {}
  HLML_INLINEF explicit float2(f32 x) : float2(x, x) {}
  HLML_INLINEF explicit float2(const f32 *p) : float2(p[0], p[1]) {}
  HLML_INLINEF explicit float2(VF128 v) : m(v) {}
  HLML_INLINEF float2 float2i(i32 x, i32 y) { return float2((f32)x, (f32)y); }

  HLML_INLINEF void store(f32 *p) const { p[0] = x(); p[1] = y(); }

  HLML_INLINEF void setX(f32 x) { m = insertf(m, x, 0); }
  HLML_INLINEF void setY(f32 y) { m = insertf(m, y, 1); }

  HLML_INLINEF f32 x() const { uiasf res(extractf(m, 0)); return res.asf32; }
  HLML_INLINEF f32 y() const { uiasf res(extractf(m, 1)); return res.asf32; }

  HLML_INLINEF float2 xx() const { return shufflef2(*this, 0, 0); }
  HLML_INLINEF float2 xy() const { return *this; }
  HLML_INLINEF float2 yx() const { return shufflef2(*this, 1, 0); }
  HLML_INLINEF float2 yy() const { return shufflef2(*this, 1, 1); }

  HLML_INLINEF f32 r() const { return x(); }
  HLML_INLINEF f32 g() const { return y(); }

  HLML_INLINEF float2 rr() const { return xx(); }
  HLML_INLINEF float2 rg() const { return xy(); }
  HLML_INLINEF float2 gr() const { return yx(); }
  HLML_INLINEF float2 gg() const { return yy(); }
};
//boolean
HLML_INLINEF bool2    operator==  (float2 a, float2 b) { a.m = funcs::AcmpeqB(a.m, b.m); return bool2(funcs::fasi(a.m)); }
HLML_INLINEF bool2    operator!=  (float2 a, float2 b) { a.m = funcs::AcmpneB(a.m, b.m); return bool2(funcs::fasi(a.m)); }
HLML_INLINEF bool2    operator<   (float2 a, float2 b) { a.m = funcs::AcmpltB(a.m, b.m); return bool2(funcs::fasi(a.m)); }
HLML_INLINEF bool2    operator>   (float2 a, float2 b) { a.m = funcs::AcmpgtB(a.m, b.m); return bool2(funcs::fasi(a.m)); }
HLML_INLINEF bool2    operator<=  (float2 a, float2 b) { a.m = funcs::AcmpleB(a.m, b.m); return bool2(funcs::fasi(a.m)); }
HLML_INLINEF bool2    operator>=  (float2 a, float2 b) { a.m = funcs::AcmpgeB(a.m, b.m); return bool2(funcs::fasi(a.m)); }
//logical
HLML_INLINEF float2   operator~   (float2 a) { a.m = funcs::notAandB(a.m, consts::vnall2); return a; }
HLML_INLINEF float2   operator&   (float2 a, float2 b) { a.m = funcs::AandB(a.m, b.m); return a; }
HLML_INLINEF float2   operator|   (float2 a, float2 b) { a.m = funcs::AorB(a.m, b.m); return a; }
HLML_INLINEF float2   operator^   (float2 a, float2 b) { a.m = funcs::AxorB(a.m, b.m); return a; }
//arithmetic
HLML_INLINEF float2   operator+   (float2 a) { return a; }
HLML_INLINEF float2   operator-   (float2 a) { a.m = funcs::AxorB(a.m, consts::vsignbits_xy); return a; }
HLML_INLINEF float2   operator+   (float2 a, float2 b) { a.m = funcs::AaddB(a.m, b.m); return a; }
HLML_INLINEF float2   operator-   (float2 a, float2 b) { a.m = funcs::AsubB(a.m, b.m); return a; }
HLML_INLINEF float2   operator*   (float2 a, float2 b) { a.m = funcs::AmulB(a.m, b.m); return a; }
HLML_INLINEF float2   operator/   (float2 a, float2 b) { a.m = funcs::AdivB(a.m, b.m); return a; }
HLML_INLINEF float2&  operator+=  (float2& a, float2 b) { a = a + b; return a; }
HLML_INLINEF float2&  operator-=  (float2& a, float2 b) { a = a - b; return a; }
HLML_INLINEF float2&  operator*=  (float2& a, float2 b) { a = a * b; return a; }
HLML_INLINEF float2&  operator/=  (float2& a, float2 b) { a = a / b; return a; }
HLML_INLINEF float2   operator+   (float2 a, f32 b) { return a + float2(b); }
HLML_INLINEF float2   operator-   (float2 a, f32 b) { return a - float2(b); }
HLML_INLINEF float2   operator*   (float2 a, f32 b) { return a * float2(b); }
HLML_INLINEF float2   operator/   (float2 a, f32 b) { return a / float2(b); }
HLML_INLINEF float2&  operator+=  (float2& a, f32 b) { return a += float2(b); }
HLML_INLINEF float2&  operator-=  (float2& a, f32 b) { return a -= float2(b); }
HLML_INLINEF float2&  operator*=  (float2& a, f32 b) { return a *= float2(b); }
HLML_INLINEF float2&  operator/=  (float2& a, f32 b) { return a /= float2(b); }
HLML_INLINEF float2   operator+   (f32 a, float2 b) { return float2(a) + b; }
HLML_INLINEF float2   operator-   (f32 a, float2 b) { return float2(a) - b; }
HLML_INLINEF float2   operator*   (f32 a, float2 b) { return float2(a) * b; }
HLML_INLINEF float2   operator/   (f32 a, float2 b) { return float2(a) / b; }
//funcs
HLML_INLINEF int2     asint       (float2 a) { return int2(funcs::fasi(a.m)); }
HLML_INLINEF int2     toint       (float2 a) { return int2(funcs::ftoi(a.m)); }
HLML_INLINEF float2   asflt       (int2 a) { return float2(funcs::iasf(a.m)); }
HLML_INLINEF float2   toflt       (int2 a) { return float2(funcs::itof(a.m)); }

HLML_INLINEF float2   abs         (float2 v) { v.m = funcs::notAandB(consts::vsignbits_xy, v.m); return v; }
HLML_INLINEF float2   ceil        (float2 a) { a.m = funcs::ceil(a.m); return a; }
HLML_INLINEF float2   clamp       (float2 v, float2 a, float2 b) { v.m = funcs::AminB(funcs::AmaxB(v.m, a.m), b.m); return v; }
HLML_INLINEF float2   clamp       (float2 v, f32 a, f32 b) { return clamp(v, float2(a), float2(b)); }
HLML_INLINEF float2   crossv      (float2 a, float2 b) { return (a * b.yx() - a.yx() * b); }
HLML_INLINEF float2   dotv        (float2 a, float2 b) { a.m = funcs::AdotBxy(a.m, b.m); return a; }
HLML_INLINEF float2   floor       (float2 a) { a.m = funcs::floor(a.m); return a; }
HLML_INLINEF float2   fmod        (float2 a, float2 b) { return a - toflt(toint(a / b)) * b; }
HLML_INLINEF float2   frac        (float2 a) { a.m = funcs::frac(a.m); return a; }
HLML_INLINEF float2   lerp        (float2 a, float2 b, f32 t) { return a + (b - a) * t; }
HLML_INLINEF float2   lerp        (float2 a, float2 b, float2 t) { return a + (b - a) * t; }
HLML_INLINEF float2   mad         (float2 a, float2 b, float2 c) { a.m = funcs::AmulBaddC(a.m, b.m, c.m); return a; }
HLML_INLINEF float2   maxv        (float2 a, float2 b) { a.m = funcs::AmaxB(a.m, b.m); return a; }
HLML_INLINEF float2   minv        (float2 a, float2 b) { a.m = funcs::AminB(a.m, b.m); return a; }
HLML_INLINEF float2   rcp         (float2 v) { v.m = funcs::axay0000(funcs::rcp(funcs::axay1111(v.m))); return v; }
HLML_INLINEF float2   reflect     (float2 v, float2 n) { return v - n * dotv(v, n) * 2.0f; }
HLML_INLINEF float2   round       (float2 a) { a.m = funcs::round(a.m); return a; }
HLML_INLINEF float2   rsqrt       (float2 v) { v.m = funcs::axay0000(funcs::rsqrt(funcs::axay1111(v.m))); return v; }
HLML_INLINEF float2   saturate    (float2 a) { return clamp(a, 0.0f, 1.0f); }
HLML_INLINEF float2   sumv        (float2 v) { v.m = funcs::AhaddB(v.m, v.m);  return v; }
HLML_INLINEF float2   sqrt        (float2 v) { v.m = funcs::sqrt(v.m); return v; }
HLML_INLINEF float2   trunc       (float2 a) { a.m = funcs::trunc(a.m); return a; }


HLML_INLINEF f32      cross       (float2 a, float2 b) { return crossv(a, b).x(); }
HLML_INLINEF f32      hmin        (float2 v) { return minv(v, shufflef2(v, 1, 0)).x(); }
HLML_INLINEF f32      hmax        (float2 v) { return maxv(v, shufflef2(v, 1, 0)).x(); }
HLML_INLINEF f32      sum         (float2 v) { return sumv(v).x(); }
HLML_INLINEF f32      dot         (float2 a, float2 b) { return dotv(a, b).x(); }
HLML_INLINEF f32      lengthsq    (float2 v) { return dot(v, v); }
HLML_INLINEF f32      length      (float2 v) { return sqrt(dotv(v, v)).x(); }

HLML_INLINEF float2 normalize(float2 v) {
  float2 t = dotv(v, v);
  float2 d = rsqrt(t);
  return v * d;
}

HLML_INLINEF float2 refract(float2 v, float2 n, f32 idx) {
  float2 vn = dotv(v, n);
  float2 k = maxv(float2(consts::vzeros), float2(1.0f - idx * idx * (1.0f - vn * vn)));
  return v * idx - (vn * idx + sqrt(k)) * n;
}

HLML_INLINEF float2 sign(float2 v) {
  //https://github.com/g-truc/glm/blob/master/glm/simd/common.h#L99
  VF128 cmp0 = funcs::AcmpltB(v.m, consts::vzeros);
  VF128 cmp1 = funcs::AcmpgtB(v.m, consts::vzeros);
  VF128 and0 = funcs::AandB(cmp0, consts::vnones2);
  VF128 and1 = funcs::AandB(cmp1, consts::vones2);
  v.m = funcs::AorB(and0, and1);
  return v;
}

HLML_INLINEF float2 smoothstep(float2 e0, float2 e1, float2 v) {
  float2 zeros(consts::vzeros), ones(consts::vones);
  float2 t = clamp((v - e0) / (e1 - e0), zeros, ones);
  return (3.0f - 2.0f * t) * t * t;
}

HLML_INLINEF float2 step(float2 e, float2 v) {
  e = sign(v - e);
  return maxv(float2(consts::vzeros), e);
}
}