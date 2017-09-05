#pragma once

#include "../../Common/CommonDefines.h"
#include "IVector.h"
#include "../FMath.h"

namespace SupergodEngine { namespace Math
{
	/// <summary>
	/// Functions shared between different vector types.
	/// </summary>
	namespace Vector
	{
		/// <summary>
		/// Gets the dot product of a and b. NOTE: The implementation is struct-specific, and this is just a static way to call the methods.
		/// </summary>
		template<class T>
		SUPERGOD_API float Dot(const IVector<T>& a, const IVector<T>& b)
		{
			return a.Dot((const T&)b);
		}

		/// <summary>
		/// Gets the squared magnitude of vector. This is faster than squaring the magnitude.
		/// </summary>
		template<class T>
		SUPERGOD_API float SqrMagnitude(const IVector<T>& vector)
		{
			return vector.Dot((const T&)vector);
		}

		/// <summary>
		/// Gets the magnitude (length) of vector.
		/// </summary>
		template<class T>
		SUPERGOD_API float Magnitude(const IVector<T>& vector)
		{
			return FMath::Sqrt(vector.SqrMagnitude());
		}

		/// <summary>
		/// Gets a unit vector pointing at the same direction of vector.
		/// </summary>
		template<class T>
		SUPERGOD_API T Normalize(const IVector<T>& vector)
		{
			return vector.Divide(vector.Magnitude());
		}
	}
} }