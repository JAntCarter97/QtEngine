#include "HelperFunctions.h"
#include <Math/Matrix3D.h>
#include <Math/Vector3D.h>
#include <Math/Vector2D.h>
#include <gtest/gtest.h>
#include <Math/Constants.h>

using Math::Matrix3D;
using Math::Vector3D;
using Math::Vector2D;

TEST(Matrix3D, Construction)
{
	// Test Matrix3D default constructor
	Matrix3D identity;
	EXPECT_FLOAT_EQ(identity.r0c0, 1.0f);
	EXPECT_FLOAT_EQ(identity.r0c1, 0.0f);
	EXPECT_FLOAT_EQ(identity.r0c2, 0.0f);
	EXPECT_FLOAT_EQ(identity.r1c0, 0.0f);
	EXPECT_FLOAT_EQ(identity.r1c1, 1.0f);
	EXPECT_FLOAT_EQ(identity.r1c2, 0.0f);
	EXPECT_FLOAT_EQ(identity.r2c0, 0.0f);
	EXPECT_FLOAT_EQ(identity.r2c1, 0.0f);
	EXPECT_FLOAT_EQ(identity.r2c2, 1.0f);
}

TEST(Matrix3D, Rotation)
{
	// Create a default Matrix3D
	// Test its rotateZd values at angle = 0
	Matrix3D op;
	op = Matrix3D::rotateZ(0);
	EXPECT_FLOAT_EQ(op.r0c0, 1);
	EXPECT_FLOAT_EQ(op.r0c1, 0);
	EXPECT_FLOAT_EQ(op.r0c2, 0);
	EXPECT_FLOAT_EQ(op.r1c0, 0);
	EXPECT_FLOAT_EQ(op.r1c1, 1);
	EXPECT_FLOAT_EQ(op.r1c2, 0);
	EXPECT_FLOAT_EQ(op.r2c0, 0);
	EXPECT_FLOAT_EQ(op.r2c1, 0);
	EXPECT_FLOAT_EQ(op.r2c2, 1);

	// Test roated values at angle = PI
	op = Matrix3D::rotateZ(Math::PI);
	EXPECT_FLOAT_EQ(op.r0c0, -1);
	EXPECT_TRUE(closeEnough(op.r0c1, 0));
	EXPECT_FLOAT_EQ(op.r0c2, 0);
	EXPECT_TRUE(closeEnough(op.r1c0, 0));
	EXPECT_FLOAT_EQ(op.r1c1, -1);
	EXPECT_FLOAT_EQ(op.r1c2, 0);
	EXPECT_FLOAT_EQ(op.r2c0, 0);
	EXPECT_FLOAT_EQ(op.r2c1, 0);
	EXPECT_FLOAT_EQ(op.r2c2, 1);

	// Test roated values at angle = PI / 2
	op = Matrix3D::rotateZ(Math::PI / 2);
	EXPECT_TRUE(closeEnough(op.r0c0, 0));
	EXPECT_FLOAT_EQ(op.r0c1, -1);
	EXPECT_FLOAT_EQ(op.r0c2, 0);
	EXPECT_FLOAT_EQ(op.r1c0, 1);
	EXPECT_TRUE(closeEnough(op.r1c1, 0));
	EXPECT_FLOAT_EQ(op.r1c2, 0);
	EXPECT_FLOAT_EQ(op.r2c0, 0);
	EXPECT_FLOAT_EQ(op.r2c1, 0);
	EXPECT_FLOAT_EQ(op.r2c2, 1);

	// Test roated values at angle = PI / 4
	op = Matrix3D::rotateZ(Math::PI / 4);
	const float sqrt2Over2 = 0.707106769;
	EXPECT_FLOAT_EQ(op.r0c0, sqrt2Over2);
	EXPECT_FLOAT_EQ(op.r0c1, -sqrt2Over2);
	EXPECT_FLOAT_EQ(op.r1c2, 0);
	EXPECT_FLOAT_EQ(op.r1c0, sqrt2Over2);
	EXPECT_FLOAT_EQ(op.r1c1, sqrt2Over2);
	EXPECT_FLOAT_EQ(op.r1c2, 0);
	EXPECT_FLOAT_EQ(op.r2c0, 0);
	EXPECT_FLOAT_EQ(op.r2c1, 0);
	EXPECT_FLOAT_EQ(op.r2c2, 1);

	// Test roated values at angle = -PI / 4
	op = Matrix3D::rotateZ(-Math::PI / 4);
	EXPECT_FLOAT_EQ(op.r0c0, sqrt2Over2);
	EXPECT_FLOAT_EQ(op.r0c1, sqrt2Over2);
	EXPECT_FLOAT_EQ(op.r0c2, 0);
	EXPECT_FLOAT_EQ(op.r1c0, -sqrt2Over2);
	EXPECT_FLOAT_EQ(op.r1c1, sqrt2Over2);
	EXPECT_FLOAT_EQ(op.r1c2, 0);
	EXPECT_FLOAT_EQ(op.r2c0, 0);
	EXPECT_FLOAT_EQ(op.r2c1, 0);
	EXPECT_FLOAT_EQ(op.r2c2, 1);

	// Test roated values at angle = PI / 3
	op = Matrix3D::rotateZ(Math::PI / 3);
	const float sqrt3Over2 = 0.866025388;
	EXPECT_FLOAT_EQ(op.r0c0, 0.5);
	EXPECT_FLOAT_EQ(op.r0c1, -sqrt3Over2);
	EXPECT_FLOAT_EQ(op.r0c2, 0);
	EXPECT_FLOAT_EQ(op.r1c0, sqrt3Over2);
	EXPECT_FLOAT_EQ(op.r1c1, 0.5);
	EXPECT_FLOAT_EQ(op.r1c2, 0);
	EXPECT_FLOAT_EQ(op.r2c0, 0);
	EXPECT_FLOAT_EQ(op.r2c1, 0);
	EXPECT_FLOAT_EQ(op.r2c2, 1);

	// Test roated values at angle = -PI / 3
	op = Matrix3D::rotateZ(-Math::PI / 3);
	EXPECT_FLOAT_EQ(op.r0c0, 0.5);
	EXPECT_FLOAT_EQ(op.r0c1, sqrt3Over2);
	EXPECT_FLOAT_EQ(op.r0c2, 0);
	EXPECT_FLOAT_EQ(op.r1c0, -sqrt3Over2);
	EXPECT_FLOAT_EQ(op.r1c1, 0.5);
	EXPECT_FLOAT_EQ(op.r1c2, 0);
	EXPECT_FLOAT_EQ(op.r2c0, 0);
	EXPECT_FLOAT_EQ(op.r2c1, 0);
	EXPECT_FLOAT_EQ(op.r2c2, 1);

}

TEST(Matrix3D, Translation)
{
	Matrix3D op, op2;
	Vector2D tVec(1, 2);
	op = Matrix3D::translate(tVec);
	op2 = Matrix3D::translate(1, 3);
	EXPECT_FLOAT_EQ(op.r0c0, 1);
	EXPECT_FLOAT_EQ(op.r0c1, 0);
	EXPECT_FLOAT_EQ(op.r0c2, 1);
	EXPECT_FLOAT_EQ(op.r1c0, 0);
	EXPECT_FLOAT_EQ(op.r1c1, 1);
	EXPECT_FLOAT_EQ(op.r1c2, 2);
	EXPECT_FLOAT_EQ(op.r2c0, 0);
	EXPECT_FLOAT_EQ(op.r2c1, 0);
	EXPECT_FLOAT_EQ(op.r2c2, 1);

	EXPECT_FLOAT_EQ(op2.r0c0, 1);
	EXPECT_FLOAT_EQ(op2.r0c1, 0);
	EXPECT_FLOAT_EQ(op2.r0c2, 1);
	EXPECT_FLOAT_EQ(op2.r1c0, 0);
	EXPECT_FLOAT_EQ(op2.r1c1, 1);
	EXPECT_FLOAT_EQ(op2.r1c2, 3);
	EXPECT_FLOAT_EQ(op2.r2c0, 0);
	EXPECT_FLOAT_EQ(op2.r2c1, 0);
	EXPECT_FLOAT_EQ(op2.r2c2, 1);
}

TEST(Matrix3D, MatrixVectorMultiply)
{
	// Matrix3D times a Vector3D test
	Matrix3D op(2, -3, 1, 4, -5, 2, 0, 0, 1);
	Vector3D v(3, 9, 1);
	Vector3D vprime = op * v;
	EXPECT_FLOAT_EQ(vprime.x, -20);
	EXPECT_FLOAT_EQ(vprime.y, -31);
	EXPECT_FLOAT_EQ(vprime.z, 1);
}

TEST(Matrix3D, MatrixMatrixMultiply)
{
	// Mutiply 2 Matrix3D matrices together
	Matrix3D mat1(1, 2, 3, 2, 1, 3, 3, 1, 2);
	Matrix3D mat2(1, 2, 1, 2, 3, 3, 4, 3, 2);
	Matrix3D res = mat1 * mat2;
	EXPECT_FLOAT_EQ(res.r0c0, 17);
	EXPECT_FLOAT_EQ(res.r0c1, 17);
	EXPECT_FLOAT_EQ(res.r0c2, 13);
	EXPECT_FLOAT_EQ(res.r1c0, 16);
	EXPECT_FLOAT_EQ(res.r1c1, 16);
	EXPECT_FLOAT_EQ(res.r1c2, 11);
	EXPECT_FLOAT_EQ(res.r2c0, 13);
	EXPECT_FLOAT_EQ(res.r2c1, 15);
	EXPECT_FLOAT_EQ(res.r2c2, 10);
}