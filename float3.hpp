#pragma once

#include "float2.hpp"
#include "bool3.hpp"
#include "int3.hpp"

namespace hlml {
struct float3 {

  VF128 m = { 0 };

  HLML_INLINEF float3() {}
  HLML_INLINEF float3(F32 x, F32 y, F32 z) : m(funcs::setXYZW(x, y, z, consts::sfZero)) {}
  HLML_INLINEF float3(float2 v, F32 z) : float3(v.x(), v.y(), z) {}
  HLML_INLINEF explicit float3(F32 x) : float3(x, x, x) {}
  HLML_INLINEF explicit float3(const F32 *p) : float3(p[0], p[1], p[2]) {}
  HLML_INLINEF explicit float3(VF128 v) : m(v) {}
  HLML_INLINEF float3 float3i(I32 x, I32 y, I32 z) { return float3((F32)x, (F32)y, (F32)z); }

  HLML_INLINEF void store(F32 *p) const { p[0] = x(); p[1] = y(); p[2] = z(); }

  HLML_INLINEF void setX(F32 x) { m = insertf(m, x, 0); }
  HLML_INLINEF void setY(F32 y) { m = insertf(m, y, 1); }
  HLML_INLINEF void setZ(F32 z) { m = insertf(m, z, 2); }

  HLML_INLINEF F32 x() const { uiasf res = extractf(m, 0); return res.f; }
  HLML_INLINEF F32 y() const { uiasf res = extractf(m, 1); return res.f; }
  HLML_INLINEF F32 z() const { uiasf res = extractf(m, 2); return res.f; }

  HLML_INLINEF float2 xx() const { return shufflef2(*this, 0, 0); }
  HLML_INLINEF float2 xy() const { return shufflef2(*this, 0, 1); }
  HLML_INLINEF float2 xz() const { return shufflef2(*this, 0, 2); }
  HLML_INLINEF float2 yx() const { return shufflef2(*this, 1, 0); }
  HLML_INLINEF float2 yy() const { return shufflef2(*this, 1, 1); }
  HLML_INLINEF float2 yz() const { return shufflef2(*this, 1, 2); }
  HLML_INLINEF float2 zx() const { return shufflef2(*this, 2, 0); }
  HLML_INLINEF float2 zy() const { return shufflef2(*this, 2, 1); }
  HLML_INLINEF float2 zz() const { return shufflef2(*this, 2, 2); }

  HLML_INLINEF float3 xxx() const { return shufflef3(*this, 0, 0, 0); }
  HLML_INLINEF float3 xxy() const { return shufflef3(*this, 0, 0, 1); }
  HLML_INLINEF float3 xxz() const { return shufflef3(*this, 0, 0, 2); }
  HLML_INLINEF float3 xyx() const { return shufflef3(*this, 0, 1, 0); }
  HLML_INLINEF float3 xyy() const { return shufflef3(*this, 0, 1, 1); }
  HLML_INLINEF float3 xyz() const { return *this; }
  HLML_INLINEF float3 xzx() const { return shufflef3(*this, 0, 2, 0); }
  HLML_INLINEF float3 xzy() const { return shufflef3(*this, 0, 2, 1); }
  HLML_INLINEF float3 xzz() const { return shufflef3(*this, 0, 2, 2); }
  HLML_INLINEF float3 yxx() const { return shufflef3(*this, 1, 0, 0); }
  HLML_INLINEF float3 yxy() const { return shufflef3(*this, 1, 0, 1); }
  HLML_INLINEF float3 yxz() const { return shufflef3(*this, 1, 0, 2); }
  HLML_INLINEF float3 yyx() const { return shufflef3(*this, 1, 1, 0); }
  HLML_INLINEF float3 yyy() const { return shufflef3(*this, 1, 1, 1); }
  HLML_INLINEF float3 yyz() const { return shufflef3(*this, 1, 1, 2); }
  HLML_INLINEF float3 yzx() const { return shufflef3(*this, 1, 2, 0); }
  HLML_INLINEF float3 yzy() const { return shufflef3(*this, 1, 2, 1); }
  HLML_INLINEF float3 yzz() const { return shufflef3(*this, 1, 2, 2); }
  HLML_INLINEF float3 zxx() const { return shufflef3(*this, 2, 0, 0); }
  HLML_INLINEF float3 zxy() const { return shufflef3(*this, 2, 0, 1); }
  HLML_INLINEF float3 zxz() const { return shufflef3(*this, 2, 0, 2); }
  HLML_INLINEF float3 zyx() const { return shufflef3(*this, 2, 1, 0); }
  HLML_INLINEF float3 zyy() const { return shufflef3(*this, 2, 1, 1); }
  HLML_INLINEF float3 zyz() const { return shufflef3(*this, 2, 1, 2); }
  HLML_INLINEF float3 zzx() const { return shufflef3(*this, 2, 2, 0); }
  HLML_INLINEF float3 zzy() const { return shufflef3(*this, 2, 2, 1); }
  HLML_INLINEF float3 zzz() const { return shufflef3(*this, 2, 2, 2); }

  HLML_INLINEF F32 r() const { return x(); }
  HLML_INLINEF F32 g() const { return y(); }
  HLML_INLINEF F32 b() const { return z(); }

  HLML_INLINEF float2 rr() const { return xx(); }
  HLML_INLINEF float2 rg() const { return xy(); }
  HLML_INLINEF float2 rb() const { return xz(); }
  HLML_INLINEF float2 gr() const { return yx(); }
  HLML_INLINEF float2 gg() const { return yy(); }
  HLML_INLINEF float2 gb() const { return yz(); }
  HLML_INLINEF float2 br() const { return zx(); }
  HLML_INLINEF float2 bg() const { return zy(); }
  HLML_INLINEF float2 bb() const { return zz(); }

  HLML_INLINEF float3 rrr() const { return xxx(); }
  HLML_INLINEF float3 rrg() const { return xxy(); }
  HLML_INLINEF float3 rrb() const { return xxz(); }
  HLML_INLINEF float3 rgr() const { return xyx(); }
  HLML_INLINEF float3 rgg() const { return xyy(); }
  HLML_INLINEF float3 rgb() const { return xyz(); }
  HLML_INLINEF float3 rbr() const { return xzx(); }
  HLML_INLINEF float3 rbg() const { return xzy(); }
  HLML_INLINEF float3 rbb() const { return xzz(); }
  HLML_INLINEF float3 grr() const { return yxx(); }
  HLML_INLINEF float3 grg() const { return yxy(); }
  HLML_INLINEF float3 grb() const { return yxz(); }
  HLML_INLINEF float3 ggr() const { return yyx(); }
  HLML_INLINEF float3 ggg() const { return yyy(); }
  HLML_INLINEF float3 ggb() const { return yyz(); }
  HLML_INLINEF float3 gbr() const { return yzx(); }
  HLML_INLINEF float3 gbg() const { return yzy(); }
  HLML_INLINEF float3 gbb() const { return yzz(); }
  HLML_INLINEF float3 brr() const { return zxx(); }
  HLML_INLINEF float3 brg() const { return zxy(); }
  HLML_INLINEF float3 brb() const { return zxz(); }
  HLML_INLINEF float3 bgr() const { return zyx(); }
  HLML_INLINEF float3 bgg() const { return zyy(); }
  HLML_INLINEF float3 bgb() const { return zyz(); }
  HLML_INLINEF float3 bbr() const { return zzx(); }
  HLML_INLINEF float3 bbg() const { return zzy(); }
  HLML_INLINEF float3 bbb() const { return zzz(); }
};

HLML_INLINEF bool3   operator== (float3 a, float3 b) { return bool3(funcs::ftoi(cmpeq(a, b).m)); }
HLML_INLINEF bool3   operator!= (float3 a, float3 b) { return bool3(funcs::ftoi(cmpneq(a, b).m)); }
HLML_INLINEF bool3   operator<  (float3 a, float3 b) { return bool3(funcs::ftoi(cmplt(a, b).m)); }
HLML_INLINEF bool3   operator>  (float3 a, float3 b) { return bool3(funcs::ftoi(cmpgt(a, b).m)); }
HLML_INLINEF bool3   operator<= (float3 a, float3 b) { return bool3(funcs::ftoi(cmple(a, b).m)); }
HLML_INLINEF bool3   operator>= (float3 a, float3 b) { return bool3(funcs::ftoi(cmpge(a, b).m)); }

HLML_INLINEF int3 asint(float3 a) { return int3(funcs::fasi(a.m)); }
HLML_INLINEF int3 toint(float3 a) { return int3(funcs::ftoi(a.m)); }
HLML_INLINEF float3 asflt(int3 a) { return float3(funcs::iasf(a.m)); }
HLML_INLINEF float3 toflt(int3 a) { return float3(funcs::itof(a.m)); }
HLML_INLINEF float3 sumv(float3 v) { return v += v.zxy() + v.yzx(); }
HLML_INLINEF float3 crossv(float3 a, float3 b) { return (a.zxy() * b - a * b.zxy()).zxy(); }
HLML_INLINEF float3 cross(float3 a, float3 b) { return crossv(a, b); }
HLML_INLINEF F32 hmin(float3 v) { v = min(v, shufflef3(v, 1, 0, 2)); return min(v, shufflef3(v, 2, 0, 1)).x(); }
HLML_INLINEF F32 hmax(float3 v) { v = max(v, shufflef3(v, 1, 0, 2)); return max(v, shufflef3(v, 2, 0, 1)).x(); }
}
