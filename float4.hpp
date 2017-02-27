#pragma once

#include "float3.hpp"
#include "bool4.hpp"
#include "int4.hpp"

namespace hlml {
struct float4 {

  VF128 m = { 0 };

  HLML_INLINEF float4() {}
  HLML_INLINEF float4(F32 x, F32 y, F32 z, F32 w) : m(funcs::setXYZW(x, y, z, w)) {}
  HLML_INLINEF float4(float2 v, F32 z, F32 w) : float4(v.x(), v.y(), z, w) {}
  HLML_INLINEF float4(float3 v, F32 w) : float4(v.x(), v.y(), v.z(), w) {}
  HLML_INLINEF explicit float4(F32 x) : float4(x, x, x, x) {}
  HLML_INLINEF explicit float4(const F32 *p) : float4(p[0], p[1], p[2], p[3]) {}
  HLML_INLINEF explicit float4(VF128 v) : m(v) {}
  HLML_INLINEF float4 float4i(I32 x, I32 y, I32 z, I32 w) { return float4((F32)x, (F32)y, (F32)z, (F32)w); }

  HLML_INLINEF void store(F32 *p) const { p[0] = x(); p[1] = y(); p[2] = z(); p[3] = w(); }

  HLML_INLINEF void setX(F32 x) { m = insertf(m, x, 0); }
  HLML_INLINEF void setY(F32 y) { m = insertf(m, y, 1); }
  HLML_INLINEF void setZ(F32 z) { m = insertf(m, z, 2); }
  HLML_INLINEF void setW(F32 w) { m = insertf(m, w, 3); }

  HLML_INLINEF F32 x() const { uiasf res = extractf(m, 0); return res.f; }
  HLML_INLINEF F32 y() const { uiasf res = extractf(m, 1); return res.f; }
  HLML_INLINEF F32 z() const { uiasf res = extractf(m, 2); return res.f; }
  HLML_INLINEF F32 w() const { uiasf res = extractf(m, 3); return res.f; }

  HLML_INLINEF float2 xx() const { return shufflef2(*this, 0, 0); }
  HLML_INLINEF float2 xy() const { return shufflef2(*this, 0, 1); }
  HLML_INLINEF float2 xz() const { return shufflef2(*this, 0, 2); }
  HLML_INLINEF float2 xw() const { return shufflef2(*this, 0, 3); }
  HLML_INLINEF float2 yy() const { return shufflef2(*this, 1, 1); }
  HLML_INLINEF float2 yx() const { return shufflef2(*this, 1, 0); }
  HLML_INLINEF float2 yz() const { return shufflef2(*this, 1, 2); }
  HLML_INLINEF float2 yw() const { return shufflef2(*this, 1, 3); }
  HLML_INLINEF float2 zz() const { return shufflef2(*this, 2, 2); }
  HLML_INLINEF float2 zx() const { return shufflef2(*this, 2, 0); }
  HLML_INLINEF float2 zy() const { return shufflef2(*this, 2, 1); }
  HLML_INLINEF float2 zw() const { return shufflef2(*this, 2, 3); }
  HLML_INLINEF float2 ww() const { return shufflef2(*this, 3, 3); }
  HLML_INLINEF float2 wx() const { return shufflef2(*this, 3, 0); }
  HLML_INLINEF float2 wy() const { return shufflef2(*this, 3, 1); }
  HLML_INLINEF float2 wz() const { return shufflef2(*this, 3, 2); }

  HLML_INLINEF float3 xxx() const { return shufflef3(*this, 0, 0, 0); }
  HLML_INLINEF float3 xxy() const { return shufflef3(*this, 0, 0, 1); }
  HLML_INLINEF float3 xxz() const { return shufflef3(*this, 0, 0, 2); }
  HLML_INLINEF float3 xxw() const { return shufflef3(*this, 0, 0, 3); }
  HLML_INLINEF float3 xyx() const { return shufflef3(*this, 0, 1, 0); }
  HLML_INLINEF float3 xyy() const { return shufflef3(*this, 0, 1, 1); }
  HLML_INLINEF float3 xyz() const { return shufflef3(*this, 0, 1, 2); }
  HLML_INLINEF float3 xyw() const { return shufflef3(*this, 0, 1, 3); }
  HLML_INLINEF float3 xzx() const { return shufflef3(*this, 0, 2, 0); }
  HLML_INLINEF float3 xzy() const { return shufflef3(*this, 0, 2, 1); }
  HLML_INLINEF float3 xzz() const { return shufflef3(*this, 0, 2, 2); }
  HLML_INLINEF float3 xzw() const { return shufflef3(*this, 0, 2, 3); }
  HLML_INLINEF float3 xwx() const { return shufflef3(*this, 0, 3, 0); }
  HLML_INLINEF float3 xwy() const { return shufflef3(*this, 0, 3, 1); }
  HLML_INLINEF float3 xwz() const { return shufflef3(*this, 0, 3, 2); }
  HLML_INLINEF float3 xww() const { return shufflef3(*this, 0, 3, 3); }

  HLML_INLINEF float3 yxx() const { return shufflef3(*this, 1, 0, 0); }
  HLML_INLINEF float3 yxy() const { return shufflef3(*this, 1, 0, 1); }
  HLML_INLINEF float3 yxz() const { return shufflef3(*this, 1, 0, 2); }
  HLML_INLINEF float3 yxw() const { return shufflef3(*this, 1, 0, 3); }
  HLML_INLINEF float3 yyx() const { return shufflef3(*this, 1, 1, 0); }
  HLML_INLINEF float3 yyy() const { return shufflef3(*this, 1, 1, 1); }
  HLML_INLINEF float3 yyz() const { return shufflef3(*this, 1, 1, 2); }
  HLML_INLINEF float3 yyw() const { return shufflef3(*this, 1, 1, 3); }
  HLML_INLINEF float3 yzx() const { return shufflef3(*this, 1, 2, 0); }
  HLML_INLINEF float3 yzy() const { return shufflef3(*this, 1, 2, 1); }
  HLML_INLINEF float3 yzz() const { return shufflef3(*this, 1, 2, 2); }
  HLML_INLINEF float3 yzw() const { return shufflef3(*this, 1, 2, 3); }
  HLML_INLINEF float3 ywx() const { return shufflef3(*this, 1, 3, 0); }
  HLML_INLINEF float3 ywy() const { return shufflef3(*this, 1, 3, 1); }
  HLML_INLINEF float3 ywz() const { return shufflef3(*this, 1, 3, 2); }
  HLML_INLINEF float3 yww() const { return shufflef3(*this, 1, 3, 3); }

  HLML_INLINEF float3 zxx() const { return shufflef3(*this, 2, 0, 0); }
  HLML_INLINEF float3 zxy() const { return shufflef3(*this, 2, 0, 1); }
  HLML_INLINEF float3 zxz() const { return shufflef3(*this, 2, 0, 2); }
  HLML_INLINEF float3 zxw() const { return shufflef3(*this, 2, 0, 3); }
  HLML_INLINEF float3 zyx() const { return shufflef3(*this, 2, 1, 0); }
  HLML_INLINEF float3 zyy() const { return shufflef3(*this, 2, 1, 1); }
  HLML_INLINEF float3 zyz() const { return shufflef3(*this, 2, 1, 2); }
  HLML_INLINEF float3 zyw() const { return shufflef3(*this, 2, 1, 3); }
  HLML_INLINEF float3 zzx() const { return shufflef3(*this, 2, 2, 0); }
  HLML_INLINEF float3 zzy() const { return shufflef3(*this, 2, 2, 1); }
  HLML_INLINEF float3 zzz() const { return shufflef3(*this, 2, 2, 2); }
  HLML_INLINEF float3 zzw() const { return shufflef3(*this, 2, 2, 3); }
  HLML_INLINEF float3 zwx() const { return shufflef3(*this, 2, 3, 0); }
  HLML_INLINEF float3 zwy() const { return shufflef3(*this, 2, 3, 1); }
  HLML_INLINEF float3 zwz() const { return shufflef3(*this, 2, 3, 2); }
  HLML_INLINEF float3 zww() const { return shufflef3(*this, 2, 3, 3); }

  HLML_INLINEF float3 wxx() const { return shufflef3(*this, 3, 0, 0); }
  HLML_INLINEF float3 wxy() const { return shufflef3(*this, 3, 0, 1); }
  HLML_INLINEF float3 wxz() const { return shufflef3(*this, 3, 0, 2); }
  HLML_INLINEF float3 wxw() const { return shufflef3(*this, 3, 0, 3); }
  HLML_INLINEF float3 wyx() const { return shufflef3(*this, 3, 1, 0); }
  HLML_INLINEF float3 wyy() const { return shufflef3(*this, 3, 1, 1); }
  HLML_INLINEF float3 wyz() const { return shufflef3(*this, 3, 1, 2); }
  HLML_INLINEF float3 wyw() const { return shufflef3(*this, 3, 1, 3); }
  HLML_INLINEF float3 wzx() const { return shufflef3(*this, 3, 2, 0); }
  HLML_INLINEF float3 wzy() const { return shufflef3(*this, 3, 2, 1); }
  HLML_INLINEF float3 wzz() const { return shufflef3(*this, 3, 2, 2); }
  HLML_INLINEF float3 wzw() const { return shufflef3(*this, 3, 2, 3); }
  HLML_INLINEF float3 wwx() const { return shufflef3(*this, 3, 3, 0); }
  HLML_INLINEF float3 wwy() const { return shufflef3(*this, 3, 3, 1); }
  HLML_INLINEF float3 wwz() const { return shufflef3(*this, 3, 3, 2); }
  HLML_INLINEF float3 www() const { return shufflef3(*this, 3, 3, 3); }

  HLML_INLINEF float4 xxxx() const { return shufflef4(*this, 0, 0, 0, 0); }
  HLML_INLINEF float4 xxxy() const { return shufflef4(*this, 0, 0, 0, 1); }
  HLML_INLINEF float4 xxxz() const { return shufflef4(*this, 0, 0, 0, 2); }
  HLML_INLINEF float4 xxxw() const { return shufflef4(*this, 0, 0, 0, 3); }
  HLML_INLINEF float4 xxyx() const { return shufflef4(*this, 0, 0, 1, 0); }
  HLML_INLINEF float4 xxyy() const { return shufflef4(*this, 0, 0, 1, 1); }
  HLML_INLINEF float4 xxyz() const { return shufflef4(*this, 0, 0, 1, 2); }
  HLML_INLINEF float4 xxyw() const { return shufflef4(*this, 0, 0, 1, 3); }
  HLML_INLINEF float4 xxzx() const { return shufflef4(*this, 0, 0, 2, 0); }
  HLML_INLINEF float4 xxzy() const { return shufflef4(*this, 0, 0, 2, 1); }
  HLML_INLINEF float4 xxzz() const { return shufflef4(*this, 0, 0, 2, 2); }
  HLML_INLINEF float4 xxzw() const { return shufflef4(*this, 0, 0, 2, 3); }
  HLML_INLINEF float4 xxwx() const { return shufflef4(*this, 0, 0, 3, 0); }
  HLML_INLINEF float4 xxwy() const { return shufflef4(*this, 0, 0, 3, 1); }
  HLML_INLINEF float4 xxwz() const { return shufflef4(*this, 0, 0, 3, 2); }
  HLML_INLINEF float4 xxww() const { return shufflef4(*this, 0, 0, 3, 3); }
  HLML_INLINEF float4 xyxx() const { return shufflef4(*this, 0, 1, 0, 0); }
  HLML_INLINEF float4 xyxy() const { return shufflef4(*this, 0, 1, 0, 1); }
  HLML_INLINEF float4 xyxz() const { return shufflef4(*this, 0, 1, 0, 2); }
  HLML_INLINEF float4 xyxw() const { return shufflef4(*this, 0, 1, 0, 3); }
  HLML_INLINEF float4 xyyx() const { return shufflef4(*this, 0, 1, 1, 0); }
  HLML_INLINEF float4 xyyy() const { return shufflef4(*this, 0, 1, 1, 1); }
  HLML_INLINEF float4 xyyz() const { return shufflef4(*this, 0, 1, 1, 2); }
  HLML_INLINEF float4 xyyw() const { return shufflef4(*this, 0, 1, 1, 3); }
  HLML_INLINEF float4 xyzx() const { return shufflef4(*this, 0, 1, 2, 0); }
  HLML_INLINEF float4 xyzy() const { return shufflef4(*this, 0, 1, 2, 1); }
  HLML_INLINEF float4 xyzz() const { return shufflef4(*this, 0, 1, 2, 2); }
  HLML_INLINEF float4 xyzw() const { return *this; }
  HLML_INLINEF float4 xywx() const { return shufflef4(*this, 0, 1, 3, 0); }
  HLML_INLINEF float4 xywy() const { return shufflef4(*this, 0, 1, 3, 1); }
  HLML_INLINEF float4 xywz() const { return shufflef4(*this, 0, 1, 3, 2); }
  HLML_INLINEF float4 xyww() const { return shufflef4(*this, 0, 1, 3, 3); }
  HLML_INLINEF float4 xzxx() const { return shufflef4(*this, 0, 2, 0, 0); }
  HLML_INLINEF float4 xzxy() const { return shufflef4(*this, 0, 2, 0, 1); }
  HLML_INLINEF float4 xzxz() const { return shufflef4(*this, 0, 2, 0, 2); }
  HLML_INLINEF float4 xzxw() const { return shufflef4(*this, 0, 2, 0, 3); }
  HLML_INLINEF float4 xzyx() const { return shufflef4(*this, 0, 2, 1, 0); }
  HLML_INLINEF float4 xzyy() const { return shufflef4(*this, 0, 2, 1, 1); }
  HLML_INLINEF float4 xzyz() const { return shufflef4(*this, 0, 2, 1, 2); }
  HLML_INLINEF float4 xzyw() const { return shufflef4(*this, 0, 2, 1, 3); }
  HLML_INLINEF float4 xzzx() const { return shufflef4(*this, 0, 2, 2, 0); }
  HLML_INLINEF float4 xzzy() const { return shufflef4(*this, 0, 2, 2, 1); }
  HLML_INLINEF float4 xzzz() const { return shufflef4(*this, 0, 2, 2, 2); }
  HLML_INLINEF float4 xzzw() const { return shufflef4(*this, 0, 2, 2, 3); }
  HLML_INLINEF float4 xzwx() const { return shufflef4(*this, 0, 2, 3, 0); }
  HLML_INLINEF float4 xzwy() const { return shufflef4(*this, 0, 2, 3, 1); }
  HLML_INLINEF float4 xzwz() const { return shufflef4(*this, 0, 2, 3, 2); }
  HLML_INLINEF float4 xzww() const { return shufflef4(*this, 0, 2, 3, 3); }
  HLML_INLINEF float4 xwxx() const { return shufflef4(*this, 0, 3, 0, 0); }
  HLML_INLINEF float4 xwxy() const { return shufflef4(*this, 0, 3, 0, 1); }
  HLML_INLINEF float4 xwxz() const { return shufflef4(*this, 0, 3, 0, 2); }
  HLML_INLINEF float4 xwxw() const { return shufflef4(*this, 0, 3, 0, 3); }
  HLML_INLINEF float4 xwyx() const { return shufflef4(*this, 0, 3, 1, 0); }
  HLML_INLINEF float4 xwyy() const { return shufflef4(*this, 0, 3, 1, 1); }
  HLML_INLINEF float4 xwyz() const { return shufflef4(*this, 0, 3, 1, 2); }
  HLML_INLINEF float4 xwyw() const { return shufflef4(*this, 0, 3, 1, 3); }
  HLML_INLINEF float4 xwzx() const { return shufflef4(*this, 0, 3, 2, 0); }
  HLML_INLINEF float4 xwzy() const { return shufflef4(*this, 0, 3, 2, 1); }
  HLML_INLINEF float4 xwzz() const { return shufflef4(*this, 0, 3, 2, 2); }
  HLML_INLINEF float4 xwzw() const { return shufflef4(*this, 0, 3, 2, 3); }
  HLML_INLINEF float4 xwwx() const { return shufflef4(*this, 0, 3, 3, 0); }
  HLML_INLINEF float4 xwwy() const { return shufflef4(*this, 0, 3, 3, 1); }
  HLML_INLINEF float4 xwwz() const { return shufflef4(*this, 0, 3, 3, 2); }
  HLML_INLINEF float4 xwww() const { return shufflef4(*this, 0, 3, 3, 3); }

  HLML_INLINEF float4 yxxx() const { return shufflef4(*this, 1, 0, 0, 0); }
  HLML_INLINEF float4 yxxy() const { return shufflef4(*this, 1, 0, 0, 1); }
  HLML_INLINEF float4 yxxz() const { return shufflef4(*this, 1, 0, 0, 2); }
  HLML_INLINEF float4 yxxw() const { return shufflef4(*this, 1, 0, 0, 3); }
  HLML_INLINEF float4 yxyx() const { return shufflef4(*this, 1, 0, 1, 0); }
  HLML_INLINEF float4 yxyy() const { return shufflef4(*this, 1, 0, 1, 1); }
  HLML_INLINEF float4 yxyz() const { return shufflef4(*this, 1, 0, 1, 2); }
  HLML_INLINEF float4 yxyw() const { return shufflef4(*this, 1, 0, 1, 3); }
  HLML_INLINEF float4 yxzx() const { return shufflef4(*this, 1, 0, 2, 0); }
  HLML_INLINEF float4 yxzy() const { return shufflef4(*this, 1, 0, 2, 1); }
  HLML_INLINEF float4 yxzz() const { return shufflef4(*this, 1, 0, 2, 2); }
  HLML_INLINEF float4 yxzw() const { return shufflef4(*this, 1, 0, 2, 3); }
  HLML_INLINEF float4 yxwx() const { return shufflef4(*this, 1, 0, 3, 0); }
  HLML_INLINEF float4 yxwy() const { return shufflef4(*this, 1, 0, 3, 1); }
  HLML_INLINEF float4 yxwz() const { return shufflef4(*this, 1, 0, 3, 2); }
  HLML_INLINEF float4 yxww() const { return shufflef4(*this, 1, 0, 3, 3); }
  HLML_INLINEF float4 yyxx() const { return shufflef4(*this, 1, 1, 0, 0); }
  HLML_INLINEF float4 yyxy() const { return shufflef4(*this, 1, 1, 0, 1); }
  HLML_INLINEF float4 yyxz() const { return shufflef4(*this, 1, 1, 0, 2); }
  HLML_INLINEF float4 yyxw() const { return shufflef4(*this, 1, 1, 0, 3); }
  HLML_INLINEF float4 yyyx() const { return shufflef4(*this, 1, 1, 1, 0); }
  HLML_INLINEF float4 yyyy() const { return shufflef4(*this, 1, 1, 1, 1); }
  HLML_INLINEF float4 yyyz() const { return shufflef4(*this, 1, 1, 1, 2); }
  HLML_INLINEF float4 yyyw() const { return shufflef4(*this, 1, 1, 1, 3); }
  HLML_INLINEF float4 yyzx() const { return shufflef4(*this, 1, 1, 2, 0); }
  HLML_INLINEF float4 yyzy() const { return shufflef4(*this, 1, 1, 2, 1); }
  HLML_INLINEF float4 yyzz() const { return shufflef4(*this, 1, 1, 2, 2); }
  HLML_INLINEF float4 yyzw() const { return shufflef4(*this, 1, 1, 2, 3); }
  HLML_INLINEF float4 yywx() const { return shufflef4(*this, 1, 1, 3, 0); }
  HLML_INLINEF float4 yywy() const { return shufflef4(*this, 1, 1, 3, 1); }
  HLML_INLINEF float4 yywz() const { return shufflef4(*this, 1, 1, 3, 2); }
  HLML_INLINEF float4 yyww() const { return shufflef4(*this, 1, 1, 3, 3); }
  HLML_INLINEF float4 yzxx() const { return shufflef4(*this, 1, 2, 0, 0); }
  HLML_INLINEF float4 yzxy() const { return shufflef4(*this, 1, 2, 0, 1); }
  HLML_INLINEF float4 yzxz() const { return shufflef4(*this, 1, 2, 0, 2); }
  HLML_INLINEF float4 yzxw() const { return shufflef4(*this, 1, 2, 0, 3); }
  HLML_INLINEF float4 yzyx() const { return shufflef4(*this, 1, 2, 1, 0); }
  HLML_INLINEF float4 yzyy() const { return shufflef4(*this, 1, 2, 1, 1); }
  HLML_INLINEF float4 yzyz() const { return shufflef4(*this, 1, 2, 1, 2); }
  HLML_INLINEF float4 yzyw() const { return shufflef4(*this, 1, 2, 1, 3); }
  HLML_INLINEF float4 yzzx() const { return shufflef4(*this, 1, 2, 2, 0); }
  HLML_INLINEF float4 yzzy() const { return shufflef4(*this, 1, 2, 2, 1); }
  HLML_INLINEF float4 yzzz() const { return shufflef4(*this, 1, 2, 2, 2); }
  HLML_INLINEF float4 yzzw() const { return shufflef4(*this, 1, 2, 2, 3); }
  HLML_INLINEF float4 yzwx() const { return shufflef4(*this, 1, 2, 3, 0); }
  HLML_INLINEF float4 yzwy() const { return shufflef4(*this, 1, 2, 3, 1); }
  HLML_INLINEF float4 yzwz() const { return shufflef4(*this, 1, 2, 3, 2); }
  HLML_INLINEF float4 yzww() const { return shufflef4(*this, 1, 2, 3, 3); }
  HLML_INLINEF float4 ywxx() const { return shufflef4(*this, 1, 3, 0, 0); }
  HLML_INLINEF float4 ywxy() const { return shufflef4(*this, 1, 3, 0, 1); }
  HLML_INLINEF float4 ywxz() const { return shufflef4(*this, 1, 3, 0, 2); }
  HLML_INLINEF float4 ywxw() const { return shufflef4(*this, 1, 3, 0, 3); }
  HLML_INLINEF float4 ywyx() const { return shufflef4(*this, 1, 3, 1, 0); }
  HLML_INLINEF float4 ywyy() const { return shufflef4(*this, 1, 3, 1, 1); }
  HLML_INLINEF float4 ywyz() const { return shufflef4(*this, 1, 3, 1, 2); }
  HLML_INLINEF float4 ywyw() const { return shufflef4(*this, 1, 3, 1, 3); }
  HLML_INLINEF float4 ywzx() const { return shufflef4(*this, 1, 3, 2, 0); }
  HLML_INLINEF float4 ywzy() const { return shufflef4(*this, 1, 3, 2, 1); }
  HLML_INLINEF float4 ywzz() const { return shufflef4(*this, 1, 3, 2, 2); }
  HLML_INLINEF float4 ywzw() const { return shufflef4(*this, 1, 3, 2, 3); }
  HLML_INLINEF float4 ywwx() const { return shufflef4(*this, 1, 3, 3, 0); }
  HLML_INLINEF float4 ywwy() const { return shufflef4(*this, 1, 3, 3, 1); }
  HLML_INLINEF float4 ywwz() const { return shufflef4(*this, 1, 3, 3, 2); }
  HLML_INLINEF float4 ywww() const { return shufflef4(*this, 1, 3, 3, 3); }

  HLML_INLINEF float4 zxxx() const { return shufflef4(*this, 2, 0, 0, 0); }
  HLML_INLINEF float4 zxxy() const { return shufflef4(*this, 2, 0, 0, 1); }
  HLML_INLINEF float4 zxxz() const { return shufflef4(*this, 2, 0, 0, 2); }
  HLML_INLINEF float4 zxxw() const { return shufflef4(*this, 2, 0, 0, 3); }
  HLML_INLINEF float4 zxyx() const { return shufflef4(*this, 2, 0, 1, 0); }
  HLML_INLINEF float4 zxyy() const { return shufflef4(*this, 2, 0, 1, 1); }
  HLML_INLINEF float4 zxyz() const { return shufflef4(*this, 2, 0, 1, 2); }
  HLML_INLINEF float4 zxyw() const { return shufflef4(*this, 2, 0, 1, 3); }
  HLML_INLINEF float4 zxzx() const { return shufflef4(*this, 2, 0, 2, 0); }
  HLML_INLINEF float4 zxzy() const { return shufflef4(*this, 2, 0, 2, 1); }
  HLML_INLINEF float4 zxzz() const { return shufflef4(*this, 2, 0, 2, 2); }
  HLML_INLINEF float4 zxzw() const { return shufflef4(*this, 2, 0, 2, 3); }
  HLML_INLINEF float4 zxwx() const { return shufflef4(*this, 2, 0, 3, 0); }
  HLML_INLINEF float4 zxwy() const { return shufflef4(*this, 2, 0, 3, 1); }
  HLML_INLINEF float4 zxwz() const { return shufflef4(*this, 2, 0, 3, 2); }
  HLML_INLINEF float4 zxww() const { return shufflef4(*this, 2, 0, 3, 3); }
  HLML_INLINEF float4 zyxx() const { return shufflef4(*this, 2, 1, 0, 0); }
  HLML_INLINEF float4 zyxy() const { return shufflef4(*this, 2, 1, 0, 1); }
  HLML_INLINEF float4 zyxz() const { return shufflef4(*this, 2, 1, 0, 2); }
  HLML_INLINEF float4 zyxw() const { return shufflef4(*this, 2, 1, 0, 3); }
  HLML_INLINEF float4 zyyx() const { return shufflef4(*this, 2, 1, 1, 0); }
  HLML_INLINEF float4 zyyy() const { return shufflef4(*this, 2, 1, 1, 1); }
  HLML_INLINEF float4 zyyz() const { return shufflef4(*this, 2, 1, 1, 2); }
  HLML_INLINEF float4 zyyw() const { return shufflef4(*this, 2, 1, 1, 3); }
  HLML_INLINEF float4 zyzx() const { return shufflef4(*this, 2, 1, 2, 0); }
  HLML_INLINEF float4 zyzy() const { return shufflef4(*this, 2, 1, 2, 1); }
  HLML_INLINEF float4 zyzz() const { return shufflef4(*this, 2, 1, 2, 2); }
  HLML_INLINEF float4 zyzw() const { return shufflef4(*this, 2, 1, 2, 3); }
  HLML_INLINEF float4 zywx() const { return shufflef4(*this, 2, 1, 3, 0); }
  HLML_INLINEF float4 zywy() const { return shufflef4(*this, 2, 1, 3, 1); }
  HLML_INLINEF float4 zywz() const { return shufflef4(*this, 2, 1, 3, 2); }
  HLML_INLINEF float4 zyww() const { return shufflef4(*this, 2, 1, 3, 3); }
  HLML_INLINEF float4 zzxx() const { return shufflef4(*this, 2, 2, 0, 0); }
  HLML_INLINEF float4 zzxy() const { return shufflef4(*this, 2, 2, 0, 1); }
  HLML_INLINEF float4 zzxz() const { return shufflef4(*this, 2, 2, 0, 2); }
  HLML_INLINEF float4 zzxw() const { return shufflef4(*this, 2, 2, 0, 3); }
  HLML_INLINEF float4 zzyx() const { return shufflef4(*this, 2, 2, 1, 0); }
  HLML_INLINEF float4 zzyy() const { return shufflef4(*this, 2, 2, 1, 1); }
  HLML_INLINEF float4 zzyz() const { return shufflef4(*this, 2, 2, 1, 2); }
  HLML_INLINEF float4 zzyw() const { return shufflef4(*this, 2, 2, 1, 3); }
  HLML_INLINEF float4 zzzx() const { return shufflef4(*this, 2, 2, 2, 0); }
  HLML_INLINEF float4 zzzy() const { return shufflef4(*this, 2, 2, 2, 1); }
  HLML_INLINEF float4 zzzz() const { return shufflef4(*this, 2, 2, 2, 2); }
  HLML_INLINEF float4 zzzw() const { return shufflef4(*this, 2, 2, 2, 3); }
  HLML_INLINEF float4 zzwx() const { return shufflef4(*this, 2, 2, 3, 0); }
  HLML_INLINEF float4 zzwy() const { return shufflef4(*this, 2, 2, 3, 1); }
  HLML_INLINEF float4 zzwz() const { return shufflef4(*this, 2, 2, 3, 2); }
  HLML_INLINEF float4 zzww() const { return shufflef4(*this, 2, 2, 3, 3); }
  HLML_INLINEF float4 zwxx() const { return shufflef4(*this, 2, 3, 0, 0); }
  HLML_INLINEF float4 zwxy() const { return shufflef4(*this, 2, 3, 0, 1); }
  HLML_INLINEF float4 zwxz() const { return shufflef4(*this, 2, 3, 0, 2); }
  HLML_INLINEF float4 zwxw() const { return shufflef4(*this, 2, 3, 0, 3); }
  HLML_INLINEF float4 zwyx() const { return shufflef4(*this, 2, 3, 1, 0); }
  HLML_INLINEF float4 zwyy() const { return shufflef4(*this, 2, 3, 1, 1); }
  HLML_INLINEF float4 zwyz() const { return shufflef4(*this, 2, 3, 1, 2); }
  HLML_INLINEF float4 zwyw() const { return shufflef4(*this, 2, 3, 1, 3); }
  HLML_INLINEF float4 zwzx() const { return shufflef4(*this, 2, 3, 2, 0); }
  HLML_INLINEF float4 zwzy() const { return shufflef4(*this, 2, 3, 2, 1); }
  HLML_INLINEF float4 zwzz() const { return shufflef4(*this, 2, 3, 2, 2); }
  HLML_INLINEF float4 zwzw() const { return shufflef4(*this, 2, 3, 2, 3); }
  HLML_INLINEF float4 zwwx() const { return shufflef4(*this, 2, 3, 3, 0); }
  HLML_INLINEF float4 zwwy() const { return shufflef4(*this, 2, 3, 3, 1); }
  HLML_INLINEF float4 zwwz() const { return shufflef4(*this, 2, 3, 3, 2); }
  HLML_INLINEF float4 zwww() const { return shufflef4(*this, 2, 3, 3, 3); }

  HLML_INLINEF float4 wxxx() const { return shufflef4(*this, 3, 0, 0, 0); }
  HLML_INLINEF float4 wxxy() const { return shufflef4(*this, 3, 0, 0, 1); }
  HLML_INLINEF float4 wxxz() const { return shufflef4(*this, 3, 0, 0, 2); }
  HLML_INLINEF float4 wxxw() const { return shufflef4(*this, 3, 0, 0, 3); }
  HLML_INLINEF float4 wxyx() const { return shufflef4(*this, 3, 0, 1, 0); }
  HLML_INLINEF float4 wxyy() const { return shufflef4(*this, 3, 0, 1, 1); }
  HLML_INLINEF float4 wxyz() const { return shufflef4(*this, 3, 0, 1, 2); }
  HLML_INLINEF float4 wxyw() const { return shufflef4(*this, 3, 0, 1, 3); }
  HLML_INLINEF float4 wxzx() const { return shufflef4(*this, 3, 0, 2, 0); }
  HLML_INLINEF float4 wxzy() const { return shufflef4(*this, 3, 0, 2, 1); }
  HLML_INLINEF float4 wxzz() const { return shufflef4(*this, 3, 0, 2, 2); }
  HLML_INLINEF float4 wxzw() const { return shufflef4(*this, 3, 0, 2, 3); }
  HLML_INLINEF float4 wxwx() const { return shufflef4(*this, 3, 0, 3, 0); }
  HLML_INLINEF float4 wxwy() const { return shufflef4(*this, 3, 0, 3, 1); }
  HLML_INLINEF float4 wxwz() const { return shufflef4(*this, 3, 0, 3, 2); }
  HLML_INLINEF float4 wxww() const { return shufflef4(*this, 3, 0, 3, 3); }
  HLML_INLINEF float4 wyxx() const { return shufflef4(*this, 3, 1, 0, 0); }
  HLML_INLINEF float4 wyxy() const { return shufflef4(*this, 3, 1, 0, 1); }
  HLML_INLINEF float4 wyxz() const { return shufflef4(*this, 3, 1, 0, 2); }
  HLML_INLINEF float4 wyxw() const { return shufflef4(*this, 3, 1, 0, 3); }
  HLML_INLINEF float4 wyyx() const { return shufflef4(*this, 3, 1, 1, 0); }
  HLML_INLINEF float4 wyyy() const { return shufflef4(*this, 3, 1, 1, 1); }
  HLML_INLINEF float4 wyyz() const { return shufflef4(*this, 3, 1, 1, 2); }
  HLML_INLINEF float4 wyyw() const { return shufflef4(*this, 3, 1, 1, 3); }
  HLML_INLINEF float4 wyzx() const { return shufflef4(*this, 3, 1, 2, 0); }
  HLML_INLINEF float4 wyzy() const { return shufflef4(*this, 3, 1, 2, 1); }
  HLML_INLINEF float4 wyzz() const { return shufflef4(*this, 3, 1, 2, 2); }
  HLML_INLINEF float4 wyzw() const { return shufflef4(*this, 3, 1, 2, 3); }
  HLML_INLINEF float4 wywx() const { return shufflef4(*this, 3, 1, 3, 0); }
  HLML_INLINEF float4 wywy() const { return shufflef4(*this, 3, 1, 3, 1); }
  HLML_INLINEF float4 wywz() const { return shufflef4(*this, 3, 1, 3, 2); }
  HLML_INLINEF float4 wyww() const { return shufflef4(*this, 3, 1, 3, 3); }
  HLML_INLINEF float4 wzxx() const { return shufflef4(*this, 3, 2, 0, 0); }
  HLML_INLINEF float4 wzxy() const { return shufflef4(*this, 3, 2, 0, 1); }
  HLML_INLINEF float4 wzxz() const { return shufflef4(*this, 3, 2, 0, 2); }
  HLML_INLINEF float4 wzxw() const { return shufflef4(*this, 3, 2, 0, 3); }
  HLML_INLINEF float4 wzyx() const { return shufflef4(*this, 3, 2, 1, 0); }
  HLML_INLINEF float4 wzyy() const { return shufflef4(*this, 3, 2, 1, 1); }
  HLML_INLINEF float4 wzyz() const { return shufflef4(*this, 3, 2, 1, 2); }
  HLML_INLINEF float4 wzyw() const { return shufflef4(*this, 3, 2, 1, 3); }
  HLML_INLINEF float4 wzzx() const { return shufflef4(*this, 3, 2, 2, 0); }
  HLML_INLINEF float4 wzzy() const { return shufflef4(*this, 3, 2, 2, 1); }
  HLML_INLINEF float4 wzzz() const { return shufflef4(*this, 3, 2, 2, 2); }
  HLML_INLINEF float4 wzzw() const { return shufflef4(*this, 3, 2, 2, 3); }
  HLML_INLINEF float4 wzwx() const { return shufflef4(*this, 3, 2, 3, 0); }
  HLML_INLINEF float4 wzwy() const { return shufflef4(*this, 3, 2, 3, 1); }
  HLML_INLINEF float4 wzwz() const { return shufflef4(*this, 3, 2, 3, 2); }
  HLML_INLINEF float4 wzww() const { return shufflef4(*this, 3, 2, 3, 3); }
  HLML_INLINEF float4 wwxx() const { return shufflef4(*this, 3, 3, 0, 0); }
  HLML_INLINEF float4 wwxy() const { return shufflef4(*this, 3, 3, 0, 1); }
  HLML_INLINEF float4 wwxz() const { return shufflef4(*this, 3, 3, 0, 2); }
  HLML_INLINEF float4 wwxw() const { return shufflef4(*this, 3, 3, 0, 3); }
  HLML_INLINEF float4 wwyx() const { return shufflef4(*this, 3, 3, 1, 0); }
  HLML_INLINEF float4 wwyy() const { return shufflef4(*this, 3, 3, 1, 1); }
  HLML_INLINEF float4 wwyz() const { return shufflef4(*this, 3, 3, 1, 2); }
  HLML_INLINEF float4 wwyw() const { return shufflef4(*this, 3, 3, 1, 3); }
  HLML_INLINEF float4 wwzx() const { return shufflef4(*this, 3, 3, 2, 0); }
  HLML_INLINEF float4 wwzy() const { return shufflef4(*this, 3, 3, 2, 1); }
  HLML_INLINEF float4 wwzz() const { return shufflef4(*this, 3, 3, 2, 2); }
  HLML_INLINEF float4 wwzw() const { return shufflef4(*this, 3, 3, 2, 3); }
  HLML_INLINEF float4 wwwx() const { return shufflef4(*this, 3, 3, 3, 0); }
  HLML_INLINEF float4 wwwy() const { return shufflef4(*this, 3, 3, 3, 1); }
  HLML_INLINEF float4 wwwz() const { return shufflef4(*this, 3, 3, 3, 2); }
  HLML_INLINEF float4 wwww() const { return shufflef4(*this, 3, 3, 3, 3); }

  HLML_INLINEF F32 r() const { return x(); }
  HLML_INLINEF F32 g() const { return y(); }
  HLML_INLINEF F32 b() const { return z(); }
  HLML_INLINEF F32 a() const { return w(); }

  HLML_INLINEF float2 rr() const { return xx(); }
  HLML_INLINEF float2 rg() const { return xy(); }
  HLML_INLINEF float2 rb() const { return xz(); }
  HLML_INLINEF float2 ra() const { return xw(); }
  HLML_INLINEF float2 gr() const { return yx(); }
  HLML_INLINEF float2 gg() const { return yy(); }
  HLML_INLINEF float2 gb() const { return yz(); }
  HLML_INLINEF float2 ga() const { return yw(); }
  HLML_INLINEF float2 br() const { return zx(); }
  HLML_INLINEF float2 bg() const { return zy(); }
  HLML_INLINEF float2 bb() const { return zz(); }
  HLML_INLINEF float2 ba() const { return zw(); }
  HLML_INLINEF float2 ar() const { return wx(); }
  HLML_INLINEF float2 ag() const { return wy(); }
  HLML_INLINEF float2 ab() const { return wz(); }
  HLML_INLINEF float2 aa() const { return ww(); }

  HLML_INLINEF float3 rrr() const { return xxx(); }
  HLML_INLINEF float3 rrg() const { return xxy(); }
  HLML_INLINEF float3 rrb() const { return xxz(); }
  HLML_INLINEF float3 rra() const { return xxw(); }
  HLML_INLINEF float3 rgr() const { return xyx(); }
  HLML_INLINEF float3 rgg() const { return xyy(); }
  HLML_INLINEF float3 rgb() const { return xyz(); }
  HLML_INLINEF float3 rga() const { return xyw(); }
  HLML_INLINEF float3 rbr() const { return xzx(); }
  HLML_INLINEF float3 rbg() const { return xzy(); }
  HLML_INLINEF float3 rbb() const { return xzz(); }
  HLML_INLINEF float3 rba() const { return xzw(); }
  HLML_INLINEF float3 rar() const { return xwx(); }
  HLML_INLINEF float3 rag() const { return xwy(); }
  HLML_INLINEF float3 rab() const { return xwz(); }
  HLML_INLINEF float3 raa() const { return xww(); }
  HLML_INLINEF float3 grr() const { return yxx(); }
  HLML_INLINEF float3 grg() const { return yxy(); }
  HLML_INLINEF float3 grb() const { return yxz(); }
  HLML_INLINEF float3 gra() const { return yxw(); }
  HLML_INLINEF float3 ggr() const { return yyx(); }
  HLML_INLINEF float3 ggg() const { return yyy(); }
  HLML_INLINEF float3 ggb() const { return yyz(); }
  HLML_INLINEF float3 gga() const { return yyw(); }
  HLML_INLINEF float3 gbr() const { return yzx(); }
  HLML_INLINEF float3 gbg() const { return yzy(); }
  HLML_INLINEF float3 gbb() const { return yzz(); }
  HLML_INLINEF float3 gba() const { return yzw(); }
  HLML_INLINEF float3 gar() const { return ywx(); }
  HLML_INLINEF float3 gag() const { return ywy(); }
  HLML_INLINEF float3 gab() const { return ywz(); }
  HLML_INLINEF float3 gaa() const { return yww(); }
  HLML_INLINEF float3 brr() const { return zxx(); }
  HLML_INLINEF float3 brg() const { return zxy(); }
  HLML_INLINEF float3 brb() const { return zxz(); }
  HLML_INLINEF float3 bra() const { return zxw(); }
  HLML_INLINEF float3 bgr() const { return zyx(); }
  HLML_INLINEF float3 bgg() const { return zyy(); }
  HLML_INLINEF float3 bgb() const { return zyz(); }
  HLML_INLINEF float3 bga() const { return zyw(); }
  HLML_INLINEF float3 bbr() const { return zzx(); }
  HLML_INLINEF float3 bbg() const { return zzy(); }
  HLML_INLINEF float3 bbb() const { return zzz(); }
  HLML_INLINEF float3 bba() const { return zzw(); }
  HLML_INLINEF float3 bar() const { return zwx(); }
  HLML_INLINEF float3 bag() const { return zwy(); }
  HLML_INLINEF float3 bab() const { return zwz(); }
  HLML_INLINEF float3 baa() const { return zww(); }

  HLML_INLINEF float4 rrrr() const { return xxxx(); }
  HLML_INLINEF float4 rrrg() const { return xxxy(); }
  HLML_INLINEF float4 rrrb() const { return xxxz(); }
  HLML_INLINEF float4 rrra() const { return xxxw(); }
  HLML_INLINEF float4 rrgr() const { return xxyx(); }
  HLML_INLINEF float4 rrgg() const { return xxyy(); }
  HLML_INLINEF float4 rrgb() const { return xxyz(); }
  HLML_INLINEF float4 rrga() const { return xxyw(); }
  HLML_INLINEF float4 rrbr() const { return xxzx(); }
  HLML_INLINEF float4 rrbg() const { return xxzy(); }
  HLML_INLINEF float4 rrbb() const { return xxzz(); }
  HLML_INLINEF float4 rrba() const { return xxzw(); }
  HLML_INLINEF float4 rrar() const { return xxwx(); }
  HLML_INLINEF float4 rrag() const { return xxwy(); }
  HLML_INLINEF float4 rrab() const { return xxwz(); }
  HLML_INLINEF float4 rraa() const { return xxww(); }
  HLML_INLINEF float4 rgrr() const { return xyxx(); }
  HLML_INLINEF float4 rgrg() const { return xyxy(); }
  HLML_INLINEF float4 rgrb() const { return xyxz(); }
  HLML_INLINEF float4 rgra() const { return xyxy(); }
  HLML_INLINEF float4 rggr() const { return xyyx(); }
  HLML_INLINEF float4 rggg() const { return xyyy(); }
  HLML_INLINEF float4 rggb() const { return xyyz(); }
  HLML_INLINEF float4 rgga() const { return xyyw(); }
  HLML_INLINEF float4 rgbr() const { return xyzx(); }
  HLML_INLINEF float4 rgbg() const { return xyzy(); }
  HLML_INLINEF float4 rgbb() const { return xyzz(); }
  HLML_INLINEF float4 rgba() const { return xyzw(); }
  HLML_INLINEF float4 rgar() const { return xywx(); }
  HLML_INLINEF float4 rgag() const { return xywy(); }
  HLML_INLINEF float4 rgab() const { return xywz(); }
  HLML_INLINEF float4 rgaa() const { return xyww(); }
  HLML_INLINEF float4 rbrr() const { return xzxx(); }
  HLML_INLINEF float4 rbrg() const { return xzxy(); }
  HLML_INLINEF float4 rbrb() const { return xzxz(); }
  HLML_INLINEF float4 rbra() const { return xzxw(); }
  HLML_INLINEF float4 rbgr() const { return xzyx(); }
  HLML_INLINEF float4 rbgg() const { return xzyy(); }
  HLML_INLINEF float4 rbgb() const { return xzyz(); }
  HLML_INLINEF float4 rbga() const { return xzyw(); }
  HLML_INLINEF float4 rbbr() const { return xzzx(); }
  HLML_INLINEF float4 rbbg() const { return xzzy(); }
  HLML_INLINEF float4 rbbb() const { return xzzz(); }
  HLML_INLINEF float4 rbba() const { return xzzw(); }
  HLML_INLINEF float4 rbar() const { return xzwx(); }
  HLML_INLINEF float4 rbag() const { return xzwy(); }
  HLML_INLINEF float4 rbab() const { return xzwz(); }
  HLML_INLINEF float4 rbaa() const { return xzww(); }
  HLML_INLINEF float4 rarr() const { return xwxx(); }
  HLML_INLINEF float4 rarg() const { return xwxy(); }
  HLML_INLINEF float4 rarb() const { return xwxz(); }
  HLML_INLINEF float4 rara() const { return xwxw(); }
  HLML_INLINEF float4 ragr() const { return xwyx(); }
  HLML_INLINEF float4 ragg() const { return xwyy(); }
  HLML_INLINEF float4 ragb() const { return xwyz(); }
  HLML_INLINEF float4 raga() const { return xwyw(); }
  HLML_INLINEF float4 rabr() const { return xwzx(); }
  HLML_INLINEF float4 rabg() const { return xwzy(); }
  HLML_INLINEF float4 rabb() const { return xwzz(); }
  HLML_INLINEF float4 raba() const { return xwzw(); }
  HLML_INLINEF float4 raar() const { return xwwx(); }
  HLML_INLINEF float4 raag() const { return xwwy(); }
  HLML_INLINEF float4 raab() const { return xwwz(); }
  HLML_INLINEF float4 raaa() const { return xwww(); }

  HLML_INLINEF float4 grrr() const { return yxxx(); }
  HLML_INLINEF float4 grrg() const { return yxxy(); }
  HLML_INLINEF float4 grrb() const { return yxxz(); }
  HLML_INLINEF float4 grra() const { return yxxw(); }
  HLML_INLINEF float4 grgr() const { return yxyx(); }
  HLML_INLINEF float4 grgg() const { return yxyy(); }
  HLML_INLINEF float4 grgb() const { return yxyz(); }
  HLML_INLINEF float4 grga() const { return yxyw(); }
  HLML_INLINEF float4 grbr() const { return yxzx(); }
  HLML_INLINEF float4 grbg() const { return yxzy(); }
  HLML_INLINEF float4 grbb() const { return yxzz(); }
  HLML_INLINEF float4 grba() const { return yxzw(); }
  HLML_INLINEF float4 grar() const { return yxwx(); }
  HLML_INLINEF float4 grag() const { return yxwy(); }
  HLML_INLINEF float4 grab() const { return yxwz(); }
  HLML_INLINEF float4 graa() const { return yxww(); }
  HLML_INLINEF float4 ggrr() const { return yyxx(); }
  HLML_INLINEF float4 ggrg() const { return yyxy(); }
  HLML_INLINEF float4 ggrb() const { return yyxz(); }
  HLML_INLINEF float4 ggra() const { return yyxy(); }
  HLML_INLINEF float4 gggr() const { return yyyx(); }
  HLML_INLINEF float4 gggg() const { return yyyy(); }
  HLML_INLINEF float4 gggb() const { return yyyz(); }
  HLML_INLINEF float4 ggga() const { return yyyw(); }
  HLML_INLINEF float4 ggbr() const { return yyzx(); }
  HLML_INLINEF float4 ggbg() const { return yyzy(); }
  HLML_INLINEF float4 ggbb() const { return yyzz(); }
  HLML_INLINEF float4 ggba() const { return yyzw(); }
  HLML_INLINEF float4 ggar() const { return yywx(); }
  HLML_INLINEF float4 ggag() const { return yywy(); }
  HLML_INLINEF float4 ggab() const { return yywz(); }
  HLML_INLINEF float4 ggaa() const { return yyww(); }
  HLML_INLINEF float4 gbrr() const { return yzxx(); }
  HLML_INLINEF float4 gbrg() const { return yzxy(); }
  HLML_INLINEF float4 gbrb() const { return yzxz(); }
  HLML_INLINEF float4 gbra() const { return yzxw(); }
  HLML_INLINEF float4 gbgr() const { return yzyx(); }
  HLML_INLINEF float4 gbgg() const { return yzyy(); }
  HLML_INLINEF float4 gbgb() const { return yzyz(); }
  HLML_INLINEF float4 gbga() const { return yzyw(); }
  HLML_INLINEF float4 gbbr() const { return yzzx(); }
  HLML_INLINEF float4 gbbg() const { return yzzy(); }
  HLML_INLINEF float4 gbbb() const { return yzzz(); }
  HLML_INLINEF float4 gbba() const { return yzzw(); }
  HLML_INLINEF float4 gbar() const { return yzwx(); }
  HLML_INLINEF float4 gbag() const { return yzwy(); }
  HLML_INLINEF float4 gbab() const { return yzwz(); }
  HLML_INLINEF float4 gbaa() const { return yzww(); }
  HLML_INLINEF float4 garr() const { return ywxx(); }
  HLML_INLINEF float4 garg() const { return ywxy(); }
  HLML_INLINEF float4 garb() const { return ywxz(); }
  HLML_INLINEF float4 gara() const { return ywxw(); }
  HLML_INLINEF float4 gagr() const { return ywyx(); }
  HLML_INLINEF float4 gagg() const { return ywyy(); }
  HLML_INLINEF float4 gagb() const { return ywyz(); }
  HLML_INLINEF float4 gaga() const { return ywyw(); }
  HLML_INLINEF float4 gabr() const { return ywzx(); }
  HLML_INLINEF float4 gabg() const { return ywzy(); }
  HLML_INLINEF float4 gabb() const { return ywzz(); }
  HLML_INLINEF float4 gaba() const { return ywzw(); }
  HLML_INLINEF float4 gaar() const { return ywwx(); }
  HLML_INLINEF float4 gaag() const { return ywwy(); }
  HLML_INLINEF float4 gaab() const { return ywwz(); }
  HLML_INLINEF float4 gaaa() const { return ywww(); }

  HLML_INLINEF float4 brrr() const { return zxxx(); }
  HLML_INLINEF float4 brrg() const { return zxxy(); }
  HLML_INLINEF float4 brrb() const { return zxxz(); }
  HLML_INLINEF float4 brra() const { return zxxw(); }
  HLML_INLINEF float4 brgr() const { return zxyx(); }
  HLML_INLINEF float4 brgg() const { return zxyy(); }
  HLML_INLINEF float4 brgb() const { return zxyz(); }
  HLML_INLINEF float4 brga() const { return zxyw(); }
  HLML_INLINEF float4 brbr() const { return zxzx(); }
  HLML_INLINEF float4 brbg() const { return zxzy(); }
  HLML_INLINEF float4 brbb() const { return zxzz(); }
  HLML_INLINEF float4 brba() const { return zxzw(); }
  HLML_INLINEF float4 brar() const { return zxwx(); }
  HLML_INLINEF float4 brag() const { return zxwy(); }
  HLML_INLINEF float4 brab() const { return zxwz(); }
  HLML_INLINEF float4 braa() const { return zxww(); }
  HLML_INLINEF float4 bgrr() const { return zyxx(); }
  HLML_INLINEF float4 bgrg() const { return zyxy(); }
  HLML_INLINEF float4 bgrb() const { return zyxz(); }
  HLML_INLINEF float4 bgra() const { return zyxy(); }
  HLML_INLINEF float4 bggr() const { return zyyx(); }
  HLML_INLINEF float4 bggg() const { return zyyy(); }
  HLML_INLINEF float4 bggb() const { return zyyz(); }
  HLML_INLINEF float4 bgga() const { return zyyw(); }
  HLML_INLINEF float4 bgbr() const { return zyzx(); }
  HLML_INLINEF float4 bgbg() const { return zyzy(); }
  HLML_INLINEF float4 bgbb() const { return zyzz(); }
  HLML_INLINEF float4 bgba() const { return zyzw(); }
  HLML_INLINEF float4 bgar() const { return zywx(); }
  HLML_INLINEF float4 bgag() const { return zywy(); }
  HLML_INLINEF float4 bgab() const { return zywz(); }
  HLML_INLINEF float4 bgaa() const { return zyww(); }
  HLML_INLINEF float4 bbrr() const { return zzxx(); }
  HLML_INLINEF float4 bbrg() const { return zzxy(); }
  HLML_INLINEF float4 bbrb() const { return zzxz(); }
  HLML_INLINEF float4 bbra() const { return zzxw(); }
  HLML_INLINEF float4 bbgr() const { return zzyx(); }
  HLML_INLINEF float4 bbgg() const { return zzyy(); }
  HLML_INLINEF float4 bbgb() const { return zzyz(); }
  HLML_INLINEF float4 bbga() const { return zzyw(); }
  HLML_INLINEF float4 bbbr() const { return zzzx(); }
  HLML_INLINEF float4 bbbg() const { return zzzy(); }
  HLML_INLINEF float4 bbbb() const { return zzzz(); }
  HLML_INLINEF float4 bbba() const { return zzzw(); }
  HLML_INLINEF float4 bbar() const { return zzwx(); }
  HLML_INLINEF float4 bbag() const { return zzwy(); }
  HLML_INLINEF float4 bbab() const { return zzwz(); }
  HLML_INLINEF float4 bbaa() const { return zzww(); }
  HLML_INLINEF float4 barr() const { return zwxx(); }
  HLML_INLINEF float4 barg() const { return zwxy(); }
  HLML_INLINEF float4 barb() const { return zwxz(); }
  HLML_INLINEF float4 bara() const { return zwxw(); }
  HLML_INLINEF float4 bagr() const { return zwyx(); }
  HLML_INLINEF float4 bagg() const { return zwyy(); }
  HLML_INLINEF float4 bagb() const { return zwyz(); }
  HLML_INLINEF float4 baga() const { return zwyw(); }
  HLML_INLINEF float4 babr() const { return zwzx(); }
  HLML_INLINEF float4 babg() const { return zwzy(); }
  HLML_INLINEF float4 babb() const { return zwzz(); }
  HLML_INLINEF float4 baba() const { return zwzw(); }
  HLML_INLINEF float4 baar() const { return zwwx(); }
  HLML_INLINEF float4 baag() const { return zwwy(); }
  HLML_INLINEF float4 baab() const { return zwwz(); }
  HLML_INLINEF float4 baaa() const { return zwww(); }

  HLML_INLINEF float4 arrr() const { return wxxx(); }
  HLML_INLINEF float4 arrg() const { return wxxy(); }
  HLML_INLINEF float4 arrb() const { return wxxz(); }
  HLML_INLINEF float4 arra() const { return wxxw(); }
  HLML_INLINEF float4 argr() const { return wxyx(); }
  HLML_INLINEF float4 argg() const { return wxyy(); }
  HLML_INLINEF float4 argb() const { return wxyz(); }
  HLML_INLINEF float4 arga() const { return wxyw(); }
  HLML_INLINEF float4 arbr() const { return wxzx(); }
  HLML_INLINEF float4 arbg() const { return wxzy(); }
  HLML_INLINEF float4 arbb() const { return wxzz(); }
  HLML_INLINEF float4 arba() const { return wxzw(); }
  HLML_INLINEF float4 arar() const { return wxwx(); }
  HLML_INLINEF float4 arag() const { return wxwy(); }
  HLML_INLINEF float4 arab() const { return wxwz(); }
  HLML_INLINEF float4 araa() const { return wxww(); }
  HLML_INLINEF float4 agrr() const { return wyxx(); }
  HLML_INLINEF float4 agrg() const { return wyxy(); }
  HLML_INLINEF float4 agrb() const { return wyxz(); }
  HLML_INLINEF float4 agra() const { return wyxy(); }
  HLML_INLINEF float4 aggr() const { return wyyx(); }
  HLML_INLINEF float4 aggg() const { return wyyy(); }
  HLML_INLINEF float4 aggb() const { return wyyz(); }
  HLML_INLINEF float4 agga() const { return wyyw(); }
  HLML_INLINEF float4 agbr() const { return wyzx(); }
  HLML_INLINEF float4 agbg() const { return wyzy(); }
  HLML_INLINEF float4 agbb() const { return wyzz(); }
  HLML_INLINEF float4 agba() const { return wyzw(); }
  HLML_INLINEF float4 agar() const { return wywx(); }
  HLML_INLINEF float4 agag() const { return wywy(); }
  HLML_INLINEF float4 agab() const { return wywz(); }
  HLML_INLINEF float4 agaa() const { return wyww(); }
  HLML_INLINEF float4 abrr() const { return wzxx(); }
  HLML_INLINEF float4 abrg() const { return wzxy(); }
  HLML_INLINEF float4 abrb() const { return wzxz(); }
  HLML_INLINEF float4 abra() const { return wzxw(); }
  HLML_INLINEF float4 abgr() const { return wzyx(); }
  HLML_INLINEF float4 abgg() const { return wzyy(); }
  HLML_INLINEF float4 abgb() const { return wzyz(); }
  HLML_INLINEF float4 abga() const { return wzyw(); }
  HLML_INLINEF float4 abbr() const { return wzzx(); }
  HLML_INLINEF float4 abbg() const { return wzzy(); }
  HLML_INLINEF float4 abbb() const { return wzzz(); }
  HLML_INLINEF float4 abba() const { return wzzw(); }
  HLML_INLINEF float4 abar() const { return wzwx(); }
  HLML_INLINEF float4 abag() const { return wzwy(); }
  HLML_INLINEF float4 abab() const { return wzwz(); }
  HLML_INLINEF float4 abaa() const { return wzww(); }
  HLML_INLINEF float4 aarr() const { return wwxx(); }
  HLML_INLINEF float4 aarg() const { return wwxy(); }
  HLML_INLINEF float4 aarb() const { return wwxz(); }
  HLML_INLINEF float4 aara() const { return wwxw(); }
  HLML_INLINEF float4 aagr() const { return wwyx(); }
  HLML_INLINEF float4 aagg() const { return wwyy(); }
  HLML_INLINEF float4 aagb() const { return wwyz(); }
  HLML_INLINEF float4 aaga() const { return wwyw(); }
  HLML_INLINEF float4 aabr() const { return wwzx(); }
  HLML_INLINEF float4 aabg() const { return wwzy(); }
  HLML_INLINEF float4 aabb() const { return wwzz(); }
  HLML_INLINEF float4 aaba() const { return wwzw(); }
  HLML_INLINEF float4 aaar() const { return wwwx(); }
  HLML_INLINEF float4 aaag() const { return wwwy(); }
  HLML_INLINEF float4 aaab() const { return wwwz(); }
  HLML_INLINEF float4 aaaa() const { return wwww(); }
};

HLML_INLINEF bool4    operator== (float4 a, float4 b) { return bool4(funcs::ftoi(cmpeq(a, b).m)); }
HLML_INLINEF bool4    operator!= (float4 a, float4 b) { return bool4(funcs::ftoi(cmpneq(a, b).m)); }
HLML_INLINEF bool4    operator<  (float4 a, float4 b) { return bool4(funcs::ftoi(cmplt(a, b).m)); }
HLML_INLINEF bool4    operator>  (float4 a, float4 b) { return bool4(funcs::ftoi(cmpgt(a, b).m)); }
HLML_INLINEF bool4    operator<= (float4 a, float4 b) { return bool4(funcs::ftoi(cmple(a, b).m)); }
HLML_INLINEF bool4    operator>= (float4 a, float4 b) { return bool4(funcs::ftoi(cmpge(a, b).m)); }

HLML_INLINEF int4 asint(float4 a) { return int4(funcs::fasi(a.m)); }
HLML_INLINEF int4 toint(float4 a) { return int4(funcs::ftoi(a.m)); }
HLML_INLINEF float4 asflt(int4 a) { return float4(funcs::iasf(a.m)); }
HLML_INLINEF float4 toflt(int4 a) { return float4(funcs::itof(a.m)); }

HLML_INLINEF float4 sumv(float4 v) { v.m = funcs::AhaddB(v.m, v.zwxy().m); v.m = funcs::AhaddB(v.m, v.m); return v; }
HLML_INLINEF F32 hmin(float4 v) { v = min(v, shufflef4(v, 1, 0, 3, 2)); return min(v, shufflef4(v, 3, 2, 1, 0)).x(); }
HLML_INLINEF F32 hmax(float4 v) { v = max(v, shufflef4(v, 1, 0, 3, 2)); return max(v, shufflef4(v, 3, 2, 1, 0)).x(); }
}
