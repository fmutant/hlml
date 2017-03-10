#pragma once

#include "common.hpp"
#include "bool2.hpp"
#include "int2.hpp"

namespace hlml {
struct float2 {
  
  VF128 m = { 0 };

  HLML_INLINEF float2() {}
  HLML_INLINEF float2(F32 x, F32 y) : m(funcs::setXYZW(x, y, consts::sfZero, consts::sfZero)) {}
  HLML_INLINEF explicit float2(F32 x) : float2(x, x) {}
  HLML_INLINEF explicit float2(const F32 *p) : float2(p[0], p[1]) {}
  HLML_INLINEF explicit float2(VF128 v) : m(v) {}
  HLML_INLINEF float2 float2i(I32 x, I32 y) { return float2((F32)x, (F32)y); }

  HLML_INLINEF void store(F32 *p) const { p[0] = x(); p[1] = y(); }

  HLML_INLINEF void setX(F32 x) { m = insertf(m, x, 0); }
  HLML_INLINEF void setY(F32 y) { m = insertf(m, y, 1); }

  HLML_INLINEF F32 x() const { uiasf res = extractf(m, 0); return res.f; }
  HLML_INLINEF F32 y() const { uiasf res = extractf(m, 1); return res.f; }

  HLML_INLINEF float2 xx() const { return shufflef2(*this, 0, 0); }
  HLML_INLINEF float2 xy() const { return *this; }
  HLML_INLINEF float2 yx() const { return shufflef2(*this, 1, 0); }
  HLML_INLINEF float2 yy() const { return shufflef2(*this, 1, 1); }

  HLML_INLINEF F32 r() const { return x(); }
  HLML_INLINEF F32 g() const { return y(); }

  HLML_INLINEF float2 rr() const { return xx(); }
  HLML_INLINEF float2 rg() const { return xy(); }
  HLML_INLINEF float2 gr() const { return yx(); }
  HLML_INLINEF float2 gg() const { return yy(); }
};

HLML_INLINEF bool2                    operator== (float2 a, float2 b) { return bool2(funcs::ftoi(cmpeq(a, b).m)); }
HLML_INLINEF bool2                    operator!= (float2 a, float2 b) { return bool2(funcs::ftoi(cmpneq(a, b).m)); }
HLML_INLINEF bool2                    operator<  (float2 a, float2 b) { return bool2(funcs::ftoi(cmplt(a, b).m)); }
HLML_INLINEF bool2                    operator>  (float2 a, float2 b) { return bool2(funcs::ftoi(cmpgt(a, b).m)); }
HLML_INLINEF bool2                    operator<= (float2 a, float2 b) { return bool2(funcs::ftoi(cmple(a, b).m)); }
HLML_INLINEF bool2                    operator>= (float2 a, float2 b) { return bool2(funcs::ftoi(cmpge(a, b).m)); }

template<typename T> HLML_INLINEF T   operator+  (T a, F32 b) { return a + T(b); }
template<typename T> HLML_INLINEF T   operator+  (F32 b, T a) { return a + b; }
template<typename T> HLML_INLINEF T&  operator+= (T& a, F32 b) { return a += T(b); }
template<typename T> HLML_INLINEF T   operator-  (T a, F32 b) { return a - T(b); }
template<typename T> HLML_INLINEF T   operator-  (F32 a, T b) { return T(a) - b; }
template<typename T> HLML_INLINEF T&  operator-= (T& a, F32 b) { return a -= T(b); }
template<typename T> HLML_INLINEF T   operator*  (T a, F32 b) { return a * T(b); }
template<typename T> HLML_INLINEF T   operator*  (F32 b, T a) { return a * b; }
template<typename T> HLML_INLINEF T&  operator*= (T& a, F32 b) { return a *= T(b); }
template<typename T> HLML_INLINEF T   operator/  (T a, F32 b) { return a / T(b); }
template<typename T> HLML_INLINEF T   operator/  (F32 a, T b) { return T(a) / b; }
template<typename T> HLML_INLINEF T&  operator/= (T& a, F32 b) { return a /= T(b); }

HLML_INLINEF int2 asint(float2 a) { return int2(funcs::fasi(a.m)); }
HLML_INLINEF int2 toint(float2 a) { return int2(funcs::ftoi(a.m)); }
HLML_INLINEF float2 asflt(int2 a) { return float2(funcs::iasf(a.m)); }
HLML_INLINEF float2 toflt(int2 a) { return float2(funcs::itof(a.m)); }

HLML_INLINEF float2 sumv(float2 v) { v.m = funcs::AhaddB(v.m, v.m);  return v; }
HLML_INLINEF float2 crossv(float2 a, float2 b) { return (a * b.yx() - a.yx() * b); }
HLML_INLINEF F32 cross(float2 a, float2 b) { return crossv(a, b).x(); }
HLML_INLINEF F32 hmin(float2 v) { return min(v, shufflef2(v, 1, 0)).x(); }
HLML_INLINEF F32 hmax(float2 v) { return max(v, shufflef2(v, 1, 0)).x(); }

template<typename T> HLML_INLINEF T rcp(T v) { v.m = funcs::rcp(v.m); return v; }
template<typename T> HLML_INLINEF T sqrt(T v) { v.m = funcs::sqrt(v.m); return v; }
template<typename T> HLML_INLINEF T rsqrt(T v) { v.m = funcs::rsqrt(v.m); return v; }
template<typename T> HLML_INLINEF T normalize(T v) { return v * rsqrt(dotv(v, v)); }
template<typename T> HLML_INLINEF T dotv(T a, T b) { return sumv(a * b); }
template<typename T> HLML_INLINEF F32 dot(T a, T b) { return dotv(a, b).x(); }
template<typename T> HLML_INLINEF F32 sum(T v) { return sumv(v).x(); }
template<typename T> HLML_INLINEF T reflect(T v, T n) { return v = v - 2.0f * n * dotv(v, n); }
template<typename T> HLML_INLINEF T refract(T v, T n, F32 idx) {
  T vn = dotv(v, n), k = max(T(vzeros), 1.0f - idx * idx * (1.0f - vn * vn));
  return idx * v - (idx * vn + sqrt(k)) * n;
}
template<typename T> HLML_INLINEF T mad(T a, T b, T c) { a.m = funcs::mulABaddC(a.m, b.m, c.m); return a; }
template<typename T> HLML_INLINEF T fmod(T a, T b) { return a - toflt(toint(a / b)) * b; }
template<typename T> HLML_INLINEF T lerp(T a, T b, F32 t) { return a + (b - a) * t; }
template<typename T> HLML_INLINEF T saturate(T a) { return clamp(a, T(vzeros), T(vones)); }
template<typename T> HLML_INLINEF T floor(T a) { a.m = funcs::floor(a.m); return a; }
template<typename T> HLML_INLINEF T ceil(T a) { a.m = funcs::ceil(a.m); return a; }
template<typename T> HLML_INLINEF T frac(T a) { a.m = funcs::frac(a.m); return a; }
template<typename T> HLML_INLINEF T trunc(T a) { a.m = funcs::trunc(a.m); return a; }
template<typename T> HLML_INLINEF T round(T a) { a.m = funcs::round(a.m); return a; }
template<typename T> HLML_INLINEF F32 length(T v) { return sqrt(dotv(v, v)).x(); }
template<typename T> HLML_INLINEF F32 lengthSq(T v) { return dot(v, v); }
template<typename T> HLML_INLINEF T step(T e, T v) { return max(T(vzeros), sign(v - e)); }
template<typename T> HLML_INLINEF T smoothstep(T e0, T e1, T v) {
  T zeros(vzeros), ones(vones), t = clamp((v - e0) / (e1 - e0), zeros, ones);
  return (3.0f - 2.0f * t) * t * t;
}
}
