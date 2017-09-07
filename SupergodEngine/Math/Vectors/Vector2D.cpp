#include "Vector2D.h"
#include "../SMath.h"
#include "VectorUtils.h"
#include <functional>

namespace SupergodEngine { namespace Math
{
	Vector2D::Vector2D()
		: x(0), y(0)
	{
	}
	
	Vector2D::Vector2D(const float& x, const float& y)
		: x(x), y(y)
	{
	}

	bool Vector2D::Equals(const Vector2D& other) const
	{
		return x == other.x && y == other.y;
	}

	bool Vector2D::CloseEnough(const Vector2D& other, const float& threshold) const
	{
		return SMath::CloseEnough(x, other.x, threshold) && SMath::CloseEnough(y, other.y, threshold);
	}

	bool Vector2D::ContainsComponent(std::function<bool(const float&)> test) const
	{
		for (size_t i = 0; i < ARRAY_ELEMENTS_COUNT(components); i++)
		{
			if (test(components[i]))
				return true;
		}
		return false;
	}

	bool Vector2D::operator==(const Vector2D& other) const
	{
		return Equals(other);
	}

	bool Vector2D::operator!=(const Vector2D& other) const
	{
		return !(*this == other);
	}

	float Vector2D::Magnitude() const
	{
		return Vector::Magnitude(*this);
	}

	float Vector2D::SqrMagnitude() const
	{
		return Vector::SqrMagnitude(*this);
	}

	Vector2D Vector2D::Normalized() const
	{
		return Vector::Normalize(*this);
	}

	float Vector2D::Dot(const Vector2D& other) const
	{
		return x * other.x + y * other.y;
	}

	Vector2D Vector2D::Multiply(const Vector2D& other) const
	{
		return Vector2D(x * other.x, y * other.y);
	}
	
	Vector2D Vector2D::Multiply(const float& scalar) const
	{
		return Vector2D(x * scalar, y * scalar);
	}

	Vector2D Vector2D::operator*(const Vector2D& other) const
	{
		return Multiply(other);
	}

	Vector2D Vector2D::operator*(const float& scalar) const
	{
		return Multiply(scalar);
	}

	Vector2D Vector2D::Divide(const float& scalar) const
	{
		return Vector2D(x / scalar, y / scalar);
	}

	Vector2D Vector2D::operator/(const float& scalar) const
	{
		return Divide(scalar);
	}

	Vector2D Vector2D::Divide(const Vector2D& other) const
	{
		return Vector2D(x / other.x, y / other.y);
	}

	Vector2D Vector2D::operator/(const Vector2D& other) const
	{
		return Divide(other);
	}

	#pragma region Those methods are here just so it will compile. I will organize and implement them later.
	Vector2D Vector2D::Abs() const
	{
		return Vector2D();
	}
	Vector2D Vector2D::Clamp(const Vector2D & min, const Vector2D & max) const
	{
		return Vector2D();
	}
	Vector2D Vector2D::Add(const Vector2D & other) const
	{
		return Vector2D();
	}
	Vector2D Vector2D::Subtract(const Vector2D & other) const
	{
		return Vector2D();
	}
	Vector2D Vector2D::Negated() const
	{
		return Vector2D();
	}
	const float & Vector2D::BiggestComponent() const
	{
		return x;
		// TODO: insert return statement here
	}
	const float & Vector2D::SmallestComponent() const
	{
		return x;
		// TODO: insert return statement here
	}
	Vector2D Vector2D::ClampComponents(const float & min, const float & max) const
	{
		return Vector2D();
	}
	#pragma endregion
} }