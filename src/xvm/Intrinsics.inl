#pragma once

namespace xvm
{
	INTRINSICS_INLINE float4x4::float4x4()
	{
		r[0] = XVMIdentityR0;
		r[1] = XVMIdentityR1;
		r[2] = XVMIdentityR2;
		r[3] = XVMIdentityR3;
	}

	INTRINSICS_INLINE float2 INTRINSICS_CALLCONV operator-(float2 v)
	{
		//return _mm_sub_ps(_mm_setzero_ps(), v.vec);
		return _mm_xor_ps(v.vec, XVMMaskNegative);
	}
	INTRINSICS_INLINE float3 INTRINSICS_CALLCONV operator-(float3 v)
	{
		//return _mm_sub_ps(_mm_setzero_ps(), v.vec);
		return _mm_xor_ps(v.vec, XVMMaskNegative);
	}
	INTRINSICS_INLINE float4 INTRINSICS_CALLCONV operator-(float4 v)
	{
		//return _mm_sub_ps(_mm_setzero_ps(), v.vec);
		return _mm_xor_ps(v.vec, XVMMaskNegative);
	}
	INTRINSICS_INLINE float4x4 INTRINSICS_CALLCONV operator-(float4x4 m)
	{
		__m128 nx = _mm_xor_ps(m.r[0], XVMMaskNegative);
		__m128 ny = _mm_xor_ps(m.r[1], XVMMaskNegative);
		__m128 nz = _mm_xor_ps(m.r[2], XVMMaskNegative);
		__m128 nw = _mm_xor_ps(m.r[3], XVMMaskNegative);
		return float4x4(nx, ny, nz, nw);
	}

	INTRINSICS_INLINE float2 INTRINSICS_CALLCONV operator+(float2 v1, float2 v2) { return { _mm_add_ps(v1.vec, v2.vec) }; }
	INTRINSICS_INLINE float3 INTRINSICS_CALLCONV operator+(float3 v1, float3 v2) { return { _mm_add_ps(v1.vec, v2.vec) }; }
	INTRINSICS_INLINE float4 INTRINSICS_CALLCONV operator+(float4 v1, float4 v2) { return { _mm_add_ps(v1.vec, v2.vec) }; }
	INTRINSICS_INLINE float4x4 INTRINSICS_CALLCONV operator+(float4x4 m1, float4x4 m2)
	{
		__m128 r0 = _mm_add_ps(m1.r[0], m2.r[0]);
		__m128 r1 = _mm_add_ps(m1.r[1], m2.r[1]);
		__m128 r2 = _mm_add_ps(m1.r[2], m2.r[2]);
		__m128 r3 = _mm_add_ps(m1.r[3], m2.r[3]);
		return float4x4(r0, r1, r2, r3);
	}

	INTRINSICS_INLINE float2 INTRINSICS_CALLCONV operator-(float2 v1, float2 v2) { return { _mm_sub_ps(v1.vec, v2.vec) }; }
	INTRINSICS_INLINE float3 INTRINSICS_CALLCONV operator-(float3 v1, float3 v2) { return { _mm_sub_ps(v1.vec, v2.vec) }; }
	INTRINSICS_INLINE float4 INTRINSICS_CALLCONV operator-(float4 v1, float4 v2) { return { _mm_sub_ps(v1.vec, v2.vec) }; }
	INTRINSICS_INLINE float4x4 INTRINSICS_CALLCONV operator-(float4x4 m1, float4x4 m2)
	{
		__m128 r0 = _mm_sub_ps(m1.r[0], m2.r[0]);
		__m128 r1 = _mm_sub_ps(m1.r[1], m2.r[1]);
		__m128 r2 = _mm_sub_ps(m1.r[2], m2.r[2]);
		__m128 r3 = _mm_sub_ps(m1.r[3], m2.r[3]);
		return float4x4(r0, r1, r2, r3);
	}

	INTRINSICS_INLINE float2 INTRINSICS_CALLCONV operator*(float2 v1, float2 v2) { return { _mm_mul_ps(v1.vec, v2.vec) }; }
	INTRINSICS_INLINE float3 INTRINSICS_CALLCONV operator*(float3 v1, float3 v2) { return { _mm_mul_ps(v1.vec, v2.vec) }; }
	INTRINSICS_INLINE float4 INTRINSICS_CALLCONV operator*(float4 v1, float4 v2) { return { _mm_mul_ps(v1.vec, v2.vec) }; }
	INTRINSICS_INLINE float4x4 INTRINSICS_CALLCONV operator*(float4x4 m, float scalar)
	{
		__m128 s = _mm_set1_ps(scalar);
		__m128 r0 = _mm_mul_ps(m.r[0], s);
		__m128 r1 = _mm_mul_ps(m.r[1], s);
		__m128 r2 = _mm_mul_ps(m.r[2], s);
		__m128 r3 = _mm_mul_ps(m.r[3], s);
		return float4x4(r0, r1, r2, r3);
	}
	INTRINSICS_INLINE float4x4 INTRINSICS_CALLCONV operator*(float scalar, float4x4 m)
	{
		// scalar multiplication is commutative
		return m * scalar;
	}
	INTRINSICS_INLINE float4x4 INTRINSICS_CALLCONV operator*(float4x4 m1, float4x4 m2)
	{
		return mul(m1, m2);
	}

	INTRINSICS_INLINE float2 INTRINSICS_CALLCONV operator/(float2 v1, float2 v2) { return { _mm_div_ps(v1.vec, v2.vec) }; }
	INTRINSICS_INLINE float3 INTRINSICS_CALLCONV operator/(float3 v1, float3 v2) { return { _mm_div_ps(v1.vec, v2.vec) }; }
	INTRINSICS_INLINE float4 INTRINSICS_CALLCONV operator/(float4 v1, float4 v2) { return { _mm_div_ps(v1.vec, v2.vec) }; }
	INTRINSICS_INLINE float4x4 INTRINSICS_CALLCONV operator/(float4x4 m, float scalar)
	{
		__m128 s = _mm_set1_ps(scalar);
		__m128 r0 = _mm_div_ps(m.r[0], s);
		__m128 r1 = _mm_div_ps(m.r[1], s);
		__m128 r2 = _mm_div_ps(m.r[2], s);
		__m128 r3 = _mm_div_ps(m.r[3], s);
		return float4x4(r0, r1, r2, r3);
	}

	INTRINSICS_INLINE float2& INTRINSICS_CALLCONV operator+=(float2& v1, float2 v2) { v1 = v1 + v2; return v1; }
	INTRINSICS_INLINE float3& INTRINSICS_CALLCONV operator+=(float3& v1, float3 v2) { v1 = v1 + v2; return v1; }
	INTRINSICS_INLINE float4& INTRINSICS_CALLCONV operator+=(float4& v1, float4 v2) { v1 = v1 + v2; return v1; }
	INTRINSICS_INLINE float4x4& INTRINSICS_CALLCONV operator+=(float4x4& m1, float4x4 m2) { m1 = m1 + m2; return m1; }

	INTRINSICS_INLINE float2& INTRINSICS_CALLCONV operator-=(float2& v1, float2 v2) { v1 = v1 - v2; return v1; }
	INTRINSICS_INLINE float3& INTRINSICS_CALLCONV operator-=(float3& v1, float3 v2) { v1 = v1 - v2; return v1; }
	INTRINSICS_INLINE float4& INTRINSICS_CALLCONV operator-=(float4& v1, float4 v2) { v1 = v1 - v2; return v1; }
	INTRINSICS_INLINE float4x4& INTRINSICS_CALLCONV operator-=(float4x4& m1, float4x4 m2) { m1 = m1 - m2; return m1; }

	INTRINSICS_INLINE float2& INTRINSICS_CALLCONV operator*=(float2& v1, float2 v2) { v1 = v1 * v2; return v1; }
	INTRINSICS_INLINE float3& INTRINSICS_CALLCONV operator*=(float3& v1, float3 v2) { v1 = v1 * v2; return v1; }
	INTRINSICS_INLINE float4& INTRINSICS_CALLCONV operator*=(float4& v1, float4 v2) { v1 = v1 * v2; return v1; }
	INTRINSICS_INLINE float4x4& INTRINSICS_CALLCONV operator*=(float4x4& m, float scalar) { m = m * scalar; return m; }
	INTRINSICS_INLINE float4x4& INTRINSICS_CALLCONV operator*=(float4x4& m1, float4x4 m2) { m1 = m1 * m2; return m1; }

	INTRINSICS_INLINE float2& INTRINSICS_CALLCONV operator/=(float2& v1, float2 v2) { v1 = v1 / v2; return v1; }
	INTRINSICS_INLINE float3& INTRINSICS_CALLCONV operator/=(float3& v1, float3 v2) { v1 = v1 / v2; return v1; }
	INTRINSICS_INLINE float4& INTRINSICS_CALLCONV operator/=(float4& v1, float4 v2) { v1 = v1 / v2; return v1; }
	INTRINSICS_INLINE float4x4& INTRINSICS_CALLCONV operator/=(float4x4& m, float scalar) { m = m / scalar; return m; }

	INTRINSICS_INLINE float2 INTRINSICS_CALLCONV abs(float2 v)
	{
		// & the sign bit
		return _mm_and_ps(XVMMaskAbsoluteValue, v.vec);
	}
	INTRINSICS_INLINE float3 INTRINSICS_CALLCONV abs(float3 v)
	{
		// & the sign bit
		return _mm_and_ps(XVMMaskAbsoluteValue, v.vec);
	}
	INTRINSICS_INLINE float4 INTRINSICS_CALLCONV abs(float4 v)
	{
		// & the sign bit
		return _mm_and_ps(XVMMaskAbsoluteValue, v.vec);
	}

	INTRINSICS_INLINE bool INTRINSICS_CALLCONV all(float2 v)
	{
		// v != 0
		__m128 dst = _mm_cmpneq_ps(v.vec, _mm_setzero_ps());
		// If all is non-zero, the mask is exactly 0x00000003
		int mask = _mm_movemask_ps(dst) & 0x00000003;
		return mask == 0x00000003;
	}
	INTRINSICS_INLINE bool INTRINSICS_CALLCONV all(float3 v)
	{
		// v != 0
		__m128 dst = _mm_cmpneq_ps(v.vec, _mm_setzero_ps());
		// If all is non-zero, the mask is exactly 0x00000007
		int mask = _mm_movemask_ps(dst) & 0x00000007;
		return mask == 0x00000007;
	}
	INTRINSICS_INLINE bool INTRINSICS_CALLCONV all(float4 v)
	{
		// v != 0
		__m128 dst = _mm_cmpneq_ps(v.vec, _mm_setzero_ps());
		// If all is non-zero, the mask is exactly 0x0000000F
		int mask = _mm_movemask_ps(dst) & 0x0000000F;
		return mask == 0x0000000F;
	}

	INTRINSICS_INLINE bool INTRINSICS_CALLCONV any(float2 v)
	{
		// v != 0
		__m128 dst = _mm_cmpneq_ps(v.vec, _mm_setzero_ps());
		// If x or y are non-zero, the mask is non-zero
		int mask = _mm_movemask_ps(dst) & 0x00000003;
		return mask != 0;
	}
	INTRINSICS_INLINE bool INTRINSICS_CALLCONV any(float3 v)
	{
		// v != 0
		__m128 dst = _mm_cmpneq_ps(v.vec, _mm_setzero_ps());
		// If x or y or z are non-zero, the mask is non-zero
		int mask = _mm_movemask_ps(dst) & 0x00000007;
		return mask != 0;
	}
	INTRINSICS_INLINE bool INTRINSICS_CALLCONV any(float4 v)
	{
		// v != 0
		__m128 dst = _mm_cmpneq_ps(v.vec, _mm_setzero_ps());
		// If x or y or z or w are non-zero, the mask is non-zero
		int mask = _mm_movemask_ps(dst) & 0x0000000F;
		return mask != 0;
	}

	INTRINSICS_INLINE float2 INTRINSICS_CALLCONV clamp(float2 v, float2 min, float2 max)
	{
		__m128 xmm0 = _mm_min_ps(v.vec, max.vec);
		__m128 xmm1 = _mm_max_ps(xmm0, min.vec);
		return xmm1;
	}
	INTRINSICS_INLINE float3 INTRINSICS_CALLCONV clamp(float3 v, float3 min, float3 max)
	{
		__m128 xmm0 = _mm_min_ps(v.vec, max.vec);
		__m128 xmm1 = _mm_max_ps(xmm0, min.vec);
		return xmm1;
	}
	INTRINSICS_INLINE float4 INTRINSICS_CALLCONV clamp(float4 v, float4 min, float4 max)
	{
		__m128 xmm0 = _mm_min_ps(v.vec, max.vec);
		__m128 xmm1 = _mm_max_ps(xmm0, min.vec);
		return xmm1;
	}

	INTRINSICS_INLINE float3 INTRINSICS_CALLCONV cross(float3 v1, float3 v2)
	{
		/*
		* http://threadlocalmutex.com/?p=8
		* (v1 x v2).x = v1.y * v2.z - v1.z * v2.y;
		* (v1 x v2).y = v1.z * v2.x - v1.x * v2.z;
		* (v1 x v2).z = v1.x * v2.y - v1.y * v2.x;
		*
		* moving the 3rd operation to top yields this
		*
		* (v1 x v2).z = v1.x * v2.y - v1.y * v2.x;
		* (v1 x v2).x = v1.y * v2.z - v1.z * v2.y;
		* (v1 x v2).y = v1.z * v2.x - v1.x * v2.z;
		*
		* we can perform swizzling here
		*
		* (v1 x v2).zxy = v1 * v2.yzx - v1.yzx * v2;
		*
		* swizzle zxy on both sides gives us the cross product again
		*
		* (v1 x v2) = (v1 * v2.yzx - v1.yzx * v2).yzx;
		*/
		__m128 v1_yzx = INTRINSICS_SHUFFLE_PS(v1.vec, _MM_SHUFFLE(3, 0, 2, 1));
		__m128 v2_yzx = INTRINSICS_SHUFFLE_PS(v2.vec, _MM_SHUFFLE(3, 0, 2, 1));
		__m128 cross = _mm_sub_ps(_mm_mul_ps(v1.vec, v2_yzx), _mm_mul_ps(v1_yzx, v2.vec));
		return INTRINSICS_SHUFFLE_PS(cross, _MM_SHUFFLE(3, 0, 2, 1));
	}

	INTRINSICS_INLINE float2 INTRINSICS_CALLCONV dot(float2 v1, float2 v2)
	{
		__m128 dot = _mm_mul_ps(v1.vec, v2.vec);
		__m128 shuff = INTRINSICS_SHUFFLE_PS(dot, _MM_SHUFFLE(1, 1, 1, 1)); // { y, y, y, y }
		dot = _mm_add_ss(dot, shuff); // { x+y, ?, ?, ? }
		return INTRINSICS_SHUFFLE_PS(dot, _MM_SHUFFLE(0, 0, 0, 0)); // splat fp0
	}
	INTRINSICS_INLINE float3 INTRINSICS_CALLCONV dot(float3 v1, float3 v2)
	{
		__m128 dot = _mm_mul_ps(v1.vec, v2.vec);
		__m128 shuff = INTRINSICS_SHUFFLE_PS(dot, _MM_SHUFFLE(2, 2, 2, 1)); // { y, z, z, z }
		dot = _mm_add_ss(dot, shuff); // { x+y, ?, ?, ? }
		shuff = INTRINSICS_SHUFFLE_PS(dot, _MM_SHUFFLE(2, 2, 2, 2)); // { z, z, z, z }
		dot = _mm_add_ss(dot, shuff); // { x+y+z, ?, ?, ? }
		return INTRINSICS_SHUFFLE_PS(dot, _MM_SHUFFLE(0, 0, 0, 0)); // splat fp0
	}
	INTRINSICS_INLINE float4 INTRINSICS_CALLCONV dot(float4 v1, float4 v2)
	{
		__m128 dot = _mm_mul_ps(v1.vec, v2.vec);
		__m128 shuff = INTRINSICS_SHUFFLE_PS(dot, _MM_SHUFFLE(2, 3, 0, 1)); // { y, x, w, z }
		dot = _mm_add_ps(dot, shuff); // { x+y, y+x, z+w, w+z }
		shuff = _mm_movehl_ps(shuff, dot); // { dot.fp2, dot.fp3, shuff.fp2, shuff.fp3 }
		dot = _mm_add_ss(dot, shuff); // { x+y+z+w, ?, ?, ? }
		return INTRINSICS_SHUFFLE_PS(dot, _MM_SHUFFLE(0, 0, 0, 0)); // splat fp0
	}

	INTRINSICS_INLINE bool INTRINSICS_CALLCONV isfinite(float2 v)
	{
		// Mask off the sign bit
		__m128 and = _mm_and_ps(v.vec, XVMMaskAbsoluteValue);
		// v != infinity
		__m128 cmp = _mm_cmpneq_ps(and, XVMInfinity);
		// If x, y is finite, the mask is exactly 0x00000003
		int mask = _mm_movemask_ps(cmp) & 0x00000003;
		return mask == 0x00000003;
	}
	INTRINSICS_INLINE bool INTRINSICS_CALLCONV isfinite(float3 v)
	{
		// Mask off the sign bit
		__m128 and = _mm_and_ps(v.vec, XVMMaskAbsoluteValue);
		// v != infinity
		__m128 cmp = _mm_cmpneq_ps(and, XVMInfinity);
		// If x, y, z is finite, the mask is exactly 0x00000007
		int mask = _mm_movemask_ps(cmp) & 0x00000007;
		return mask == 0x00000007;
	}
	INTRINSICS_INLINE bool INTRINSICS_CALLCONV isfinite(float4 v)
	{
		// Mask off the sign bit
		__m128 and = _mm_and_ps(v.vec, XVMMaskAbsoluteValue);
		// v != infinity
		__m128 cmp = _mm_cmpneq_ps(and, XVMInfinity);
		// If x, y, z, w is finite, the mask is exactly 0x0000000F
		int mask = _mm_movemask_ps(cmp) & 0x0000000F;
		return mask == 0x0000000F;
	}

	INTRINSICS_INLINE bool INTRINSICS_CALLCONV isinf(float2 v)
	{
		// Mask off the sign bit then compare to infinity
		__m128 and = _mm_and_ps(v.vec, XVMMaskAbsoluteValue);
		// v == infinity
		__m128 cmp = _mm_cmpeq_ps(and, XVMInfinity);
		// If x or y is infinity, the mask is non-zero
		int mask = _mm_movemask_ps(cmp) & 0x00000003;
		return mask != 0;
	}
	INTRINSICS_INLINE bool INTRINSICS_CALLCONV isinf(float3 v)
	{
		// Mask off the sign bit then compare to infinity
		__m128 and = _mm_and_ps(v.vec, XVMMaskAbsoluteValue);
		// v == infinity
		__m128 cmp = _mm_cmpeq_ps(and, XVMInfinity);
		// If x or y or z is infinity, the mask is non-zero
		int mask = _mm_movemask_ps(cmp) & 0x00000007;
		return mask != 0;
	}
	INTRINSICS_INLINE bool INTRINSICS_CALLCONV isinf(float4 v)
	{
		// Mask off the sign bit then compare to infinity
		__m128 and = _mm_and_ps(v.vec, XVMMaskAbsoluteValue);
		// v == infinity
		__m128 cmp = _mm_cmpeq_ps(and, XVMInfinity);
		// If x or y or z or w is infinity, the mask is non-zero
		int mask = _mm_movemask_ps(cmp) & 0x0000000F;
		return mask != 0;
	}

	INTRINSICS_INLINE bool INTRINSICS_CALLCONV isnan(float2 v)
	{
		// v != v
		__m128 dst = _mm_cmpneq_ps(v.vec, v.vec);
		// If x or y are nan, the mask is non-zero
		int mask = _mm_movemask_ps(dst) & 0x00000003;
		return mask != 0;
	}
	INTRINSICS_INLINE bool INTRINSICS_CALLCONV isnan(float3 v)
	{
		// v != v
		__m128 dst = _mm_cmpneq_ps(v.vec, v.vec);
		// If x or y or z are nan, the mask is non-zero
		int mask = _mm_movemask_ps(dst) & 0x00000007;
		return mask != 0;
	}
	INTRINSICS_INLINE bool INTRINSICS_CALLCONV isnan(float4 v)
	{
		// v != v
		__m128 dst = _mm_cmpneq_ps(v.vec, v.vec);
		// If x or y or z or w are NaN, the mask is non-zero
		int mask = _mm_movemask_ps(dst) & 0x0000000F;
		return mask != 0;
	}

	INTRINSICS_INLINE float2 INTRINSICS_CALLCONV length(float2 v)
	{
		float2 v2 = dot(v, v);
		return _mm_sqrt_ps(v2.vec);
	}
	INTRINSICS_INLINE float3 INTRINSICS_CALLCONV length(float3 v)
	{
		float3 v2 = dot(v, v);
		return _mm_sqrt_ps(v2.vec);
	}
	INTRINSICS_INLINE float4 INTRINSICS_CALLCONV length(float4 v)
	{
		float4 v2 = dot(v, v);
		return _mm_sqrt_ps(v2.vec);
	}

	INTRINSICS_INLINE float2 INTRINSICS_CALLCONV lerp(float2 v1, float2 v2, float2 s)
	{
		// x + s(y-x)
		__m128 sub = _mm_sub_ps(v2.vec, v1.vec);
		__m128 mul = _mm_mul_ps(sub, s.vec);
		return _mm_add_ps(v1.vec, mul);
	}
	INTRINSICS_INLINE float3 INTRINSICS_CALLCONV lerp(float3 v1, float3 v2, float3 s)
	{
		// x + s(y-x)
		__m128 sub = _mm_sub_ps(v2.vec, v1.vec);
		__m128 mul = _mm_mul_ps(sub, s.vec);
		return _mm_add_ps(v1.vec, mul);
	}
	INTRINSICS_INLINE float4 INTRINSICS_CALLCONV lerp(float4 v1, float4 v2, float4 s)
	{
		// x + s(y-x)
		__m128 sub = _mm_sub_ps(v2.vec, v1.vec);
		__m128 mul = _mm_mul_ps(sub, s.vec);
		return _mm_add_ps(v1.vec, mul);
	}

	INTRINSICS_INLINE float2 INTRINSICS_CALLCONV max(float2 v1, float2 v2)
	{
		return _mm_max_ps(v1.vec, v2.vec);
	}
	INTRINSICS_INLINE float3 INTRINSICS_CALLCONV max(float3 v1, float3 v2)
	{
		return _mm_max_ps(v1.vec, v2.vec);
	}
	INTRINSICS_INLINE float4 INTRINSICS_CALLCONV max(float4 v1, float4 v2)
	{
		return _mm_max_ps(v1.vec, v2.vec);
	}

	INTRINSICS_INLINE float2 INTRINSICS_CALLCONV min(float2 v1, float2 v2)
	{
		return _mm_min_ps(v1.vec, v2.vec);
	}
	INTRINSICS_INLINE float3 INTRINSICS_CALLCONV min(float3 v1, float3 v2)
	{
		return _mm_min_ps(v1.vec, v2.vec);
	}
	INTRINSICS_INLINE float4 INTRINSICS_CALLCONV min(float4 v1, float4 v2)
	{
		return _mm_min_ps(v1.vec, v2.vec);
	}

	INTRINSICS_INLINE float2 INTRINSICS_CALLCONV normalize(float2 v)
	{
		float2 l = length(v);
		return _mm_div_ps(v.vec, l.vec);
	}
	INTRINSICS_INLINE float3 INTRINSICS_CALLCONV normalize(float3 v)
	{
		float3 l = length(v);
		return _mm_div_ps(v.vec, l.vec);
	}
	INTRINSICS_INLINE float4 INTRINSICS_CALLCONV normalize(float4 v)
	{
		float4 l = length(v);
		return _mm_div_ps(v.vec, l.vec);
	}

	INTRINSICS_INLINE float2 INTRINSICS_CALLCONV sqrt(float2 v)
	{
		return _mm_sqrt_ps(v.vec);
	}
	INTRINSICS_INLINE float3 INTRINSICS_CALLCONV sqrt(float3 v)
	{
		return _mm_sqrt_ps(v.vec);
	}
	INTRINSICS_INLINE float4 INTRINSICS_CALLCONV sqrt(float4 v)
	{
		return _mm_sqrt_ps(v.vec);
	}

	INTRINSICS_INLINE float4 INTRINSICS_CALLCONV mul(float4 v, float4x4 m)
	{
		//					[a, b, c, d]
		// [x, y, z, w] *	[e, f, g, h]
		//					[i, j, k, l]
		//					[m, n, o, p]
		// 
		// x' = x * a + y * e + z * i + w * m
		// y' = x * b + y * f + z * j + w * n
		// z' = x * c + y * g + z * k + w * o
		// w' = x * d + y * h + z * l + w * p
		// Splat all vector components
		__m128 x = INTRINSICS_SHUFFLE_PS(v.vec, _MM_SHUFFLE(0, 0, 0, 0)); // [x, x, x, x]
		__m128 y = INTRINSICS_SHUFFLE_PS(v.vec, _MM_SHUFFLE(1, 1, 1, 1)); // [y, y, y, y]
		__m128 z = INTRINSICS_SHUFFLE_PS(v.vec, _MM_SHUFFLE(2, 2, 2, 2)); // [z, z, z, z]
		__m128 w = INTRINSICS_SHUFFLE_PS(v.vec, _MM_SHUFFLE(3, 3, 3, 3)); // [w, w, w, w]

		x = _mm_mul_ps(x, m.r[0]); // mul x by r0
		y = _mm_mul_ps(y, m.r[1]); // mul y by r1
		z = _mm_mul_ps(z, m.r[2]); // mul z by r2
		w = _mm_mul_ps(w, m.r[3]); // mul w by r3
		// sum
		x = _mm_add_ps(x, y); // x+y
		z = _mm_add_ps(z, w); // z+w;
		return _mm_add_ps(x, z); // x+y+z+w
	}
	INTRINSICS_INLINE float4x4 INTRINSICS_CALLCONV mul(float4x4 m1, float4x4 m2)
	{
		__m128 r[4];

		// See mul(float4, float4x4)
		for (int i = 0; i < 4; ++i)
		{
			__m128 x = INTRINSICS_SHUFFLE_PS(m1.r[i], _MM_SHUFFLE(0, 0, 0, 0)); // [x, x, x, x]
			__m128 y = INTRINSICS_SHUFFLE_PS(m1.r[i], _MM_SHUFFLE(1, 1, 1, 1)); // [y, y, y, y]
			__m128 z = INTRINSICS_SHUFFLE_PS(m1.r[i], _MM_SHUFFLE(2, 2, 2, 2)); // [z, z, z, z]
			__m128 w = INTRINSICS_SHUFFLE_PS(m1.r[i], _MM_SHUFFLE(3, 3, 3, 3)); // [w, w, w, w]

			x = _mm_mul_ps(x, m2.r[0]); // mul x by r0
			y = _mm_mul_ps(y, m2.r[1]); // mul y by r1
			z = _mm_mul_ps(z, m2.r[2]); // mul z by r2
			w = _mm_mul_ps(w, m2.r[3]); // mul w by r3
			// sum
			x = _mm_add_ps(x, y); // x+y
			z = _mm_add_ps(z, w); // z+w;
			r[i] = _mm_add_ps(x, z); // x+y+z+w
		}

		return float4x4(r[0], r[1], r[2], r[3]);
	}

	INTRINSICS_INLINE float4x4 INTRINSICS_CALLCONV transpose(float4x4 m)
	{
		// I worked this out on paper, is pretty interesting on how they arrived at the solution
		_MM_TRANSPOSE4_PS(m.r[0], m.r[1], m.r[2], m.r[3]);
		return m;
	}
}
