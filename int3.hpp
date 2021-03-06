#pragma once

#include "int2.hpp"
#include "bool3.hpp"

namespace hlml {
struct int3 {
  VI128 m = { 0 };

  HLML_INLINEF int3() {}
  HLML_INLINEF explicit int3(VI128 v) : m(v) {}
  HLML_INLINEF int3(i32 x, i32 y, i32 z) : int3(funcs::setXYZW(x, y, z, consts::snZero)) {}
  HLML_INLINEF int3(int2 v, i32 z) : int3(v.x(), v.y(), z) {}
  HLML_INLINEF explicit int3(i32 x) : int3(x, x, x) {}
  HLML_INLINEF explicit int3(const i32* p) : int3(p[0], p[1], p[2]) {}

  HLML_INLINEF void store(i32 *p) const { p[0] = x(), p[1] = y(), p[2] = z(); }

  HLML_INLINEF void setX(i32 x) { m = inserti(m, x, 0); }
  HLML_INLINEF void setY(i32 y) { m = inserti(m, y, 1); }
  HLML_INLINEF void setZ(i32 z) { m = inserti(m, z, 2); }

  HLML_INLINEF i32 x() const { return extracti(m, 0); }
  HLML_INLINEF i32 y() const { return extracti(m, 1); }
  HLML_INLINEF i32 z() const { return extracti(m, 2); }

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

  HLML_INLINEF i32 r() const { return x(); }
  HLML_INLINEF i32 g() const { return y(); }
  HLML_INLINEF i32 b() const { return z(); }

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
//boolean
HLML_INLINEF bool3  operator==  (int3 a, int3 b) { return bool3(funcs::AcmpeqB(a.m, b.m)); }
HLML_INLINEF bool3  operator!=  (int3 a, int3 b) { return bool3(funcs::AcmpneqB(a.m, b.m)); }
HLML_INLINEF bool3  operator<   (int3 a, int3 b) { return bool3(funcs::AcmpltB(a.m, b.m)); }
HLML_INLINEF bool3  operator>   (int3 a, int3 b) { return bool3(funcs::AcmpgtB(a.m, b.m)); }
HLML_INLINEF bool3  operator<=  (int3 a, int3 b) { return bool3(funcs::AcmpleB(a.m, b.m)); }
HLML_INLINEF bool3  operator>=  (int3 a, int3 b) { return bool3(funcs::AcmpgeB(a.m, b.m)); }
//logical
HLML_INLINEF int3   operator~   (int3 a) { a.m = funcs::notAandB(a.m, consts::vnall3); return a; }
HLML_INLINEF int3   operator&   (int3 a, int3 b) { a.m = funcs::AandB(a.m, b.m); return a; }
HLML_INLINEF int3   operator|   (int3 a, int3 b) { a.m = funcs::AorB(a.m, b.m); return a; }
HLML_INLINEF int3   operator^   (int3 a, int3 b) { a.m = funcs::AxorB(a.m, b.m); return a; }
HLML_INLINEF int3   operator<<  (int3 a, u8 bits) { a.m = funcs::Ashiftl(a.m, bits); return a; }
HLML_INLINEF int3   operator>>  (int3 a, u8 bits) { a.m = funcs::Ashiftr(a.m, bits); return a; }
HLML_INLINEF int3&  operator<<= (int3& a, u8 bits) { a = a << bits; return a; }
HLML_INLINEF int3&  operator>>= (int3& a, u8 bits) { a = a >> bits; return a; }
//arithmetic
HLML_INLINEF int3   operator+   (int3 a) { return a; }
HLML_INLINEF int3   operator-   (int3 a) { a.m = funcs::AxorB(a.m, consts::vsignbits_xyz); return a; }
HLML_INLINEF int3   operator+   (int3 a, int3 b) { a.m = funcs::AaddB(a.m, b.m); return a; }
HLML_INLINEF int3   operator-   (int3 a, int3 b) { a.m = funcs::AsubB(a.m, b.m); return a; }
HLML_INLINEF int3   operator*   (int3 a, int3 b) { a.m = funcs::AmulB(a.m, b.m); return a; }
HLML_INLINEF int3   operator+   (int3 a, i32 b) { return a + int3(b); }
HLML_INLINEF int3   operator-   (int3 a, i32 b) { return a - int3(b); }
HLML_INLINEF int3   operator*   (int3 a, i32 b) { return a * int3(b); }
HLML_INLINEF int3   operator+   (i32 b, int3 a) { return a + b; }
HLML_INLINEF int3   operator-   (i32 a, int3 b) { return int3(a) - b; }
HLML_INLINEF int3   operator*   (i32 b, int3 a) { return a * b; }
HLML_INLINEF int3&  operator+=  (int3& a, int3 b) { a = a + b; return a; }
HLML_INLINEF int3&  operator-=  (int3& a, int3 b) { a = a - b; return a; }
HLML_INLINEF int3&  operator*=  (int3& a, int3 b) { a = a * b; return a; }
HLML_INLINEF int3&  operator+=  (int3& a, i32 b) { return a += int3(b); }
HLML_INLINEF int3&  operator-=  (int3& a, i32 b) { return a -= int3(b); }
HLML_INLINEF int3&  operator*=  (int3& a, i32 b) { return a *= int3(b); }
//other
HLML_INLINEF int3 abs(int3 v) { v.m = funcs::notAandB(consts::vsignbits_xyzw, v.m); return v; }
HLML_INLINEF int3 minv(int3 a, int3 b) { a.m = funcs::AminB(a.m, b.m); return a; }
HLML_INLINEF int3 maxv(int3 a, int3 b) { a.m = funcs::AmaxB(a.m, b.m); return a; }
HLML_INLINEF int3 sumv(int3 v) { return v + v.zxy() + v.yzx(); }
HLML_INLINEF i32 sum(int3 v) { return sumv(v).x(); }
HLML_INLINEF i32 hmin(int3 v) {
  v = minv(v, shufflei3(v, 1, 0, 2));
  return minv(v, shufflei3(v, 2, 0, 1)).x();
}
HLML_INLINEF i32 hmax(int3 v) {
  v = maxv(v, shufflei3(v, 1, 0, 2));
  return maxv(v, shufflei3(v, 2, 0, 1)).x();
}
}
