#include <Math/Matrix2D.h>
#include <Math/Vector2D.h>
#include <gtest/gtest.h>
#include "HelperFunctions.h"
#include "Math/Constants.h"

using Math::Matrix2D;
using Math::Vector2D;

TEST(Matrix2D, Construction)
{
	Matrix2D identity;
	EXPECT_FLOAT_EQ(identity.r0c0, 1.0f);
	EXPECT_FLOAT_EQ(identity.r0c1, 0.0f);
	EXPECT_FLOAT_EQ(identity.r1c0, 0.0f);
	EXPECT_FLOAT_EQ(identity.r1c1, 1.0f);
}

TEST(Matrix2D, Rotation)
{
	Matrix2D op;
	op = Matrix2D::rotate(0);
	EXPECT_FLOAT_EQ(op.r0c0, 1);
	EXPECT_FLOAT_EQ(op.r0c1, 0);
	EXPECT_FLOAT_EQ(op.r1c0, 0);
	EXPECT_FLOAT_EQ(op.r1c1, 1);

	op = Matrix2D::rotate(Math::PI);
	EXPECT_FLOAT_EQ(op.r0c0, -1);
	EXPECT_TRUE(closeEnough(op.r0c1, 0));
	EXPECT_TRUE(closeEnough(op.r1c0, 0));
	EXPECT_FLOAT_EQ(op.r1c1, -1);

	op = Matrix2D::rotate(Math::PI / 2);
	EXPECT_TRUE(closeEnough(op.r0c0, 0));
	EXPECT_FLOAT_EQ(op.r0c1, -1);
	EXPECT_FLOAT_EQ(op.r1c0, 1);
	EXPECT_TRUE(closeEnough(op.r1c1, 0));

	op = Matrix2D::rotate(Math::PI / 4);
	const float sqrt2Over2 = 0.707106769;
	EXPECT_FLOAT_EQ(op.r0c0, sqrt2Over2);
	EXPECT_FLOAT_EQ(op.r0c1, -sqrt2Over2);
	EXPECT_FLOAT_EQ(op.r1c0, sqrt2Over2);
	EXPECT_FLOAT_EQ(op.r1c1, sqrt2Over2);

	op = Matrix2D::rotate(-Math::PI / 4);
	EXPECT_FLOAT_EQ(op.r0c0, sqrt2Over2);
	EXPECT_FLOAT_EQ(op.r0c1, sqrt2Over2);
	EXPECT_FLOAT_EQ(op.r1c0, -sqrt2Over2);
	EXPECT_FLOAT_EQ(op.r1c1, sqrt2Over2);

	op = Matrix2D::rotate(Math::PI / 3);
	const float sqrt3Over2 = 0.866025388;
	EXPECT_FLOAT_EQ(op.r0c0, 0.5);
	EXPECT_FLOAT_EQ(op.r0c1, -sqrt3Over2);
	EXPECT_FLOAT_EQ(op.r1c0, sqrt3Over2);
	EXPECT_FLOAT_EQ(op.r1c1, 0.5);

	op = Matrix2D::rotate(-Math::PI / 3);
	EXPECT_FLOAT_EQ(op.r0c0, 0.5);
	EXPECT_FLOAT_EQ(op.r0c1, sqrt3Over2);
	EXPECT_FLOAT_EQ(op.r1c0, -sqrt3Over2);
	EXPECT_FLOAT_EQ(op.r1c1, 0.5);

}

TEST(Matrix2D, MatrixVectorMultiply)
{
	Matrix2D op(2, -3, 4, -5);
	Vector2D v(3, 9);
	Vector2D vprime = op * v;
	EXPECT_FLOAT_EQ(vprime.x, -21);
	EXPECT_FLOAT_EQ(vprime.y, -33);
}