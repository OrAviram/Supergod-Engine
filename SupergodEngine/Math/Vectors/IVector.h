#pragma once

#include "../../Common/CommonDefines.h"
#include "../Interfaces/ISupergodEquatable.h"
#include "../Interfaces/IAbsolutable.h"
#include "../Interfaces/IClampable.h"
#include "../Interfaces/ILerpable.h"
#include "../Interfaces/ArithmeticInterfaces.h"

namespace std
{
	template<class T>
	class function;
}

namespace SupergodEngine { namespace Math
{
	// TODO: Add the methods for finding the angle when the Angle struct is added.

	/// <summary>
	/// Interface vector structs can implement.<para/>
	/// T is the type of the vector.
	/// </summary>
	template<class T>
	interface SUPERGOD_API IVector : public ISupergodEquatable<T>, public IAbsolutable<T>, public IClampable<T>, public ILerpable<T>,
		public ISubtractable<T>, public INegatable<T>, public IDividable<T>, public IScalarDividable<T>, public IMultipliable<T>
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
		inline float Magnitude() const
		{
			float sqrMagnitude = SqrMagnitude();
			if (sqrMagnitude == 1 || sqrMagnitude == 0)
				return sqrMagnitude;

			return SMath::Sqrt(sqrMagnitude);
		}

		/// <summary>
		/// Gets the squared magnitude (length) of this vector. This is faster than squaring the magnitude.
		/// </summary>
		inline float SqrMagnitude() const
		{
			return Dot((const T&)*this);
		}

		/// <summary>
		/// Gets a unit vector pointing to the same direction as this.
		/// </summary>
		inline T Normalized() const
		{
			return *this / Magnitude();
		}

		/// <summary>
		/// Gets a vector pointing in the same direction as this with a magnitude that is clamped between min and max.
		/// </summary>
		inline T ClampMagnitude(const float& min, const float& max) const
		{
			float magnitude = Magnitude();
			T normalized = *this / magnitude;
			return normalized * SMath::Clamp(magnitude, min, max);
		}

		/// <summary>
		/// Gets a vector pointing in the same direction as this with a magnitude of magnitude.
		/// </summary>
		inline T SetMagnitude(const float& magnitude) const
		{
			return Normalized() * magnitude;
		}

		/// <summary>
		/// Projects this onto target.
		/// </summary>
		inline T ProjectOnto(const T& target) const
		{
			return this->Dot(target) / target.SqrMagnitude() * target;
		}

		/// <summary>
		/// Reflects this through mirror.
		/// </summary>
		inline T Reflect(const T& mirror) const
		{
			return *this - 2 * ProjectOnto(mirror);
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
		/// Gets a reference to the biggest component in vector.
		/// </summary>
		template<class T>
		inline float& BiggestComponent(IVector<T>& vector)
		{
			return vector.BiggestComponent();
		}

		/// <summary>
		/// Gets a reference to the biggest component in vector.
		/// </summary>
		template<class T>
		inline const float& BiggestComponent(const IVector<T>& vector)
		{
			return vector.BiggestComponent();
		}

		/// <summary>
		/// Gets a reference to the smallest component in vector.
		/// </summary>
		template<class T>
		inline float& SmallestComponent(IVector<T>& vector)
		{
			return vector.SmallestComponent();
		}

		/// <summary>
		/// Gets a reference to the smallest component in vector.
		/// </summary>
		template<class T>
		inline const float& SmallestComponent(const IVector<T>& vector)
		{
			return vector.SmallestComponent();
		}

		/// <summary>
		/// Gets the dot product of a and b.
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

		/// <summary>
		/// Gets a vector pointing in the same direction as this with a magnitude that is clamped between min and max.
		/// </summary>
		template<class T>
		inline T ClampMagnitude(const IVector<T>& vector, const float& min, const float& max)
		{
			return vector.ClampMagnitude(min, max);
		}

		/// <summary>
		/// Gets a vector pointing in the same direction as this with a magnitude of magnitude.
		/// </summary>
		template<class T>
		inline T SetMagnitude(const IVector<T>& vector, const float& magnitude)
		{
			return vector.SetMagnitude(magnitude);
		}

		/// <summary>
		/// Projects source onto target.
		/// </summary>
		template<class T>
		inline T ProjectOnto(const IVector<T>& source, const T& target)
		{
			return source.ProjectOnto(target);
		}

		/// <summary>
		/// Reflects source through mirror.
		/// </summary>
		template<class T>
		inline T Reflect(const IVector<T>& source, const T& mirror)
		{
			return source.ProjectOnto(mirror);
		}
	}
} }