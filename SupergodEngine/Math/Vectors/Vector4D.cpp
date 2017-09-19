#include <functional>
#include "Vector4D.h"

namespace SupergodEngine { namespace Math
{
	Vector4D::Vector4D()
		: x(0), y(0), z(0), w(0)
	{
	}

	Vector4D::Vector4D(const float& x, const float& y, const float& z, const float& w)
		: x(x), y(y), z(z), w(w)
	{
	}

	Vector4D::Vector4D(const Vector2D& xy, const Vector2D& zw)
		: x(xy.x), y(xy.y), z(zw.x), w(zw.y)
	{
	}

	Vector4D::Vector4D(const Vector3D& xyz, const float& w)
		: x(xyz.x), y(xyz.y), z(xyz.z), w(w)
	{
	}

	Vector4D::Vector4D(const float& x, const Vector3D& yzw)
		: x(x), y(yzw.x), z(yzw.y), w(yzw.z)
	{
	}

	Vector4D::Vector4D(const float& x, const float& y, const Vector2D& zw)
		: x(x), y(y), z(zw.x), w(zw.y)
	{
	}

	Vector4D::Vector4D(const float& x, const Vector2D& yz, const float& w)
		: x(x), y(yz.x), z(yz.y), w(w)
	{
	}

	Vector4D::Vector4D(const Vector2D& xy, const float& z, const float& w)
		: x(xy.x), y(xy.y), z(z), w(w)
	{
	}

	Vector4D::operator Vector2D() const
	{
		return Vector2D(x, y);
	}

	Vector4D::operator Vector3D() const
	{
		return Vector3D(x, y, z);
	}

	bool Vector4D::Equals(const Vector4D& other) const
	{
		return x == other.x && y == other.y && z == other.z && w == other.w;
	}

	bool Vector4D::CloseEnough(const Vector4D& other, const float& threshold) const
	{
		return SMath::CloseEnough(x, other.x, threshold) && SMath::CloseEnough(y, other.y, threshold) && SMath::CloseEnough(z, other.z, threshold) && SMath::CloseEnough(w, other.w, threshold);
	}

	bool Vector4D::ContainsComponent(const std::function<bool(const float&)>& test) const
	{
		return test(x) || test(y) || test(z) || test(w);
	}

	Vector4D Vector4D::Add(const Vector4D& other) const
	{
		return Vector4D(x + other.x, y + other.y, z + other.z, w + other.w);
	}

	Vector4D Vector4D::Subtract(const Vector4D& other) const
	{
		return Vector4D(x - other.x, y - other.y, z - other.z, w - other.w);
	}

	Vector4D Vector4D::Negated() const
	{
		return Vector4D(-x, -y, -z, -w);
	}

	float Vector4D::Dot(const Vector4D& other) const
	{
		return x * other.x + y * other.y + z * other.z + w * other.w;
	}

	Vector4D Vector4D::Multiply(const Vector4D& other) const
	{
		return Vector4D(x * other.x, y * other.y, z * other.z, w * other.w);
	}

	Vector4D Vector4D::Multiply(const float& scalar) const
	{
		return Vector4D(x * scalar, y * scalar, z * scalar, w * scalar);
	}

	Vector4D Vector4D::Divide(const float& scalar) const
	{
		return Vector4D(x / scalar, y / scalar, z / scalar, w / scalar);
	}

	Vector4D Vector4D::Divide(const Vector4D& other) const
	{
		return Vector4D(x / other.x, y / other.y, z / other.z, w / other.w);
	}

	float& Vector4D::BiggestComponent()
	{
		return SMath::Max(x, SMath::Max(y, SMath::Max(z, w)));
	}

	float& Vector4D::SmallestComponent()
	{
		return SMath::Min(x, SMath::Min(y, SMath::Min(z, w)));
	}

	const float& Vector4D::BiggestComponent() const
	{
		return SMath::Max(x, SMath::Max(y, SMath::Max(z, w)));
	}

	const float& Vector4D::SmallestComponent() const
	{
		return SMath::Min(x, SMath::Min(y, SMath::Min(z, w)));
	}

	Vector4D Vector4D::Abs() const
	{
		return Vector4D(SMath::Abs(x), SMath::Abs(y), SMath::Abs(z), SMath::Abs(w));
	}

	Vector4D Vector4D::Clamp(const Vector4D& min, const Vector4D& max) const
	{
		return Vector4D(SMath::Clamp(x, min.x, max.x), SMath::Clamp(y, min.y, max.y), SMath::Clamp(z, min.z, max.z), SMath::Clamp(w, min.w, max.w));
	}

	Vector4D Vector4D::ClampComponents(const float& min, const float& max) const
	{
		return Vector4D(SMath::Clamp(x, min, max), SMath::Clamp(y, min, max), SMath::Clamp(z, min, max), SMath::Clamp(w, min, max));
	}
} }