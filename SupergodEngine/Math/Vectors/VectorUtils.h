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