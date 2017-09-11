#include <functional>
#include "Vector3D.h"
#include "../SMath.h"

namespace SupergodEngine { namespace Math
{
	Vector3D::Vector3D()
		: x(0), y(0), z(0)
	{
	}

	Vector3D::Vector3D(const float & x, const float & y, const float & z)
		: x(x), y(y), z(z)
	{
	}

	bool Vector3D::Equals(const Vector3D& other) const
	{
		return x == other.x && y == other.y && z == other.z;
	}

	bool Vector3D::CloseEnough(const Vector3D& other, const float& threshold) const
	{
		return SMath::CloseEnough(x, other.x, threshold) && SMath::CloseEnough(y, other.y, threshold) && SMath::CloseEnough(z, other.z, threshold);
	}

	bool Vector3D::ContainsComponent(std::function<bool(const float&)> test) const
	{
		return test(x) || test(y) || test(z);
	}

	Vector3D Vector3D::Add(const Vector3D& other) const
	{
		return Vector3D(x + other.x, y + other.y, z + other.z);
	}

	Vector3D Vector3D::Subtract(const Vector3D& other) const
	{
		return Vector3D(x - other.x, y - other.y, z - other.z);
	}

	Vector3D Vector3D::Negated() const
	{
		return Vector3D(-x, -y, -z);
	}

	float Vector3D::Dot(const Vector3D& other) const
	{
		return x * other.x + y * other.y + z * other.z;
	}

	Vector3D Vector3D::Multiply(const Vector3D& other) const
	{
		return Vector3D(x * other.x, y * other.y, z * other.z);
	}

	Vector3D Vector3D::Multiply(const float& scalar) const
	{
		return Vector3D(x * scalar, y * scalar, z * scalar);
	}

	Vector3D Vector3D::Divide(const float& scalar) const
	{
		return Vector3D(x / scalar, y / scalar, z / scalar);
	}

	Vector3D Vector3D::Divide(const Vector3D& other) const
	{
		return Vector3D(x / other.x, y / other.y, z / other.z);
	}

	float& Vector3D::BiggestComponent()
	{
		return SMath::Max(x, SMath::Max(y, z));
	}

	float& Vector3D::SmallestComponent()
	{
		return SMath::Min(x, SMath::Min(y, z));
	}

	const float& Vector3D::BiggestComponent() const
	{
		return SMath::Max(x, SMath::Max(y, z));
	}

	const float& Vector3D::SmallestComponent() const
	{
		return SMath::Min(x, SMath::Min(y, z));
	}

	Vector3D Vector3D::Abs() const
	{
		return Vector3D(SMath::Abs(x), SMath::Abs(y), SMath::Abs(z));
	}

	Vector3D Vector3D::Clamp(const Vector3D& min, const Vector3D& max) const
	{
		return Vector3D(SMath::Clamp(x, min.x, max.x), SMath::Clamp(y, min.y, max.y), SMath::Clamp(z, min.z, max.z));
	}

	Vector3D Vector3D::ClampComponents(const float& min, const float& max) const
	{
		return Vector3D(SMath::Clamp(x, min, max), SMath::Clamp(y, min, max), SMath::Clamp(z, min, max));
	}
} }