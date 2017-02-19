#pragma once

#include "common.hpp"

namespace hlml {
struct bool2 {
  #define shuffleb2(V, X, Y) bool2(_mm_shuffle_epi32((V).m, _MM_SHUFFLE(3,2,Y,X)))

  VI128 m = { 0 };

  HLML_INLINEF bool2() {}
  HLML_INLINEF explicit bool2(B8* p) : m(_mm_set_epi32(snZero, snZero, p[1], p[0])) {}
  HLML_INLINEF explicit bool2(B8 x, B8 y) : m(_mm_set_epi32(snZero, snZero, y, x)) {}
  HLML_INLINEF explicit bool2(VI128 v) : m(v) {}

  HLML_INLINEF B8 x() const { return 0 != _mm_cvtsi128_si32(m); }
  HLML_INLINEF B8 y() const { return 0 != _mm_cvtsi128_si32(_mm_shuffle_epi32(m, _MM_SHUFFLE(1, 1, 1, 1))); }

  HLML_INLINEF bool2 xy() const { return *this; }
  HLML_INLINEF bool2 yx() const { return shuffleb2(*this, 1, 0); }
  HLML_INLINEF bool2 xx() const { return shuffleb2(*this, 0, 0); }
  HLML_INLINEF bool2 yy() const { return shuffleb2(*this, 1, 1); }

  HLML_INLINEF void store(B8 *p) const { p[0] = x(); p[1] = y(); }

  HLML_INLINEF void setX(B8 x) { m = _mm_cvtps_epi32(_mm_move_ss(_mm_cvtepi32_ps(m), _mm_set_ss(x))); }
  HLML_INLINEF void setY(B8 y) { m = _mm_cvtps_epi32(_mm_move_ss(_mm_set1_ps(y), _mm_cvtepi32_ps(m))); }

  HLML_INLINEF bool2& operator =  (bool2 vec) { m = vec.m; return *this; }
  HLML_INLINEF bool2& operator &= (bool2 vec) { m = _mm_and_si128(m, vec.m); return *this; }
  HLML_INLINEF bool2& operator ^= (bool2 vec) { m = _mm_xor_si128(m, vec.m); return *this; }
  HLML_INLINEF bool2& operator |= (bool2 vec) { m = _mm_or_si128(m, vec.m); return *this; }
};
HLML_INLINEF U32 mask(bool2 v) { return 0x88 & _mm_movemask_epi8(v.m); }
HLML_INLINEF B8  none(bool2 v) { return 0 == mask(v); }
HLML_INLINEF B8  any (bool2 v) { return 0 != mask(v); }
HLML_INLINEF B8  all (bool2 v) { return 0x88 == mask(v); }

HLML_INLINEF bool2  operator!  (bool2 a) { a.m = _mm_andnot_si128(a.m, vsignbits); return a; }
HLML_INLINEF bool2  operator== (bool2 a, bool2 b) { return bool2(_mm_cmpeq_epi32(a.m, b.m)); }
HLML_INLINEF bool2  operator!= (bool2 a, bool2 b) { return !(a == b); }
HLML_INLINEF bool2  operator&  (bool2 a, bool2 b) { return a &= b; }
HLML_INLINEF bool2  operator|  (bool2 a, bool2 b) { return a |= b; }
HLML_INLINEF bool2  operator^  (bool2 a, bool2 b) { return a ^= b; }
}