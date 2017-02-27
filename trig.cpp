#include "trig.hpp"
#include "int4.hpp"

namespace hlml {
namespace consts {
// i got these here http://gruntthepeon.free.fr/ssemath/
// and here https://github.com/to-miz/sse_mathfun_extension/blob/master/sse_mathfun_extension.h
static constexpr F32 sfOneNeg = -sfOne;
static constexpr F32 sfHalf = 0.5f;
static constexpr U32 snOne = 1u;
static constexpr U32 snOneN = ~snOne;
static constexpr U32 snTwo = 2u;
static constexpr U32 snFour = 4u;
static constexpr U32 sn127 = 0x7F;

static constexpr U32 snNormPos = 0x00800000;
static constexpr U32 snMaskMantis = 0x7f800000;
static constexpr U32 snMaskMantisN = ~snMaskMantis;

HLML_VCONST vconstu vnormpos = { snNormPos, snNormPos, snNormPos, snNormPos };
HLML_VCONST vconstu vmskmnts = { snMaskMantis, snMaskMantis, snMaskMantis, snMaskMantis };
HLML_VCONST vconstu vmskmntsn = { snMaskMantisN, snMaskMantisN, snMaskMantisN, snMaskMantisN };

HLML_VCONST vconstu vnzeros = { snZero, snZero, snZero, snZero };
HLML_VCONST vconstu vnones = { snOne, snOne, snOne, snOne };
HLML_VCONST vconstu vnonesn = { snOneN, snOneN, snOneN, snOneN };
HLML_VCONST vconstu vntwos = { snTwo, snTwo, snTwo, snTwo };
HLML_VCONST vconstu vnfours = { snFour, snFour, snFour, snFour };
HLML_VCONST vconstu vn127s = { sn127, sn127, sn127, sn127 };

HLML_VCONST vconstu vones = { sfOne, sfOne, sfOne, sfOne };
HLML_VCONST vconstu vonesneg = { sfOneNeg, sfOneNeg, sfOneNeg, sfOneNeg };
HLML_VCONST vconstu vhalves = { sfHalf, sfHalf, sfHalf, sfHalf };
HLML_VCONST vconstu vsqrthf = { 0.707106781186547524f, 0.707106781186547524f, 0.707106781186547524f, 0.707106781186547524f };
HLML_VCONST vconstu vlogp0 = { 7.0376836292E-2f, 7.0376836292E-2f, 7.0376836292E-2f, 7.0376836292E-2f };
HLML_VCONST vconstu vlogp1 = { -1.1514610310E-1f, -1.1514610310E-1f, -1.1514610310E-1f, -1.1514610310E-1f };
HLML_VCONST vconstu vlogp2 = { 1.1676998740E-1f, 1.1676998740E-1f, 1.1676998740E-1f, 1.1676998740E-1f };
HLML_VCONST vconstu vlogp3 = { -1.2420140846E-1f, -1.2420140846E-1f, -1.2420140846E-1f, -1.2420140846E-1f };
HLML_VCONST vconstu vlogp4 = { +1.4249322787E-1f, +1.4249322787E-1f, +1.4249322787E-1f, +1.4249322787E-1f };
HLML_VCONST vconstu vlogp5 = { -1.6668057665E-1f, -1.6668057665E-1f, -1.6668057665E-1f, -1.6668057665E-1f };
HLML_VCONST vconstu vlogp6 = { +2.0000714765E-1f, +2.0000714765E-1f, +2.0000714765E-1f, +2.0000714765E-1f };
HLML_VCONST vconstu vlogp7 = { -2.4999993993E-1f, -2.4999993993E-1f, -2.4999993993E-1f, -2.4999993993E-1f };
HLML_VCONST vconstu vlogp8 = { +3.3333331174E-1f, +3.3333331174E-1f, +3.3333331174E-1f, +3.3333331174E-1f };
HLML_VCONST vconstu vlogq1 = { -2.12194440e-4f, -2.12194440e-4f, -2.12194440e-4f, -2.12194440e-4f };
HLML_VCONST vconstu vlogq2 = { 0.693359375f, 0.693359375f, 0.693359375f, 0.693359375f };
HLML_VCONST vconstu vexphi = { 88.3762626647949f, 88.3762626647949f, 88.3762626647949f, 88.3762626647949f };
HLML_VCONST vconstu vexplo = { -88.3762626647949f, -88.3762626647949f, -88.3762626647949f, -88.3762626647949f };
HLML_VCONST vconstu vlogef = { 1.44269504088896341f, 1.44269504088896341f, 1.44269504088896341f, 1.44269504088896341f };
HLML_VCONST vconstu vexpc1 = { 0.693359375f, 0.693359375f, 0.693359375f, 0.693359375f };
HLML_VCONST vconstu vexpc2 = { -2.12194440e-4f, -2.12194440e-4f, -2.12194440e-4f, -2.12194440e-4f };
HLML_VCONST vconstu vexpp0 = { 1.9875691500E-4f, 1.9875691500E-4f, 1.9875691500E-4f, 1.9875691500E-4f };
HLML_VCONST vconstu vexpp1 = { 1.3981999507E-3f, 1.3981999507E-3f, 1.3981999507E-3f, 1.3981999507E-3f };
HLML_VCONST vconstu vexpp2 = { 8.3334519073E-3f, 8.3334519073E-3f, 8.3334519073E-3f, 8.3334519073E-3f };
HLML_VCONST vconstu vexpp3 = { 4.1665795894E-2f, 4.1665795894E-2f, 4.1665795894E-2f, 4.1665795894E-2f };
HLML_VCONST vconstu vexpp4 = { 1.6666665459E-1f, 1.6666665459E-1f, 1.6666665459E-1f, 1.6666665459E-1f };
HLML_VCONST vconstu vexpp5 = { 5.0000001201E-1f, 5.0000001201E-1f, 5.0000001201E-1f, 5.0000001201E-1f };
HLML_VCONST vconstu vnegdp1 = { -0.78515625f, -0.78515625f, -0.78515625f, -0.78515625f };
HLML_VCONST vconstu vnegdp2 = { -2.4187564849853515625e-4f, -2.4187564849853515625e-4f, -2.4187564849853515625e-4f, -2.4187564849853515625e-4f };
HLML_VCONST vconstu vnegdp3 = { -3.77489497744594108e-8f, -3.77489497744594108e-8f, -3.77489497744594108e-8f, -3.77489497744594108e-8f };
HLML_VCONST vconstu vsincp0 = { -1.9515295891E-4f, -1.9515295891E-4f, -1.9515295891E-4f, -1.9515295891E-4f };
HLML_VCONST vconstu vsincp1 = { 8.3321608736E-3f, 8.3321608736E-3f, 8.3321608736E-3f, 8.3321608736E-3f };
HLML_VCONST vconstu vsincp2 = { -1.6666654611E-1f, -1.6666654611E-1f, -1.6666654611E-1f, -1.6666654611E-1f };
HLML_VCONST vconstu vcoscp0 = { 2.443315711809948E-005f, 2.443315711809948E-005f, 2.443315711809948E-005f, 2.443315711809948E-005f };
HLML_VCONST vconstu vcoscp1 = { -1.388731625493765E-003f, -1.388731625493765E-003f, -1.388731625493765E-003f, -1.388731625493765E-003f };
HLML_VCONST vconstu vcoscp2 = { 4.166664568298827E-002f, 4.166664568298827E-002f, 4.166664568298827E-002f, 4.166664568298827E-002f };
HLML_VCONST vconstu vtancp0 = { 9.38540185543E-3f, 9.38540185543E-3f, 9.38540185543E-3f, 9.38540185543E-3f };
HLML_VCONST vconstu vtancp1 = { 3.11992232697E-3f, 3.11992232697E-3f, 3.11992232697E-3f, 3.11992232697E-3f };
HLML_VCONST vconstu vtancp2 = { 2.44301354525E-2f, 2.44301354525E-2f, 2.44301354525E-2f, 2.44301354525E-2f };
HLML_VCONST vconstu vtancp3 = { 5.34112807005E-2f, 5.34112807005E-2f, 5.34112807005E-2f, 5.34112807005E-2f };
HLML_VCONST vconstu vtancp4 = { 1.33387994085E-1f, 1.33387994085E-1f, 1.33387994085E-1f, 1.33387994085E-1f };
HLML_VCONST vconstu vtancp5 = { 3.33331568548E-1f, 3.33331568548E-1f, 3.33331568548E-1f, 3.33331568548E-1f };
HLML_VCONST vconstu vtaneps = { 1.0e-4f, 1.0e-4f, 1.0e-4f, 1.0e-4f };
HLML_VCONST vconstu vfopi = { 1.27323954473516f, 1.27323954473516f, 1.27323954473516f, 1.27323954473516f };// 4 / M_PI
HLML_VCONST vconstu vpif = { 3.141592653589793238f, 3.141592653589793238f, 3.141592653589793238f, 3.141592653589793238f };
HLML_VCONST vconstu vpih = { 1.5707963267948966192f, 1.5707963267948966192f, 1.5707963267948966192f, 1.5707963267948966192f};
HLML_VCONST vconstu vpiq = { 0.7853981633974483096f, 0.7853981633974483096f, 0.7853981633974483096f, 0.7853981633974483096f};
HLML_VCONST vconstu vatanhi = { 2.414213562373095f, 2.414213562373095f, 2.414213562373095f, 2.414213562373095f };
HLML_VCONST vconstu vatanlo = { 0.4142135623730950f, 0.4142135623730950f, 0.4142135623730950f, 0.4142135623730950f };
HLML_VCONST vconstu vatanp0 = { 8.05374449538e-2f, 8.05374449538e-2f, 8.05374449538e-2f, 8.05374449538e-2f };
HLML_VCONST vconstu vatanp1 = { 1.38776856032E-1f, 1.38776856032E-1f, 1.38776856032E-1f, 1.38776856032E-1f };
HLML_VCONST vconstu vatanp2 = { 1.99777106478E-1f, 1.99777106478E-1f, 1.99777106478E-1f, 1.99777106478E-1f };
HLML_VCONST vconstu vatanp3 = { 3.33329491539E-1f, 3.33329491539E-1f, 3.33329491539E-1f, 3.33329491539E-1f };
}
float4 log(float4 x) {
  const float4 ones(consts::vones), zeros(consts::vzeros), halves(consts::vhalves), npos(consts::vnormpos), sqrthf(consts::vsqrthf), mantisn(consts::vmskmntsn), lp1(consts::vlogp1), lp2(consts::vlogp2), lp3(consts::vlogp3), lp4(consts::vlogp4), lp5(consts::vlogp5), lp6(consts::vlogp6), lp7(consts::vlogp7), lp8(consts::vlogp8), lq1(consts::vlogq1), lq2(consts::vlogq2);
  const int4 v127(consts::vn127s);

  float4 maskinv = cmple(x, zeros);
  x = max(x, npos);
  int4 emm0((asint(x) >> 23) - v127);
  x = (x & mantisn) | halves;
  float4 mask = cmplt(x, sqrthf), e = toflt(emm0) - (ones & mask) + ones;
  x = x - ones + (x & mask);
  float4 z(x * x), y(consts::vlogp0);
  y = y * x + lp1;
  y = y * x + lp2;
  y = y * x + lp3;
  y = y * x + lp4;
  y = y * x + lp5;
  y = y * x + lp6;
  y = y * x + lp7;
  y = y * x + lp8;
  y = y * z * x + e * lq1 + e * lq2 - z * halves;
  return (x + y) | maskinv;
}

float4 exp(float4 x) {
  const float4 one(consts::vones), ehi(consts::vexphi), elo(consts::vexplo), elf(consts::vlogef), halves(consts::vhalves), exc1(consts::vexpc1), exc2(consts::vexpc2), exp1(consts::vexpp1), exp2(consts::vexpp2), exp3(consts::vexpp3), exp4(consts::vexpp4), exp5(consts::vexpp5);
  const int4 n127(consts::vn127s);
  float4 xex = max(elo, min(x, ehi)), fx = xex * elf + halves; //express exp(x) as exp(g + n*log(2))
  float4 nfx(toflt(toint(fx))); //how to perform a floorf with SSE: just below
  fx = toflt(toint(fx)) - (cmpgt(nfx, fx) & one); //if greater, substract 1
  xex = xex - fx * exc1 - fx * exc2;

  float4 z(xex * xex), poly(consts::vexpp0);
  poly = poly * xex + exp1;
  poly = poly * xex + exp2;
  poly = poly * xex + exp3;
  poly = poly * xex + exp4;
  poly = poly * xex + exp5;
  poly = poly * z + xex + one;

  return poly * asflt((toint(fx) + n127) << 23);// build 2^n
}

void sincos(float4 x, float4& s, float4& c) {
  const int4 ones(consts::vnones), nones(consts::vnonesn), zeros(consts::vnzeros), twos(consts::vntwos), fours(consts::vnfours);
  const float4 cp1(consts::vcoscp1), cp2(consts::vcoscp2), sp1(consts::vsincp1), sp2(consts::vsincp2), halves(consts::vhalves), fones(consts::vones), ndp1(consts::vnegdp1), ndp2(consts::vnegdp2), ndp3(consts::vnegdp3), fpi(consts::vfopi);

  float4 ax(abs(x)), y(ax * fpi);
  int4 emm2 = nones & (toint(y) + ones);
  y = toflt(emm2);
  float4 dps = ((ax + y * ndp1) + y * ndp2) + y * ndp3, z(dps * dps), polyc(consts::vcoscp0), polys(consts::vsincp0);
  polyc = polyc * z + cp1;
  polys = polys * z + sp1;
  polyc = polyc * z + cp2;
  polys = polys * z + sp2;
  polyc = polyc * z * z - halves * z + fones;
  polys = polys * z * dps + dps;
  
  float4 polymsk = asflt(cmpeq((emm2 & twos), zeros)), polymskn(~polymsk);
  float4 ysin = (polymsk & polys) + (polymskn & polyc);
  float4 ycos = polyc + polys - ysin;
  float4 signs_cos = asflt((~(emm2 - twos) & fours) << 29);
  float4 signs_sin = (x & float4(consts::vsignbits)) ^ asflt((emm2 & fours) << 29);
  s = ysin ^ signs_sin;
  c = ycos ^ signs_cos;
}

float4 sincos(float4 x) {
  float4 s, c;
  sincos(x, s, c);
  return float4(funcs::ayaxbybx(s.m, c.m));
}

float4 tan(float4 x) {
  const float4 signs(consts::vsignbits), ones(consts::vones), signsres(x & signs), fopi(consts::vfopi), tanp1(consts::vtancp1), tanp2(consts::vtancp2), tanp3(consts::vtancp3), tanp4(consts::vtancp4), tanp5(consts::vtancp5);
  const int4 iones(consts::vnones), ionesn(consts::vnonesn), twos(consts::vntwos), nzeros(consts::vnzeros);

	float4 ax(abs(x));
	/* store the integer part of y in mm0 */
	int4 emm2 = (toint(ax * fopi) + iones) & ionesn;
  float4 y = toflt(emm2);
  emm2 = cmpeq(emm2 & twos, nzeros);
  const float4 polymsk(asflt(emm2)), polymskn(~polymsk);

	float4 z = ((ax + y * float4(consts::vnegdp1)) + y * float4(consts::vnegdp2)) + y * float4(consts::vnegdp3), zz(z * z), poly(consts::vtancp0);
	poly = poly * zz + tanp1;
	poly = poly * zz + tanp2;
	poly = poly * zz + tanp3;
	poly = poly * zz + tanp4;
	poly = poly * zz + tanp5;
	poly = poly * zz * z + z;

	float4 polyinv = ones / poly;
	poly = (poly & polymsk) | (-polyinv & polymskn);
	return poly ^ signsres;
}

float4 atan(float4 x) {
  const float4 signsn(consts::vsignbitsn), signs(consts::vsignbits), ones(consts::vones), atanhi(consts::vatanhi), atanlo(consts::vatanlo), pih(consts::vpih), piq(consts::vpiq), atanp0(consts::vatanp0), atanp1(consts::vatanp1), atanp2(consts::vatanp2), atanp3(consts::vatanp3);
  float4 ax = abs(x), r = ax - ones, r0 = rcp(ax + ones), r1 = -rcp(ax);
	float4 cmp0 = cmpgt(ax, atanhi), cmp1 = cmpgt(ax, atanlo), cmp2 = ~cmp0 & cmp1, cmp = cmp0 | cmp1;
	float4 x2 = (cmp2 & (r * r0)) | (cmp0 & r1);
	ax = (cmp & x2) | (~cmp & ax);

	float4 zz = ax * ax, acc = atanp0;
	acc = acc * zz - atanp1;
	acc = acc * zz + atanp2;
	acc = acc * zz - atanp3;
	acc = acc * zz * ax + ax + ((cmp0 & pih) | (cmp2 & piq));
	return acc ^ (x & signs);
}

float4 atan2(float4 x, float4 y) {
  const float4 zeros(consts::vzeros), signs(consts::vsignbits), pi(consts::vpif), pih(consts::vpih);
	float4 xeq = cmpeq(x, zeros), xgt = cmpgt(x, zeros), xle = cmple(x, zeros), xlt = cmplt(x, zeros), yeq = cmpeq(y, zeros), ylt = cmplt(y, zeros);
	float4 zero_mask = (xeq & yeq) | (xgt & yeq), pio2_mask = ~yeq &  xeq;
	float4 pio2_result = (pih ^ (ylt & signs)) & pio2_mask;
	float4 atan_result = atan(y / x) + (xlt & (pi ^ (xlt & ylt & signs)));

	return (~zero_mask & pio2_result) | (~pio2_mask & atan_result) | (pi & xle & yeq);
}
}
