#pragma once

#include "common.hpp"
#include "float4.hpp"
#include "trig.hpp"

namespace hlml {
struct float4x4 {
  float4 c0, c1, c2, c3;

  HLML_INLINEF float4x4() : c0(), c1(), c2(), c3() {}
  HLML_INLINEF explicit float4x4(const F32* p) : c0(p), c1(p+4), c2(p+8), c3(p+12) {}
  HLML_INLINEF float4x4(F32 x0, F32 y0, F32 z0, F32 w0, F32 x1, F32 y1, F32 z1, F32 w1, F32 x2, F32 y2, F32 z2, F32 w2, F32 x3, F32 y3, F32 z3, F32 w3) : c0(x0, y0, z0, w0), c1(x1, y1, z1, w1), c2(x2, y2, z2, w2), c3(x3, y3, z3, w3) {}
  HLML_INLINEF float4x4(float4 col0, float4 col1, float4 col2, float4 col3) : c0(col0), c1(col1), c2(col2), c3(col3) {}

  HLML_INLINEF static float4x4 identity() { static float4x4 i( { 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f } ); return i; }

  HLML_INLINEF float4x4& operator= (float4x4 b) { c0 = b.c0; c1 = b.c1; c2 = b.c2; c3 = b.c3; return *this; }
  HLML_INLINEF float4x4& operator= (F32 s) { c0 = c1 = c2 = c3 = float4(s); return *this; }
};

HLML_INLINEF float4x4 transpose(float4x4 m) {
  float4 t0(axbxayby(m.c0.m, m.c1.m));
  float4 t2(azbzawbw(m.c0.m, m.c1.m));
  float4 t1(axbxayby(m.c2.m, m.c3.m));
  float4 t3(azbzawbw(m.c2.m, m.c3.m));
  m.c0.m = axaybxby(t0.m, t1.m);
  m.c1.m = bzbwazaw(t1.m, t0.m);
	m.c2.m = axaybxby(t2.m, t3.m);
  m.c3.m = bzbwazaw(t3.m, t2.m);
  return m;
}

HLML_INLINEF float4x4 inverse(float4x4 m) {
  float4 A(axbxayby(m.c0.m, m.c1.m)), B(axbxayby(m.c2.m, m.c3.m)), C(azbzawbw(m.c0.m, m.c1.m)), D(azbzawbw(m.c2.m, m.c3.m));
  float4 AB = A.wwxx() * B - A.yyzz() * B.zwxy();
  float4 t0 = AB.xyxy() * C.xxzz() + AB.zwzw() * C.yyww();
  float4 t1 = AB.wxwx() * D - AB.zyzy() * D.yxwz();
  float4 DC = D.wwxx() * C - D.yyzz() * C.zwxy();
  float4 t2 = DC.wxwx() * A - DC.zyzy() * A.yxwz();
  float4 t3 = DC.xyxy() * B.xxzz() + DC.zwzw() * B.yyww();

  float4 dA = A * A.wwyy();
  dA = (dA - dA.zwzw()).xxxx();
  float4 iD = D * dA - t0;
  float4 dB = B.wwyy() * B;
  dB = (dB - dB.zwzw()).xxxx();
  float4 iB = C * dB - t1;
  float4 dC = C.wwyy() * C;
  dC = (dC - dC.zwzw()).xxxx();
  float4 iC = B * dC - t2;
  float4 dD = D.wwyy() * D;
  dD = (dD - dD.zwzw()).xxxx();
  float4 iA = A * dD - t3;

  float4 det = dA * dD + dB * dC - dotv(DC.xzyw(), AB);
  det.m = AxorB(det.m, vsignpnnp);
  float4 idet = rcp(det);
  iA *= idet;
  iB *= idet;
  iC *= idet;
  iD *= idet;

  m.c0.m = awazbwbz(iA.m, iC.m);
  m.c1.m = ayaxbybx(iA.m, iC.m);
  m.c2.m = awazbwbz(iB.m, iD.m);
  m.c3.m = ayaxbybx(iB.m, iD.m);

  return m;
}

HLML_INLINEF float4x4 inverse2(float4x4 m) {
  float4  xz0xz2(axazbxbz(m.c0.m, m.c2.m))
		    , yw0yw2(ayawbybw(m.c0.m, m.c2.m))
		    , yw1yw3(ayawbybw(m.c1.m, m.c3.m))
		    , xz1xz3(axazbxbz(m.c1.m, m.c3.m));
	float4  dACBD(xz0xz2 * yw1yw3 - yw0yw2 * xz1xz3)
		    , A(axbxayby(m.c0.m, m.c1.m))
		    , B(axbxayby(m.c2.m, m.c3.m))
		    , AB(A.wwxx() * B - A.yyzz() * B.zwxy())
		    , C(azbzawbw(m.c0.m, m.c1.m))
		    , D(azbzawbw(m.c2.m, m.c3.m))
		    , DC(D.wwxx() * C - D.yyzz() * C.zwxy());
	float4  dA(dACBD.xxxx())
		    , dB(dACBD.zzzz())
		    , dC(dACBD.yyyy())
		    , dD(dACBD.wwww())
		    , dAD(dA * dD)
		    , dBC(dB * dC)
		    , AdD(A * dD)
		    , CdB(C * dB)
		    , BdC(B * dC)
		    , DdA(D * dA);
	float4 det = dAD + dBC - dotv(DC.xzyw(), AB);
    det.m = AxorB(det.m, vsignpnnp);
	float4 t0(DC.xyxy() * B.xxzz() + DC.zwzw() * B.yyww())
		 , t1(AB.wxwx() * D - AB.zyzy() * D.yxwz())
		 , t2(DC.wxwx() * A - DC.zyzy() * A.yxwz())
		 , t3(AB.xyxy() * C.xxzz() + AB.zwzw() * C.yyww());
	float4 iA((AdD - t0) / det)
		 , iB((CdB - t1) / det)
		 , iC((BdC - t2) / det)
		 , iD((DdA - t3) / det);
	
    m.c0.m = awazbwbz(iA.m, iC.m);
    m.c1.m = ayaxbybx(iA.m, iC.m);
    m.c2.m = awazbwbz(iB.m, iD.m);
    m.c3.m = ayaxbybx(iB.m, iD.m);

	return m;
}

HLML_INLINEF B8         operator==  (float4x4 lhs, float4x4 rhs) { return all(lhs.c0 == rhs.c0) && all(lhs.c1 == rhs.c1) && all(lhs.c2 == rhs.c2) && all(lhs.c3 == rhs.c3); }
HLML_INLINEF B8         operator!=  (float4x4 lhs, float4x4 rhs) { return !(lhs == rhs); }

HLML_INLINEF float4x4   operator+   (float4x4 m) { return m; }
HLML_INLINEF float4x4   operator+   (float4x4 a, float4x4 b) { a.c0 += b.c0; a.c1 += b.c1; a.c2 += b.c2; a.c3 += b.c3; return a; }
HLML_INLINEF float4x4   operator+   (float4x4 a, F32 s) { a.c0 += s; a.c1 += s; a.c2 += s; a.c3 += s; return a; }
HLML_INLINEF float4x4   operator+   (F32 s, float4x4 a) { return a + s; }
HLML_INLINEF float4x4&  operator+=  (float4x4& a, float4x4 b) { a = a + b; return a; }
HLML_INLINEF float4x4&  operator+=  (float4x4& a, F32 s) { a = a + s; return a; }
HLML_INLINEF float4x4   operator-   (float4x4 m) { m.c0 = -m.c0; m.c1 = -m.c1; m.c2 = -m.c2, m.c3 = -m.c3; return m; }
HLML_INLINEF float4x4   operator-   (float4x4 a, float4x4 b) { a.c0 -= b.c0; a.c1 -= b.c1; a.c2 -= b.c2; a.c3 -= b.c3; return a; }
HLML_INLINEF float4x4   operator-   (float4x4 a, F32 s) { float4 tmp(s); return a - float4x4(tmp, tmp, tmp, tmp); }
HLML_INLINEF float4x4   operator-   (F32 s, float4x4 a) { float4 tmp(s); return float4x4(tmp, tmp, tmp, tmp) - a; }
HLML_INLINEF float4x4&  operator-=  (float4x4& a, float4x4 b) { a = a - b; return a; }
HLML_INLINEF float4x4&  operator-=  (float4x4& a, F32 s) { a = a - s; return a; }
HLML_INLINEF float4x4   operator*   (float4x4 a, float4x4 b) {
  float4 lc0 = a.c0, lc1 = a.c1, lc2 = a.c2, lc3 = a.c3, rc0 = b.c0, rc1 = b.c1, rc2 = b.c2, rc3 = b.c3;
  a.c0 = lc0 * rc0.xxxx() + lc1 * rc0.yyyy() + lc2 * rc0.zzzz() + lc3 * rc0.wwww();
  a.c1 = lc0 * rc1.xxxx() + lc1 * rc1.yyyy() + lc2 * rc1.zzzz() + lc3 * rc1.wwww();
  a.c2 = lc0 * rc2.xxxx() + lc1 * rc2.yyyy() + lc2 * rc2.zzzz() + lc3 * rc2.wwww();
  a.c3 = lc0 * rc3.xxxx() + lc1 * rc3.yyyy() + lc2 * rc3.zzzz() + lc3 * rc3.wwww();
  return a;
}
HLML_INLINEF float4x4   operator*   (float4x4 a, F32 s) { a.c0 *= s; a.c1 *= s; a.c2 *= s; a.c3 *= s; return a; }
HLML_INLINEF float4x4   operator*   (F32 s, float4x4 a) { return a * s; }
HLML_INLINEF float4     operator*   (float4x4 a, float4 v) { return v.xxxx() * a.c0 + v.yyyy() * a.c1 + v.zzzz() * a.c2 + v.wwww() * a.c3; }
HLML_INLINEF float4     operator*   (float4 v, float4x4 a) {
  float4 xxxx(dotv(v, a.c0)), yyyy(dotv(v, a.c1)), zzzz(dotv(v, a.c2)), wwww(dotv(v, a.c3));
  float4 xyxy(axbxayby(xxxx.m, yyyy.m)), zwzw(axbxayby(zzzz.m, wwww.m)), xyzw(axaybxby(xyxy.m, zwzw.m));
  return xyzw;
}
HLML_INLINEF float4x4&  operator*=  (float4x4& a, float4x4 b) { a = a * b; return a; }
HLML_INLINEF float4x4&  operator*=  (float4x4& a, F32 s) { a = a * s; return a; }
HLML_INLINEF float4x4   operator/   (float4x4 a, F32 s) { a.c0 /= s; a.c1 /= s; a.c2 /= s; a.c3 /= s; return a; }
HLML_INLINEF float4x4&  operator/=  (float4x4& a, F32 s) { a = a / s; return a; }

HLML_INLINEF float4x4 perspective(F32 fovDegs, F32 aspectW2H, F32 zNear, F32 zFar) {
  const float4 rads(HLML_DEG2RAD(fovDegs) * 0.5f);
  const F32 scaley = (1.0f / tan(rads)).x();

  const F32 aspectInv = 1.0f / aspectW2H;
  const F32 scalex = aspectInv * scaley;
  const F32 zdiff = 1.0f / (zNear - zFar);
  const F32 roty = (zNear + zFar) * zdiff;
  const F32 tranz = 2.0f * zFar * zNear * zdiff;
  return float4x4(
    scalex, 0.0f, 0.0f, 0.0f,
    0.0f, scaley, 0.0f, 0.0f,
    0.0f, 0.0f,   roty, -1.0f,
    0.0f, 0.0f,  tranz, 0.0f
  );
}

HLML_INLINEF float4x4 perspectiveInvZ(F32 fovDegs, F32 aspectW2H, F32 zNear) {
  const float4 rads(HLML_DEG2RAD(fovDegs) * 0.5f);
  const F32 scaley = (1.0f / tan(rads)).x();
  const F32 aspectInv = 1.0f / aspectW2H;
  const F32 scalex = aspectInv * scaley;
  return float4x4(
    scalex, 0.0f,  0.0f,  0.0f,
    0.0f, scaley,  0.0f,  0.0f,
    0.0f, 0.0f,    0.0f, -1.0f,
    0.0f, 0.0f,   zNear,  0.0f
  );
}
}
