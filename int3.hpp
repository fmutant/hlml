#pragma once

#include "int2.hpp"
#include "bool3.hpp"

namespace hlml {
struct int3 {

  VI128 m = { 0 };

  HLML_INLINEF int3() {}
  HLML_INLINEF int3(I32 x, I32 y, I32 z) : m(funcs::setXYZW(x, y, z, consts::snZero)) {}
  HLML_INLINEF int3(int2 v, I32 z, I32 w) : int3(v.x(), v.y(), z) {}
  HLML_INLINEF explicit int3(I32 x) : int3(x, x, x) {}
  HLML_INLINEF explicit int3(const I32 *p) : int3(p[0], p[1], p[2]) {}
  HLML_INLINEF explicit int3(VI128 v) : m(v) {}

  HLML_INLINEF void store(I32 *p) const { p[0] = x(); p[1] = y(); p[2] = z(); }

  HLML_INLINEF void setX(I32 x) { m = inserti(m, x, 0); }
  HLML_INLINEF void setY(I32 y) { m = inserti(m, y, 1); }
  HLML_INLINEF void setZ(I32 z) { m = inserti(m, z, 2); }

  HLML_INLINEF I32 x() const { return extracti(m, 0); }
  HLML_INLINEF I32 y() const { return extracti(m, 1); }
  HLML_INLINEF I32 z() const { return extracti(m, 2); }

  HLML_INLINEF int2 xx() const { return shufflei2(*this, 0, 0); }
  HLML_INLINEF int2 xy() const { return shufflei2(*this, 0, 1); }
  HLML_INLINEF int2 xz() const { return shufflei2(*this, 0, 2); }
  HLML_INLINEF int2 yy() const { return shufflei2(*this, 1, 1); }
  HLML_INLINEF int2 yx() const { return shufflei2(*this, 1, 0); }
  HLML_INLINEF int2 yz() const { return shufflei2(*this, 1, 2); }
  HLML_INLINEF int2 zz() const { return shufflei2(*this, 2, 2); }
  HLML_INLINEF int2 zx() const { return shufflei2(*this, 2, 0); }
  HLML_INLINEF int2 zy() const { return shufflei2(*this, 2, 1); }

  HLML_INLINEF int3 xxx() const { return shufflei3(*this, 0, 0, 0); }
  HLML_INLINEF int3 xxy() const { return shufflei3(*this, 0, 0, 1); }
  HLML_INLINEF int3 xxz() const { return shufflei3(*this, 0, 0, 2); }
  HLML_INLINEF int3 xyx() const { return shufflei3(*this, 0, 1, 0); }
  HLML_INLINEF int3 xyy() const { return shufflei3(*this, 0, 1, 1); }
  HLML_INLINEF int3 xyz() const { return shufflei3(*this, 0, 1, 2); }
  HLML_INLINEF int3 xzx() const { return shufflei3(*this, 0, 2, 0); }
  HLML_INLINEF int3 xzy() const { return shufflei3(*this, 0, 2, 1); }
  HLML_INLINEF int3 xzz() const { return shufflei3(*this, 0, 2, 2); }

  HLML_INLINEF int3 yxx() const { return shufflei3(*this, 1, 0, 0); }
  HLML_INLINEF int3 yxy() const { return shufflei3(*this, 1, 0, 1); }
  HLML_INLINEF int3 yxz() const { return shufflei3(*this, 1, 0, 2); }
  HLML_INLINEF int3 yyx() const { return shufflei3(*this, 1, 1, 0); }
  HLML_INLINEF int3 yyy() const { return shufflei3(*this, 1, 1, 1); }
  HLML_INLINEF int3 yyz() const { return shufflei3(*this, 1, 1, 2); }
  HLML_INLINEF int3 yzx() const { return shufflei3(*this, 1, 2, 0); }
  HLML_INLINEF int3 yzy() const { return shufflei3(*this, 1, 2, 1); }
  HLML_INLINEF int3 yzz() const { return shufflei3(*this, 1, 2, 2); }

  HLML_INLINEF int3 zxx() const { return shufflei3(*this, 2, 0, 0); }
  HLML_INLINEF int3 zxy() const { return shufflei3(*this, 2, 0, 1); }
  HLML_INLINEF int3 zxz() const { return shufflei3(*this, 2, 0, 2); }
  HLML_INLINEF int3 zyx() const { return shufflei3(*this, 2, 1, 0); }
  HLML_INLINEF int3 zyy() const { return shufflei3(*this, 2, 1, 1); }
  HLML_INLINEF int3 zyz() const { return shufflei3(*this, 2, 1, 2); }
  HLML_INLINEF int3 zzx() const { return shufflei3(*this, 2, 2, 0); }
  HLML_INLINEF int3 zzy() const { return shufflei3(*this, 2, 2, 1); }
  HLML_INLINEF int3 zzz() const { return shufflei3(*this, 2, 2, 2); }

  HLML_INLINEF I32 r() const { return x(); }
  HLML_INLINEF I32 g() const { return y(); }
  HLML_INLINEF I32 b() const { return z(); }

  HLML_INLINEF int2 rr() const { return xx(); }
  HLML_INLINEF int2 rg() const { return xy(); }
  HLML_INLINEF int2 rb() const { return xz(); }
  HLML_INLINEF int2 gr() const { return yx(); }
  HLML_INLINEF int2 gg() const { return yy(); }
  HLML_INLINEF int2 gb() const { return yz(); }
  HLML_INLINEF int2 br() const { return zx(); }
  HLML_INLINEF int2 bg() const { return zy(); }
  HLML_INLINEF int2 bb() const { return zz(); }

  HLML_INLINEF int3 rrr() const { return xxx(); }
  HLML_INLINEF int3 rrg() const { return xxy(); }
  HLML_INLINEF int3 rrb() const { return xxz(); }
  HLML_INLINEF int3 rgr() const { return xyx(); }
  HLML_INLINEF int3 rgg() const { return xyy(); }
  HLML_INLINEF int3 rgb() const { return xyz(); }
  HLML_INLINEF int3 rbr() const { return xzx(); }
  HLML_INLINEF int3 rbg() const { return xzy(); }
  HLML_INLINEF int3 rbb() const { return xzz(); }
  HLML_INLINEF int3 grr() const { return yxx(); }
  HLML_INLINEF int3 grg() const { return yxy(); }
  HLML_INLINEF int3 grb() const { return yxz(); }
  HLML_INLINEF int3 ggr() const { return yyx(); }
  HLML_INLINEF int3 ggg() const { return yyy(); }
  HLML_INLINEF int3 ggb() const { return yyz(); }
  HLML_INLINEF int3 gbr() const { return yzx(); }
  HLML_INLINEF int3 gbg() const { return yzy(); }
  HLML_INLINEF int3 gbb() const { return yzz(); }
  HLML_INLINEF int3 brr() const { return zxx(); }
  HLML_INLINEF int3 brg() const { return zxy(); }
  HLML_INLINEF int3 brb() const { return zxz(); }
  HLML_INLINEF int3 bgr() const { return zyx(); }
  HLML_INLINEF int3 bgg() const { return zyy(); }
  HLML_INLINEF int3 bgb() const { return zyz(); }
  HLML_INLINEF int3 bbr() const { return zzx(); }
  HLML_INLINEF int3 bbg() const { return zzy(); }
  HLML_INLINEF int3 bbb() const { return zzz(); }
};

HLML_INLINEF bool3   operator== (int3 a, int3 b) { return bool3(funcs::ftoi(cmpeq(a, b).m)); }
HLML_INLINEF bool3   operator!= (int3 a, int3 b) { return bool3(funcs::ftoi(cmpneq(a, b).m)); }
HLML_INLINEF bool3   operator<  (int3 a, int3 b) { return bool3(funcs::ftoi(cmplt(a, b).m)); }
HLML_INLINEF bool3   operator>  (int3 a, int3 b) { return bool3(funcs::ftoi(cmpgt(a, b).m)); }
HLML_INLINEF bool3   operator<= (int3 a, int3 b) { return bool3(funcs::ftoi(cmple(a, b).m)); }
HLML_INLINEF bool3   operator>= (int3 a, int3 b) { return bool3(funcs::ftoi(cmpge(a, b).m)); }

HLML_INLINEF int3 sumv(int3 v) { return v += v.zxy() + v.yzx(); }
HLML_INLINEF I32 hmin(int3 v) { v = min(v, shufflei3(v, 1, 0, 2)); return min(v, shufflei3(v, 2, 0, 1)).x(); }
HLML_INLINEF I32 hmax(int3 v) { v = max(v, shufflei3(v, 1, 0, 2)); return max(v, shufflei3(v, 2, 0, 1)).x(); }
}
