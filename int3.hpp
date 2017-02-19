#pragma once

#include "int2.hpp"
#include "bool3.hpp"

namespace hlml {
struct int3 {
  #define shufflei3(V, X, Y, Z) int3(_mm_shuffle_epi32((V).m, _MM_SHUFFLE(3, Z, Y, X)))
  #define inserti3(V, X, i) _mm_insert_epi32((V), (X), i)
  #define extracti3(V, i) _mm_extract_epi32((V), i)

  VI128 m = { 0 };

  HLML_INLINEF int3() {}
  HLML_INLINEF int3(I32 x, I32 y, I32 z) : m(_mm_set_epi32(snZero, z, y, x)) {}
  HLML_INLINEF int3(int2 v, I32 z, I32 w) : m(_mm_set_epi32(snZero, z, v.y(), v.x())) {}
  HLML_INLINEF explicit int3(I32 x) : m(_mm_set_epi32(snZero, x, x, x)) {}
  HLML_INLINEF explicit int3(const I32 *p) : m(_mm_set_epi32(snZero, p[2], p[1], p[0])) {}
  HLML_INLINEF explicit int3(VI128 v) : m(v) {}

  HLML_INLINEF void store(I32 *p) const { p[0] = x(); p[1] = y(); p[2] = z(); }

  HLML_INLINEF void setX(I32 x) { m = inserti3(m, x, 0); }
  HLML_INLINEF void setY(I32 y) { m = inserti3(m, y, 1); }
  HLML_INLINEF void setZ(I32 z) { m = inserti3(m, z, 2); }

  HLML_INLINEF I32 x() const { return extracti3(m, 0); }
  HLML_INLINEF I32 y() const { return extracti3(m, 1); }
  HLML_INLINEF I32 z() const { return extracti3(m, 2); }

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

HLML_INLINEF int3   operator~   (int3 a) { a.m = _mm_andnot_si128(a.m, vnall); return a; }
HLML_INLINEF int3   operator&   (int3 a, int3 b) { a.m = _mm_and_si128(a.m, b.m); return a; }
HLML_INLINEF int3   operator|   (int3 a, int3 b) { a.m = _mm_or_si128(a.m, b.m); return a; }
HLML_INLINEF int3   operator^   (int3 a, int3 b) { a.m = _mm_xor_si128(a.m, b.m); return a; }

HLML_INLINEF int3   operator+   (int3 a) { return a; }
HLML_INLINEF int3   operator+   (int3 a, int3 b) { a.m = _mm_add_epi32(a.m, b.m); return a; }
HLML_INLINEF int3   operator+   (int3 a, I32 b) { return a + int3(b); }
HLML_INLINEF int3   operator+   (I32 b, int3 a) { return a + b; }
HLML_INLINEF int3&  operator+=  (int3& a, int3 b) { a = a + b; return a; }
HLML_INLINEF int3&  operator+=  (int3& a, I32 b) { return a += int3(b); }
HLML_INLINEF int3   operator-   (int3 a) { a.m = _mm_xor_si128(a.m, vsignbits); return a; }
HLML_INLINEF int3   operator-   (int3 a, int3 b) { a.m = _mm_sub_epi32(a.m, b.m); return a; }
HLML_INLINEF int3   operator-   (int3 a, I32 b) { return a - int3(b); }
HLML_INLINEF int3   operator-   (I32 a, int3 b) { return int3(a) - b; }
HLML_INLINEF int3&  operator-=  (int3& a, int3 b) { a = a - b; return a; }
HLML_INLINEF int3&  operator-=  (int3& a, I32 b) { return a -= int3(b); }
HLML_INLINEF int3   operator*   (int3 a, int3 b) { a.m = _mm_mul_epi32(a.m, b.m); return a; }
HLML_INLINEF int3   operator*   (int3 a, I32 b) { return a * int3(b); }
HLML_INLINEF int3   operator*   (I32 b, int3 a) { return a * b; }
HLML_INLINEF int3&  operator*=  (int3& a, int3 b) { a = a * b; return a; }
HLML_INLINEF int3&  operator*=  (int3& a, I32 b) { return a *= int3(b); }

HLML_INLINEF int3   cmpeq       (int3 a, int3 b) { return int3(_mm_cmpeq_epi32(a.m, b.m)); }
HLML_INLINEF int3   cmpgt       (int3 a, int3 b) { return int3(_mm_cmpgt_epi32(a.m, b.m)); }
HLML_INLINEF int3   cmplt       (int3 a, int3 b) { return int3(_mm_cmplt_epi32(a.m, b.m)); }

HLML_INLINEF bool3  operator==  (int3 a, int3 b) { return bool3(cmpeq(a, b).m); }
HLML_INLINEF bool3  operator!=  (int3 a, int3 b) { return !(a == b); }
HLML_INLINEF bool3  operator<   (int3 a, int3 b) { return bool3(cmplt(a, b).m); }
HLML_INLINEF bool3  operator>   (int3 a, int3 b) { return bool3(cmpgt(a, b).m); }
HLML_INLINEF bool3  operator<=  (int3 a, int3 b) { return !(a > b); }
HLML_INLINEF bool3  operator>=  (int3 a, int3 b) { return b <= a; }

HLML_INLINEF int3   operator<<  (int3 a, U8 bits) { a.m = _mm_slli_epi32(a.m, bits); return a; }
HLML_INLINEF int3   operator>>  (int3 a, U8 bits) { a.m = _mm_srli_epi32(a.m, bits); return a; }
HLML_INLINEF int3&  operator<<= (int3& a, U8 bits) { a = a << bits; return a; }
HLML_INLINEF int3&  operator>>= (int3& a, U8 bits) { a = a >> bits; return a; }

HLML_INLINEF int3 abs(int3 v) { v.m = _mm_andnot_si128(vsignbits, v.m); return v; }
HLML_INLINEF int3 min(int3 a, int3 b) { a.m = _mm_min_epi32(a.m, b.m); return a; }
HLML_INLINEF int3 max(int3 a, int3 b) { a.m = _mm_max_epi32(a.m, b.m); return a; }
HLML_INLINEF int3 sumv(int3 v) { return v += v.zxy() + v.yzx(); }
HLML_INLINEF I32 sum(int3 v) { return sumv(v).x(); }
HLML_INLINEF int3 clamp(int3 t, int3 a, int3 b) { return min(max(t, a), b); }
HLML_INLINEF I32 hmin(int3 v) { v = min(v, shufflei3(v, 1, 0, 2)); return min(v, shufflei3(v, 2, 0, 1)).x(); }
HLML_INLINEF I32 hmax(int3 v) { v = max(v, shufflei3(v, 1, 0, 2)); return max(v, shufflei3(v, 2, 0, 1)).x(); }
}