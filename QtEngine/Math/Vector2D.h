#pragma once

namespace Math
{
	struct Vector2D
	{
		float x;
		float y;
		explicit Vector2D(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

		inline Vector2D& operator+=(const Vector2D& right)
		{
			x += right.x;
			y += right.y;
			return *this;
		}
		inline Vector2D& operator-=(const Vector2D& right)
		{
			x -= right.x;
			y -= right.y;
			return *this;
		}
	};


	inline Vector2D operator+(const Vector2D& left, const Vector2D& right)
	{
		return Vector2D(left.x + right.x, left.y + right.y);
	}

	inline Vector2D operator*(float scalar, const Vector2D& vector)
	{
		return Vector2D(scalar * vector.x, scalar * vector.y);
	}

	inline Vector2D operator*(const Vector2D& vector, float scalar)
	{
		return scalar * vector;
	}

}