#pragma once

#include "common.hpp"

namespace hlml {
struct bool2 {
  static constexpr u32 flagsall = 0x88;

  VI128 m = { 0 };

  HLML_INLINEF bool2() {}
  HLML_INLINEF explicit bool2(VI128 v) : m(v) {}
  HLML_INLINEF explicit bool2(b8 x, b8 y) : bool2(funcs::Ashiftl(funcs::setXYZW(x, y, consts::snZero, consts::snZero), 31u)) {}
  HLML_INLINEF explicit bool2(b8* p) : bool2(p[0], p[1]) {}

  HLML_INLINEF void store(b8 *p) const { p[0] = x(); p[1] = y(); }

  HLML_INLINEF void setX(b8 x) { m = inserti(m, x << 31u, 0); }
  HLML_INLINEF void setY(b8 y) { m = inserti(m, y << 31u, 1); }

  HLML_INLINEF b8 x() const { return 0 != extracti(m, 0); }
  HLML_INLINEF b8 y() const { return 0 != extracti(m, 1); }

  HLML_INLINEF bool2 xx() const { return shuffleb2(*this, 0, 0); }
  HLML_INLINEF bool2 xy() const { return *this; }
  HLML_INLINEF bool2 yx() const { return shuffleb2(*this, 1, 0); }
  HLML_INLINEF bool2 yy() const { return shuffleb2(*this, 1, 1); }
};
HLML_INLINEF bool2    operator!   (bool2 a) { a.m = funcs::notAandB(a.m, consts::vsignppnn); return a; }
HLML_INLINEF bool2    operator&   (bool2 a, bool2 b) { a.m = funcs::AandB(a.m, b.m); return a; }
HLML_INLINEF bool2    operator|   (bool2 a, bool2 b) { a.m = funcs::AorB(a.m, b.m); return a; }
HLML_INLINEF bool2    operator^   (bool2 a, bool2 b) { a.m = funcs::AxorB(a.m, b.m); return a; }
HLML_INLINEF bool2&   operator&=  (bool2& a, bool2 b) { a = a & b; return a; }
HLML_INLINEF bool2&   operator|=  (bool2& a, bool2 b) { a = a | b; return a; }
HLML_INLINEF bool2&   operator^=  (bool2& a, bool2 b) { a = a ^ b; return a; }
HLML_INLINEF bool2    operator~   (bool2 a) { return !a; }
HLML_INLINEF u32      mask        (bool2 v) { return bool2::flagsall & funcs::movemask(v.m); }
HLML_INLINEF b8       all         (bool2 v) { return bool2::flagsall == mask(v); }
HLML_INLINEF b8       any         (bool2 v) { return mask(v); }
HLML_INLINEF b8       none        (bool2 v) { return !any(v); }
}
