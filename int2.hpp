#pragma once

#include "common.hpp"
#include "bool2.hpp"

namespace hlml {
struct int2 {

  VI128 m = { 0 };

  HLML_INLINEF int2() {}
  HLML_INLINEF explicit int2(VI128 v) : m(v) {}
  HLML_INLINEF int2(i32 x, i32 y) : int2(funcs::setXYZW(x, y, consts::snZero, consts::snZero)) {}
  HLML_INLINEF explicit int2(i32 x) : int2(x, x) {}
  HLML_INLINEF explicit int2(const i32* p) : int2(p[0], p[1]) {}

  HLML_INLINEF void store(i32* p) const { p[0] = x(), p[1] = y(); }

  HLML_INLINEF void setX(i32 x) { m = inserti(m, x, 0); }
  HLML_INLINEF void setY(i32 y) { m = inserti(m, y, 1); }

  HLML_INLINEF i32 x() const { return extracti(m, 0); }
  HLML_INLINEF i32 y() const { return extracti(m, 1); }

  HLML_INLINEF int2 xx() const { return shufflei2(*this, 0, 0); }
  HLML_INLINEF int2 xy() const { return *this; }
  HLML_INLINEF int2 yx() const { return shufflei2(*this, 1, 0); }
  HLML_INLINEF int2 yy() const { return shufflei2(*this, 1, 1); }

  HLML_INLINEF i32 r() const { return x(); }
  HLML_INLINEF i32 g() const { return y(); }

  HLML_INLINEF int2 rr() const { return xx(); }
  HLML_INLINEF int2 rg() const { return xy(); }
  HLML_INLINEF int2 gr() const { return yx(); }
  HLML_INLINEF int2 gg() const { return yy(); }
};
//boolean
HLML_INLINEF bool2  operator==  (int2 a, int2 b) { return bool2(funcs::AcmpeqB(a.m, b.m)); }
HLML_INLINEF bool2  operator!=  (int2 a, int2 b) { return bool2(funcs::AcmpneqB(a.m, b.m)); }
HLML_INLINEF bool2  operator<   (int2 a, int2 b) { return bool2(funcs::AcmpltB(a.m, b.m)); }
HLML_INLINEF bool2  operator>   (int2 a, int2 b) { return bool2(funcs::AcmpgtB(a.m, b.m)); }
HLML_INLINEF bool2  operator<=  (int2 a, int2 b) { return bool2(funcs::AcmpleB(a.m, b.m)); }
HLML_INLINEF bool2  operator>=  (int2 a, int2 b) { return bool2(funcs::AcmpgeB(a.m, b.m)); }
//logical
HLML_INLINEF int2   operator~   (int2 a) { a.m = funcs::notAandB(a.m, consts::vnall2); return a; }
HLML_INLINEF int2   operator&   (int2 a, int2 b) { a.m = funcs::AandB(a.m, b.m); return a; }
HLML_INLINEF int2   operator|   (int2 a, int2 b) { a.m = funcs::AorB(a.m, b.m); return a; }
HLML_INLINEF int2   operator^   (int2 a, int2 b) { a.m = funcs::AxorB(a.m, b.m); return a; }
HLML_INLINEF int2   operator<<  (int2 a, u8 bits) { a.m = funcs::Ashiftl(a.m, bits); return a; }
HLML_INLINEF int2   operator>>  (int2 a, u8 bits) { a.m = funcs::Ashiftr(a.m, bits); return a; }
HLML_INLINEF int2&  operator<<= (int2& a, u8 bits) { a = a << bits; return a; }
HLML_INLINEF int2&  operator>>= (int2& a, u8 bits) { a = a >> bits; return a; }
//arithmetic
HLML_INLINEF int2   operator+   (int2 a) { return a; }
HLML_INLINEF int2   operator-   (int2 a) { a.m = funcs::AxorB(a.m, consts::vsignppnn); return a; }
HLML_INLINEF int2   operator+   (int2 a, int2 b) { a.m = funcs::AaddB(a.m, b.m); return a; }
HLML_INLINEF int2   operator-   (int2 a, int2 b) { a.m = funcs::AsubB(a.m, b.m); return a; }
HLML_INLINEF int2   operator*   (int2 a, int2 b) { a.m = funcs::AmulB(a.m, b.m); return a; }
HLML_INLINEF int2   operator+   (int2 a, i32 b) { return a + int2(b); }
HLML_INLINEF int2   operator-   (int2 a, i32 b) { return a - int2(b); }
HLML_INLINEF int2   operator*   (int2 a, i32 b) { return a * int2(b); }
HLML_INLINEF int2   operator+   (i32 b, int2 a) { return a + b; }
HLML_INLINEF int2   operator-   (i32 a, int2 b) { return int2(a) - b; }
HLML_INLINEF int2   operator*   (i32 b, int2 a) { return a * b; }
HLML_INLINEF int2&  operator+=  (int2& a, int2 b) { a = a + b; return a; }
HLML_INLINEF int2&  operator-=  (int2& a, int2 b) { a = a - b; return a; }
HLML_INLINEF int2&  operator*=  (int2& a, int2 b) { a = a * b; return a; }
HLML_INLINEF int2&  operator+=  (int2& a, i32 b) { return a += int2(b); }
HLML_INLINEF int2&  operator-=  (int2& a, i32 b) { return a -= int2(b); }
HLML_INLINEF int2&  operator*=  (int2& a, i32 b) { return a *= int2(b); }
//other
HLML_INLINEF int2 abs(int2 v) { v.m = funcs::notAandB(consts::vsignbits, v.m); return v; }
HLML_INLINEF int2 minv(int2 a, int2 b) { a.m = funcs::AminB(a.m, b.m); return a; }
HLML_INLINEF int2 maxv(int2 a, int2 b) { a.m = funcs::AmaxB(a.m, b.m); return a; }
HLML_INLINEF int2 sumv(int2 v) { v.m = funcs::AhaddB(v.m, v.m);  return v; }
HLML_INLINEF i32 sum(int2 v) { return sumv(v).x(); }
HLML_INLINEF i32 hmin(int2 v) { return minv(v, shufflei2(v, 1, 0)).x(); }
HLML_INLINEF i32 hmax(int2 v) { return maxv(v, shufflei2(v, 1, 0)).x(); }
}
