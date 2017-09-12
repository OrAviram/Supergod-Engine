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

/// <summary>
/// Defines a vector preset function. This is being undefined in Vector.h.
/// </summary>
#define DEFINE_VECTOR_PRESET(type, name, value) \
			inline static const type& name() \
			{ \
				static const type val value; \
				return val; \
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

		virtual bool ContainsComponent(const std::function<bool(const float&)>& test) const = 0;
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
		/// Reflects this through mirror using the formula "2 * m * ((v dot m) / |m|²) - v" where v is this and m is mirror.
		/// </summary>
		inline T Reflect(const T& mirror) const
		{
			return 2 * ProjectOnto(mirror) - (const T&)*this;
		}

		/// <summary>
		/// Gets a vector that goes from this to other.
		/// </summary>
		inline T LookAt(const T& other) const
		{
			return ArithmeticOps::Subtract(other, (const T&)*this);
		}

		/// <summary>
		/// Gets a unit length vector pointing from this at other.
		/// </summary>
		inline T PointAt(const T& other) const
		{
			return this->LookAt(other).Normalized();
		}

		/// <summary>
		/// Gets the distance squared between this and other. This is faster than squaring the distance.
		/// </summary>
		inline float SqrDistance(const T& other) const
		{
			return this->LookAt(other).SqrMagnitude();
		}

		/// <summary>
		/// Gets the distance between this and other.
		/// </summary>
		inline float Distance(const T& other) const
		{
			return SMath::Sqrt(this->SqrDistance(other));
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
		/// Does any component of vector pass test?
		///	</summary>
		/// <param name="test">The test to run for each component.</param>
		template<class T>
		inline bool ContainsComponent(const IVector<T>& vector, const std::function<bool(const float&)>& test)
		{
			return vector.ContainsComponent(test);
		}

		/// <summary>
		/// Gets a vector where all of its components are the absolute value their corresponding component in vector.
		///	</summary>
		template<class T>
		inline T Abs(const IVector<T>& vector)
		{
			return vector.Abs();
		}

		/// <summary>
		/// Clamps all of the components of vector so they are never smaller than min and never bigger than max.
		///	</summary>
		template<class T>
		inline T ClampComponents(const IVector<T>& vector, const float& min, const float& max)
		{
			return vector.ClampComponents(min, max);
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
		/// Reflects source through mirror using the formula "2 * m * ((v dot m) / |m|²) - v" where v is source and m is mirror.
		/// </summary>
		template<class T>
		inline T Reflect(const IVector<T>& source, const T& mirror)
		{
			return source.ProjectOnto(mirror);
		}

		/// <summary>
		/// Gets a vector that goes from a to b.
		/// </summary>
		template<class T>
		inline T LookAt(const IVector<T>& a, const T& b)
		{
			return a.LookAt(b);
		}

		/// <summary>
		/// Gets a unit length vector pointing from a at b.
		/// </summary>
		template<class T>
		inline T PointAt(const IVector<T>& a, const T& b)
		{
			return a.PointAt(b);
		}

		/// <summary>
		/// Gets the distance squared between a and b. This is faster than squaring the distance.
		/// </summary>
		template<class T>
		inline float SqrDistance(const IVector<T>& a, const T& b)
		{
			return a.SqrDistance(b);
		}

		/// <summary>
		/// Gets the distance between a and b.
		/// </summary>
		template<class T>
		inline float Distance(const IVector<T>& a, const T& b)
		{
			return a.Distance(b);
		}
	}
} }