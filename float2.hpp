#pragma once

#include "common.hpp"
#include "bool2.hpp"
#include "int2.hpp"

namespace hlml {
struct float2 {
  VF128 m = { 0 };

  HLML_INLINEF float2() {}
  HLML_INLINEF float2(f32 x, f32 y) : m(funcs::setXYZW(x, y, consts::sfZero, consts::sfZero)) {}
  HLML_INLINEF explicit float2(f32 x) : float2(x, x) {}
  HLML_INLINEF explicit float2(const f32 *p) : float2(p[0], p[1]) {}
  HLML_INLINEF explicit float2(VF128 v) : m(funcs::axay0000(v)) {}
  HLML_INLINEF float2 float2i(i32 x, i32 y) { return float2((f32)x, (f32)y); }

  HLML_INLINEF void store(f32 *p) const { p[0] = x(); p[1] = y(); }

  HLML_INLINEF void setX(f32 x) { m = insertf(m, x, 0); }
  HLML_INLINEF void setY(f32 y) { m = insertf(m, y, 1); }

  HLML_INLINEF f32 x() const { uiasf res = extractf(m, 0); return res.asf32; }
  HLML_INLINEF f32 y() const { uiasf res = extractf(m, 1); return res.asf32; }

  HLML_INLINEF float2 xx() const { return shufflef2(*this, 0, 0); }
  HLML_INLINEF float2 xy() const { return *this; }
  HLML_INLINEF float2 yx() const { return shufflef2(*this, 1, 0); }
  HLML_INLINEF float2 yy() const { return shufflef2(*this, 1, 1); }

  HLML_INLINEF f32 r() const { return x(); }
  HLML_INLINEF f32 g() const { return y(); }

  HLML_INLINEF float2 rr() const { return xx(); }
  HLML_INLINEF float2 rg() const { return xy(); }
  HLML_INLINEF float2 gr() const { return yx(); }
  HLML_INLINEF float2 gg() const { return yy(); }
};

HLML_INLINEF bool2                    operator== (float2 a, float2 b) { return bool2(funcs::ftoi(cmpeq(a, b).m)); }
HLML_INLINEF bool2                    operator!= (float2 a, float2 b) { return bool2(funcs::ftoi(cmpneq(a, b).m)); }
HLML_INLINEF bool2                    operator<  (float2 a, float2 b) { return bool2(funcs::ftoi(cmplt(a, b).m)); }
HLML_INLINEF bool2                    operator>  (float2 a, float2 b) { return bool2(funcs::ftoi(cmpgt(a, b).m)); }
HLML_INLINEF bool2                    operator<= (float2 a, float2 b) { return bool2(funcs::ftoi(cmple(a, b).m)); }
HLML_INLINEF bool2                    operator>= (float2 a, float2 b) { return bool2(funcs::ftoi(cmpge(a, b).m)); }

HLML_INLINEF int2 asint(float2 a) { return int2(funcs::fasi(a.m)); }
HLML_INLINEF int2 toint(float2 a) { return int2(funcs::ftoi(a.m)); }
HLML_INLINEF float2 asflt(int2 a) { return float2(funcs::iasf(a.m)); }
HLML_INLINEF float2 toflt(int2 a) { return float2(funcs::itof(a.m)); }

HLML_INLINEF float2 sumv(float2 v) { v.m = funcs::AhaddB(v.m, v.m);  return v; }
HLML_INLINEF float2 crossv(float2 a, float2 b) { return (a * b.yx() - a.yx() * b); }
HLML_INLINEF f32 cross(float2 a, float2 b) { return crossv(a, b).x(); }
HLML_INLINEF f32 hmin(float2 v) { return minv(v, shufflef2(v, 1, 0)).x(); }
HLML_INLINEF f32 hmax(float2 v) { return maxv(v, shufflef2(v, 1, 0)).x(); }
}
