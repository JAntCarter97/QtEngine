#pragma once
#include "Vector2D.h"

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
						  float r1c0 = 0.0f, float r1c1 = 1.0f) {}
	};

	inline Vector2D operator*(const Matrix2D& left, const Vector2D& right) {}
}