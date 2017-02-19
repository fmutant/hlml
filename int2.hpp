#pragma once

#include "common.hpp"
#include "bool2.hpp"

namespace hlml {
struct int2 {
  #define shufflei2(V, X, Y) int2(_mm_shuffle_epi32((V).m, _MM_SHUFFLE(3, 2, Y, X)))
  #define inserti2(V, X, i) _mm_insert_epi32((V), (X), i)
  #define extracti2(V, i) _mm_extract_epi32((V), i)

  VI128 m = { 0 };

  HLML_INLINEF int2() {}
  HLML_INLINEF int2(I32 x, I32 y) : m(_mm_set_epi32(snZero, snZero, y, x)) {}
  HLML_INLINEF explicit int2(I32 x) : m(_mm_set_epi32(snZero, snZero, x, x)) {}
  HLML_INLINEF explicit int2(const I32 *p) : m(_mm_set_epi32(snZero, snZero, p[1], p[0])) {}
  HLML_INLINEF explicit int2(VI128 v) : m(v) {}

  HLML_INLINEF void store(I32 *p) const { p[0] = x(); p[1] = y(); }

  HLML_INLINEF void setX(I32 x) { m = inserti2(m, x, 0); }
  HLML_INLINEF void setY(I32 y) { m = inserti2(m, y, 1); }

  HLML_INLINEF I32 x() const { return extracti2(m, 0); }
  HLML_INLINEF I32 y() const { return extracti2(m, 1); }

  HLML_INLINEF int2 xx() const { return shufflei2(*this, 0, 0); }
  HLML_INLINEF int2 xy() const { return shufflei2(*this, 0, 1); }
  HLML_INLINEF int2 yy() const { return shufflei2(*this, 1, 1); }
  HLML_INLINEF int2 yx() const { return shufflei2(*this, 1, 0); }

  HLML_INLINEF I32 r() const { return x(); }
  HLML_INLINEF I32 g() const { return y(); }

  HLML_INLINEF int2 rr() const { return xx(); }
  HLML_INLINEF int2 rg() const { return xy(); }
  HLML_INLINEF int2 gr() const { return yx(); }
  HLML_INLINEF int2 gg() const { return yy(); }
};

HLML_INLINEF int2   operator~   (int2 a) { a.m = _mm_andnot_si128(a.m, vnall); return a; }
HLML_INLINEF int2   operator&   (int2 a, int2 b) { a.m = _mm_and_si128(a.m, b.m); return a; }
HLML_INLINEF int2   operator|   (int2 a, int2 b) { a.m = _mm_or_si128(a.m, b.m); return a; }
HLML_INLINEF int2   operator^   (int2 a, int2 b) { a.m = _mm_xor_si128(a.m, b.m); return a; }

HLML_INLINEF int2   operator+   (int2 a) { return a; }
HLML_INLINEF int2   operator+   (int2 a, int2 b) { a.m = _mm_add_epi32(a.m, b.m); return a; }
HLML_INLINEF int2   operator+   (int2 a, I32 b) { return a + int2(b); }
HLML_INLINEF int2   operator+   (I32 b, int2 a) { return a + b; }
HLML_INLINEF int2&  operator+=  (int2& a, int2 b) { a = a + b; return a; }
HLML_INLINEF int2&  operator+=  (int2& a, I32 b) { return a += int2(b); }
HLML_INLINEF int2   operator-   (int2 a) { a.m = _mm_xor_si128(a.m, vsignbits); return a; }
HLML_INLINEF int2   operator-   (int2 a, int2 b) { a.m = _mm_sub_epi32(a.m, b.m); return a; }
HLML_INLINEF int2   operator-   (int2 a, I32 b) { return a - int2(b); }
HLML_INLINEF int2   operator-   (I32 a, int2 b) { return int2(a) - b; }
HLML_INLINEF int2&  operator-=  (int2& a, int2 b) { a = a - b; return a; }
HLML_INLINEF int2&  operator-=  (int2& a, I32 b) { return a -= int2(b); }
HLML_INLINEF int2   operator*   (int2 a, int2 b) { a.m = _mm_mul_epi32(a.m, b.m); return a; }
HLML_INLINEF int2   operator*   (int2 a, I32 b) { return a * int2(b); }
HLML_INLINEF int2   operator*   (I32 b, int2 a) { return a * b; }
HLML_INLINEF int2&  operator*=  (int2& a, int2 b) { a = a * b; return a; }
HLML_INLINEF int2&  operator*=  (int2& a, I32 b) { return a *= int2(b); }

HLML_INLINEF int2   cmpeq       (int2 a, int2 b) { return int2(_mm_cmpeq_epi32(a.m, b.m)); }
HLML_INLINEF int2   cmpgt       (int2 a, int2 b) { return int2(_mm_cmpgt_epi32(a.m, b.m)); }
HLML_INLINEF int2   cmplt       (int2 a, int2 b) { return int2(_mm_cmplt_epi32(a.m, b.m)); }

HLML_INLINEF bool2  operator==  (int2 a, int2 b) { return bool2(cmpeq(a, b).m); }
HLML_INLINEF bool2  operator!=  (int2 a, int2 b) { return !(a == b); }
HLML_INLINEF bool2  operator<   (int2 a, int2 b) { return bool2(cmplt(a, b).m); }
HLML_INLINEF bool2  operator>   (int2 a, int2 b) { return bool2(cmpgt(a, b).m); }
HLML_INLINEF bool2  operator<=  (int2 a, int2 b) { return !(a > b); }
HLML_INLINEF bool2  operator>=  (int2 a, int2 b) { return b <= a; }

HLML_INLINEF int2   operator<<  (int2 a, U8 bits) { a.m = _mm_slli_epi32(a.m, bits); return a; }
HLML_INLINEF int2   operator>>  (int2 a, U8 bits) { a.m = _mm_srli_epi32(a.m, bits); return a; }
HLML_INLINEF int2&  operator<<= (int2& a, U8 bits) { a = a << bits; return a; }
HLML_INLINEF int2&  operator>>= (int2& a, U8 bits) { a = a >> bits; return a; }

HLML_INLINEF int2 abs(int2 v) { v.m = _mm_andnot_si128(vsignbits, v.m); return v; }
HLML_INLINEF int2 min(int2 a, int2 b) { a.m = _mm_min_epi32(a.m, b.m); return a; }
HLML_INLINEF int2 max(int2 a, int2 b) { a.m = _mm_max_epi32(a.m, b.m); return a; }
HLML_INLINEF int2 sumv(int2 v) { v.m =_mm_hadd_epi32(v.m, v.m);  return v; }
HLML_INLINEF I32 sum(int2 v) { return sumv(v).x(); }
HLML_INLINEF int2 clamp(int2 t, int2 a, int2 b) { return min(max(t, a), b); }
HLML_INLINEF I32 hmin(int2 v) { return min(v, shufflei2(v, 1, 0)).x(); }
HLML_INLINEF I32 hmax(int2 v) { return max(v, shufflei2(v, 1, 0)).x(); }
}