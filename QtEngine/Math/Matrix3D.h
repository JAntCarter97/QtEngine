#pragma once
#include "Math/Vector2D.h"
#include "Math/Vector3D.h"
float sin(float) noexcept;
float cos(float) noexcept;

namespace Math
{
	struct Matrix3D
	{
		float r0c0, r0c1, r0c2;
		float r1c0, r1c1, r1c2;
		float r2c0, r2c1, r2c2;

		inline explicit Matrix3D(float r0c0 = 1.0f, float r0c1 = 0.0f, float r0c2 = 0.0f, 
								 float r1c0 = 0.0f, float r1c1 = 1.0f, float r1c2 = 0.0f,
								 float r2c0 = 0.0f, float r2c1 = 0.0f, float r2c2 = 1.0f)
			: r0c0(r0c0), r0c1(r0c1), r0c2(r0c2),
			  r1c0(r1c0), r1c1(r1c1), r1c2(r1c2),
			  r2c0(r2c0), r2c1(r2c1), r2c2(r2c2) {}
		inline static Matrix3D rotateZ(float angleInRads)
		{
			float cosResult = cos(angleInRads);
			float sinResult = sin(angleInRads);
			return Matrix3D(cosResult, -sinResult, 0.0f, sinResult, cosResult, 0.0f, 0.0f, 0.0f, 1.0f);
		}

		inline static Matrix3D translate(Vector2D &transVec)
		{
			return Matrix3D(1, 0, transVec.x,
							0, 1, transVec.y,
							0, 0, 1);
		}

		inline static Matrix3D translate(float x, float y)
		{
			return Matrix3D(1, 0, x,
							0, 1, y,
							0, 0, 1);
		}
	};

	// Overloaded * operator function
	// Takes in: Matrix3D Reference and Vector3D reference
	// Multiplies the correct values and returns the corresponding Vector3D
	inline Vector3D operator*(const Matrix3D& mat, const Vector3D& vec)
	{
		return Vector3D((mat.r0c0 * vec.x) + (mat.r0c1 * vec.y) + (mat.r0c2 * vec.z),
						(mat.r1c0 * vec.x) + (mat.r1c1 * vec.y) + (mat.r1c2 * vec.z),
						(mat.r2c0 * vec.x) + (mat.r2c1 * vec.y) + (mat.r2c2 * vec.z));
	}		

	inline Matrix3D operator*(const Matrix3D& matLeft, const Matrix3D& matRight)
	{
		return Matrix3D((matLeft.r0c0 * matRight.r0c0) + (matLeft.r0c1 * matRight.r1c0) + (matLeft.r0c2 * matRight.r2c0),
						(matLeft.r0c0 * matRight.r0c1) + (matLeft.r0c1 * matRight.r1c1) + (matLeft.r0c2 * matRight.r2c1), 
						(matLeft.r0c0 * matRight.r0c2) + (matLeft.r0c1 * matRight.r1c2) + (matLeft.r0c2 * matRight.r2c2),
						(matLeft.r1c0 * matRight.r0c0) + (matLeft.r1c1 * matRight.r1c0) + (matLeft.r1c2 * matRight.r2c0), 
						(matLeft.r1c0 * matRight.r0c1) + (matLeft.r1c1 * matRight.r1c1) + (matLeft.r1c2 * matRight.r2c1), 
						(matLeft.r1c0 * matRight.r0c2) + (matLeft.r1c1 * matRight.r1c2) + (matLeft.r1c2 * matRight.r2c2), 
						(matLeft.r2c0 * matRight.r0c0) + (matLeft.r2c1 * matRight.r1c0) + (matLeft.r2c2 * matRight.r2c0), 
						(matLeft.r2c0 * matRight.r0c1) + (matLeft.r2c1 * matRight.r1c1) + (matLeft.r2c2 * matRight.r2c1), 
						(matLeft.r2c0 * matRight.r0c2) + (matLeft.r2c1 * matRight.r1c2) + (matLeft.r2c2 * matRight.r2c2));
	}
}						