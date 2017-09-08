#pragma once

#include "../../Common/CommonDefines.h"
#include "../Interfaces/ISupergodEquatable.h"
#include "../Interfaces/IAbsolutable.h"
#include "../Interfaces/IClampable.h"

namespace std
{
	template<class T>
	class function;
}

namespace SupergodEngine { namespace Math
{
	// TODO: Add ILerpable once you figure out how to fixe the problem you have because of the lack of extension methods in C++.
	
	/// <summary>
	/// Interface vector structs can implement.<para/>
	/// T is the type of the vector.
	/// </summary>
	template<class T>
	interface SUPERGOD_API IVector : public ISupergodEquatable<T>, public IAbsolutable<T>, public IClampable<T>
	{
		virtual T Add(const T& other) const = 0;
		virtual T Subtract(const T& other) const = 0;
		virtual T Negated() const = 0;

		virtual T Multiply(const T& other) const = 0;
		virtual T Multiply(const float& scalar) const = 0;

		virtual T Divide(const T& other) const = 0;
		virtual T Divide(const float& scalar) const = 0;

		virtual float& BiggestComponent() = 0;
		virtual float& SmallestComponent() = 0;
		virtual const float& BiggestComponent() const = 0;
		virtual const float& SmallestComponent() const = 0;

		virtual float Dot(const T& other) const = 0;

		virtual bool ContainsComponent(std::function<bool(const float&)> test) const = 0;
		virtual T ClampComponents(const float& min, const float& max) const = 0;

		/// <summary>
		/// Gets the magnitude (length) of this vector.
		/// </summary>
		float Magnitude() const
		{
			return Vector::Magnitude(*this);
		}

		/// <summary>
		/// Gets the squared magnitude (length) of this vector. This is faster than squaring the magnitude.
		/// </summary>
		float SqrMagnitude() const
		{
			return Vector::SqrMagnitude(*this);
		}

		/// <summary>
		/// Gets a unit vector pointing to the same direction as this.
		/// </summary>
		T Normalized() const
		{
			return Vector::Normalize(*this);
		}

		/// <summary>
		/// Multiplies this and other component-wise.
		/// </summary>
		T operator*(const T& other) const
		{
			return Multiply(other);
		}

		/// <summary>
		/// Multiplies every component of this by scalar.
		/// </summary>
		T operator*(const float& scalar) const
		{
			return Multiply(scalar);
		}

		/// <summary>
		/// Multiplies every component of vector by scalar.
		/// </summary>
		friend T operator*(const float& scalar, const T& vector)
		{
			return vector * scalar;
		}

		/// <summary>
		/// Divides every component of this by its corresponding component in other.
		/// </summary>
		T operator/(const T& other) const
		{
			return Divide(other);
		}

		/// <summary>
		/// Divides every component of this by scalar.
		/// </summary>
		T operator/(const float& scalar) const
		{
			return Divide(scalar);
		}

		/// <summary>
		/// Adds every component of this with its corresponding component in other.
		/// </summary>
		T operator+(const T& other) const
		{
			return Add(other);
		}

		/// <summary>
		/// Adds every component of other from its corresponding component in this.
		/// </summary>
		T operator-(const T& other) const
		{
			return Subtract(other);
		}

		/// <summary>
		/// Negates every component of this.
		/// </summary>
		T operator-() const
		{
			return Negated();
		}
	};
} }