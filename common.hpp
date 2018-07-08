#pragma once

#include <stdint.h>
#include <intrin.h>

#define HLML_VCONST       extern const __declspec(selectany)
#define HLML_PI           3.14159265358979323846f
#define HLML_DEG2RAD(_a)  ((_a) * HLML_PI / 180.0f)
#define HLML_RAD2DEG(_a)  ((_a) * 180.0f / HLML_PI)

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
};

#undef min
#undef max

#include "funcs_sse.hpp"

namespace hlml {
namespace consts {
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

static constexpr u32 snSignBit = 0x80000000;
static constexpr u32 snNSignBit = ~snSignBit;
static constexpr u32 snZero = 0x00000000;
static constexpr u32 snZeroN = ~snZero;
static constexpr i32 snMagicF2I = (150 << 23) | (1 << 22);

HLML_VCONST vconstu vzeros = { sfZero, sfZero, sfZero, sfZero };
HLML_VCONST vconstu vones = { sfOne, sfOne, sfOne, sfOne };
HLML_VCONST vconstu vpoint = { sfZero, sfZero, sfZero, sfOne };
HLML_VCONST vconstu vvector = { sfZero, sfZero, sfZero, sfZero };
HLML_VCONST vconstu vscaleinv = { sfOne, sfOne, sfOne, sfZero };
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
}

struct uiasf {
  union { i32 i; f32 f; };
  uiasf(i32 val) : i(val) {}
};
HLML_INLINEF i32 f2i(f32 x) {
  const i32 magic = consts::snMagicF2I;
  x += *(f32*)&magic;
  return *(i32*)&x - magic;
}
template<typename T> HLML_INLINEF T min(T a, T b) { return (a) < (b) ? (a) : (b); }
template<typename T> HLML_INLINEF T max(T a, T b) { return (a) > (b) ? (a) : (b); }
HLML_INLINEF u32 ftou(f32 nfloat, u32 bits) { u32 nIntervals = (1u << bits) - 1u; return min((u32)(nfloat * (f32)(nIntervals) + 0.5f), nIntervals); }
HLML_INLINEF f32 utof(u32 quantized, u32 bits) { return (f32)quantized / (f32)((1u << bits) - 1u); }
HLML_INLINEF u32 ftou(f32 value, f32 min, f32 max, u32 bits) { return ftou((value - min) / (max - min), bits); }
HLML_INLINEF f32 utof(u32 quantized, f32 min, f32 max, u32 bits) { return min + (utof(quantized, bits) * (max - min)); }

template<typename T> HLML_INLINEF T   operator!   (T a) { a.m = funcs::notAandB(a.m, consts::vsignbits); return a; } // for bools
template<typename T> HLML_INLINEF T   operator~   (T a) { a.m = funcs::notAandB(a.m, consts::vnall); return a; }
template<typename T> HLML_INLINEF T   operator&   (T a, T b) { a.m = funcs::AandB(a.m, b.m); return a; }
template<typename T> HLML_INLINEF T   operator|   (T a, T b) { a.m = funcs::AorB(a.m, b.m); return a; }
template<typename T> HLML_INLINEF T   operator^   (T a, T b) { a.m = funcs::AxorB(a.m, b.m); return a; }
template<typename T> HLML_INLINEF T&  operator&=  (T& a, T b) { a = a & b; return a; }
template<typename T> HLML_INLINEF T&  operator|=  (T& a, T b) { a = a | b; return a; }
template<typename T> HLML_INLINEF T&  operator^=  (T& a, T b) { a = a ^ b; return a; }

template<typename T> HLML_INLINEF T   operator+   (T a) { return a; }
template<typename T> HLML_INLINEF T   operator+   (T a, T b) { a.m = funcs::AaddB(a.m, b.m); return a; }
template<typename T> HLML_INLINEF T&  operator+=  (T& a, T b) { a = a + b; return a; }
template<typename T> HLML_INLINEF T   operator-   (T a) { a.m = funcs::AxorB(a.m, consts::vsignbits); return a; }
template<typename T> HLML_INLINEF T   operator-   (T a, T b) { a.m = funcs::AsubB(a.m, b.m); return a; }
template<typename T> HLML_INLINEF T&  operator-=  (T& a, T b) { a = a - b; return a; }
template<typename T> HLML_INLINEF T   operator*   (T a, T b) { a.m = funcs::AmulB(a.m, b.m); return a; }
template<typename T> HLML_INLINEF T&  operator*=  (T& a, T b) { a = a * b; return a; }
template<typename T> HLML_INLINEF T   operator/   (T a, T b) { a.m = funcs::AdivB(a.m, b.m); return a; }
template<typename T> HLML_INLINEF T&  operator/=  (T& a, T b) { a = a / b; return a; }

template<typename T> HLML_INLINEF T   operator<<  (T a, u8 bits) { a.m = funcs::Ashiftl(a.m, bits); return a; }
template<typename T> HLML_INLINEF T   operator>>  (T a, u8 bits) { a.m = funcs::Ashiftr(a.m, bits); return a; }
template<typename T> HLML_INLINEF T&  operator<<= (T& a, u8 bits) { a = a << bits; return a; }
template<typename T> HLML_INLINEF T&  operator>>= (T& a, u8 bits) { a = a >> bits; return a; }

template<typename T> HLML_INLINEF T   cmpeq       (T a, T b) { return T(funcs::AcmpeqB(a.m, b.m)); }
template<typename T> HLML_INLINEF T   cmpneq      (T a, T b) { return T(funcs::AcmpneqB(a.m, b.m)); }
template<typename T> HLML_INLINEF T   cmpgt       (T a, T b) { return T(funcs::AcmpgtB(a.m, b.m)); }
template<typename T> HLML_INLINEF T   cmpge       (T a, T b) { return T(funcs::AcmpgeB(a.m, b.m)); }
template<typename T> HLML_INLINEF T   cmplt       (T a, T b) { return T(funcs::AcmpltB(a.m, b.m)); }
template<typename T> HLML_INLINEF T   cmple       (T a, T b) { return T(funcs::AcmpleB(a.m, b.m)); }

template<typename T> HLML_INLINEF T   abs         (T v) { v.m = funcs::notAandB(consts::vsignbits, v.m); return v; }
template<typename T> HLML_INLINEF T   sign        (T v) { T zro0(vzeros); return (cmplt(v, zro0) & T(vonesneg)) | (cmpgt(v, zro0) & T(vones)); } //https://github.com/g-truc/glm/blob/master/glm/simd/common.h#L99
template<typename T> HLML_INLINEF T   minv        (T a, T b) { a.m = funcs::AminB(a.m, b.m); return a; }
template<typename T> HLML_INLINEF T   maxv        (T a, T b) { a.m = funcs::AmaxB(a.m, b.m); return a; }
template<typename T> HLML_INLINEF T   clamp       (T t, T a, T b) { return min(max(t, a), b); }

template<typename T> HLML_INLINEF u32 mask(T v) { return T::flagsall & funcs::movemask(v.m); }
template<typename T> HLML_INLINEF b8  any (T v) { return mask(v); }
template<typename T> HLML_INLINEF b8  none(T v) { return !any(v); }
template<typename T> HLML_INLINEF b8  all (T v) { return T::flagsall == mask(v); }

template<typename T> HLML_INLINEF T   operator+  (T a, f32 b) { return a + T(b); }
template<typename T> HLML_INLINEF T&  operator+= (T& a, f32 b) { return a += T(b); }
template<typename T> HLML_INLINEF T   operator-  (T a, f32 b) { return a - T(b); }
template<typename T> HLML_INLINEF T&  operator-= (T& a, f32 b) { return a -= T(b); }
template<typename T> HLML_INLINEF T   operator*  (T a, f32 b) { return a * T(b); }
template<typename T> HLML_INLINEF T&  operator*= (T& a, f32 b) { return a *= T(b); }
template<typename T> HLML_INLINEF T   operator/  (T a, f32 b) { return a / T(b); }
template<typename T> HLML_INLINEF T&  operator/= (T& a, f32 b) { return a /= T(b); }

template<typename T> HLML_INLINEF T   operator+  (f32 a, T b) { return T(a) + b; }
template<typename T> HLML_INLINEF T   operator-  (f32 a, T b) { return T(a) - b; }
template<typename T> HLML_INLINEF T   operator*  (f32 a, T b) { return T(a) * b; }
template<typename T> HLML_INLINEF T   operator/  (f32 a, T b) { return T(a) / b; }
}
