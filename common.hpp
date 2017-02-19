#pragma once

#include <stdint.h>
#include <emmintrin.h>
#include <intrin.h>

#define HLML_INLINEF      __forceinline
#define HLML_VCONST       extern const __declspec(selectany)
#define HLML_PI           3.14159265358979323846f
#define HLML_DEG2RAD(_a)  ((_a) * HLML_PI / 180.0f)
#define HLML_RAD2DEG(_a)  ((_a) * 180.0f / HLML_PI)

#undef min
#undef max

namespace hlml {
typedef float F32;
typedef bool B8;
typedef ::uint_least8_t U8;
typedef ::int_least8_t I8;
typedef ::uint_least16_t U16;
typedef ::int_least16_t I16;
typedef ::uint_least32_t U32;
typedef ::int_least32_t I32;
typedef ::uint_least64_t U64;
typedef ::int_least64_t I64;
typedef __m128 VF128;
typedef __m128i VI128;

struct vconstu {
  vconstu(U32 u0, U32 u1, U32 u2, U32 u3) {
    u[0] = u0;
    u[1] = u1;
    u[2] = u2;
    u[3] = u3;
  }
  vconstu(I32 u0, I32 u1, I32 u2, I32 u3) {
    i[0] = u0;
    i[1] = u1;
    i[2] = u2;
    i[3] = u3;
  }
  vconstu(F32 f0, F32 f1, F32 f2, F32 f3) {
    f[0] = f0;
    f[1] = f1;
    f[2] = f2;
    f[3] = f3;
  }
  union { U32 u[4]; I32 i[4]; F32 f[4]; VF128 vf; VI128 vi; };
  HLML_INLINEF operator VF128() const { return vf; }
  HLML_INLINEF operator VI128() const { return vi; }
};

static constexpr F32 sfZero = 0.0f;
static constexpr F32 sfOne = 1.0f;

static constexpr U32 snSignBit = 0x80000000;
static constexpr U32 snNSignBit = ~snSignBit;
static constexpr U32 snZero = 0x00000000;
static constexpr U32 snZeroN = ~snZero;
static constexpr I32 snMagicF2I = (150 << 23) | (1 << 22);

HLML_VCONST vconstu vf2ibits = { snMagicF2I, snMagicF2I, snMagicF2I, snMagicF2I };
HLML_VCONST vconstu vsignbits = { snSignBit, snSignBit, snSignBit, snSignBit };
HLML_VCONST vconstu vsignbitsn = { snNSignBit, snNSignBit, snNSignBit, snNSignBit };
HLML_VCONST vconstu vsignpnnp = { snZero, snSignBit, snSignBit, snZero };
HLML_VCONST vconstu vsignnnnp = { snZero, snZero, snZero, snSignBit };
HLML_VCONST vconstu vsignpppn = { snSignBit, snSignBit, snSignBit, snZero };
HLML_VCONST vconstu vsignppnn = { snSignBit, snSignBit, snZero, snZero };
HLML_VCONST vconstu vsignpnpn = { snSignBit, snZero, snSignBit, snZero };
HLML_VCONST vconstu vsignnpnp = { snZero, snSignBit, snZero, snSignBit };
HLML_VCONST vconstu vnall = { snZeroN, snZeroN, snZeroN, snZeroN };

struct iasf {
  union { I32 i; F32 f; };
  iasf(I32 val) : i(val) {}
};
HLML_INLINEF I32 f2i(F32 x) {
  const I32 magic = snMagicF2I;
  x += *(F32*)&magic;
  return *(I32*)&x - magic;
}
template<typename T> HLML_INLINEF T min(T x, T y) { return (y) ^ (((x) ^ (y)) & -((x) < (y))); }
template<typename T> HLML_INLINEF T max(T x, T y) { return (x) ^ (((x) ^ (y)) & -((x) < (y))); }
HLML_INLINEF F32 min(F32 a, F32 b) { return (a) < (b) ? (a) : (b); }
HLML_INLINEF F32 max(F32 a, F32 b) { return (a) > (b) ? (a) : (b); }
HLML_INLINEF F32 clamp(F32 t, F32 a, F32 b) { return min(max(t, a), b); }
}
