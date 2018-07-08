#pragma once

#include "common.hpp"

namespace hlml {
struct bool2 {
  static constexpr u32 flagsall = 0x88;

  VI128 m = { 0 };

  HLML_INLINEF bool2() {}
  HLML_INLINEF explicit bool2(b8 x, b8 y) : bool2(funcs::setXYZW(x, y, consts::snZero, consts::snZero)) {}
  HLML_INLINEF explicit bool2(b8* p) : bool2(p[0], p[1]) {}
  HLML_INLINEF explicit bool2(VI128 v) : m(v) {}

  HLML_INLINEF void store(b8 *p) const { p[0] = x(); p[1] = y(); }

  HLML_INLINEF void setX(b8 x) { m = inserti(m, x, 0); }
  HLML_INLINEF void setY(b8 y) { m = inserti(m, y, 1); }

  HLML_INLINEF b8 x() const { return 0 != extracti(m, 0); }
  HLML_INLINEF b8 y() const { return 0 != extracti(m, 1); }

  HLML_INLINEF bool2 xx() const { return shuffleb2(*this, 0, 0); }
  HLML_INLINEF bool2 xy() const { return *this; }
  HLML_INLINEF bool2 yx() const { return shuffleb2(*this, 1, 0); }
  HLML_INLINEF bool2 yy() const { return shuffleb2(*this, 1, 1); }
};
}
