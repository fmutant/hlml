#pragma once

#include "bool2.hpp"

namespace hlml {
struct bool3 {
  static constexpr u32 flagsall = 0x888;

  VI128 m = { 0 };

  HLML_INLINEF bool3() {}
  HLML_INLINEF explicit bool3(VI128 v) : m(v) {}
  HLML_INLINEF explicit bool3(b8 x, b8 y, b8 z) : m(funcs::Ashiftl(funcs::setXYZW(x, y, z, consts::snZero), 31u)) {}
  HLML_INLINEF explicit bool3(const b8* p) : bool3(p[0], p[1], p[2]) {}
  HLML_INLINEF explicit bool3(bool2 v, b8 z) : bool3(v.x(), v.y(), z) {}

  HLML_INLINEF void store(b8 *p) const { p[0] = x(), p[1] = y(), p[2] = z(); }

  HLML_INLINEF void setX(b8 x) { m = inserti(m, x << 31u, 0); }
  HLML_INLINEF void setY(b8 y) { m = inserti(m, y << 31u, 1); }
  HLML_INLINEF void setZ(b8 y) { m = inserti(m, y << 31u, 2); }

  HLML_INLINEF b8 x() const { return 0 != extracti(m, 0); }
  HLML_INLINEF b8 y() const { return 0 != extracti(m, 1); }
  HLML_INLINEF b8 z() const { return 0 != extracti(m, 2); }

  HLML_INLINEF bool2 xx() const { return shuffleb2(*this, 0, 0); }
  HLML_INLINEF bool2 xy() const { return shuffleb2(*this, 0, 1); }
  HLML_INLINEF bool2 xz() const { return shuffleb2(*this, 0, 2); }
  HLML_INLINEF bool2 yx() const { return shuffleb2(*this, 1, 0); }
  HLML_INLINEF bool2 yy() const { return shuffleb2(*this, 1, 1); }
  HLML_INLINEF bool2 yz() const { return shuffleb2(*this, 1, 2); }

  HLML_INLINEF bool3 xxx() const { return shuffleb3(*this, 0, 0, 0); }
  HLML_INLINEF bool3 xxy() const { return shuffleb3(*this, 0, 0, 1); }
  HLML_INLINEF bool3 xxz() const { return shuffleb3(*this, 0, 0, 2); }
  HLML_INLINEF bool3 xyx() const { return shuffleb3(*this, 0, 1, 0); }
  HLML_INLINEF bool3 xyy() const { return shuffleb3(*this, 0, 1, 1); }
  HLML_INLINEF bool3 xyz() const { return *this; }
  HLML_INLINEF bool3 xzx() const { return shuffleb3(*this, 0, 2, 0); }
  HLML_INLINEF bool3 xzy() const { return shuffleb3(*this, 0, 2, 1); }
  HLML_INLINEF bool3 xzz() const { return shuffleb3(*this, 0, 2, 2); }

  HLML_INLINEF bool3 yxx() const { return shuffleb3(*this, 1, 0, 0); }
  HLML_INLINEF bool3 yxy() const { return shuffleb3(*this, 1, 0, 1); }
  HLML_INLINEF bool3 yxz() const { return shuffleb3(*this, 1, 0, 2); }
  HLML_INLINEF bool3 yyx() const { return shuffleb3(*this, 1, 1, 0); }
  HLML_INLINEF bool3 yyy() const { return shuffleb3(*this, 1, 1, 1); }
  HLML_INLINEF bool3 yyz() const { return shuffleb3(*this, 1, 1, 2); }
  HLML_INLINEF bool3 yzx() const { return shuffleb3(*this, 1, 2, 0); }
  HLML_INLINEF bool3 yzy() const { return shuffleb3(*this, 1, 2, 1); }
  HLML_INLINEF bool3 yzz() const { return shuffleb3(*this, 1, 2, 2); }

  HLML_INLINEF bool3 zxx() const { return shuffleb3(*this, 2, 0, 0); }
  HLML_INLINEF bool3 zxy() const { return shuffleb3(*this, 2, 0, 1); }
  HLML_INLINEF bool3 zxz() const { return shuffleb3(*this, 2, 0, 2); }
  HLML_INLINEF bool3 zyx() const { return shuffleb3(*this, 2, 1, 0); }
  HLML_INLINEF bool3 zyy() const { return shuffleb3(*this, 2, 1, 1); }
  HLML_INLINEF bool3 zyz() const { return shuffleb3(*this, 2, 1, 2); }
  HLML_INLINEF bool3 zzx() const { return shuffleb3(*this, 2, 2, 0); }
  HLML_INLINEF bool3 zzy() const { return shuffleb3(*this, 2, 2, 1); }
  HLML_INLINEF bool3 zzz() const { return shuffleb3(*this, 2, 2, 2); }
};
HLML_INLINEF bool3    operator!   (bool3 a) { a.m = funcs::notAandB(a.m, consts::vsignpppn); return a; }
HLML_INLINEF bool3    operator~   (bool3 a) { return !a; }
HLML_INLINEF bool3    operator&   (bool3 a, bool3 b) { a.m = funcs::AandB(a.m, b.m); return a; }
HLML_INLINEF bool3    operator|   (bool3 a, bool3 b) { a.m = funcs::AorB(a.m, b.m); return a; }
HLML_INLINEF bool3    operator^   (bool3 a, bool3 b) { a.m = funcs::AxorB(a.m, b.m); return a; }
HLML_INLINEF bool3&   operator&=  (bool3& a, bool3 b) { a = a & b; return a; }
HLML_INLINEF bool3&   operator|=  (bool3& a, bool3 b) { a = a | b; return a; }
HLML_INLINEF bool3&   operator^=  (bool3& a, bool3 b) { a = a ^ b; return a; }
HLML_INLINEF u32      mask        (bool3 v) { return bool3::flagsall & funcs::movemask(v.m); }
HLML_INLINEF b8       all         (bool3 v) { return bool3::flagsall == mask(v); }
HLML_INLINEF b8       any         (bool3 v) { return mask(v); }
HLML_INLINEF b8       none        (bool3 v) { return !any(v); }
}
