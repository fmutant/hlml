#pragma once

#include "bool2.hpp"

namespace hlml {
struct bool3 {
#define shuffleb3(V, X, Y, Z) bool3(_mm_shuffle_epi32((V).m, _MM_SHUFFLE(3, Z, Y, X)))

  VI128 m = { 0 };

  HLML_INLINEF bool3() {}
  HLML_INLINEF explicit bool3(B8* p) : m(_mm_set_epi32(snZero, p[2], p[1], p[0])) {}
  HLML_INLINEF explicit bool3(B8 x, B8 y, B8 z) : m(_mm_set_epi32(snZero, z, y, x)) {}
  HLML_INLINEF explicit bool3(bool2 v, B8 z) : m(_mm_set_epi32(snZero, z, v.y(), v.x())) {}
  HLML_INLINEF explicit bool3(VI128 v) : m(v) {}

  HLML_INLINEF B8 x() const { return 0 != _mm_cvtsi128_si32(m); }
  HLML_INLINEF B8 y() const { return 0 != _mm_cvtsi128_si32(_mm_shuffle_epi32(m, _MM_SHUFFLE(1, 1, 1, 1))); }
  HLML_INLINEF B8 z() const { return 0 != _mm_cvtsi128_si32(_mm_shuffle_epi32(m, _MM_SHUFFLE(2, 2, 2, 2))); }

  HLML_INLINEF bool2 xx() const { return shuffleb2(*this, 0, 0); }
  HLML_INLINEF bool2 xy() const { return shuffleb2(*this, 0, 1); }
  HLML_INLINEF bool2 xz() const { return shuffleb2(*this, 0, 2); }
  HLML_INLINEF bool2 yy() const { return shuffleb2(*this, 1, 1); }
  HLML_INLINEF bool2 yx() const { return shuffleb2(*this, 1, 0); }
  HLML_INLINEF bool2 yz() const { return shuffleb2(*this, 1, 2); }

  HLML_INLINEF bool3 xxx() const { return shuffleb3(*this, 0, 0, 0); }
  HLML_INLINEF bool3 xxy() const { return shuffleb3(*this, 0, 0, 1); }
  HLML_INLINEF bool3 xxz() const { return shuffleb3(*this, 0, 0, 2); }
  HLML_INLINEF bool3 xyx() const { return shuffleb3(*this, 0, 1, 0); }
  HLML_INLINEF bool3 xyy() const { return shuffleb3(*this, 0, 1, 1); }
  HLML_INLINEF bool3 xyz() const { return shuffleb3(*this, 0, 1, 2); }
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

  HLML_INLINEF void store(B8 *p) const { p[0] = x(); p[1] = y(); p[2] = z(); }

  HLML_INLINEF void setX(B8 x) { m = _mm_cvtps_epi32(_mm_move_ss(_mm_cvtepi32_ps(m), _mm_set_ss(x))); }
  void setY(B8 y) {
    VF128 t = _mm_move_ss(_mm_cvtepi32_ps(m), _mm_set_ss(y));
    t = _mm_shuffle_ps(t, t, _MM_SHUFFLE(3, 2, 0, 0));
    m = _mm_cvtps_epi32(_mm_move_ss(t, _mm_cvtepi32_ps(m)));
  }
  void setZ(B8 z) {
    VF128 t = _mm_move_ss(_mm_cvtepi32_ps(m), _mm_set_ss(z));
    t = _mm_shuffle_ps(t, t, _MM_SHUFFLE(0, 0, 1, 0));
    m = _mm_cvtps_epi32(_mm_move_ss(t, _mm_cvtepi32_ps(m)));
  }

  HLML_INLINEF bool3& operator =  (bool3 vec) { m = vec.m; return *this; }
  HLML_INLINEF bool3& operator &= (bool3 vec) { m = _mm_and_si128(m, vec.m); return *this; }
  HLML_INLINEF bool3& operator ^= (bool3 vec) { m = _mm_xor_si128(m, vec.m); return *this; }
  HLML_INLINEF bool3& operator |= (bool3 vec) { m = _mm_or_si128(m, vec.m); return *this; }
};
HLML_INLINEF U32 mask(bool3 v) { return 0x888 & _mm_movemask_epi8(v.m); }
HLML_INLINEF B8  none(bool3 v) { return 0 == mask(v); }
HLML_INLINEF B8  any (bool3 v) { return 0 != mask(v); }
HLML_INLINEF B8  all (bool3 v) { return 0x888 == mask(v); }

HLML_INLINEF bool3  operator!  (bool3 a) { a.m = _mm_andnot_si128(a.m, vsignbits); return a; }
HLML_INLINEF bool3  operator== (bool3 a, bool3 b) { return bool3(_mm_cmpeq_epi32(a.m, b.m)); }
HLML_INLINEF bool3  operator!= (bool3 a, bool3 b) { return !(a == b); }
HLML_INLINEF bool3  operator&  (bool3 a, bool3 b) { return a &= b; }
HLML_INLINEF bool3  operator|  (bool3 a, bool3 b) { return a |= b; }
HLML_INLINEF bool3  operator^  (bool3 a, bool3 b) { return a ^= b; }
}