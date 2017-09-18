#pragma once

#include "Common/CommonDefines.h"
#include "../MathConstants.h"

namespace SupergodEngine { namespace Math
{
	/// <summary>
	/// An interface that adds all the comparison methods needed to compare it like a real supergod object!<para/>
	/// T is the type being compared.
	/// </summary>
	template<class T>
	interface SUPERGOD_API ISupergodEquatable
	{
		virtual bool Equals(const T& other) const = 0;
		virtual bool CloseEnough(const T& other, const float& threshold = Constants::CLOSE_ENOUGH_DEFAULT_THRESHOLD) const = 0;
		
		/// <summary>
		/// Checks if this equals to other.
		/// </summary>
		inline bool operator==(const T& other) const
		{
			return Equals(other);
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
		inline bool Equals(const ISupergodEquatable<T>& first, const T& second)
		{
			return first.Equals(second);
		}

		/// <summary>
		/// Is first close enough to second with the threshold of threshold?
		/// </summary>
		template<class T>
		inline bool CloseEnough(const ISupergodEquatable<T>& first, const T& second, const float& threshold = Constants::CLOSE_ENOUGH_DEFAULT_THRESHOLD)
		{
			return first.CloseEnough(second, threshold);
		}
	}
} }