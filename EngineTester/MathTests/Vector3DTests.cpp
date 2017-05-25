#include <Math/Vector3D.h>
#include <gtest/gtest.h>

using Math::Vector3D;

TEST(Vector3D, Constructor)
{
	// Test Vector3D constructor values
	Vector3D first(1, 2, 3);
	EXPECT_FLOAT_EQ(1, first.x);
	EXPECT_FLOAT_EQ(2, first.y);
	EXPECT_FLOAT_EQ(3, first.z);
}

TEST(Vector3D, VectorAddition)
{
	// Test the sum of 2 Vector3D vectors and their reflexivity
	Vector3D first(1, 2, 3);
	Vector3D second(3, 4, 5);
	Vector3D result = first + second;
	Vector3D resultReflexive = second + first;
	EXPECT_FLOAT_EQ(4, result.x);
	EXPECT_FLOAT_EQ(6, result.y);
	EXPECT_FLOAT_EQ(8, result.z);
	EXPECT_FLOAT_EQ(result.x, resultReflexive.x);
	EXPECT_FLOAT_EQ(result.y, resultReflexive.y);
	EXPECT_FLOAT_EQ(result.z, resultReflexive.z);
}

TEST(Vector3D, ScalarMultiplication)
{
	// Test the Scalar multiplication of a Vector3D vector
	Vector3D vec(-7, 3, 2);
	Vector3D result1 = 2 * vec;
	Vector3D result2 = vec * 2;
	EXPECT_FLOAT_EQ(-14, result1.x);
	EXPECT_FLOAT_EQ(6, result1.y);
	EXPECT_FLOAT_EQ(4, result1.z);
	EXPECT_FLOAT_EQ(result1.x, result2.x);
	EXPECT_FLOAT_EQ(result1.y, result2.y);
	EXPECT_FLOAT_EQ(result1.z, result2.z);
}

TEST(Vector3D, AssignmentPlusEquals)
{
	// Test the overloaded += operator of 2 Vector3D vectors
	Vector3D source(5, -1234.5678, 24);
	Vector3D another(1, 1, 1);
	another += source;
	EXPECT_FLOAT_EQ(another.x, 6);
	EXPECT_FLOAT_EQ(another.y, -1233.5678);
	EXPECT_FLOAT_EQ(another.z, 25);
}

TEST(Vector3D, AssignmentMinusEquals)
{
	// Test the overloaded -= operator of 2 Vector3D vectors
	Vector3D source(5, -1234.5678, 24);
	Vector3D another(1, 1, 1);
	another -= source;
	EXPECT_FLOAT_EQ(another.x, -4);
	EXPECT_FLOAT_EQ(another.y, 1235.5678);
	EXPECT_FLOAT_EQ(another.z, -23);
}