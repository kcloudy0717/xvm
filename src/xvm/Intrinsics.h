#pragma once
#include <cstdint>
#include <intrin.h>
#include <xmmintrin.h>
#include <immintrin.h>

#define INTRINSICS_INLINE inline

#define INTRINSICS_CALLCONV __vectorcall

#define INTRINSICS_SHUFFLE_PS(v, c) _mm_shuffle_ps(v, v, c)

// https://stackoverflow.com/questions/51641131/how-to-achieve-vector-swizzling-in-c
// https://docs.microsoft.com/en-us/cpp/cpp/m128?view=msvc-160

namespace xvm
{
	// TODO: Add swizzling to float2,float3,float4
	template<int I>
	struct scalar_swizzle
	{
		operator float() const { return fp32[I]; }
	private:
		union
		{
			__m128 vec;
			float fp32[4];
		};
	};

	struct float2
	{
		float2() : vec(_mm_setzero_ps()) { }
		float2(__m128 a) : vec(a) { }
		float2(float x, float y) : vec(_mm_set_ps(0.0f, 0.0f, y, x)) { }
		float2(float scalar) : float2(scalar, scalar) { }
		float2(float floats[2]) : float2(floats[0], floats[1]) { }

		union
		{
			__m128 vec;
			scalar_swizzle<0> x;
			scalar_swizzle<1> y;
		};
	};

	struct float3
	{
		float3() : vec(_mm_setzero_ps()) { }
		float3(__m128 a) : vec(a) { }
		float3(float x, float y, float z) : vec(_mm_set_ps(0.0f, z, y, x)) { }
		float3(float scalar) : float3(scalar, scalar, scalar) { }
		float3(float floats[3]) : float3(floats[0], floats[1], floats[2]) { }

		union
		{
			__m128 vec;
			scalar_swizzle<0> x;
			scalar_swizzle<1> y;
			scalar_swizzle<2> z;
		};
	};

	struct float4
	{
		float4() : vec(_mm_setzero_ps()) { }
		float4(__m128 a) : vec(a) { }
		float4(float x, float y, float z, float w) : vec(_mm_set_ps(w, z, y, x)) { }
		float4(float scalar) : float4(scalar, scalar, scalar, scalar) { }
		float4(float floats[4]) : float4(floats[0], floats[1], floats[2], floats[3]) { }

		union
		{
			__m128 vec;
			scalar_swizzle<0> x;
			scalar_swizzle<1> y;
			scalar_swizzle<2> z;
			scalar_swizzle<3> w;
		};
	};
}