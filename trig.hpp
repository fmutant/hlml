#pragma once

#include "float4.hpp"

namespace hlml {
float4 log(float4 x);
float4 exp(float4 x);
void sincos(float4 x, float4& s, float4& c);
float4 sincos(float4 x);
float4 tan(float4 x);
float4 atan(float4 x);
float4 atan2(float4 x, float4 y);
}