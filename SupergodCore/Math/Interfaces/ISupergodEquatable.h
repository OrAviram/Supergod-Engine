#pragma once

#include "Common/CommonDefines.h"
#include "../MathConstants.h"

namespace SupergodCore { namespace Math
{
	/// <summary>
	/// An interface that adds all the comparison methods needed to compare it like a real supergod object!<para/>
	/// T is the type being compared.
	/// </summary>
	template<class T>
	struct SUPERGOD_API_CLASS ISupergodEquatable
	{
		/// <summary>
		/// Checks if this equals to other.
		/// </summary>
		inline bool operator==(const T& other) const
		{
			return TEMPLATED_INTERFACE_THIS.Equals(other);
		}

		/// <summary>
		/// Checks if this equals to other.
		/// </summary>
		inline bool operator!=(const T& other) const
		{
			return !(*this == other);
		}
	};

	/// <summary>
	/// Namespace that calls methods from ISupergodEquatable.
	/// </summary>
	namespace SupergodEquatable
	{
		/// <summary>
		/// Is first equal to second?
		/// </summary>
		template<class T>
		inline bool Equals(const T& first, const T& second)
		{
			return first.Equals(second);
		}

		/// <summary>
		/// Is first close enough to second with the threshold of threshold?
		/// </summary>
		template<class T>
		inline bool CloseEnough(const T& first, const T& second, float threshold = Constants::CLOSE_ENOUGH_DEFAULT_THRESHOLD)
		{
			return first.CloseEnough(second, threshold);
		}
	}
} }