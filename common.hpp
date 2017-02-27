#pragma once

#include <stdint.h>
#include <intrin.h>

#define HLML_VCONST       extern const __declspec(selectany)
#define HLML_PI           3.14159265358979323846f
#define HLML_DEG2RAD(_a)  ((_a) * HLML_PI / 180.0f)
#define HLML_RAD2DEG(_a)  ((_a) * 180.0f / HLML_PI)

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
};

#undef min
#undef max

#include "funcs_sse.hpp"

namespace hlml {
namespace consts {
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

HLML_VCONST vconstu vzeros = { sfZero, sfZero, sfZero, sfZero };
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
  union { I32 i; F32 f; };
  uiasf(I32 val) : i(val) {}
};

HLML_INLINEF I32 f2i(F32 x) {
  const I32 magic = consts::snMagicF2I;
  x += *(F32*)&magic;
  return *(I32*)&x - magic;
}
HLML_INLINEF F32 min(F32 a, F32 b) { return (a) < (b) ? (a) : (b); }
HLML_INLINEF F32 max(F32 a, F32 b) { return (a) > (b) ? (a) : (b); }
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

template<typename T> HLML_INLINEF T   operator<<  (T a, U8 bits) { a.m = funcs::Ashiftl(a.m, bits); return a; }
template<typename T> HLML_INLINEF T   operator>>  (T a, U8 bits) { a.m = funcs::Ashiftr(a.m, bits); return a; }
template<typename T> HLML_INLINEF T&  operator<<= (T& a, U8 bits) { a = a << bits; return a; }
template<typename T> HLML_INLINEF T&  operator>>= (T& a, U8 bits) { a = a >> bits; return a; }

template<typename T> HLML_INLINEF T   cmpeq       (T a, T b) { return T(funcs::AcmpeqB(a.m, b.m)); }
template<typename T> HLML_INLINEF T   cmpneq      (T a, T b) { return T(funcs::AcmpneqB(a.m, b.m)); }
template<typename T> HLML_INLINEF T   cmpgt       (T a, T b) { return T(funcs::AcmpgtB(a.m, b.m)); }
template<typename T> HLML_INLINEF T   cmpge       (T a, T b) { return T(funcs::AcmpgeB(a.m, b.m)); }
template<typename T> HLML_INLINEF T   cmplt       (T a, T b) { return T(funcs::AcmpltB(a.m, b.m)); }
template<typename T> HLML_INLINEF T   cmple       (T a, T b) { return T(funcs::AcmpleB(a.m, b.m)); }

template<typename T> HLML_INLINEF T   abs         (T v) { v.m = funcs::notAandB(consts::vsignbits, v.m); return v; }
template<typename T> HLML_INLINEF T   sign        (T v) { T zro0(vzeros); return (cmplt(v, zro0) & T(vonesneg)) | (cmpgt(v, zro0) & T(vones)); } //https://github.com/g-truc/glm/blob/master/glm/simd/common.h#L99
template<typename T> HLML_INLINEF T   min         (T a, T b) { a.m = funcs::AminB(a.m, b.m); return a; }
template<typename T> HLML_INLINEF T   max         (T a, T b) { a.m = funcs::AmaxB(a.m, b.m); return a; }
template<typename T> HLML_INLINEF T   clamp       (T t, T a, T b) { return min(max(t, a), b); }

template<typename T> HLML_INLINEF U32 mask(T v) { return T::flagsall & funcs::movemask(v.m); }
template<typename T> HLML_INLINEF B8  any (T v) { return mask(v); }
template<typename T> HLML_INLINEF B8  none(T v) { return !any(v); }
template<typename T> HLML_INLINEF B8  all (T v) { return T::flagsall == mask(v); }

template<typename T, typename S> HLML_INLINEF T   operator+  (T a, S b) { return a + T(b); }
template<typename T, typename S> HLML_INLINEF T   operator+  (S b, T a) { return a + b; }
template<typename T, typename S> HLML_INLINEF T&  operator+= (T& a, S b) { return a += T(b); }
template<typename T, typename S> HLML_INLINEF T   operator-  (T a, S b) { return a - T(b); }
template<typename T, typename S> HLML_INLINEF T   operator-  (S a, T b) { return T(a) - b; }
template<typename T, typename S> HLML_INLINEF T&  operator-= (T& a, S b) { return a -= T(b); }
template<typename T, typename S> HLML_INLINEF T   operator*  (T a, S b) { return a * T(b); }
template<typename T, typename S> HLML_INLINEF T   operator*  (S b, T a) { return a * b; }
template<typename T, typename S> HLML_INLINEF T&  operator*= (T& a, S b) { return a *= T(b); }
template<typename T, typename S> HLML_INLINEF T   operator/  (T a, S b) { return a / T(b); }
template<typename T, typename S> HLML_INLINEF T   operator/  (S a, T b) { return T(a) / b; }
template<typename T, typename S> HLML_INLINEF T&  operator/= (T& a, S b) { return a /= T(b); }
}
