#pragma once

TEST(float4, ctor)
{
	float4 v;

	EXPECT_FLOAT_EQ(v.x, 0.0f);
	EXPECT_FLOAT_EQ(v.y, 0.0f);
	EXPECT_FLOAT_EQ(v.z, 0.0f);
	EXPECT_FLOAT_EQ(v.w, 0.0f);
}

TEST(float4, ctor_component)
{
	float4 v(1.0f, 2.0f, 3.0f, 4.0f);

	EXPECT_FLOAT_EQ(v.x, 1.0f);
	EXPECT_FLOAT_EQ(v.y, 2.0f);
	EXPECT_FLOAT_EQ(v.z, 3.0f);
	EXPECT_FLOAT_EQ(v.w, 4.0f);
}

TEST(float4, ctor_scalar)
{
	float4 v(1.0f);

	EXPECT_FLOAT_EQ(v.x, 1.0f);
	EXPECT_FLOAT_EQ(v.y, 1.0f);
	EXPECT_FLOAT_EQ(v.z, 1.0f);
	EXPECT_FLOAT_EQ(v.w, 1.0f);
}

TEST(float4, ctor_array)
{
	float array[4] = { 1.0f, 2.0f, 3.0f, 4.0f };
	float4 v(array);

	EXPECT_FLOAT_EQ(v.x, 1.0f);
	EXPECT_FLOAT_EQ(v.y, 2.0f);
	EXPECT_FLOAT_EQ(v.z, 3.0f);
	EXPECT_FLOAT_EQ(v.w, 4.0f);
}

TEST(float4, negation)
{
	float4 v(1.0f, 2.0f, 3.0f, 4.0f);
	v = -v;

	EXPECT_FLOAT_EQ(v.x, -1.0f);
	EXPECT_FLOAT_EQ(v.y, -2.0f);
	EXPECT_FLOAT_EQ(v.z, -3.0f);
	EXPECT_FLOAT_EQ(v.w, -4.0f);
}

TEST(float4, arithmetic_add)
{
	float4 v1(1.0f, 2.0f, 3.0f, 4.0f);
	float4 v2(4.0f, 3.0f, 2.0f, 1.0f);
	float4 result = v1 + v2;

	EXPECT_FLOAT_EQ(result.x, 5.0f);
	EXPECT_FLOAT_EQ(result.y, 5.0f);
	EXPECT_FLOAT_EQ(result.z, 5.0f);
	EXPECT_FLOAT_EQ(result.w, 5.0f);
}

TEST(float4, arithmetic_subtract)
{
	float4 v1(1.0f, 2.0f, 3.0f, 4.0f);
	float4 v2(0.1f, 0.2f, 0.3f, 0.4f);
	float4 result = v1 - v2;

	EXPECT_FLOAT_EQ(result.x, 0.9f);
	EXPECT_FLOAT_EQ(result.y, 1.8f);
	EXPECT_FLOAT_EQ(result.z, 2.7f);
	EXPECT_FLOAT_EQ(result.w, 3.6f);
}

TEST(float4, arithmetic_multiply)
{
	float4 v1(0.1f, 0.2f, 0.3f, 0.4f);
	float4 v2(0.3f);
	float4 result = v1 * v2;

	EXPECT_FLOAT_EQ(result.x, 0.03f);
	EXPECT_FLOAT_EQ(result.y, 0.06f);
	EXPECT_FLOAT_EQ(result.z, 0.09f);
	EXPECT_FLOAT_EQ(result.w, 0.12f);
}

TEST(float4, arithmetic_divide)
{
	constexpr float episilon = 1e-2f;

	float4 v1(0.1f, 0.2f, 0.3f, 0.4f);
	float4 v2(0.3f);
	float4 result = v1 / v2;

	EXPECT_NEAR(result.x, 0.33f, episilon);
	EXPECT_NEAR(result.y, 0.66f, episilon);
	EXPECT_NEAR(result.z, 1.0f, episilon);
	EXPECT_NEAR(result.w, 1.33f, episilon);
}
