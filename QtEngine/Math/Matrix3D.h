#pragma once
#include "Math/Vector3D.h"
float sin(float) noexcept;
float cos(float) noexcept;

namespace Math
{
	struct Matrix3D
	{
		float r0c0;
		float r0c1;
		float r0c2;
		float r1c0;
		float r1c1;
		float r1c2;
		float r2c0;
		float r2c1;
		float r2c2;

		inline explicit Matrix3D(float r0c0 = 1.0f, float r0c1 = 0.0f, float r0c2 = 0.0f, 
								 float r1c0 = 0.0f, float r1c1 = 1.0f, float r1c2 = 0.0f,
								 float r2c0 = 0.0f, float r2c1 = 0.0f, float r2c2 = 1.0f)
			: r0c0(r0c0), r0c1(r0c1), r0c2(r0c2),
			  r1c0(r1c0), r1c1(r1c1), r1c2(r1c2),
			  r2c0(r2c0), r2c1(r2c1), r2c2(r2c2) {}
		inline static Matrix3D rotate(float angleInRads)
		{
			float cosResult = cos(angleInRads);
			float sinResult = sin(angleInRads);
			return Matrix3D(cosResult, -sinResult, 0.0f, sinResult, cosResult, 0.0f, 0.0f, 0.0f, 1.0f);
		}
	};

	inline Vector3D operator*(const Matrix3D& mat, const Vector3D& vec)
	{
		Vector3D t;
		t.x = (mat.r0c0 * vec.x) + (mat.r0c1 * vec.y) + (mat.r0c2 * vec.z);
		t.y = (mat.r1c0 * vec.x) + (mat.r1c1 * vec.y) + (mat.r1c2 * vec.z);
		t.z = (mat.r2c0 * vec.x) + (mat.r2c1 * vec.y) + (mat.r2c2 * vec.z);
		return t;
	}
}