#pragma once

namespace Math
{
	struct Vector3D
	{
		float x;
		float y;
		float z;

		explicit Vector3D(float x = 0.0f, float y = 0.0f, float z = 0.0f) : x(x), y(y), z(z) {}

		inline Vector3D& operator+=(const Vector3D& right)
		{
			x += right.x;
			y += right.y;
			z += right.z;
			return *this;
		}
		inline Vector3D& operator-=(const Vector3D& right)
		{
			x -= right.x;
			y -= right.y;
			z -= right.z;
			return *this;
		}
	};


	inline Vector3D operator+(const Vector3D& left, const Vector3D& right)
	{
		return Vector3D(left.x + right.x, left.y + right.y, left.z + right.z);
	}

	inline Vector3D operator*(float scalar, const Vector3D& vector)
	{
		return Vector3D(scalar * vector.x, scalar * vector.y, scalar * vector.z);
	}

	inline Vector3D operator*(const Vector3D& vector, float scalar)
	{
		return scalar * vector;
	}

}