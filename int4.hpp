#pragma once

#include "int3.hpp"
#include "bool4.hpp"

namespace hlml {
struct int4 {

  VI128 m = { 0 };

  HLML_INLINEF int4() {}
  HLML_INLINEF int4(I32 x, I32 y, I32 z, I32 w) : m(funcs::setXYZW(x, y, z, w)) {}
  HLML_INLINEF int4(int2 v, I32 z, I32 w) : int4(v.x(), v.y(), z, w) {}
  HLML_INLINEF int4(int3 v, I32 w) : int4(v.x(), v.y(), v.z(), w) {}
  HLML_INLINEF explicit int4(I32 x) : int4(x, x, x, x) {}
  HLML_INLINEF explicit int4(const I32 *p) : int4(p[0], p[1], p[2], p[3]) {}
  HLML_INLINEF explicit int4(VI128 v) : m(v) {}

  HLML_INLINEF void store(I32 *p) const { p[0] = x(); p[1] = y(); p[2] = z(); p[3] = w(); }

  HLML_INLINEF void setX(I32 x) { m = inserti(m, x, 0); }
  HLML_INLINEF void setY(I32 y) { m = inserti(m, y, 1); }
  HLML_INLINEF void setZ(I32 z) { m = inserti(m, z, 2); }
  HLML_INLINEF void setW(I32 w) { m = inserti(m, w, 3); }

  HLML_INLINEF I32 x() const { return extracti(m, 0); }
  HLML_INLINEF I32 y() const { return extracti(m, 1); }
  HLML_INLINEF I32 z() const { return extracti(m, 2); }
  HLML_INLINEF I32 w() const { return extracti(m, 3); }

  HLML_INLINEF int2 xx() const { return shufflei2(*this, 0, 0); }
  HLML_INLINEF int2 xy() const { return shufflei2(*this, 0, 1); }
  HLML_INLINEF int2 xz() const { return shufflei2(*this, 0, 2); }
  HLML_INLINEF int2 xw() const { return shufflei2(*this, 0, 3); }
  HLML_INLINEF int2 yy() const { return shufflei2(*this, 1, 1); }
  HLML_INLINEF int2 yx() const { return shufflei2(*this, 1, 0); }
  HLML_INLINEF int2 yz() const { return shufflei2(*this, 1, 2); }
  HLML_INLINEF int2 yw() const { return shufflei2(*this, 1, 3); }
  HLML_INLINEF int2 zz() const { return shufflei2(*this, 2, 2); }
  HLML_INLINEF int2 zx() const { return shufflei2(*this, 2, 0); }
  HLML_INLINEF int2 zy() const { return shufflei2(*this, 2, 1); }
  HLML_INLINEF int2 zw() const { return shufflei2(*this, 2, 3); }
  HLML_INLINEF int2 ww() const { return shufflei2(*this, 3, 3); }
  HLML_INLINEF int2 wx() const { return shufflei2(*this, 3, 0); }
  HLML_INLINEF int2 wy() const { return shufflei2(*this, 3, 1); }
  HLML_INLINEF int2 wz() const { return shufflei2(*this, 3, 2); }

  HLML_INLINEF int3 xxx() const { return shufflei3(*this, 0, 0, 0); }
  HLML_INLINEF int3 xxy() const { return shufflei3(*this, 0, 0, 1); }
  HLML_INLINEF int3 xxz() const { return shufflei3(*this, 0, 0, 2); }
  HLML_INLINEF int3 xxw() const { return shufflei3(*this, 0, 0, 3); }
  HLML_INLINEF int3 xyx() const { return shufflei3(*this, 0, 1, 0); }
  HLML_INLINEF int3 xyy() const { return shufflei3(*this, 0, 1, 1); }
  HLML_INLINEF int3 xyz() const { return shufflei3(*this, 0, 1, 2); }
  HLML_INLINEF int3 xyw() const { return shufflei3(*this, 0, 1, 3); }
  HLML_INLINEF int3 xzx() const { return shufflei3(*this, 0, 2, 0); }
  HLML_INLINEF int3 xzy() const { return shufflei3(*this, 0, 2, 1); }
  HLML_INLINEF int3 xzz() const { return shufflei3(*this, 0, 2, 2); }
  HLML_INLINEF int3 xzw() const { return shufflei3(*this, 0, 2, 3); }
  HLML_INLINEF int3 xwx() const { return shufflei3(*this, 0, 3, 0); }
  HLML_INLINEF int3 xwy() const { return shufflei3(*this, 0, 3, 1); }
  HLML_INLINEF int3 xwz() const { return shufflei3(*this, 0, 3, 2); }
  HLML_INLINEF int3 xww() const { return shufflei3(*this, 0, 3, 3); }

  HLML_INLINEF int3 yxx() const { return shufflei3(*this, 1, 0, 0); }
  HLML_INLINEF int3 yxy() const { return shufflei3(*this, 1, 0, 1); }
  HLML_INLINEF int3 yxz() const { return shufflei3(*this, 1, 0, 2); }
  HLML_INLINEF int3 yxw() const { return shufflei3(*this, 1, 0, 3); }
  HLML_INLINEF int3 yyx() const { return shufflei3(*this, 1, 1, 0); }
  HLML_INLINEF int3 yyy() const { return shufflei3(*this, 1, 1, 1); }
  HLML_INLINEF int3 yyz() const { return shufflei3(*this, 1, 1, 2); }
  HLML_INLINEF int3 yyw() const { return shufflei3(*this, 1, 1, 3); }
  HLML_INLINEF int3 yzx() const { return shufflei3(*this, 1, 2, 0); }
  HLML_INLINEF int3 yzy() const { return shufflei3(*this, 1, 2, 1); }
  HLML_INLINEF int3 yzz() const { return shufflei3(*this, 1, 2, 2); }
  HLML_INLINEF int3 yzw() const { return shufflei3(*this, 1, 2, 3); }
  HLML_INLINEF int3 ywx() const { return shufflei3(*this, 1, 3, 0); }
  HLML_INLINEF int3 ywy() const { return shufflei3(*this, 1, 3, 1); }
  HLML_INLINEF int3 ywz() const { return shufflei3(*this, 1, 3, 2); }
  HLML_INLINEF int3 yww() const { return shufflei3(*this, 1, 3, 3); }

  HLML_INLINEF int3 zxx() const { return shufflei3(*this, 2, 0, 0); }
  HLML_INLINEF int3 zxy() const { return shufflei3(*this, 2, 0, 1); }
  HLML_INLINEF int3 zxz() const { return shufflei3(*this, 2, 0, 2); }
  HLML_INLINEF int3 zxw() const { return shufflei3(*this, 2, 0, 3); }
  HLML_INLINEF int3 zyx() const { return shufflei3(*this, 2, 1, 0); }
  HLML_INLINEF int3 zyy() const { return shufflei3(*this, 2, 1, 1); }
  HLML_INLINEF int3 zyz() const { return shufflei3(*this, 2, 1, 2); }
  HLML_INLINEF int3 zyw() const { return shufflei3(*this, 2, 1, 3); }
  HLML_INLINEF int3 zzx() const { return shufflei3(*this, 2, 2, 0); }
  HLML_INLINEF int3 zzy() const { return shufflei3(*this, 2, 2, 1); }
  HLML_INLINEF int3 zzz() const { return shufflei3(*this, 2, 2, 2); }
  HLML_INLINEF int3 zzw() const { return shufflei3(*this, 2, 2, 3); }
  HLML_INLINEF int3 zwx() const { return shufflei3(*this, 2, 3, 0); }
  HLML_INLINEF int3 zwy() const { return shufflei3(*this, 2, 3, 1); }
  HLML_INLINEF int3 zwz() const { return shufflei3(*this, 2, 3, 2); }
  HLML_INLINEF int3 zww() const { return shufflei3(*this, 2, 3, 3); }

  HLML_INLINEF int3 wxx() const { return shufflei3(*this, 3, 0, 0); }
  HLML_INLINEF int3 wxy() const { return shufflei3(*this, 3, 0, 1); }
  HLML_INLINEF int3 wxz() const { return shufflei3(*this, 3, 0, 2); }
  HLML_INLINEF int3 wxw() const { return shufflei3(*this, 3, 0, 3); }
  HLML_INLINEF int3 wyx() const { return shufflei3(*this, 3, 1, 0); }
  HLML_INLINEF int3 wyy() const { return shufflei3(*this, 3, 1, 1); }
  HLML_INLINEF int3 wyz() const { return shufflei3(*this, 3, 1, 2); }
  HLML_INLINEF int3 wyw() const { return shufflei3(*this, 3, 1, 3); }
  HLML_INLINEF int3 wzx() const { return shufflei3(*this, 3, 2, 0); }
  HLML_INLINEF int3 wzy() const { return shufflei3(*this, 3, 2, 1); }
  HLML_INLINEF int3 wzz() const { return shufflei3(*this, 3, 2, 2); }
  HLML_INLINEF int3 wzw() const { return shufflei3(*this, 3, 2, 3); }
  HLML_INLINEF int3 wwx() const { return shufflei3(*this, 3, 3, 0); }
  HLML_INLINEF int3 wwy() const { return shufflei3(*this, 3, 3, 1); }
  HLML_INLINEF int3 wwz() const { return shufflei3(*this, 3, 3, 2); }
  HLML_INLINEF int3 www() const { return shufflei3(*this, 3, 3, 3); }

  HLML_INLINEF int4 xxxx() const { return shufflei4(*this, 0, 0, 0, 0); }
  HLML_INLINEF int4 xxxy() const { return shufflei4(*this, 0, 0, 0, 1); }
  HLML_INLINEF int4 xxxz() const { return shufflei4(*this, 0, 0, 0, 2); }
  HLML_INLINEF int4 xxxw() const { return shufflei4(*this, 0, 0, 0, 3); }
  HLML_INLINEF int4 xxyx() const { return shufflei4(*this, 0, 0, 1, 0); }
  HLML_INLINEF int4 xxyy() const { return shufflei4(*this, 0, 0, 1, 1); }
  HLML_INLINEF int4 xxyz() const { return shufflei4(*this, 0, 0, 1, 2); }
  HLML_INLINEF int4 xxyw() const { return shufflei4(*this, 0, 0, 1, 3); }
  HLML_INLINEF int4 xxzx() const { return shufflei4(*this, 0, 0, 2, 0); }
  HLML_INLINEF int4 xxzy() const { return shufflei4(*this, 0, 0, 2, 1); }
  HLML_INLINEF int4 xxzz() const { return shufflei4(*this, 0, 0, 2, 2); }
  HLML_INLINEF int4 xxzw() const { return shufflei4(*this, 0, 0, 2, 3); }
  HLML_INLINEF int4 xxwx() const { return shufflei4(*this, 0, 0, 3, 0); }
  HLML_INLINEF int4 xxwy() const { return shufflei4(*this, 0, 0, 3, 1); }
  HLML_INLINEF int4 xxwz() const { return shufflei4(*this, 0, 0, 3, 2); }
  HLML_INLINEF int4 xxww() const { return shufflei4(*this, 0, 0, 3, 3); }
  HLML_INLINEF int4 xyxx() const { return shufflei4(*this, 0, 1, 0, 0); }
  HLML_INLINEF int4 xyxy() const { return shufflei4(*this, 0, 1, 0, 1); }
  HLML_INLINEF int4 xyxz() const { return shufflei4(*this, 0, 1, 0, 2); }
  HLML_INLINEF int4 xyxw() const { return shufflei4(*this, 0, 1, 0, 3); }
  HLML_INLINEF int4 xyyx() const { return shufflei4(*this, 0, 1, 1, 0); }
  HLML_INLINEF int4 xyyy() const { return shufflei4(*this, 0, 1, 1, 1); }
  HLML_INLINEF int4 xyyz() const { return shufflei4(*this, 0, 1, 1, 2); }
  HLML_INLINEF int4 xyyw() const { return shufflei4(*this, 0, 1, 1, 3); }
  HLML_INLINEF int4 xyzx() const { return shufflei4(*this, 0, 1, 2, 0); }
  HLML_INLINEF int4 xyzy() const { return shufflei4(*this, 0, 1, 2, 1); }
  HLML_INLINEF int4 xyzz() const { return shufflei4(*this, 0, 1, 2, 2); }
  HLML_INLINEF int4 xyzw() const { return shufflei4(*this, 0, 1, 2, 3); }
  HLML_INLINEF int4 xywx() const { return shufflei4(*this, 0, 1, 3, 0); }
  HLML_INLINEF int4 xywy() const { return shufflei4(*this, 0, 1, 3, 1); }
  HLML_INLINEF int4 xywz() const { return shufflei4(*this, 0, 1, 3, 2); }
  HLML_INLINEF int4 xyww() const { return shufflei4(*this, 0, 1, 3, 3); }
  HLML_INLINEF int4 xzxx() const { return shufflei4(*this, 0, 2, 0, 0); }
  HLML_INLINEF int4 xzxy() const { return shufflei4(*this, 0, 2, 0, 1); }
  HLML_INLINEF int4 xzxz() const { return shufflei4(*this, 0, 2, 0, 2); }
  HLML_INLINEF int4 xzxw() const { return shufflei4(*this, 0, 2, 0, 3); }
  HLML_INLINEF int4 xzyx() const { return shufflei4(*this, 0, 2, 1, 0); }
  HLML_INLINEF int4 xzyy() const { return shufflei4(*this, 0, 2, 1, 1); }
  HLML_INLINEF int4 xzyz() const { return shufflei4(*this, 0, 2, 1, 2); }
  HLML_INLINEF int4 xzyw() const { return shufflei4(*this, 0, 2, 1, 3); }
  HLML_INLINEF int4 xzzx() const { return shufflei4(*this, 0, 2, 2, 0); }
  HLML_INLINEF int4 xzzy() const { return shufflei4(*this, 0, 2, 2, 1); }
  HLML_INLINEF int4 xzzz() const { return shufflei4(*this, 0, 2, 2, 2); }
  HLML_INLINEF int4 xzzw() const { return shufflei4(*this, 0, 2, 2, 3); }
  HLML_INLINEF int4 xzwx() const { return shufflei4(*this, 0, 2, 3, 0); }
  HLML_INLINEF int4 xzwy() const { return shufflei4(*this, 0, 2, 3, 1); }
  HLML_INLINEF int4 xzwz() const { return shufflei4(*this, 0, 2, 3, 2); }
  HLML_INLINEF int4 xzww() const { return shufflei4(*this, 0, 2, 3, 3); }
  HLML_INLINEF int4 xwxx() const { return shufflei4(*this, 0, 3, 0, 0); }
  HLML_INLINEF int4 xwxy() const { return shufflei4(*this, 0, 3, 0, 1); }
  HLML_INLINEF int4 xwxz() const { return shufflei4(*this, 0, 3, 0, 2); }
  HLML_INLINEF int4 xwxw() const { return shufflei4(*this, 0, 3, 0, 3); }
  HLML_INLINEF int4 xwyx() const { return shufflei4(*this, 0, 3, 1, 0); }
  HLML_INLINEF int4 xwyy() const { return shufflei4(*this, 0, 3, 1, 1); }
  HLML_INLINEF int4 xwyz() const { return shufflei4(*this, 0, 3, 1, 2); }
  HLML_INLINEF int4 xwyw() const { return shufflei4(*this, 0, 3, 1, 3); }
  HLML_INLINEF int4 xwzx() const { return shufflei4(*this, 0, 3, 2, 0); }
  HLML_INLINEF int4 xwzy() const { return shufflei4(*this, 0, 3, 2, 1); }
  HLML_INLINEF int4 xwzz() const { return shufflei4(*this, 0, 3, 2, 2); }
  HLML_INLINEF int4 xwzw() const { return shufflei4(*this, 0, 3, 2, 3); }
  HLML_INLINEF int4 xwwx() const { return shufflei4(*this, 0, 3, 3, 0); }
  HLML_INLINEF int4 xwwy() const { return shufflei4(*this, 0, 3, 3, 1); }
  HLML_INLINEF int4 xwwz() const { return shufflei4(*this, 0, 3, 3, 2); }
  HLML_INLINEF int4 xwww() const { return shufflei4(*this, 0, 3, 3, 3); }

  HLML_INLINEF int4 yxxx() const { return shufflei4(*this, 1, 0, 0, 0); }
  HLML_INLINEF int4 yxxy() const { return shufflei4(*this, 1, 0, 0, 1); }
  HLML_INLINEF int4 yxxz() const { return shufflei4(*this, 1, 0, 0, 2); }
  HLML_INLINEF int4 yxxw() const { return shufflei4(*this, 1, 0, 0, 3); }
  HLML_INLINEF int4 yxyx() const { return shufflei4(*this, 1, 0, 1, 0); }
  HLML_INLINEF int4 yxyy() const { return shufflei4(*this, 1, 0, 1, 1); }
  HLML_INLINEF int4 yxyz() const { return shufflei4(*this, 1, 0, 1, 2); }
  HLML_INLINEF int4 yxyw() const { return shufflei4(*this, 1, 0, 1, 3); }
  HLML_INLINEF int4 yxzx() const { return shufflei4(*this, 1, 0, 2, 0); }
  HLML_INLINEF int4 yxzy() const { return shufflei4(*this, 1, 0, 2, 1); }
  HLML_INLINEF int4 yxzz() const { return shufflei4(*this, 1, 0, 2, 2); }
  HLML_INLINEF int4 yxzw() const { return shufflei4(*this, 1, 0, 2, 3); }
  HLML_INLINEF int4 yxwx() const { return shufflei4(*this, 1, 0, 3, 0); }
  HLML_INLINEF int4 yxwy() const { return shufflei4(*this, 1, 0, 3, 1); }
  HLML_INLINEF int4 yxwz() const { return shufflei4(*this, 1, 0, 3, 2); }
  HLML_INLINEF int4 yxww() const { return shufflei4(*this, 1, 0, 3, 3); }
  HLML_INLINEF int4 yyxx() const { return shufflei4(*this, 1, 1, 0, 0); }
  HLML_INLINEF int4 yyxy() const { return shufflei4(*this, 1, 1, 0, 1); }
  HLML_INLINEF int4 yyxz() const { return shufflei4(*this, 1, 1, 0, 2); }
  HLML_INLINEF int4 yyxw() const { return shufflei4(*this, 1, 1, 0, 3); }
  HLML_INLINEF int4 yyyx() const { return shufflei4(*this, 1, 1, 1, 0); }
  HLML_INLINEF int4 yyyy() const { return shufflei4(*this, 1, 1, 1, 1); }
  HLML_INLINEF int4 yyyz() const { return shufflei4(*this, 1, 1, 1, 2); }
  HLML_INLINEF int4 yyyw() const { return shufflei4(*this, 1, 1, 1, 3); }
  HLML_INLINEF int4 yyzx() const { return shufflei4(*this, 1, 1, 2, 0); }
  HLML_INLINEF int4 yyzy() const { return shufflei4(*this, 1, 1, 2, 1); }
  HLML_INLINEF int4 yyzz() const { return shufflei4(*this, 1, 1, 2, 2); }
  HLML_INLINEF int4 yyzw() const { return shufflei4(*this, 1, 1, 2, 3); }
  HLML_INLINEF int4 yywx() const { return shufflei4(*this, 1, 1, 3, 0); }
  HLML_INLINEF int4 yywy() const { return shufflei4(*this, 1, 1, 3, 1); }
  HLML_INLINEF int4 yywz() const { return shufflei4(*this, 1, 1, 3, 2); }
  HLML_INLINEF int4 yyww() const { return shufflei4(*this, 1, 1, 3, 3); }
  HLML_INLINEF int4 yzxx() const { return shufflei4(*this, 1, 2, 0, 0); }
  HLML_INLINEF int4 yzxy() const { return shufflei4(*this, 1, 2, 0, 1); }
  HLML_INLINEF int4 yzxz() const { return shufflei4(*this, 1, 2, 0, 2); }
  HLML_INLINEF int4 yzxw() const { return shufflei4(*this, 1, 2, 0, 3); }
  HLML_INLINEF int4 yzyx() const { return shufflei4(*this, 1, 2, 1, 0); }
  HLML_INLINEF int4 yzyy() const { return shufflei4(*this, 1, 2, 1, 1); }
  HLML_INLINEF int4 yzyz() const { return shufflei4(*this, 1, 2, 1, 2); }
  HLML_INLINEF int4 yzyw() const { return shufflei4(*this, 1, 2, 1, 3); }
  HLML_INLINEF int4 yzzx() const { return shufflei4(*this, 1, 2, 2, 0); }
  HLML_INLINEF int4 yzzy() const { return shufflei4(*this, 1, 2, 2, 1); }
  HLML_INLINEF int4 yzzz() const { return shufflei4(*this, 1, 2, 2, 2); }
  HLML_INLINEF int4 yzzw() const { return shufflei4(*this, 1, 2, 2, 3); }
  HLML_INLINEF int4 yzwx() const { return shufflei4(*this, 1, 2, 3, 0); }
  HLML_INLINEF int4 yzwy() const { return shufflei4(*this, 1, 2, 3, 1); }
  HLML_INLINEF int4 yzwz() const { return shufflei4(*this, 1, 2, 3, 2); }
  HLML_INLINEF int4 yzww() const { return shufflei4(*this, 1, 2, 3, 3); }
  HLML_INLINEF int4 ywxx() const { return shufflei4(*this, 1, 3, 0, 0); }
  HLML_INLINEF int4 ywxy() const { return shufflei4(*this, 1, 3, 0, 1); }
  HLML_INLINEF int4 ywxz() const { return shufflei4(*this, 1, 3, 0, 2); }
  HLML_INLINEF int4 ywxw() const { return shufflei4(*this, 1, 3, 0, 3); }
  HLML_INLINEF int4 ywyx() const { return shufflei4(*this, 1, 3, 1, 0); }
  HLML_INLINEF int4 ywyy() const { return shufflei4(*this, 1, 3, 1, 1); }
  HLML_INLINEF int4 ywyz() const { return shufflei4(*this, 1, 3, 1, 2); }
  HLML_INLINEF int4 ywyw() const { return shufflei4(*this, 1, 3, 1, 3); }
  HLML_INLINEF int4 ywzx() const { return shufflei4(*this, 1, 3, 2, 0); }
  HLML_INLINEF int4 ywzy() const { return shufflei4(*this, 1, 3, 2, 1); }
  HLML_INLINEF int4 ywzz() const { return shufflei4(*this, 1, 3, 2, 2); }
  HLML_INLINEF int4 ywzw() const { return shufflei4(*this, 1, 3, 2, 3); }
  HLML_INLINEF int4 ywwx() const { return shufflei4(*this, 1, 3, 3, 0); }
  HLML_INLINEF int4 ywwy() const { return shufflei4(*this, 1, 3, 3, 1); }
  HLML_INLINEF int4 ywwz() const { return shufflei4(*this, 1, 3, 3, 2); }
  HLML_INLINEF int4 ywww() const { return shufflei4(*this, 1, 3, 3, 3); }

  HLML_INLINEF int4 zxxx() const { return shufflei4(*this, 2, 0, 0, 0); }
  HLML_INLINEF int4 zxxy() const { return shufflei4(*this, 2, 0, 0, 1); }
  HLML_INLINEF int4 zxxz() const { return shufflei4(*this, 2, 0, 0, 2); }
  HLML_INLINEF int4 zxxw() const { return shufflei4(*this, 2, 0, 0, 3); }
  HLML_INLINEF int4 zxyx() const { return shufflei4(*this, 2, 0, 1, 0); }
  HLML_INLINEF int4 zxyy() const { return shufflei4(*this, 2, 0, 1, 1); }
  HLML_INLINEF int4 zxyz() const { return shufflei4(*this, 2, 0, 1, 2); }
  HLML_INLINEF int4 zxyw() const { return shufflei4(*this, 2, 0, 1, 3); }
  HLML_INLINEF int4 zxzx() const { return shufflei4(*this, 2, 0, 2, 0); }
  HLML_INLINEF int4 zxzy() const { return shufflei4(*this, 2, 0, 2, 1); }
  HLML_INLINEF int4 zxzz() const { return shufflei4(*this, 2, 0, 2, 2); }
  HLML_INLINEF int4 zxzw() const { return shufflei4(*this, 2, 0, 2, 3); }
  HLML_INLINEF int4 zxwx() const { return shufflei4(*this, 2, 0, 3, 0); }
  HLML_INLINEF int4 zxwy() const { return shufflei4(*this, 2, 0, 3, 1); }
  HLML_INLINEF int4 zxwz() const { return shufflei4(*this, 2, 0, 3, 2); }
  HLML_INLINEF int4 zxww() const { return shufflei4(*this, 2, 0, 3, 3); }
  HLML_INLINEF int4 zyxx() const { return shufflei4(*this, 2, 1, 0, 0); }
  HLML_INLINEF int4 zyxy() const { return shufflei4(*this, 2, 1, 0, 1); }
  HLML_INLINEF int4 zyxz() const { return shufflei4(*this, 2, 1, 0, 2); }
  HLML_INLINEF int4 zyxw() const { return shufflei4(*this, 2, 1, 0, 3); }
  HLML_INLINEF int4 zyyx() const { return shufflei4(*this, 2, 1, 1, 0); }
  HLML_INLINEF int4 zyyy() const { return shufflei4(*this, 2, 1, 1, 1); }
  HLML_INLINEF int4 zyyz() const { return shufflei4(*this, 2, 1, 1, 2); }
  HLML_INLINEF int4 zyyw() const { return shufflei4(*this, 2, 1, 1, 3); }
  HLML_INLINEF int4 zyzx() const { return shufflei4(*this, 2, 1, 2, 0); }
  HLML_INLINEF int4 zyzy() const { return shufflei4(*this, 2, 1, 2, 1); }
  HLML_INLINEF int4 zyzz() const { return shufflei4(*this, 2, 1, 2, 2); }
  HLML_INLINEF int4 zyzw() const { return shufflei4(*this, 2, 1, 2, 3); }
  HLML_INLINEF int4 zywx() const { return shufflei4(*this, 2, 1, 3, 0); }
  HLML_INLINEF int4 zywy() const { return shufflei4(*this, 2, 1, 3, 1); }
  HLML_INLINEF int4 zywz() const { return shufflei4(*this, 2, 1, 3, 2); }
  HLML_INLINEF int4 zyww() const { return shufflei4(*this, 2, 1, 3, 3); }
  HLML_INLINEF int4 zzxx() const { return shufflei4(*this, 2, 2, 0, 0); }
  HLML_INLINEF int4 zzxy() const { return shufflei4(*this, 2, 2, 0, 1); }
  HLML_INLINEF int4 zzxz() const { return shufflei4(*this, 2, 2, 0, 2); }
  HLML_INLINEF int4 zzxw() const { return shufflei4(*this, 2, 2, 0, 3); }
  HLML_INLINEF int4 zzyx() const { return shufflei4(*this, 2, 2, 1, 0); }
  HLML_INLINEF int4 zzyy() const { return shufflei4(*this, 2, 2, 1, 1); }
  HLML_INLINEF int4 zzyz() const { return shufflei4(*this, 2, 2, 1, 2); }
  HLML_INLINEF int4 zzyw() const { return shufflei4(*this, 2, 2, 1, 3); }
  HLML_INLINEF int4 zzzx() const { return shufflei4(*this, 2, 2, 2, 0); }
  HLML_INLINEF int4 zzzy() const { return shufflei4(*this, 2, 2, 2, 1); }
  HLML_INLINEF int4 zzzz() const { return shufflei4(*this, 2, 2, 2, 2); }
  HLML_INLINEF int4 zzzw() const { return shufflei4(*this, 2, 2, 2, 3); }
  HLML_INLINEF int4 zzwx() const { return shufflei4(*this, 2, 2, 3, 0); }
  HLML_INLINEF int4 zzwy() const { return shufflei4(*this, 2, 2, 3, 1); }
  HLML_INLINEF int4 zzwz() const { return shufflei4(*this, 2, 2, 3, 2); }
  HLML_INLINEF int4 zzww() const { return shufflei4(*this, 2, 2, 3, 3); }
  HLML_INLINEF int4 zwxx() const { return shufflei4(*this, 2, 3, 0, 0); }
  HLML_INLINEF int4 zwxy() const { return shufflei4(*this, 2, 3, 0, 1); }
  HLML_INLINEF int4 zwxz() const { return shufflei4(*this, 2, 3, 0, 2); }
  HLML_INLINEF int4 zwxw() const { return shufflei4(*this, 2, 3, 0, 3); }
  HLML_INLINEF int4 zwyx() const { return shufflei4(*this, 2, 3, 1, 0); }
  HLML_INLINEF int4 zwyy() const { return shufflei4(*this, 2, 3, 1, 1); }
  HLML_INLINEF int4 zwyz() const { return shufflei4(*this, 2, 3, 1, 2); }
  HLML_INLINEF int4 zwyw() const { return shufflei4(*this, 2, 3, 1, 3); }
  HLML_INLINEF int4 zwzx() const { return shufflei4(*this, 2, 3, 2, 0); }
  HLML_INLINEF int4 zwzy() const { return shufflei4(*this, 2, 3, 2, 1); }
  HLML_INLINEF int4 zwzz() const { return shufflei4(*this, 2, 3, 2, 2); }
  HLML_INLINEF int4 zwzw() const { return shufflei4(*this, 2, 3, 2, 3); }
  HLML_INLINEF int4 zwwx() const { return shufflei4(*this, 2, 3, 3, 0); }
  HLML_INLINEF int4 zwwy() const { return shufflei4(*this, 2, 3, 3, 1); }
  HLML_INLINEF int4 zwwz() const { return shufflei4(*this, 2, 3, 3, 2); }
  HLML_INLINEF int4 zwww() const { return shufflei4(*this, 2, 3, 3, 3); }

  HLML_INLINEF int4 wxxx() const { return shufflei4(*this, 3, 0, 0, 0); }
  HLML_INLINEF int4 wxxy() const { return shufflei4(*this, 3, 0, 0, 1); }
  HLML_INLINEF int4 wxxz() const { return shufflei4(*this, 3, 0, 0, 2); }
  HLML_INLINEF int4 wxxw() const { return shufflei4(*this, 3, 0, 0, 3); }
  HLML_INLINEF int4 wxyx() const { return shufflei4(*this, 3, 0, 1, 0); }
  HLML_INLINEF int4 wxyy() const { return shufflei4(*this, 3, 0, 1, 1); }
  HLML_INLINEF int4 wxyz() const { return shufflei4(*this, 3, 0, 1, 2); }
  HLML_INLINEF int4 wxyw() const { return shufflei4(*this, 3, 0, 1, 3); }
  HLML_INLINEF int4 wxzx() const { return shufflei4(*this, 3, 0, 2, 0); }
  HLML_INLINEF int4 wxzy() const { return shufflei4(*this, 3, 0, 2, 1); }
  HLML_INLINEF int4 wxzz() const { return shufflei4(*this, 3, 0, 2, 2); }
  HLML_INLINEF int4 wxzw() const { return shufflei4(*this, 3, 0, 2, 3); }
  HLML_INLINEF int4 wxwx() const { return shufflei4(*this, 3, 0, 3, 0); }
  HLML_INLINEF int4 wxwy() const { return shufflei4(*this, 3, 0, 3, 1); }
  HLML_INLINEF int4 wxwz() const { return shufflei4(*this, 3, 0, 3, 2); }
  HLML_INLINEF int4 wxww() const { return shufflei4(*this, 3, 0, 3, 3); }
  HLML_INLINEF int4 wyxx() const { return shufflei4(*this, 3, 1, 0, 0); }
  HLML_INLINEF int4 wyxy() const { return shufflei4(*this, 3, 1, 0, 1); }
  HLML_INLINEF int4 wyxz() const { return shufflei4(*this, 3, 1, 0, 2); }
  HLML_INLINEF int4 wyxw() const { return shufflei4(*this, 3, 1, 0, 3); }
  HLML_INLINEF int4 wyyx() const { return shufflei4(*this, 3, 1, 1, 0); }
  HLML_INLINEF int4 wyyy() const { return shufflei4(*this, 3, 1, 1, 1); }
  HLML_INLINEF int4 wyyz() const { return shufflei4(*this, 3, 1, 1, 2); }
  HLML_INLINEF int4 wyyw() const { return shufflei4(*this, 3, 1, 1, 3); }
  HLML_INLINEF int4 wyzx() const { return shufflei4(*this, 3, 1, 2, 0); }
  HLML_INLINEF int4 wyzy() const { return shufflei4(*this, 3, 1, 2, 1); }
  HLML_INLINEF int4 wyzz() const { return shufflei4(*this, 3, 1, 2, 2); }
  HLML_INLINEF int4 wyzw() const { return shufflei4(*this, 3, 1, 2, 3); }
  HLML_INLINEF int4 wywx() const { return shufflei4(*this, 3, 1, 3, 0); }
  HLML_INLINEF int4 wywy() const { return shufflei4(*this, 3, 1, 3, 1); }
  HLML_INLINEF int4 wywz() const { return shufflei4(*this, 3, 1, 3, 2); }
  HLML_INLINEF int4 wyww() const { return shufflei4(*this, 3, 1, 3, 3); }
  HLML_INLINEF int4 wzxx() const { return shufflei4(*this, 3, 2, 0, 0); }
  HLML_INLINEF int4 wzxy() const { return shufflei4(*this, 3, 2, 0, 1); }
  HLML_INLINEF int4 wzxz() const { return shufflei4(*this, 3, 2, 0, 2); }
  HLML_INLINEF int4 wzxw() const { return shufflei4(*this, 3, 2, 0, 3); }
  HLML_INLINEF int4 wzyx() const { return shufflei4(*this, 3, 2, 1, 0); }
  HLML_INLINEF int4 wzyy() const { return shufflei4(*this, 3, 2, 1, 1); }
  HLML_INLINEF int4 wzyz() const { return shufflei4(*this, 3, 2, 1, 2); }
  HLML_INLINEF int4 wzyw() const { return shufflei4(*this, 3, 2, 1, 3); }
  HLML_INLINEF int4 wzzx() const { return shufflei4(*this, 3, 2, 2, 0); }
  HLML_INLINEF int4 wzzy() const { return shufflei4(*this, 3, 2, 2, 1); }
  HLML_INLINEF int4 wzzz() const { return shufflei4(*this, 3, 2, 2, 2); }
  HLML_INLINEF int4 wzzw() const { return shufflei4(*this, 3, 2, 2, 3); }
  HLML_INLINEF int4 wzwx() const { return shufflei4(*this, 3, 2, 3, 0); }
  HLML_INLINEF int4 wzwy() const { return shufflei4(*this, 3, 2, 3, 1); }
  HLML_INLINEF int4 wzwz() const { return shufflei4(*this, 3, 2, 3, 2); }
  HLML_INLINEF int4 wzww() const { return shufflei4(*this, 3, 2, 3, 3); }
  HLML_INLINEF int4 wwxx() const { return shufflei4(*this, 3, 3, 0, 0); }
  HLML_INLINEF int4 wwxy() const { return shufflei4(*this, 3, 3, 0, 1); }
  HLML_INLINEF int4 wwxz() const { return shufflei4(*this, 3, 3, 0, 2); }
  HLML_INLINEF int4 wwxw() const { return shufflei4(*this, 3, 3, 0, 3); }
  HLML_INLINEF int4 wwyx() const { return shufflei4(*this, 3, 3, 1, 0); }
  HLML_INLINEF int4 wwyy() const { return shufflei4(*this, 3, 3, 1, 1); }
  HLML_INLINEF int4 wwyz() const { return shufflei4(*this, 3, 3, 1, 2); }
  HLML_INLINEF int4 wwyw() const { return shufflei4(*this, 3, 3, 1, 3); }
  HLML_INLINEF int4 wwzx() const { return shufflei4(*this, 3, 3, 2, 0); }
  HLML_INLINEF int4 wwzy() const { return shufflei4(*this, 3, 3, 2, 1); }
  HLML_INLINEF int4 wwzz() const { return shufflei4(*this, 3, 3, 2, 2); }
  HLML_INLINEF int4 wwzw() const { return shufflei4(*this, 3, 3, 2, 3); }
  HLML_INLINEF int4 wwwx() const { return shufflei4(*this, 3, 3, 3, 0); }
  HLML_INLINEF int4 wwwy() const { return shufflei4(*this, 3, 3, 3, 1); }
  HLML_INLINEF int4 wwwz() const { return shufflei4(*this, 3, 3, 3, 2); }
  HLML_INLINEF int4 wwww() const { return shufflei4(*this, 3, 3, 3, 3); }

  HLML_INLINEF I32 r() const { return x(); }
  HLML_INLINEF I32 g() const { return y(); }
  HLML_INLINEF I32 b() const { return z(); }
  HLML_INLINEF I32 a() const { return w(); }

  HLML_INLINEF int2 rr() const { return xx(); }
  HLML_INLINEF int2 rg() const { return xy(); }
  HLML_INLINEF int2 rb() const { return xz(); }
  HLML_INLINEF int2 ra() const { return xw(); }
  HLML_INLINEF int2 gr() const { return yx(); }
  HLML_INLINEF int2 gg() const { return yy(); }
  HLML_INLINEF int2 gb() const { return yz(); }
  HLML_INLINEF int2 ga() const { return yw(); }
  HLML_INLINEF int2 br() const { return zx(); }
  HLML_INLINEF int2 bg() const { return zy(); }
  HLML_INLINEF int2 bb() const { return zz(); }
  HLML_INLINEF int2 ba() const { return zw(); }
  HLML_INLINEF int2 ar() const { return wx(); }
  HLML_INLINEF int2 ag() const { return wy(); }
  HLML_INLINEF int2 ab() const { return wz(); }
  HLML_INLINEF int2 aa() const { return ww(); }

  HLML_INLINEF int3 rrr() const { return xxx(); }
  HLML_INLINEF int3 rrg() const { return xxy(); }
  HLML_INLINEF int3 rrb() const { return xxz(); }
  HLML_INLINEF int3 rra() const { return xxw(); }
  HLML_INLINEF int3 rgr() const { return xyx(); }
  HLML_INLINEF int3 rgg() const { return xyy(); }
  HLML_INLINEF int3 rgb() const { return xyz(); }
  HLML_INLINEF int3 rga() const { return xyw(); }
  HLML_INLINEF int3 rbr() const { return xzx(); }
  HLML_INLINEF int3 rbg() const { return xzy(); }
  HLML_INLINEF int3 rbb() const { return xzz(); }
  HLML_INLINEF int3 rba() const { return xzw(); }
  HLML_INLINEF int3 rar() const { return xwx(); }
  HLML_INLINEF int3 rag() const { return xwy(); }
  HLML_INLINEF int3 rab() const { return xwz(); }
  HLML_INLINEF int3 raa() const { return xww(); }
  HLML_INLINEF int3 grr() const { return yxx(); }
  HLML_INLINEF int3 grg() const { return yxy(); }
  HLML_INLINEF int3 grb() const { return yxz(); }
  HLML_INLINEF int3 gra() const { return yxw(); }
  HLML_INLINEF int3 ggr() const { return yyx(); }
  HLML_INLINEF int3 ggg() const { return yyy(); }
  HLML_INLINEF int3 ggb() const { return yyz(); }
  HLML_INLINEF int3 gga() const { return yyw(); }
  HLML_INLINEF int3 gbr() const { return yzx(); }
  HLML_INLINEF int3 gbg() const { return yzy(); }
  HLML_INLINEF int3 gbb() const { return yzz(); }
  HLML_INLINEF int3 gba() const { return yzw(); }
  HLML_INLINEF int3 gar() const { return ywx(); }
  HLML_INLINEF int3 gag() const { return ywy(); }
  HLML_INLINEF int3 gab() const { return ywz(); }
  HLML_INLINEF int3 gaa() const { return yww(); }
  HLML_INLINEF int3 brr() const { return zxx(); }
  HLML_INLINEF int3 brg() const { return zxy(); }
  HLML_INLINEF int3 brb() const { return zxz(); }
  HLML_INLINEF int3 bra() const { return zxw(); }
  HLML_INLINEF int3 bgr() const { return zyx(); }
  HLML_INLINEF int3 bgg() const { return zyy(); }
  HLML_INLINEF int3 bgb() const { return zyz(); }
  HLML_INLINEF int3 bga() const { return zyw(); }
  HLML_INLINEF int3 bbr() const { return zzx(); }
  HLML_INLINEF int3 bbg() const { return zzy(); }
  HLML_INLINEF int3 bbb() const { return zzz(); }
  HLML_INLINEF int3 bba() const { return zzw(); }
  HLML_INLINEF int3 bar() const { return zwx(); }
  HLML_INLINEF int3 bag() const { return zwy(); }
  HLML_INLINEF int3 bab() const { return zwz(); }
  HLML_INLINEF int3 baa() const { return zww(); }

  HLML_INLINEF int4 rrrr() const { return xxxx(); }
  HLML_INLINEF int4 rrrg() const { return xxxy(); }
  HLML_INLINEF int4 rrrb() const { return xxxz(); }
  HLML_INLINEF int4 rrra() const { return xxxw(); }
  HLML_INLINEF int4 rrgr() const { return xxyx(); }
  HLML_INLINEF int4 rrgg() const { return xxyy(); }
  HLML_INLINEF int4 rrgb() const { return xxyz(); }
  HLML_INLINEF int4 rrga() const { return xxyw(); }
  HLML_INLINEF int4 rrbr() const { return xxzx(); }
  HLML_INLINEF int4 rrbg() const { return xxzy(); }
  HLML_INLINEF int4 rrbb() const { return xxzz(); }
  HLML_INLINEF int4 rrba() const { return xxzw(); }
  HLML_INLINEF int4 rrar() const { return xxwx(); }
  HLML_INLINEF int4 rrag() const { return xxwy(); }
  HLML_INLINEF int4 rrab() const { return xxwz(); }
  HLML_INLINEF int4 rraa() const { return xxww(); }
  HLML_INLINEF int4 rgrr() const { return xyxx(); }
  HLML_INLINEF int4 rgrg() const { return xyxy(); }
  HLML_INLINEF int4 rgrb() const { return xyxz(); }
  HLML_INLINEF int4 rgra() const { return xyxy(); }
  HLML_INLINEF int4 rggr() const { return xyyx(); }
  HLML_INLINEF int4 rggg() const { return xyyy(); }
  HLML_INLINEF int4 rggb() const { return xyyz(); }
  HLML_INLINEF int4 rgga() const { return xyyw(); }
  HLML_INLINEF int4 rgbr() const { return xyzx(); }
  HLML_INLINEF int4 rgbg() const { return xyzy(); }
  HLML_INLINEF int4 rgbb() const { return xyzz(); }
  HLML_INLINEF int4 rgba() const { return xyzw(); }
  HLML_INLINEF int4 rgar() const { return xywx(); }
  HLML_INLINEF int4 rgag() const { return xywy(); }
  HLML_INLINEF int4 rgab() const { return xywz(); }
  HLML_INLINEF int4 rgaa() const { return xyww(); }
  HLML_INLINEF int4 rbrr() const { return xzxx(); }
  HLML_INLINEF int4 rbrg() const { return xzxy(); }
  HLML_INLINEF int4 rbrb() const { return xzxz(); }
  HLML_INLINEF int4 rbra() const { return xzxw(); }
  HLML_INLINEF int4 rbgr() const { return xzyx(); }
  HLML_INLINEF int4 rbgg() const { return xzyy(); }
  HLML_INLINEF int4 rbgb() const { return xzyz(); }
  HLML_INLINEF int4 rbga() const { return xzyw(); }
  HLML_INLINEF int4 rbbr() const { return xzzx(); }
  HLML_INLINEF int4 rbbg() const { return xzzy(); }
  HLML_INLINEF int4 rbbb() const { return xzzz(); }
  HLML_INLINEF int4 rbba() const { return xzzw(); }
  HLML_INLINEF int4 rbar() const { return xzwx(); }
  HLML_INLINEF int4 rbag() const { return xzwy(); }
  HLML_INLINEF int4 rbab() const { return xzwz(); }
  HLML_INLINEF int4 rbaa() const { return xzww(); }
  HLML_INLINEF int4 rarr() const { return xwxx(); }
  HLML_INLINEF int4 rarg() const { return xwxy(); }
  HLML_INLINEF int4 rarb() const { return xwxz(); }
  HLML_INLINEF int4 rara() const { return xwxw(); }
  HLML_INLINEF int4 ragr() const { return xwyx(); }
  HLML_INLINEF int4 ragg() const { return xwyy(); }
  HLML_INLINEF int4 ragb() const { return xwyz(); }
  HLML_INLINEF int4 raga() const { return xwyw(); }
  HLML_INLINEF int4 rabr() const { return xwzx(); }
  HLML_INLINEF int4 rabg() const { return xwzy(); }
  HLML_INLINEF int4 rabb() const { return xwzz(); }
  HLML_INLINEF int4 raba() const { return xwzw(); }
  HLML_INLINEF int4 raar() const { return xwwx(); }
  HLML_INLINEF int4 raag() const { return xwwy(); }
  HLML_INLINEF int4 raab() const { return xwwz(); }
  HLML_INLINEF int4 raaa() const { return xwww(); }

  HLML_INLINEF int4 grrr() const { return yxxx(); }
  HLML_INLINEF int4 grrg() const { return yxxy(); }
  HLML_INLINEF int4 grrb() const { return yxxz(); }
  HLML_INLINEF int4 grra() const { return yxxw(); }
  HLML_INLINEF int4 grgr() const { return yxyx(); }
  HLML_INLINEF int4 grgg() const { return yxyy(); }
  HLML_INLINEF int4 grgb() const { return yxyz(); }
  HLML_INLINEF int4 grga() const { return yxyw(); }
  HLML_INLINEF int4 grbr() const { return yxzx(); }
  HLML_INLINEF int4 grbg() const { return yxzy(); }
  HLML_INLINEF int4 grbb() const { return yxzz(); }
  HLML_INLINEF int4 grba() const { return yxzw(); }
  HLML_INLINEF int4 grar() const { return yxwx(); }
  HLML_INLINEF int4 grag() const { return yxwy(); }
  HLML_INLINEF int4 grab() const { return yxwz(); }
  HLML_INLINEF int4 graa() const { return yxww(); }
  HLML_INLINEF int4 ggrr() const { return yyxx(); }
  HLML_INLINEF int4 ggrg() const { return yyxy(); }
  HLML_INLINEF int4 ggrb() const { return yyxz(); }
  HLML_INLINEF int4 ggra() const { return yyxy(); }
  HLML_INLINEF int4 gggr() const { return yyyx(); }
  HLML_INLINEF int4 gggg() const { return yyyy(); }
  HLML_INLINEF int4 gggb() const { return yyyz(); }
  HLML_INLINEF int4 ggga() const { return yyyw(); }
  HLML_INLINEF int4 ggbr() const { return yyzx(); }
  HLML_INLINEF int4 ggbg() const { return yyzy(); }
  HLML_INLINEF int4 ggbb() const { return yyzz(); }
  HLML_INLINEF int4 ggba() const { return yyzw(); }
  HLML_INLINEF int4 ggar() const { return yywx(); }
  HLML_INLINEF int4 ggag() const { return yywy(); }
  HLML_INLINEF int4 ggab() const { return yywz(); }
  HLML_INLINEF int4 ggaa() const { return yyww(); }
  HLML_INLINEF int4 gbrr() const { return yzxx(); }
  HLML_INLINEF int4 gbrg() const { return yzxy(); }
  HLML_INLINEF int4 gbrb() const { return yzxz(); }
  HLML_INLINEF int4 gbra() const { return yzxw(); }
  HLML_INLINEF int4 gbgr() const { return yzyx(); }
  HLML_INLINEF int4 gbgg() const { return yzyy(); }
  HLML_INLINEF int4 gbgb() const { return yzyz(); }
  HLML_INLINEF int4 gbga() const { return yzyw(); }
  HLML_INLINEF int4 gbbr() const { return yzzx(); }
  HLML_INLINEF int4 gbbg() const { return yzzy(); }
  HLML_INLINEF int4 gbbb() const { return yzzz(); }
  HLML_INLINEF int4 gbba() const { return yzzw(); }
  HLML_INLINEF int4 gbar() const { return yzwx(); }
  HLML_INLINEF int4 gbag() const { return yzwy(); }
  HLML_INLINEF int4 gbab() const { return yzwz(); }
  HLML_INLINEF int4 gbaa() const { return yzww(); }
  HLML_INLINEF int4 garr() const { return ywxx(); }
  HLML_INLINEF int4 garg() const { return ywxy(); }
  HLML_INLINEF int4 garb() const { return ywxz(); }
  HLML_INLINEF int4 gara() const { return ywxw(); }
  HLML_INLINEF int4 gagr() const { return ywyx(); }
  HLML_INLINEF int4 gagg() const { return ywyy(); }
  HLML_INLINEF int4 gagb() const { return ywyz(); }
  HLML_INLINEF int4 gaga() const { return ywyw(); }
  HLML_INLINEF int4 gabr() const { return ywzx(); }
  HLML_INLINEF int4 gabg() const { return ywzy(); }
  HLML_INLINEF int4 gabb() const { return ywzz(); }
  HLML_INLINEF int4 gaba() const { return ywzw(); }
  HLML_INLINEF int4 gaar() const { return ywwx(); }
  HLML_INLINEF int4 gaag() const { return ywwy(); }
  HLML_INLINEF int4 gaab() const { return ywwz(); }
  HLML_INLINEF int4 gaaa() const { return ywww(); }

  HLML_INLINEF int4 brrr() const { return zxxx(); }
  HLML_INLINEF int4 brrg() const { return zxxy(); }
  HLML_INLINEF int4 brrb() const { return zxxz(); }
  HLML_INLINEF int4 brra() const { return zxxw(); }
  HLML_INLINEF int4 brgr() const { return zxyx(); }
  HLML_INLINEF int4 brgg() const { return zxyy(); }
  HLML_INLINEF int4 brgb() const { return zxyz(); }
  HLML_INLINEF int4 brga() const { return zxyw(); }
  HLML_INLINEF int4 brbr() const { return zxzx(); }
  HLML_INLINEF int4 brbg() const { return zxzy(); }
  HLML_INLINEF int4 brbb() const { return zxzz(); }
  HLML_INLINEF int4 brba() const { return zxzw(); }
  HLML_INLINEF int4 brar() const { return zxwx(); }
  HLML_INLINEF int4 brag() const { return zxwy(); }
  HLML_INLINEF int4 brab() const { return zxwz(); }
  HLML_INLINEF int4 braa() const { return zxww(); }
  HLML_INLINEF int4 bgrr() const { return zyxx(); }
  HLML_INLINEF int4 bgrg() const { return zyxy(); }
  HLML_INLINEF int4 bgrb() const { return zyxz(); }
  HLML_INLINEF int4 bgra() const { return zyxy(); }
  HLML_INLINEF int4 bggr() const { return zyyx(); }
  HLML_INLINEF int4 bggg() const { return zyyy(); }
  HLML_INLINEF int4 bggb() const { return zyyz(); }
  HLML_INLINEF int4 bgga() const { return zyyw(); }
  HLML_INLINEF int4 bgbr() const { return zyzx(); }
  HLML_INLINEF int4 bgbg() const { return zyzy(); }
  HLML_INLINEF int4 bgbb() const { return zyzz(); }
  HLML_INLINEF int4 bgba() const { return zyzw(); }
  HLML_INLINEF int4 bgar() const { return zywx(); }
  HLML_INLINEF int4 bgag() const { return zywy(); }
  HLML_INLINEF int4 bgab() const { return zywz(); }
  HLML_INLINEF int4 bgaa() const { return zyww(); }
  HLML_INLINEF int4 bbrr() const { return zzxx(); }
  HLML_INLINEF int4 bbrg() const { return zzxy(); }
  HLML_INLINEF int4 bbrb() const { return zzxz(); }
  HLML_INLINEF int4 bbra() const { return zzxw(); }
  HLML_INLINEF int4 bbgr() const { return zzyx(); }
  HLML_INLINEF int4 bbgg() const { return zzyy(); }
  HLML_INLINEF int4 bbgb() const { return zzyz(); }
  HLML_INLINEF int4 bbga() const { return zzyw(); }
  HLML_INLINEF int4 bbbr() const { return zzzx(); }
  HLML_INLINEF int4 bbbg() const { return zzzy(); }
  HLML_INLINEF int4 bbbb() const { return zzzz(); }
  HLML_INLINEF int4 bbba() const { return zzzw(); }
  HLML_INLINEF int4 bbar() const { return zzwx(); }
  HLML_INLINEF int4 bbag() const { return zzwy(); }
  HLML_INLINEF int4 bbab() const { return zzwz(); }
  HLML_INLINEF int4 bbaa() const { return zzww(); }
  HLML_INLINEF int4 barr() const { return zwxx(); }
  HLML_INLINEF int4 barg() const { return zwxy(); }
  HLML_INLINEF int4 barb() const { return zwxz(); }
  HLML_INLINEF int4 bara() const { return zwxw(); }
  HLML_INLINEF int4 bagr() const { return zwyx(); }
  HLML_INLINEF int4 bagg() const { return zwyy(); }
  HLML_INLINEF int4 bagb() const { return zwyz(); }
  HLML_INLINEF int4 baga() const { return zwyw(); }
  HLML_INLINEF int4 babr() const { return zwzx(); }
  HLML_INLINEF int4 babg() const { return zwzy(); }
  HLML_INLINEF int4 babb() const { return zwzz(); }
  HLML_INLINEF int4 baba() const { return zwzw(); }
  HLML_INLINEF int4 baar() const { return zwwx(); }
  HLML_INLINEF int4 baag() const { return zwwy(); }
  HLML_INLINEF int4 baab() const { return zwwz(); }
  HLML_INLINEF int4 baaa() const { return zwww(); }

  HLML_INLINEF int4 arrr() const { return wxxx(); }
  HLML_INLINEF int4 arrg() const { return wxxy(); }
  HLML_INLINEF int4 arrb() const { return wxxz(); }
  HLML_INLINEF int4 arra() const { return wxxw(); }
  HLML_INLINEF int4 argr() const { return wxyx(); }
  HLML_INLINEF int4 argg() const { return wxyy(); }
  HLML_INLINEF int4 argb() const { return wxyz(); }
  HLML_INLINEF int4 arga() const { return wxyw(); }
  HLML_INLINEF int4 arbr() const { return wxzx(); }
  HLML_INLINEF int4 arbg() const { return wxzy(); }
  HLML_INLINEF int4 arbb() const { return wxzz(); }
  HLML_INLINEF int4 arba() const { return wxzw(); }
  HLML_INLINEF int4 arar() const { return wxwx(); }
  HLML_INLINEF int4 arag() const { return wxwy(); }
  HLML_INLINEF int4 arab() const { return wxwz(); }
  HLML_INLINEF int4 araa() const { return wxww(); }
  HLML_INLINEF int4 agrr() const { return wyxx(); }
  HLML_INLINEF int4 agrg() const { return wyxy(); }
  HLML_INLINEF int4 agrb() const { return wyxz(); }
  HLML_INLINEF int4 agra() const { return wyxy(); }
  HLML_INLINEF int4 aggr() const { return wyyx(); }
  HLML_INLINEF int4 aggg() const { return wyyy(); }
  HLML_INLINEF int4 aggb() const { return wyyz(); }
  HLML_INLINEF int4 agga() const { return wyyw(); }
  HLML_INLINEF int4 agbr() const { return wyzx(); }
  HLML_INLINEF int4 agbg() const { return wyzy(); }
  HLML_INLINEF int4 agbb() const { return wyzz(); }
  HLML_INLINEF int4 agba() const { return wyzw(); }
  HLML_INLINEF int4 agar() const { return wywx(); }
  HLML_INLINEF int4 agag() const { return wywy(); }
  HLML_INLINEF int4 agab() const { return wywz(); }
  HLML_INLINEF int4 agaa() const { return wyww(); }
  HLML_INLINEF int4 abrr() const { return wzxx(); }
  HLML_INLINEF int4 abrg() const { return wzxy(); }
  HLML_INLINEF int4 abrb() const { return wzxz(); }
  HLML_INLINEF int4 abra() const { return wzxw(); }
  HLML_INLINEF int4 abgr() const { return wzyx(); }
  HLML_INLINEF int4 abgg() const { return wzyy(); }
  HLML_INLINEF int4 abgb() const { return wzyz(); }
  HLML_INLINEF int4 abga() const { return wzyw(); }
  HLML_INLINEF int4 abbr() const { return wzzx(); }
  HLML_INLINEF int4 abbg() const { return wzzy(); }
  HLML_INLINEF int4 abbb() const { return wzzz(); }
  HLML_INLINEF int4 abba() const { return wzzw(); }
  HLML_INLINEF int4 abar() const { return wzwx(); }
  HLML_INLINEF int4 abag() const { return wzwy(); }
  HLML_INLINEF int4 abab() const { return wzwz(); }
  HLML_INLINEF int4 abaa() const { return wzww(); }
  HLML_INLINEF int4 aarr() const { return wwxx(); }
  HLML_INLINEF int4 aarg() const { return wwxy(); }
  HLML_INLINEF int4 aarb() const { return wwxz(); }
  HLML_INLINEF int4 aara() const { return wwxw(); }
  HLML_INLINEF int4 aagr() const { return wwyx(); }
  HLML_INLINEF int4 aagg() const { return wwyy(); }
  HLML_INLINEF int4 aagb() const { return wwyz(); }
  HLML_INLINEF int4 aaga() const { return wwyw(); }
  HLML_INLINEF int4 aabr() const { return wwzx(); }
  HLML_INLINEF int4 aabg() const { return wwzy(); }
  HLML_INLINEF int4 aabb() const { return wwzz(); }
  HLML_INLINEF int4 aaba() const { return wwzw(); }
  HLML_INLINEF int4 aaar() const { return wwwx(); }
  HLML_INLINEF int4 aaag() const { return wwwy(); }
  HLML_INLINEF int4 aaab() const { return wwwz(); }
  HLML_INLINEF int4 aaaa() const { return wwww(); }
};

HLML_INLINEF bool4   operator== (int4 a, int4 b) { return bool4(funcs::ftoi(cmpeq(a, b).m)); }
HLML_INLINEF bool4   operator!= (int4 a, int4 b) { return bool4(funcs::ftoi(cmpneq(a, b).m)); }
HLML_INLINEF bool4   operator<  (int4 a, int4 b) { return bool4(funcs::ftoi(cmplt(a, b).m)); }
HLML_INLINEF bool4   operator>  (int4 a, int4 b) { return bool4(funcs::ftoi(cmpgt(a, b).m)); }
HLML_INLINEF bool4   operator<= (int4 a, int4 b) { return bool4(funcs::ftoi(cmple(a, b).m)); }
HLML_INLINEF bool4   operator>= (int4 a, int4 b) { return bool4(funcs::ftoi(cmpge(a, b).m)); }

HLML_INLINEF int4 sumv(int4 v) { v.m = funcs::AhaddB(v.m, v.zwxy().m); v.m = funcs::AhaddB(v.m, v.m); return v; }
HLML_INLINEF I32 hmin(int4 v) { v = min(v, shufflei4(v, 1, 0, 3, 2)); return min(v, shufflei4(v, 3, 2, 1, 0)).x(); }
HLML_INLINEF I32 hmax(int4 v) { v = max(v, shufflei4(v, 1, 0, 3, 2)); return max(v, shufflei4(v, 3, 2, 1, 0)).x(); }
}
