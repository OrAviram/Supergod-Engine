#pragma once

#include "../../Common/CommonDefines.h"
#include "../Interfaces/ISupergodEquatable.h"
#include "../Interfaces/IAbsolutable.h"
#include "../Interfaces/IClampable.h"
#include "../Interfaces/ArithmeticInterfaces.h"

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
	interface SUPERGOD_API IVector : public ISupergodEquatable<T>, public IAbsolutable<T>, public IClampable<T>,
		public ISubtractable<T>, public IAddable<T>, public INegatable<T>, public IDividable<T>, public IScalarDividable<T>, public IMultipliable<T>, public IScalarMultipliable<T>
	{
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
			float sqrMagnitude = SqrMagnitude();
			if (sqrMagnitude == 1 || sqrMagnitude == 0)
				return sqrMagnitude;

			return SMath::Sqrt(sqrMagnitude);
		}

		/// <summary>
		/// Gets the squared magnitude (length) of this vector. This is faster than squaring the magnitude.
		/// </summary>
		float SqrMagnitude() const
		{
			return Dot((const T&)*this);
		}

		/// <summary>
		/// Gets a unit vector pointing to the same direction as this.
		/// </summary>
		T Normalized() const
		{
			return Divide(Magnitude());
		}

		/// <summary>
		/// Multiplies every component of vector by scalar.
		/// </summary>
		friend T operator*(const float& scalar, const T& vector)
		{
			return vector * scalar;
		}
	};

	/// <summary>
	/// Namespace that calls functions from IVector.
	/// </summary>
	namespace Vector
	{
		/// <summary>
		/// Gets the dot product of a and b. NOTE: The implementation is struct-specific, and this is just a static way to call the methods.
		/// </summary>
		template<class T>
		inline float Dot(const IVector<T>& a, const IVector<T>& b)
		{
			return a.Dot((const T&)b);
		}

		/// <summary>
		/// Gets the squared magnitude of vector. This is faster than squaring the magnitude.
		/// </summary>
		template<class T>
		inline float SqrMagnitude(const IVector<T>& vector)
		{
			return vector.SqrMagnitude();
		}

		/// <summary>
		/// Gets the magnitude (length) of vector.
		/// </summary>
		template<class T>
		inline float Magnitude(const IVector<T>& vector)
		{
			return vector.Magnitude();
		}

		/// <summary>
		/// Gets a unit vector pointing at the same direction as vector.
		/// </summary>
		template<class T>
		inline T Normalize(const IVector<T>& vector)
		{
			return vector.Normalized();
		}
	}
} }