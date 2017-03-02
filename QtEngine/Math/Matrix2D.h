#pragma once
#include "Vector2D.h"
#include <cmath>

namespace Math
{
	struct Matrix2D
	{
		float r0c0;
		float r0c1;
		float r1c0;
		float r1c1;

		// Default as Identity matrix
		inline explicit Matrix2D(float r0c0 = 1.0f, float r0c1 = 0.0f,
								 float r1c0 = 0.0f, float r1c1 = 1.0f) 
								 : r0c0(r0c0), r0c1(r0c1), 
								   r1c0(r1c0), r1c1(r1c1) {}
		inline static Matrix2D rotate(float angleInRads)
		{ 
			return Matrix2D(cos(angleInRads), -sin(angleInRads), sin(angleInRads), cos(angleInRads)); 
		}
	};

	inline Vector2D operator*(const Matrix2D& mat, const Vector2D& vec)
	{
		Vector2D t;
		t.x = (mat.r0c0 * vec.x) + (mat.r0c1 * vec.y);
		t.y = (mat.r1c0 * vec.x) + (mat.r1c1 * vec.y);
		return t;
	}
}