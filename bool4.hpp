#pragma once

#include "bool3.hpp"

namespace hlml {
struct bool4 {
  static constexpr U32 flagsall = 0x8888;

  VI128 m = { 0 };

  HLML_INLINEF bool4() {}
  HLML_INLINEF explicit bool4(B8 x, B8 y, B8 z, B8 w) : m(funcs::setXYZW(x, y, z, w)) {}
  HLML_INLINEF explicit bool4(B8* p) : bool4(p[0], p[1], p[2], p[3]) {}
  HLML_INLINEF explicit bool4(bool3 v, B8 w) : bool4(v.x(), v.y(), v.z(), w) {}
  HLML_INLINEF explicit bool4(VI128 v) : m(v) {}

  HLML_INLINEF void store(B8 *p) const { p[0] = x(); p[1] = y(); p[2] = z(); p[3] = w(); }

  HLML_INLINEF void setX(B8 x) { m = inserti(m, x, 0); }
  HLML_INLINEF void setY(B8 y) { m = inserti(m, y, 1); }
  HLML_INLINEF void setZ(B8 y) { m = inserti(m, y, 2); }
  HLML_INLINEF void setW(B8 y) { m = inserti(m, y, 3); }

  HLML_INLINEF B8 x() const { return 0 != extracti(m, 0); }
  HLML_INLINEF B8 y() const { return 0 != extracti(m, 1); }
  HLML_INLINEF B8 z() const { return 0 != extracti(m, 2); }
  HLML_INLINEF B8 w() const { return 0 != extracti(m, 3); }

  HLML_INLINEF bool2 xx() const { return shuffleb2(*this, 0, 0); }
  HLML_INLINEF bool2 xy() const { return shuffleb2(*this, 0, 1); }
  HLML_INLINEF bool2 xz() const { return shuffleb2(*this, 0, 2); }
  HLML_INLINEF bool2 xw() const { return shuffleb2(*this, 0, 3); }
  HLML_INLINEF bool2 yx() const { return shuffleb2(*this, 1, 0); }
  HLML_INLINEF bool2 yy() const { return shuffleb2(*this, 1, 1); }
  HLML_INLINEF bool2 yz() const { return shuffleb2(*this, 1, 2); }
  HLML_INLINEF bool2 yw() const { return shuffleb2(*this, 1, 3); }
  HLML_INLINEF bool2 zx() const { return shuffleb2(*this, 2, 0); }
  HLML_INLINEF bool2 zy() const { return shuffleb2(*this, 2, 1); }
  HLML_INLINEF bool2 zz() const { return shuffleb2(*this, 2, 2); }
  HLML_INLINEF bool2 zw() const { return shuffleb2(*this, 2, 3); }
  HLML_INLINEF bool2 wx() const { return shuffleb2(*this, 3, 0); }
  HLML_INLINEF bool2 wy() const { return shuffleb2(*this, 3, 1); }
  HLML_INLINEF bool2 wz() const { return shuffleb2(*this, 3, 2); }
  HLML_INLINEF bool2 ww() const { return shuffleb2(*this, 3, 3); }

  HLML_INLINEF bool3 xxx() const { return shuffleb3(*this, 0, 0, 0); }
  HLML_INLINEF bool3 xxy() const { return shuffleb3(*this, 0, 0, 1); }
  HLML_INLINEF bool3 xxz() const { return shuffleb3(*this, 0, 0, 2); }
  HLML_INLINEF bool3 xxw() const { return shuffleb3(*this, 0, 0, 3); }
  HLML_INLINEF bool3 xyx() const { return shuffleb3(*this, 0, 1, 0); }
  HLML_INLINEF bool3 xyy() const { return shuffleb3(*this, 0, 1, 1); }
  HLML_INLINEF bool3 xyz() const { return shuffleb3(*this, 0, 1, 2); }
  HLML_INLINEF bool3 xyw() const { return shuffleb3(*this, 0, 1, 3); }
  HLML_INLINEF bool3 xzx() const { return shuffleb3(*this, 0, 2, 0); }
  HLML_INLINEF bool3 xzy() const { return shuffleb3(*this, 0, 2, 1); }
  HLML_INLINEF bool3 xzz() const { return shuffleb3(*this, 0, 2, 2); }
  HLML_INLINEF bool3 xzw() const { return shuffleb3(*this, 0, 2, 3); }
  HLML_INLINEF bool3 xwx() const { return shuffleb3(*this, 0, 3, 0); }
  HLML_INLINEF bool3 xwy() const { return shuffleb3(*this, 0, 3, 1); }
  HLML_INLINEF bool3 xwz() const { return shuffleb3(*this, 0, 3, 2); }
  HLML_INLINEF bool3 xww() const { return shuffleb3(*this, 0, 3, 3); }

  HLML_INLINEF bool3 yxx() const { return shuffleb3(*this, 1, 0, 0); }
  HLML_INLINEF bool3 yxy() const { return shuffleb3(*this, 1, 0, 1); }
  HLML_INLINEF bool3 yxz() const { return shuffleb3(*this, 1, 0, 2); }
  HLML_INLINEF bool3 yxw() const { return shuffleb3(*this, 1, 0, 3); }
  HLML_INLINEF bool3 yyx() const { return shuffleb3(*this, 1, 1, 0); }
  HLML_INLINEF bool3 yyy() const { return shuffleb3(*this, 1, 1, 1); }
  HLML_INLINEF bool3 yyz() const { return shuffleb3(*this, 1, 1, 2); }
  HLML_INLINEF bool3 yyw() const { return shuffleb3(*this, 1, 1, 3); }
  HLML_INLINEF bool3 yzx() const { return shuffleb3(*this, 1, 2, 0); }
  HLML_INLINEF bool3 yzy() const { return shuffleb3(*this, 1, 2, 1); }
  HLML_INLINEF bool3 yzz() const { return shuffleb3(*this, 1, 2, 2); }
  HLML_INLINEF bool3 yzw() const { return shuffleb3(*this, 1, 2, 3); }
  HLML_INLINEF bool3 ywx() const { return shuffleb3(*this, 1, 3, 0); }
  HLML_INLINEF bool3 ywy() const { return shuffleb3(*this, 1, 3, 1); }
  HLML_INLINEF bool3 ywz() const { return shuffleb3(*this, 1, 3, 2); }
  HLML_INLINEF bool3 yww() const { return shuffleb3(*this, 1, 3, 3); }

  HLML_INLINEF bool3 zxx() const { return shuffleb3(*this, 2, 0, 0); }
  HLML_INLINEF bool3 zxy() const { return shuffleb3(*this, 2, 0, 1); }
  HLML_INLINEF bool3 zxz() const { return shuffleb3(*this, 2, 0, 2); }
  HLML_INLINEF bool3 zxw() const { return shuffleb3(*this, 2, 0, 3); }
  HLML_INLINEF bool3 zyx() const { return shuffleb3(*this, 2, 1, 0); }
  HLML_INLINEF bool3 zyy() const { return shuffleb3(*this, 2, 1, 1); }
  HLML_INLINEF bool3 zyz() const { return shuffleb3(*this, 2, 1, 2); }
  HLML_INLINEF bool3 zyw() const { return shuffleb3(*this, 2, 1, 3); }
  HLML_INLINEF bool3 zzx() const { return shuffleb3(*this, 2, 2, 0); }
  HLML_INLINEF bool3 zzy() const { return shuffleb3(*this, 2, 2, 1); }
  HLML_INLINEF bool3 zzz() const { return shuffleb3(*this, 2, 2, 2); }
  HLML_INLINEF bool3 zzw() const { return shuffleb3(*this, 2, 2, 3); }
  HLML_INLINEF bool3 zwx() const { return shuffleb3(*this, 2, 3, 0); }
  HLML_INLINEF bool3 zwy() const { return shuffleb3(*this, 2, 3, 1); }
  HLML_INLINEF bool3 zwz() const { return shuffleb3(*this, 2, 3, 2); }
  HLML_INLINEF bool3 zww() const { return shuffleb3(*this, 2, 3, 3); }

  HLML_INLINEF bool4 xxxx() const { return shuffleb4(*this, 0, 0, 0, 0); }
  HLML_INLINEF bool4 xxxy() const { return shuffleb4(*this, 0, 0, 0, 1); }
  HLML_INLINEF bool4 xxxz() const { return shuffleb4(*this, 0, 0, 0, 2); }
  HLML_INLINEF bool4 xxxw() const { return shuffleb4(*this, 0, 0, 0, 3); }
  HLML_INLINEF bool4 xxyx() const { return shuffleb4(*this, 0, 0, 1, 0); }
  HLML_INLINEF bool4 xxyy() const { return shuffleb4(*this, 0, 0, 1, 1); }
  HLML_INLINEF bool4 xxyz() const { return shuffleb4(*this, 0, 0, 1, 2); }
  HLML_INLINEF bool4 xxyw() const { return shuffleb4(*this, 0, 0, 1, 3); }
  HLML_INLINEF bool4 xxzx() const { return shuffleb4(*this, 0, 0, 2, 0); }
  HLML_INLINEF bool4 xxzy() const { return shuffleb4(*this, 0, 0, 2, 1); }
  HLML_INLINEF bool4 xxzz() const { return shuffleb4(*this, 0, 0, 2, 2); }
  HLML_INLINEF bool4 xxzw() const { return shuffleb4(*this, 0, 0, 2, 3); }
  HLML_INLINEF bool4 xxwx() const { return shuffleb4(*this, 0, 0, 3, 0); }
  HLML_INLINEF bool4 xxwy() const { return shuffleb4(*this, 0, 0, 3, 1); }
  HLML_INLINEF bool4 xxwz() const { return shuffleb4(*this, 0, 0, 3, 2); }
  HLML_INLINEF bool4 xxww() const { return shuffleb4(*this, 0, 0, 3, 3); }
  HLML_INLINEF bool4 xyxx() const { return shuffleb4(*this, 0, 1, 0, 0); }
  HLML_INLINEF bool4 xyxy() const { return shuffleb4(*this, 0, 1, 0, 1); }
  HLML_INLINEF bool4 xyxz() const { return shuffleb4(*this, 0, 1, 0, 2); }
  HLML_INLINEF bool4 xyxw() const { return shuffleb4(*this, 0, 1, 0, 3); }
  HLML_INLINEF bool4 xyyx() const { return shuffleb4(*this, 0, 1, 1, 0); }
  HLML_INLINEF bool4 xyyy() const { return shuffleb4(*this, 0, 1, 1, 1); }
  HLML_INLINEF bool4 xyyz() const { return shuffleb4(*this, 0, 1, 1, 2); }
  HLML_INLINEF bool4 xyyw() const { return shuffleb4(*this, 0, 1, 1, 3); }
  HLML_INLINEF bool4 xyzx() const { return shuffleb4(*this, 0, 1, 2, 0); }
  HLML_INLINEF bool4 xyzy() const { return shuffleb4(*this, 0, 1, 2, 1); }
  HLML_INLINEF bool4 xyzz() const { return shuffleb4(*this, 0, 1, 2, 2); }
  HLML_INLINEF bool4 xyzw() const { return *this; }
  HLML_INLINEF bool4 xywx() const { return shuffleb4(*this, 0, 1, 3, 0); }
  HLML_INLINEF bool4 xywy() const { return shuffleb4(*this, 0, 1, 3, 1); }
  HLML_INLINEF bool4 xywz() const { return shuffleb4(*this, 0, 1, 3, 2); }
  HLML_INLINEF bool4 xyww() const { return shuffleb4(*this, 0, 1, 3, 3); }
  HLML_INLINEF bool4 xzxx() const { return shuffleb4(*this, 0, 2, 0, 0); }
  HLML_INLINEF bool4 xzxy() const { return shuffleb4(*this, 0, 2, 0, 1); }
  HLML_INLINEF bool4 xzxz() const { return shuffleb4(*this, 0, 2, 0, 2); }
  HLML_INLINEF bool4 xzxw() const { return shuffleb4(*this, 0, 2, 0, 3); }
  HLML_INLINEF bool4 xzyx() const { return shuffleb4(*this, 0, 2, 1, 0); }
  HLML_INLINEF bool4 xzyy() const { return shuffleb4(*this, 0, 2, 1, 1); }
  HLML_INLINEF bool4 xzyz() const { return shuffleb4(*this, 0, 2, 1, 2); }
  HLML_INLINEF bool4 xzyw() const { return shuffleb4(*this, 0, 2, 1, 3); }
  HLML_INLINEF bool4 xzzx() const { return shuffleb4(*this, 0, 2, 2, 0); }
  HLML_INLINEF bool4 xzzy() const { return shuffleb4(*this, 0, 2, 2, 1); }
  HLML_INLINEF bool4 xzzz() const { return shuffleb4(*this, 0, 2, 2, 2); }
  HLML_INLINEF bool4 xzzw() const { return shuffleb4(*this, 0, 2, 2, 3); }
  HLML_INLINEF bool4 xzwx() const { return shuffleb4(*this, 0, 2, 3, 0); }
  HLML_INLINEF bool4 xzwy() const { return shuffleb4(*this, 0, 2, 3, 1); }
  HLML_INLINEF bool4 xzwz() const { return shuffleb4(*this, 0, 2, 3, 2); }
  HLML_INLINEF bool4 xzww() const { return shuffleb4(*this, 0, 2, 3, 3); }
  HLML_INLINEF bool4 xwxx() const { return shuffleb4(*this, 0, 3, 0, 0); }
  HLML_INLINEF bool4 xwxy() const { return shuffleb4(*this, 0, 3, 0, 1); }
  HLML_INLINEF bool4 xwxz() const { return shuffleb4(*this, 0, 3, 0, 2); }
  HLML_INLINEF bool4 xwxw() const { return shuffleb4(*this, 0, 3, 0, 3); }
  HLML_INLINEF bool4 xwyx() const { return shuffleb4(*this, 0, 3, 1, 0); }
  HLML_INLINEF bool4 xwyy() const { return shuffleb4(*this, 0, 3, 1, 1); }
  HLML_INLINEF bool4 xwyz() const { return shuffleb4(*this, 0, 3, 1, 2); }
  HLML_INLINEF bool4 xwyw() const { return shuffleb4(*this, 0, 3, 1, 3); }
  HLML_INLINEF bool4 xwzx() const { return shuffleb4(*this, 0, 3, 2, 0); }
  HLML_INLINEF bool4 xwzy() const { return shuffleb4(*this, 0, 3, 2, 1); }
  HLML_INLINEF bool4 xwzz() const { return shuffleb4(*this, 0, 3, 2, 2); }
  HLML_INLINEF bool4 xwzw() const { return shuffleb4(*this, 0, 3, 2, 3); }
  HLML_INLINEF bool4 xwwx() const { return shuffleb4(*this, 0, 3, 3, 0); }
  HLML_INLINEF bool4 xwwy() const { return shuffleb4(*this, 0, 3, 3, 1); }
  HLML_INLINEF bool4 xwwz() const { return shuffleb4(*this, 0, 3, 3, 2); }
  HLML_INLINEF bool4 xwww() const { return shuffleb4(*this, 0, 3, 3, 3); }

  HLML_INLINEF bool4 yxxx() const { return shuffleb4(*this, 1, 0, 0, 0); }
  HLML_INLINEF bool4 yxxy() const { return shuffleb4(*this, 1, 0, 0, 1); }
  HLML_INLINEF bool4 yxxz() const { return shuffleb4(*this, 1, 0, 0, 2); }
  HLML_INLINEF bool4 yxxw() const { return shuffleb4(*this, 1, 0, 0, 3); }
  HLML_INLINEF bool4 yxyx() const { return shuffleb4(*this, 1, 0, 1, 0); }
  HLML_INLINEF bool4 yxyy() const { return shuffleb4(*this, 1, 0, 1, 1); }
  HLML_INLINEF bool4 yxyz() const { return shuffleb4(*this, 1, 0, 1, 2); }
  HLML_INLINEF bool4 yxyw() const { return shuffleb4(*this, 1, 0, 1, 3); }
  HLML_INLINEF bool4 yxzx() const { return shuffleb4(*this, 1, 0, 2, 0); }
  HLML_INLINEF bool4 yxzy() const { return shuffleb4(*this, 1, 0, 2, 1); }
  HLML_INLINEF bool4 yxzz() const { return shuffleb4(*this, 1, 0, 2, 2); }
  HLML_INLINEF bool4 yxzw() const { return shuffleb4(*this, 1, 0, 2, 3); }
  HLML_INLINEF bool4 yxwx() const { return shuffleb4(*this, 1, 0, 3, 0); }
  HLML_INLINEF bool4 yxwy() const { return shuffleb4(*this, 1, 0, 3, 1); }
  HLML_INLINEF bool4 yxwz() const { return shuffleb4(*this, 1, 0, 3, 2); }
  HLML_INLINEF bool4 yxww() const { return shuffleb4(*this, 1, 0, 3, 3); }
  HLML_INLINEF bool4 yyxx() const { return shuffleb4(*this, 1, 1, 0, 0); }
  HLML_INLINEF bool4 yyxy() const { return shuffleb4(*this, 1, 1, 0, 1); }
  HLML_INLINEF bool4 yyxz() const { return shuffleb4(*this, 1, 1, 0, 2); }
  HLML_INLINEF bool4 yyxw() const { return shuffleb4(*this, 1, 1, 0, 3); }
  HLML_INLINEF bool4 yyyx() const { return shuffleb4(*this, 1, 1, 1, 0); }
  HLML_INLINEF bool4 yyyy() const { return shuffleb4(*this, 1, 1, 1, 1); }
  HLML_INLINEF bool4 yyyz() const { return shuffleb4(*this, 1, 1, 1, 2); }
  HLML_INLINEF bool4 yyyw() const { return shuffleb4(*this, 1, 1, 1, 3); }
  HLML_INLINEF bool4 yyzx() const { return shuffleb4(*this, 1, 1, 2, 0); }
  HLML_INLINEF bool4 yyzy() const { return shuffleb4(*this, 1, 1, 2, 1); }
  HLML_INLINEF bool4 yyzz() const { return shuffleb4(*this, 1, 1, 2, 2); }
  HLML_INLINEF bool4 yyzw() const { return shuffleb4(*this, 1, 1, 2, 3); }
  HLML_INLINEF bool4 yywx() const { return shuffleb4(*this, 1, 1, 3, 0); }
  HLML_INLINEF bool4 yywy() const { return shuffleb4(*this, 1, 1, 3, 1); }
  HLML_INLINEF bool4 yywz() const { return shuffleb4(*this, 1, 1, 3, 2); }
  HLML_INLINEF bool4 yyww() const { return shuffleb4(*this, 1, 1, 3, 3); }
  HLML_INLINEF bool4 yzxx() const { return shuffleb4(*this, 1, 2, 0, 0); }
  HLML_INLINEF bool4 yzxy() const { return shuffleb4(*this, 1, 2, 0, 1); }
  HLML_INLINEF bool4 yzxz() const { return shuffleb4(*this, 1, 2, 0, 2); }
  HLML_INLINEF bool4 yzxw() const { return shuffleb4(*this, 1, 2, 0, 3); }
  HLML_INLINEF bool4 yzyx() const { return shuffleb4(*this, 1, 2, 1, 0); }
  HLML_INLINEF bool4 yzyy() const { return shuffleb4(*this, 1, 2, 1, 1); }
  HLML_INLINEF bool4 yzyz() const { return shuffleb4(*this, 1, 2, 1, 2); }
  HLML_INLINEF bool4 yzyw() const { return shuffleb4(*this, 1, 2, 1, 3); }
  HLML_INLINEF bool4 yzzx() const { return shuffleb4(*this, 1, 2, 2, 0); }
  HLML_INLINEF bool4 yzzy() const { return shuffleb4(*this, 1, 2, 2, 1); }
  HLML_INLINEF bool4 yzzz() const { return shuffleb4(*this, 1, 2, 2, 2); }
  HLML_INLINEF bool4 yzzw() const { return shuffleb4(*this, 1, 2, 2, 3); }
  HLML_INLINEF bool4 yzwx() const { return shuffleb4(*this, 1, 2, 3, 0); }
  HLML_INLINEF bool4 yzwy() const { return shuffleb4(*this, 1, 2, 3, 1); }
  HLML_INLINEF bool4 yzwz() const { return shuffleb4(*this, 1, 2, 3, 2); }
  HLML_INLINEF bool4 yzww() const { return shuffleb4(*this, 1, 2, 3, 3); }
  HLML_INLINEF bool4 ywxx() const { return shuffleb4(*this, 1, 3, 0, 0); }
  HLML_INLINEF bool4 ywxy() const { return shuffleb4(*this, 1, 3, 0, 1); }
  HLML_INLINEF bool4 ywxz() const { return shuffleb4(*this, 1, 3, 0, 2); }
  HLML_INLINEF bool4 ywxw() const { return shuffleb4(*this, 1, 3, 0, 3); }
  HLML_INLINEF bool4 ywyx() const { return shuffleb4(*this, 1, 3, 1, 0); }
  HLML_INLINEF bool4 ywyy() const { return shuffleb4(*this, 1, 3, 1, 1); }
  HLML_INLINEF bool4 ywyz() const { return shuffleb4(*this, 1, 3, 1, 2); }
  HLML_INLINEF bool4 ywyw() const { return shuffleb4(*this, 1, 3, 1, 3); }
  HLML_INLINEF bool4 ywzx() const { return shuffleb4(*this, 1, 3, 2, 0); }
  HLML_INLINEF bool4 ywzy() const { return shuffleb4(*this, 1, 3, 2, 1); }
  HLML_INLINEF bool4 ywzz() const { return shuffleb4(*this, 1, 3, 2, 2); }
  HLML_INLINEF bool4 ywzw() const { return shuffleb4(*this, 1, 3, 2, 3); }
  HLML_INLINEF bool4 ywwx() const { return shuffleb4(*this, 1, 3, 3, 0); }
  HLML_INLINEF bool4 ywwy() const { return shuffleb4(*this, 1, 3, 3, 1); }
  HLML_INLINEF bool4 ywwz() const { return shuffleb4(*this, 1, 3, 3, 2); }
  HLML_INLINEF bool4 ywww() const { return shuffleb4(*this, 1, 3, 3, 3); }

  HLML_INLINEF bool4 zxxx() const { return shuffleb4(*this, 2, 0, 0, 0); }
  HLML_INLINEF bool4 zxxy() const { return shuffleb4(*this, 2, 0, 0, 1); }
  HLML_INLINEF bool4 zxxz() const { return shuffleb4(*this, 2, 0, 0, 2); }
  HLML_INLINEF bool4 zxxw() const { return shuffleb4(*this, 2, 0, 0, 3); }
  HLML_INLINEF bool4 zxyx() const { return shuffleb4(*this, 2, 0, 1, 0); }
  HLML_INLINEF bool4 zxyy() const { return shuffleb4(*this, 2, 0, 1, 1); }
  HLML_INLINEF bool4 zxyz() const { return shuffleb4(*this, 2, 0, 1, 2); }
  HLML_INLINEF bool4 zxyw() const { return shuffleb4(*this, 2, 0, 1, 3); }
  HLML_INLINEF bool4 zxzx() const { return shuffleb4(*this, 2, 0, 2, 0); }
  HLML_INLINEF bool4 zxzy() const { return shuffleb4(*this, 2, 0, 2, 1); }
  HLML_INLINEF bool4 zxzz() const { return shuffleb4(*this, 2, 0, 2, 2); }
  HLML_INLINEF bool4 zxzw() const { return shuffleb4(*this, 2, 0, 2, 3); }
  HLML_INLINEF bool4 zxwx() const { return shuffleb4(*this, 2, 0, 3, 0); }
  HLML_INLINEF bool4 zxwy() const { return shuffleb4(*this, 2, 0, 3, 1); }
  HLML_INLINEF bool4 zxwz() const { return shuffleb4(*this, 2, 0, 3, 2); }
  HLML_INLINEF bool4 zxww() const { return shuffleb4(*this, 2, 0, 3, 3); }
  HLML_INLINEF bool4 zyxx() const { return shuffleb4(*this, 2, 1, 0, 0); }
  HLML_INLINEF bool4 zyxy() const { return shuffleb4(*this, 2, 1, 0, 1); }
  HLML_INLINEF bool4 zyxz() const { return shuffleb4(*this, 2, 1, 0, 2); }
  HLML_INLINEF bool4 zyxw() const { return shuffleb4(*this, 2, 1, 0, 3); }
  HLML_INLINEF bool4 zyyx() const { return shuffleb4(*this, 2, 1, 1, 0); }
  HLML_INLINEF bool4 zyyy() const { return shuffleb4(*this, 2, 1, 1, 1); }
  HLML_INLINEF bool4 zyyz() const { return shuffleb4(*this, 2, 1, 1, 2); }
  HLML_INLINEF bool4 zyyw() const { return shuffleb4(*this, 2, 1, 1, 3); }
  HLML_INLINEF bool4 zyzx() const { return shuffleb4(*this, 2, 1, 2, 0); }
  HLML_INLINEF bool4 zyzy() const { return shuffleb4(*this, 2, 1, 2, 1); }
  HLML_INLINEF bool4 zyzz() const { return shuffleb4(*this, 2, 1, 2, 2); }
  HLML_INLINEF bool4 zyzw() const { return shuffleb4(*this, 2, 1, 2, 3); }
  HLML_INLINEF bool4 zywx() const { return shuffleb4(*this, 2, 1, 3, 0); }
  HLML_INLINEF bool4 zywy() const { return shuffleb4(*this, 2, 1, 3, 1); }
  HLML_INLINEF bool4 zywz() const { return shuffleb4(*this, 2, 1, 3, 2); }
  HLML_INLINEF bool4 zyww() const { return shuffleb4(*this, 2, 1, 3, 3); }
  HLML_INLINEF bool4 zzxx() const { return shuffleb4(*this, 2, 2, 0, 0); }
  HLML_INLINEF bool4 zzxy() const { return shuffleb4(*this, 2, 2, 0, 1); }
  HLML_INLINEF bool4 zzxz() const { return shuffleb4(*this, 2, 2, 0, 2); }
  HLML_INLINEF bool4 zzxw() const { return shuffleb4(*this, 2, 2, 0, 3); }
  HLML_INLINEF bool4 zzyx() const { return shuffleb4(*this, 2, 2, 1, 0); }
  HLML_INLINEF bool4 zzyy() const { return shuffleb4(*this, 2, 2, 1, 1); }
  HLML_INLINEF bool4 zzyz() const { return shuffleb4(*this, 2, 2, 1, 2); }
  HLML_INLINEF bool4 zzyw() const { return shuffleb4(*this, 2, 2, 1, 3); }
  HLML_INLINEF bool4 zzzx() const { return shuffleb4(*this, 2, 2, 2, 0); }
  HLML_INLINEF bool4 zzzy() const { return shuffleb4(*this, 2, 2, 2, 1); }
  HLML_INLINEF bool4 zzzz() const { return shuffleb4(*this, 2, 2, 2, 2); }
  HLML_INLINEF bool4 zzzw() const { return shuffleb4(*this, 2, 2, 2, 3); }
  HLML_INLINEF bool4 zzwx() const { return shuffleb4(*this, 2, 2, 3, 0); }
  HLML_INLINEF bool4 zzwy() const { return shuffleb4(*this, 2, 2, 3, 1); }
  HLML_INLINEF bool4 zzwz() const { return shuffleb4(*this, 2, 2, 3, 2); }
  HLML_INLINEF bool4 zzww() const { return shuffleb4(*this, 2, 2, 3, 3); }
  HLML_INLINEF bool4 zwxx() const { return shuffleb4(*this, 2, 3, 0, 0); }
  HLML_INLINEF bool4 zwxy() const { return shuffleb4(*this, 2, 3, 0, 1); }
  HLML_INLINEF bool4 zwxz() const { return shuffleb4(*this, 2, 3, 0, 2); }
  HLML_INLINEF bool4 zwxw() const { return shuffleb4(*this, 2, 3, 0, 3); }
  HLML_INLINEF bool4 zwyx() const { return shuffleb4(*this, 2, 3, 1, 0); }
  HLML_INLINEF bool4 zwyy() const { return shuffleb4(*this, 2, 3, 1, 1); }
  HLML_INLINEF bool4 zwyz() const { return shuffleb4(*this, 2, 3, 1, 2); }
  HLML_INLINEF bool4 zwyw() const { return shuffleb4(*this, 2, 3, 1, 3); }
  HLML_INLINEF bool4 zwzx() const { return shuffleb4(*this, 2, 3, 2, 0); }
  HLML_INLINEF bool4 zwzy() const { return shuffleb4(*this, 2, 3, 2, 1); }
  HLML_INLINEF bool4 zwzz() const { return shuffleb4(*this, 2, 3, 2, 2); }
  HLML_INLINEF bool4 zwzw() const { return shuffleb4(*this, 2, 3, 2, 3); }
  HLML_INLINEF bool4 zwwx() const { return shuffleb4(*this, 2, 3, 3, 0); }
  HLML_INLINEF bool4 zwwy() const { return shuffleb4(*this, 2, 3, 3, 1); }
  HLML_INLINEF bool4 zwwz() const { return shuffleb4(*this, 2, 3, 3, 2); }
  HLML_INLINEF bool4 zwww() const { return shuffleb4(*this, 2, 3, 3, 3); }

  HLML_INLINEF bool4 wxxx() const { return shuffleb4(*this, 3, 0, 0, 0); }
  HLML_INLINEF bool4 wxxy() const { return shuffleb4(*this, 3, 0, 0, 1); }
  HLML_INLINEF bool4 wxxz() const { return shuffleb4(*this, 3, 0, 0, 2); }
  HLML_INLINEF bool4 wxxw() const { return shuffleb4(*this, 3, 0, 0, 3); }
  HLML_INLINEF bool4 wxyx() const { return shuffleb4(*this, 3, 0, 1, 0); }
  HLML_INLINEF bool4 wxyy() const { return shuffleb4(*this, 3, 0, 1, 1); }
  HLML_INLINEF bool4 wxyz() const { return shuffleb4(*this, 3, 0, 1, 2); }
  HLML_INLINEF bool4 wxyw() const { return shuffleb4(*this, 3, 0, 1, 3); }
  HLML_INLINEF bool4 wxzx() const { return shuffleb4(*this, 3, 0, 2, 0); }
  HLML_INLINEF bool4 wxzy() const { return shuffleb4(*this, 3, 0, 2, 1); }
  HLML_INLINEF bool4 wxzz() const { return shuffleb4(*this, 3, 0, 2, 2); }
  HLML_INLINEF bool4 wxzw() const { return shuffleb4(*this, 3, 0, 2, 3); }
  HLML_INLINEF bool4 wxwx() const { return shuffleb4(*this, 3, 0, 3, 0); }
  HLML_INLINEF bool4 wxwy() const { return shuffleb4(*this, 3, 0, 3, 1); }
  HLML_INLINEF bool4 wxwz() const { return shuffleb4(*this, 3, 0, 3, 2); }
  HLML_INLINEF bool4 wxww() const { return shuffleb4(*this, 3, 0, 3, 3); }
  HLML_INLINEF bool4 wyxx() const { return shuffleb4(*this, 3, 1, 0, 0); }
  HLML_INLINEF bool4 wyxy() const { return shuffleb4(*this, 3, 1, 0, 1); }
  HLML_INLINEF bool4 wyxz() const { return shuffleb4(*this, 3, 1, 0, 2); }
  HLML_INLINEF bool4 wyxw() const { return shuffleb4(*this, 3, 1, 0, 3); }
  HLML_INLINEF bool4 wyyx() const { return shuffleb4(*this, 3, 1, 1, 0); }
  HLML_INLINEF bool4 wyyy() const { return shuffleb4(*this, 3, 1, 1, 1); }
  HLML_INLINEF bool4 wyyz() const { return shuffleb4(*this, 3, 1, 1, 2); }
  HLML_INLINEF bool4 wyyw() const { return shuffleb4(*this, 3, 1, 1, 3); }
  HLML_INLINEF bool4 wyzx() const { return shuffleb4(*this, 3, 1, 2, 0); }
  HLML_INLINEF bool4 wyzy() const { return shuffleb4(*this, 3, 1, 2, 1); }
  HLML_INLINEF bool4 wyzz() const { return shuffleb4(*this, 3, 1, 2, 2); }
  HLML_INLINEF bool4 wyzw() const { return shuffleb4(*this, 3, 1, 2, 3); }
  HLML_INLINEF bool4 wywx() const { return shuffleb4(*this, 3, 1, 3, 0); }
  HLML_INLINEF bool4 wywy() const { return shuffleb4(*this, 3, 1, 3, 1); }
  HLML_INLINEF bool4 wywz() const { return shuffleb4(*this, 3, 1, 3, 2); }
  HLML_INLINEF bool4 wyww() const { return shuffleb4(*this, 3, 1, 3, 3); }
  HLML_INLINEF bool4 wzxx() const { return shuffleb4(*this, 3, 2, 0, 0); }
  HLML_INLINEF bool4 wzxy() const { return shuffleb4(*this, 3, 2, 0, 1); }
  HLML_INLINEF bool4 wzxz() const { return shuffleb4(*this, 3, 2, 0, 2); }
  HLML_INLINEF bool4 wzxw() const { return shuffleb4(*this, 3, 2, 0, 3); }
  HLML_INLINEF bool4 wzyx() const { return shuffleb4(*this, 3, 2, 1, 0); }
  HLML_INLINEF bool4 wzyy() const { return shuffleb4(*this, 3, 2, 1, 1); }
  HLML_INLINEF bool4 wzyz() const { return shuffleb4(*this, 3, 2, 1, 2); }
  HLML_INLINEF bool4 wzyw() const { return shuffleb4(*this, 3, 2, 1, 3); }
  HLML_INLINEF bool4 wzzx() const { return shuffleb4(*this, 3, 2, 2, 0); }
  HLML_INLINEF bool4 wzzy() const { return shuffleb4(*this, 3, 2, 2, 1); }
  HLML_INLINEF bool4 wzzz() const { return shuffleb4(*this, 3, 2, 2, 2); }
  HLML_INLINEF bool4 wzzw() const { return shuffleb4(*this, 3, 2, 2, 3); }
  HLML_INLINEF bool4 wzwx() const { return shuffleb4(*this, 3, 2, 3, 0); }
  HLML_INLINEF bool4 wzwy() const { return shuffleb4(*this, 3, 2, 3, 1); }
  HLML_INLINEF bool4 wzwz() const { return shuffleb4(*this, 3, 2, 3, 2); }
  HLML_INLINEF bool4 wzww() const { return shuffleb4(*this, 3, 2, 3, 3); }
  HLML_INLINEF bool4 wwxx() const { return shuffleb4(*this, 3, 3, 0, 0); }
  HLML_INLINEF bool4 wwxy() const { return shuffleb4(*this, 3, 3, 0, 1); }
  HLML_INLINEF bool4 wwxz() const { return shuffleb4(*this, 3, 3, 0, 2); }
  HLML_INLINEF bool4 wwxw() const { return shuffleb4(*this, 3, 3, 0, 3); }
  HLML_INLINEF bool4 wwyx() const { return shuffleb4(*this, 3, 3, 1, 0); }
  HLML_INLINEF bool4 wwyy() const { return shuffleb4(*this, 3, 3, 1, 1); }
  HLML_INLINEF bool4 wwyz() const { return shuffleb4(*this, 3, 3, 1, 2); }
  HLML_INLINEF bool4 wwyw() const { return shuffleb4(*this, 3, 3, 1, 3); }
  HLML_INLINEF bool4 wwzx() const { return shuffleb4(*this, 3, 3, 2, 0); }
  HLML_INLINEF bool4 wwzy() const { return shuffleb4(*this, 3, 3, 2, 1); }
  HLML_INLINEF bool4 wwzz() const { return shuffleb4(*this, 3, 3, 2, 2); }
  HLML_INLINEF bool4 wwzw() const { return shuffleb4(*this, 3, 3, 2, 3); }
  HLML_INLINEF bool4 wwwx() const { return shuffleb4(*this, 3, 3, 3, 0); }
  HLML_INLINEF bool4 wwwy() const { return shuffleb4(*this, 3, 3, 3, 1); }
  HLML_INLINEF bool4 wwwz() const { return shuffleb4(*this, 3, 3, 3, 2); }
  HLML_INLINEF bool4 wwww() const { return shuffleb4(*this, 3, 3, 3, 3); }

};
}
