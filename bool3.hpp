#pragma once

#include "bool2.hpp"

namespace hlml {
struct bool3 {
  static constexpr U32 flagsall = 0x888;

  VI128 m = { 0 };

  HLML_INLINEF bool3() {}
  HLML_INLINEF explicit bool3(B8 x, B8 y, B8 z) : m(funcs::setXYZW(x, y, z, consts::snZero)) {}
  HLML_INLINEF explicit bool3(B8* p) : bool3(p[0], p[1], p[2]) {}
  HLML_INLINEF explicit bool3(bool2 v, B8 z) : bool3(v.x(), v.y(), z) {}
  HLML_INLINEF explicit bool3(VI128 v) : m(v) {}

  HLML_INLINEF void store(B8 *p) const { p[0] = x(); p[1] = y(); p[2] = z(); }

  HLML_INLINEF void setX(B8 x) { m = inserti(m, x, 0); }
  HLML_INLINEF void setY(B8 y) { m = inserti(m, y, 1); }
  HLML_INLINEF void setZ(B8 y) { m = inserti(m, y, 2); }

  HLML_INLINEF B8 x() const { return 0 != extracti(m, 0); }
  HLML_INLINEF B8 y() const { return 0 != extracti(m, 1); }
  HLML_INLINEF B8 z() const { return 0 != extracti(m, 2); }

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
}
