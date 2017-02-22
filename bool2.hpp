#pragma once

#include "common.hpp"

namespace hlml {
struct bool2 {
  #define shuffleb2(V, X, Y) bool2(_mm_shuffle_epi32((V).m, _MM_SHUFFLE(3,2,Y,X)))
  #define insertb2(V, X, i) _mm_insert_epi32((V), (X), i)
  #define extractb2(V, i) _mm_extract_epi32((V), i)
  static constexpr U32 flagsall = 0x88;

  VI128 m = { 0 };

  HLML_INLINEF bool2() {}
  HLML_INLINEF explicit bool2(B8 x, B8 y) : bool2(setXYZW(x, y, snZero, snZero)) {}
  HLML_INLINEF explicit bool2(B8* p) : bool2(p[0], p[1]) {}
  HLML_INLINEF explicit bool2(VI128 v) : m(v) {}

  HLML_INLINEF void store(B8 *p) const { p[0] = x(); p[1] = y(); }

  HLML_INLINEF void setX(B8 x) { m = insertb2(m, x, 0); }
  HLML_INLINEF void setY(B8 y) { m = insertb2(m, y, 1); }

  HLML_INLINEF B8 x() const { return 0 != extractb2(m, 0); }
  HLML_INLINEF B8 y() const { return 0 != extractb2(m, 1); }

  HLML_INLINEF bool2 xx() const { return shuffleb2(*this, 0, 0); }
  HLML_INLINEF bool2 xy() const { return *this; }
  HLML_INLINEF bool2 yx() const { return shuffleb2(*this, 1, 0); }
  HLML_INLINEF bool2 yy() const { return shuffleb2(*this, 1, 1); }

};
}
