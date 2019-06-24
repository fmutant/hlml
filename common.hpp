#pragma once

#include <stdint.h>
#include <intrin.h>

#define HLML_VCONST       extern const __declspec(selectany)

namespace hlml {
typedef float f32;
typedef float float1;
typedef bool b8;
typedef ::uint_least8_t u8;
typedef ::int_least8_t i8;
typedef ::uint_least16_t u16;
typedef ::int_least16_t i16;
typedef ::uint_least32_t u32;
typedef ::int_least32_t i32;
typedef ::uint_least64_t u64;
typedef ::int_least64_t i64;
typedef u16 b16;
typedef u32 b32;
typedef __m128 VF128;
typedef __m128i VI128;
static_assert(sizeof(bool) == 1, "sizeof(bool) is not 1 byte");
};

#undef min
#undef max

#include "funcs_sse.hpp"

namespace hlml {
namespace consts {
constexpr f32 PI = 3.14159265358979323846f;
constexpr f32 PI_INV = 1.0f / 3.14159265358979323846f;
constexpr f32 DEGS_IN_RAD = 180.0f / PI;
constexpr f32 RADS_IN_DEG = PI / 180.0f;

struct vconstu {
  vconstu(u32 u0, u32 u1, u32 u2, u32 u3) {
    u[0] = u0;
    u[1] = u1;
    u[2] = u2;
    u[3] = u3;
  }
  vconstu(i32 u0, i32 u1, i32 u2, i32 u3) {
    i[0] = u0;
    i[1] = u1;
    i[2] = u2;
    i[3] = u3;
  }
  vconstu(f32 f0, f32 f1, f32 f2, f32 f3) {
    f[0] = f0;
    f[1] = f1;
    f[2] = f2;
    f[3] = f3;
  }
  union { u32 u[4]; i32 i[4]; f32 f[4]; VF128 vf; VI128 vi; };
  HLML_INLINEF operator VF128() const { return vf; }
  HLML_INLINEF operator VI128() const { return vi; }
};

static constexpr f32 sfZero = 0.0f;
static constexpr f32 sfOne = 1.0f;
static constexpr f32 sfNOne = -1.0f;

static constexpr u32 snSignBit = 0x80000000;
static constexpr u32 snNSignBit = ~snSignBit;
static constexpr u32 snZero = 0x00000000;
static constexpr u32 snZeroN = ~snZero;
static constexpr i32 snMagicF2I = (150 << 23) | (1 << 22);

HLML_VCONST vconstu vzeros = { sfZero, sfZero, sfZero, sfZero };
HLML_VCONST vconstu vones = { sfOne, sfOne, sfOne, sfOne };
HLML_VCONST vconstu vones2 = { sfOne, sfOne, sfZero, sfZero };
HLML_VCONST vconstu vones3 = { sfOne, sfOne, sfOne, sfZero };
HLML_VCONST vconstu vones4 = { sfOne, sfOne, sfOne, sfOne };
HLML_VCONST vconstu vnones2 = { sfNOne, sfNOne, sfZero, sfZero };
HLML_VCONST vconstu vnones3 = { sfNOne, sfNOne, sfZero, sfZero };
HLML_VCONST vconstu vnones4 = { sfNOne, sfNOne, sfNOne, sfZero };
HLML_VCONST vconstu vpoint = { sfZero, sfZero, sfZero, sfOne };
HLML_VCONST vconstu vvector = { sfZero, sfZero, sfZero, sfZero };
HLML_VCONST vconstu vscaleinv = { sfOne, sfOne, sfOne, sfZero };
HLML_VCONST vconstu vf2ibits = { snMagicF2I, snMagicF2I, snMagicF2I, snMagicF2I };
HLML_VCONST vconstu vsignbits_xyzw = { snSignBit, snSignBit, snSignBit, snSignBit };
HLML_VCONST vconstu vsignbitsn = { snNSignBit, snNSignBit, snNSignBit, snNSignBit };
HLML_VCONST vconstu vsignbits_yz = { snZero, snSignBit, snSignBit, snZero };
HLML_VCONST vconstu vsignbits_w = { snZero, snZero, snZero, snSignBit };
HLML_VCONST vconstu vsignbits_xyz = { snSignBit, snSignBit, snSignBit, snZero };
HLML_VCONST vconstu vsignbits_xy = { snSignBit, snSignBit, snZero, snZero };
HLML_VCONST vconstu vsignbits_xz = { snSignBit, snZero, snSignBit, snZero };
HLML_VCONST vconstu vsignbits_yw = { snZero, snSignBit, snZero, snSignBit };
HLML_VCONST vconstu vnall = { snZeroN, snZeroN, snZeroN, snZeroN };
HLML_VCONST vconstu vnall3 = { snZeroN, snZeroN, snZeroN, snZero };
HLML_VCONST vconstu vnall2 = { snZeroN, snZeroN, snZero, snZero };
}

HLML_INLINEF f32 DEG2RAD(f32 degs) { return degs * consts::RADS_IN_DEG; }
HLML_INLINEF f32 RAD2DEG(f32 rads) { return rads * consts::DEGS_IN_RAD; }

struct uiasf {
  union { i32 asi32; u32 asu32; f32 asf32; };
  uiasf(i32 val) : asi32(val) {}
  uiasf(f32 val) : asf32(val) {}
};

template<typename T> HLML_INLINEF T   cmpeq       (T a, T b) { a.m = funcs::AcmpeqB(a.m, b.m); return a; }
template<typename T> HLML_INLINEF T   cmpne        (T a, T b) { a.m = funcs::AcmpneB(a.m, b.m); return a; }
template<typename T> HLML_INLINEF T   cmpgt       (T a, T b) { a.m = funcs::AcmpgtB(a.m, b.m); return a; }
template<typename T> HLML_INLINEF T   cmpge       (T a, T b) { a.m = funcs::AcmpgeB(a.m, b.m); return a; }
template<typename T> HLML_INLINEF T   cmplt       (T a, T b) { a.m = funcs::AcmpltB(a.m, b.m); return a; }
template<typename T> HLML_INLINEF T   cmple       (T a, T b) { a.m = funcs::AcmpleB(a.m, b.m); return a; }

HLML_INLINEF u32 min(u32 a, u32 b) { return a < b ? a : b; }
HLML_INLINEF u32 max(u32 a, u32 b) { return b < a ? a : b; }
HLML_INLINEF f32 min(f32 a, f32 b) { return a < b ? a : b; }
HLML_INLINEF f32 max(f32 a, f32 b) { return b < a ? a : b; }
HLML_INLINEF f32 abs(f32 v) {
  uiasf a = { v };
  a.asu32 &= ~consts::snSignBit;
  return a.asf32;
}
HLML_INLINEF f32 clamp(f32 v, f32 a, f32 b) { return min(max(v, a), b); }
HLML_INLINEF f32 saturate(f32 v) { return clamp(v, 0.0, 1.0f); }

HLML_INLINEF i32 f2i(f32 x) {
  const i32 magic = consts::snMagicF2I;
  x += *(f32*)&magic;
  return *(i32*)&x - magic;
}
HLML_INLINEF u32 ftou(f32 nfloat, u32 bits) { u32 nIntervals = (1u << bits) - 1u; return min((u32)(nfloat * (f32)(nIntervals) + 0.5f), nIntervals); }
HLML_INLINEF f32 utof(u32 quantized, u32 bits) { return (f32)quantized / (f32)((1u << bits) - 1u); }
HLML_INLINEF u32 ftou(f32 value, f32 min, f32 max, u32 bits) { return ftou((value - min) / (max - min), bits); }
HLML_INLINEF f32 utof(u32 quantized, f32 min, f32 max, u32 bits) { return min + (utof(quantized, bits) * (max - min)); }

}
