#include <gtest\gtest.h>
#include <Vector2D.h>
using Math::Vector2D;

TEST(Vector2D, Constructor)
{
	Vector2D first(1, 2);
	EXPECT_FLOAT_EQ(1, first.x);
	EXPECT_FLOAT_EQ(2, first.y);
}

TEST(Vector2D, VectorAddition)
{
	Vector2D first(1, 2);
	Vector2D second(3, 4);
	Vector2D result = first + second;
	Vector2D resultReflexive = second + first;
	EXPECT_FLOAT_EQ(4, result.x);
	EXPECT_FLOAT_EQ(6, result.y);
	EXPECT_FLOAT_EQ(result.x, resultReflexive.x);
	EXPECT_FLOAT_EQ(result.y, resultReflexive.y);
}

TEST(Vector2D, ScalarMultiplication)
{
	Vector2D vec(-7, 3);
	Vector2D result1 = 2 * vec;
	EXPECT_FLOAT_EQ(-14, result1.x);
	EXPECT_FLOAT_EQ(6, result1.y);
}