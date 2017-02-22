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
  HLML_INLINEF int2(I32 x, I32 y) : m(setXYZW(x, y, snZero, snZero)) {}
  HLML_INLINEF explicit int2(I32 x) : int2(x, x) {}
  HLML_INLINEF explicit int2(const I32 *p) : int2(p[0], p[1]) {}
  HLML_INLINEF explicit int2(VI128 v) : m(v) {}

  HLML_INLINEF void store(I32 *p) const { p[0] = x(); p[1] = y(); }

  HLML_INLINEF void setX(I32 x) { m = inserti2(m, x, 0); }
  HLML_INLINEF void setY(I32 y) { m = inserti2(m, y, 1); }

  HLML_INLINEF I32 x() const { return extracti2(m, 0); }
  HLML_INLINEF I32 y() const { return extracti2(m, 1); }

  HLML_INLINEF int2 xx() const { return shufflei2(*this, 0, 0); }
  HLML_INLINEF int2 xy() const { return *this; }
  HLML_INLINEF int2 yx() const { return shufflei2(*this, 1, 0); }
  HLML_INLINEF int2 yy() const { return shufflei2(*this, 1, 1); }

  HLML_INLINEF I32 r() const { return x(); }
  HLML_INLINEF I32 g() const { return y(); }

  HLML_INLINEF int2 rr() const { return xx(); }
  HLML_INLINEF int2 rg() const { return xy(); }
  HLML_INLINEF int2 gr() const { return yx(); }
  HLML_INLINEF int2 gg() const { return yy(); }
};

template<typename T> HLML_INLINEF T   operator+  (T a, I32 b) { return a + T(b); }
template<typename T> HLML_INLINEF T   operator+  (I32 b, T a) { return a + b; }
template<typename T> HLML_INLINEF T&  operator+= (T& a, I32 b) { return a += T(b); }
template<typename T> HLML_INLINEF T   operator-  (T a, I32 b) { return a - T(b); }
template<typename T> HLML_INLINEF T   operator-  (I32 a, T b) { return T(a) - b; }
template<typename T> HLML_INLINEF T&  operator-= (T& a, I32 b) { return a -= T(b); }
template<typename T> HLML_INLINEF T   operator*  (T a, I32 b) { return a * T(b); }
template<typename T> HLML_INLINEF T   operator*  (I32 b, T a) { return a * b; }
template<typename T> HLML_INLINEF T&  operator*= (T& a, I32 b) { return a *= T(b); }

HLML_INLINEF bool2   operator== (int2 a, int2 b) { return bool2(ftoi(cmpeq(a, b).m)); }
HLML_INLINEF bool2   operator!= (int2 a, int2 b) { return bool2(ftoi(cmpneq(a, b).m)); }
HLML_INLINEF bool2   operator<  (int2 a, int2 b) { return bool2(ftoi(cmplt(a, b).m)); }
HLML_INLINEF bool2   operator>  (int2 a, int2 b) { return bool2(ftoi(cmpgt(a, b).m)); }
HLML_INLINEF bool2   operator<= (int2 a, int2 b) { return bool2(ftoi(cmple(a, b).m)); }
HLML_INLINEF bool2   operator>= (int2 a, int2 b) { return bool2(ftoi(cmpge(a, b).m)); }

HLML_INLINEF int2 sumv(int2 v) { v.m = AhaddB(v.m, v.m);  return v; }
template<typename T> HLML_INLINEF I32 sum(T v) { return sumv(v).x(); }
HLML_INLINEF I32 hmin(int2 v) { return min(v, shufflei2(v, 1, 0)).x(); }
HLML_INLINEF I32 hmax(int2 v) { return max(v, shufflei2(v, 1, 0)).x(); }
}
