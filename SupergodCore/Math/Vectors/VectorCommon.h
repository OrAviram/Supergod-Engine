#pragma once

#include "Common/CommonDefines.h"
#include "../Interfaces/ISupergodEquatable.h"
#include "../Interfaces/ILerpable.h"
#include "../Interfaces/ArithmeticInterfaces.h"
#include "../Angle.h"

namespace std
{
	template<class T>
	class function;
}

namespace SupergodCore { namespace Math
{
	/// <summary>
	/// Base struct for vector structs.<para/>
	/// T is the type of the vector.
	/// </summary>
	template<class T>
	struct SUPERGOD_API_CLASS VectorBase : public ISupergodEquatable<T>, public ILerpable<T>,
		public ISubtractable<T>, public INegatable<T>, public IDividable<T>, public IScalarDividable<T>, public IMultipliable<T>
	{
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
			return TEMPLATED_INTERFACE_THIS.Dot((const T&)*this);
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
		inline T ClampMagnitude(float min, float max) const
		{
			float magnitude = Magnitude();
			T normalized = *this / magnitude;
			return normalized * SMath::Clamp(magnitude, min, max);
		}

		/// <summary>
		/// Gets a vector pointing in the same direction as this with a magnitude of magnitude.
		/// </summary>
		inline T SetMagnitude(float magnitude) const
		{
			return Normalized() * magnitude;
		}

		/// <summary>
		/// Projects this onto target.
		/// </summary>
		inline T ProjectOnto(const T& target) const
		{
			return TEMPLATED_INTERFACE_THIS.Dot(target) / target.SqrMagnitude() * target;
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
		/// Gets the smalles angle [0, 180 degrees] between this and other.
		/// </summary>
		/// <param name="normalizethis">Should this be normalized?</param>
		/// <param name="normalizeOther">Should other be normalized?</param>
		inline Angle SmallestAngle(const T& other, bool normalizeThis = true, bool normalizeOther = true) const
		{
			return SMath::Acos(
				(normalizeThis ? Normalized() : (const T&)*this).Dot(
				normalizeOther ? other.Normalized() : other
				));
		}

		/// <summary>
		/// Gets the biggest angle [180 degrees, 360 degrees] between this and other.
		/// </summary>
		/// <param name="normalizethis">Should this be normalized?</param>
		/// <param name="normalizeOther">Should other be normalized?</param>
		inline Angle BiggestAngle(const T& other, bool normalizeThis = true, bool normalizeOther = true) const
		{
			return Angle::FullRotation() - SmallestAngle(other, normalizeThis, normalizeOther);
		}

		/// <summary>
		/// Multiplies every component of vector by scalar.
		/// </summary>
		inline friend T operator*(float scalar, const T& vector)
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
		inline float& BiggestComponent(T& vector)
		{
			return vector.BiggestComponent();
		}

		/// <summary>
		/// Gets a reference to the biggest component in vector.
		/// </summary>
		template<class T>
		inline const float& BiggestComponent(const T& vector)
		{
			return vector.BiggestComponent();
		}

		/// <summary>
		/// Gets a reference to the smallest component in vector.
		/// </summary>
		template<class T>
		inline float& SmallestComponent(T& vector)
		{
			return vector.SmallestComponent();
		}

		/// <summary>
		/// Gets a reference to the smallest component in vector.
		/// </summary>
		template<class T>
		inline const float& SmallestComponent(const T& vector)
		{
			return vector.SmallestComponent();
		}

		/// <summary>
		/// Gets the dot product of a and b.
		/// </summary>
		template<class T>
		inline float Dot(const T& a, const T& b)
		{
			return a.Dot(b);
		}
		
		/// <summary>
		/// Does any component of vector pass test?
		///	</summary>
		/// <param name="test">The test to run for each component.</param>
		template<class T>
		inline bool ContainsComponent(const T& vector, const std::function<bool(float)>& test)
		{
			return vector.ContainsComponent(test);
		}

		/// <summary>
		/// Gets a vector where all of its components are the absolute value their corresponding component in vector.
		///	</summary>
		template<class T>
		inline T Abs(const T& vector)
		{
			return vector.Abs();
		}

		/// <summary>
		/// Clamps all of the components of vector so they are never smaller than min and never bigger than max.
		///	</summary>
		template<class T>
		inline T ClampComponents(const T& vector, float min, float max)
		{
			return vector.ClampComponents(min, max);
		}

		/// <summary>
		/// Gets the squared magnitude of vector. This is faster than squaring the magnitude.
		/// </summary>
		template<class T>
		inline float SqrMagnitude(const T& vector)
		{
			return vector.SqrMagnitude();
		}

		/// <summary>
		/// Gets the magnitude (length) of vector.
		/// </summary>
		template<class T>
		inline float Magnitude(const T& vector)
		{
			return vector.Magnitude();
		}

		/// <summary>
		/// Gets a unit vector pointing at the same direction as vector.
		/// </summary>
		template<class T>
		inline T Normalize(const T& vector)
		{
			return vector.Normalized();
		}

		/// <summary>
		/// Gets a vector pointing in the same direction as this with a magnitude that is clamped between min and max.
		/// </summary>
		template<class T>
		inline T ClampMagnitude(const T& vector, float min, float max)
		{
			return vector.ClampMagnitude(min, max);
		}

		/// <summary>
		/// Gets a vector pointing in the same direction as this with a magnitude of magnitude.
		/// </summary>
		template<class T>
		inline T SetMagnitude(const T& vector, float magnitude)
		{
			return vector.SetMagnitude(magnitude);
		}

		/// <summary>
		/// Projects source onto target.
		/// </summary>
		template<class T>
		inline T ProjectOnto(const T& source, const T& target)
		{
			return source.ProjectOnto(target);
		}

		/// <summary>
		/// Reflects source through mirror using the formula "2 * m * ((v dot m) / |m|²) - v" where v is source and m is mirror.
		/// </summary>
		template<class T>
		inline T Reflect(const T& source, const T& mirror)
		{
			return source.ProjectOnto(mirror);
		}

		/// <summary>
		/// Gets a vector that goes from a to b.
		/// </summary>
		template<class T>
		inline T LookAt(const T& a, const T& b)
		{
			return a.LookAt(b);
		}

		/// <summary>
		/// Gets a unit length vector pointing from a at b.
		/// </summary>
		template<class T>
		inline T PointAt(const T& a, const T& b)
		{
			return a.PointAt(b);
		}

		/// <summary>
		/// Gets the distance squared between a and b. This is faster than squaring the distance.
		/// </summary>
		template<class T>
		inline float SqrDistance(const T& a, const T& b)
		{
			return a.SqrDistance(b);
		}

		/// <summary>
		/// Gets the distance between a and b.
		/// </summary>
		template<class T>
		inline float Distance(const T& a, const T& b)
		{
			return a.Distance(b);
		}

		/// <summary>
		/// Gets the smalles angle [0, 180 degrees] between left and right.
		/// </summary>
		/// <param name="normalizeLeft">Should left be normalized?</param>
		/// <param name="normalizeRight">Should right be normalized?</param>
		template<class T>
		inline Angle SmallestAngle(const T& left, const T& right, bool normalizeLeft = true, bool normalizeRight = true)
		{
			return left.SmallestAngle(right, normalizeLeft, normalizeRight);
		}

		/// <summary>
		/// Gets the biggest angle [180 degrees, 360 degrees] between left and right.
		/// </summary>
		/// <param name="normalizeLeft">Should left be normalized?</param>
		/// <param name="normalizeRight">Should right be normalized?</param>
		template<class T>
		inline Angle BiggestAngle(const T& left, const T& right, bool normalizeLeft = true, bool normalizeRight = true)
		{
			return left.BiggestAngle(right, normalizeLeft, normalizeRight);
		}
	}
} }