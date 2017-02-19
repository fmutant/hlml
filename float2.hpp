#pragma once

#include "common.hpp"
#include "bool2.hpp"
#include "int2.hpp"

namespace hlml {
struct float2 {
  #define shufflef2(V, X, Y) float2(_mm_shuffle_ps((V).m, (V).m, _MM_SHUFFLE(3, 2, Y, X)))
  #define insertf2(V, X, i) _mm_insert_ps((V), _mm_set_ss((X)), i << 4)
  
  VF128 m = { 0 };

  HLML_INLINEF float2() {}
  HLML_INLINEF float2(F32 x, F32 y) : m(_mm_set_ps(sfZero, sfZero, y, x)) {}
  HLML_INLINEF explicit float2(F32 x) : m(_mm_set_ps(sfZero, sfZero, x, x)) {}
  HLML_INLINEF explicit float2(const F32 *p) : m(_mm_set_ps(sfZero, sfZero, p[1], p[0])) {}
  HLML_INLINEF explicit float2(VF128 v) : m(v) {}
  HLML_INLINEF float2 float2i(I32 x, I32 y) { return float2((F32)x, (F32)y); }

  HLML_INLINEF void store(F32 *p) const { p[0] = x(); p[1] = y(); }

  HLML_INLINEF void setX(F32 x) { m = insertf2(m, x, 0); }
  HLML_INLINEF void setY(F32 y) { m = insertf2(m, y, 1); }

  HLML_INLINEF F32 x() const { iasf res = _mm_extract_ps(m, 0); return res.f; }
  HLML_INLINEF F32 y() const { iasf res = _mm_extract_ps(m, 1); return res.f; }

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

template<typename T> HLML_INLINEF T   operator~  (T a) { a.m = _mm_andnot_ps(a.m, vnall); return a; }
template<typename T> HLML_INLINEF T   operator&  (T a, T b) { a.m = _mm_and_ps(a.m, b.m); return a; }
template<typename T> HLML_INLINEF T   operator|  (T a, T b) { a.m = _mm_or_ps(a.m, b.m); return a; }
template<typename T> HLML_INLINEF T   operator^  (T a, T b) { a.m = _mm_xor_ps(a.m, b.m); return a; }

template<typename T> HLML_INLINEF T   operator+  (T a) { return a; }
template<typename T> HLML_INLINEF T   operator+  (T a, T b) { a.m = _mm_add_ps(a.m, b.m); return a; }
template<typename T> HLML_INLINEF T   operator+  (T a, F32 b) { return a + T(b); }
template<typename T> HLML_INLINEF T   operator+  (F32 b, T a) { return a + b; }
template<typename T> HLML_INLINEF T&  operator+= (T& a, T b) { a = a + b; return a; }
template<typename T> HLML_INLINEF T&  operator+= (T& a, F32 b) { return a += T(b); }
template<typename T> HLML_INLINEF T   operator-  (T a) { a.m = _mm_xor_ps(a.m, vsignbits); return a; }
template<typename T> HLML_INLINEF T   operator-  (T a, T b) { a.m = _mm_sub_ps(a.m, b.m); return a; }
template<typename T> HLML_INLINEF T   operator-  (T a, F32 b) { return a - T(b); }
template<typename T> HLML_INLINEF T   operator-  (F32 a, T b) { return T(a) - b; }
template<typename T> HLML_INLINEF T&  operator-= (T& a, T b) { a = a - b; return a; }
template<typename T> HLML_INLINEF T&  operator-= (T& a, F32 b) { return a -= T(b); }
template<typename T> HLML_INLINEF T   operator*  (T a, T b) { a.m = _mm_mul_ps(a.m, b.m); return a; }
template<typename T> HLML_INLINEF T   operator*  (T a, F32 b) { return a * T(b); }
template<typename T> HLML_INLINEF T   operator*  (F32 b, T a) { return a * b; }
template<typename T> HLML_INLINEF T&  operator*= (T& a, T b) { a = a * b; return a; }
template<typename T> HLML_INLINEF T&  operator*= (T& a, F32 b) { return a *= T(b); }
template<typename T> HLML_INLINEF T   operator/  (T a, T b) { a.m = _mm_div_ps(a.m, b.m); return a; }
template<typename T> HLML_INLINEF T   operator/  (T a, F32 b) { return a / T(b); }
template<typename T> HLML_INLINEF T   operator/  (F32 a, T b) { return T(a) / b; }
template<typename T> HLML_INLINEF T&  operator/= (T& a, T b) { a = a / b; return a; }
template<typename T> HLML_INLINEF T&  operator/= (T& a, F32 b) { return a /= T(b); }

template<typename T> HLML_INLINEF T   cmpeq      (T a, T b) { return T(_mm_cmpeq_ps(a.m, b.m)); }
template<typename T> HLML_INLINEF T   cmpneq     (T a, T b) { return T(_mm_cmpneq_ps(a.m, b.m)); }
template<typename T> HLML_INLINEF T   cmpgt      (T a, T b) { return T(_mm_cmpgt_ps(a.m, b.m)); }
template<typename T> HLML_INLINEF T   cmpge      (T a, T b) { return T(_mm_cmpge_ps(a.m, b.m)); }
template<typename T> HLML_INLINEF T   cmplt      (T a, T b) { return T(_mm_cmplt_ps(a.m, b.m)); }
template<typename T> HLML_INLINEF T   cmple      (T a, T b) { return T(_mm_cmple_ps(a.m, b.m)); }

HLML_INLINEF bool2                    operator== (float2 a, float2 b) { return bool2(_mm_cvttps_epi32(cmpeq(a, b).m)); }
HLML_INLINEF bool2                    operator!= (float2 a, float2 b) { return bool2(_mm_cvttps_epi32(cmpneq(a, b).m)); }
HLML_INLINEF bool2                    operator<  (float2 a, float2 b) { return bool2(_mm_cvttps_epi32(cmplt(a, b).m)); }
HLML_INLINEF bool2                    operator>  (float2 a, float2 b) { return bool2(_mm_cvttps_epi32(cmpgt(a, b).m)); }
HLML_INLINEF bool2                    operator<= (float2 a, float2 b) { return bool2(_mm_cvttps_epi32(cmple(a, b).m)); }
HLML_INLINEF bool2                    operator>= (float2 a, float2 b) { return bool2(_mm_cvttps_epi32(cmpge(a, b).m)); }

HLML_INLINEF int2 asint(float2 a) { return int2(_mm_castps_si128(a.m)); }
HLML_INLINEF int2 toint(float2 a) { return int2(_mm_cvttps_epi32(a.m)); }
HLML_INLINEF int2 toint2(float2 a) { return asint(a + float2(vf2ibits)) - int2(vf2ibits); }
HLML_INLINEF float2 asflt(int2 a) { return float2(_mm_castsi128_ps(a.m)); }
HLML_INLINEF float2 toflt(int2 a) { return float2(_mm_cvtepi32_ps(a.m)); }

template<> HLML_INLINEF float2 min(float2 a, float2 b) { a.m = _mm_min_ps(a.m, b.m); return a; }
template<> HLML_INLINEF float2 max(float2 a, float2 b) { a.m = _mm_max_ps(a.m, b.m); return a; }
HLML_INLINEF float2 sumv(float2 v) { v.m =_mm_hadd_ps(v.m, v.m);  return v; }
HLML_INLINEF float2 crossv(float2 a, float2 b) { return (a * b.yx() - a.yx() * b); }
HLML_INLINEF F32 cross(float2 a, float2 b) { return crossv(a, b).x(); }
HLML_INLINEF F32 hmin(float2 v) { return min(v, shufflef2(v, 1, 0)).x(); }
HLML_INLINEF F32 hmax(float2 v) { return max(v, shufflef2(v, 1, 0)).x(); }

template<typename T> HLML_INLINEF T sign(T v) { T zro0(vzeros); return (cmplt(v, zro0) & T(vonesneg)) | (cmpgt(v, zro0) & T(vones)); } //https://github.com/g-truc/glm/blob/master/glm/simd/common.h#L99
template<typename T> HLML_INLINEF T abs(T v) { v.m = _mm_andnot_ps(vsignbits, v.m); return v; }

template<typename T> HLML_INLINEF T rcp(T v) { return 1.0f / v; }
template<typename T> HLML_INLINEF T sqrt(T v) { v.m = _mm_sqrt_ps(v.m); return v; }
template<typename T> HLML_INLINEF T rsqrt(T v) { v.m = _mm_rsqrt_ps(v.m); return v; }
template<typename T> HLML_INLINEF F32 sum(T v) { return sumv(v).x(); }
template<typename T> HLML_INLINEF T normalize(T v) { return v * rsqrt(dotv(v, v)); }
template<typename T> HLML_INLINEF T dotv(T a, T b) { return sumv(a * b); }
template<typename T> HLML_INLINEF F32 dot(T a, T b) { return dotv(a, b).x(); }
template<typename T> HLML_INLINEF T reflect(T v, T n) { return v = v - 2.0f * n * dotv(v, n); }
template<typename T> HLML_INLINEF T refract(T v, T n, F32 idx) {
  T vn = dotv(v, n), k = max(T(vzeros), 1.0f - idx * idx * (1.0f - vn * vn));
  return idx * v - (idx * vn + sqrt(k)) * n;
}
template<typename T> HLML_INLINEF T mad(T a, T b, T c) { a.m = _mm_fmadd_ps(a.m, b.m, c.m); return a; }
template<typename T> HLML_INLINEF T fmod(T a, T b) { return a - toflt(toint(a / b)) * b; }
template<typename T> HLML_INLINEF T clamp(T t, T a, T b) { return min(max(t, a), b); }
template<typename T> HLML_INLINEF T lerp(T a, T b, F32 t) { return a + (b - a) * t; }
template<typename T> HLML_INLINEF T saturate(T a) { return clamp(a, T(vzeros), T(vones)); }
template<typename T> HLML_INLINEF T floor(T a) { a.m = _mm_floor_ps(a.m); return a; }
template<typename T> HLML_INLINEF T ceil(T a) { a.m = _mm_ceil_ps(a.m); return a; }
template<typename T> HLML_INLINEF T frac(T a) { a.m = _mm_frcz_ps(a.m); return a; }
template<typename T> HLML_INLINEF T trunc(T a) { a.m = _mm_round_ps(a.m, _MM_FROUND_TRUNC); return a; }
template<typename T> HLML_INLINEF T round(T a) { a.m = _mm_round_ps(a.m, _MM_FROUND_NINT); return a; }
template<typename T> HLML_INLINEF F32 length(T v) { return sqrt(sumv(v * v)).x(); }
template<typename T> HLML_INLINEF F32 lengthSq(T v) { return dot(v, v); }
template<typename T> HLML_INLINEF T step(T e, T v) { return max(T(vzeros), sign(v - e)); }
template<typename T> HLML_INLINEF T smoothstep(T e0, T e1, T v) {
  T zeros(vzeros), ones(vones), t = clamp((v - e0) / (e1 - e0), zeros, ones);
  return (3.0f - 2.0f * t) * t * t;
}
}