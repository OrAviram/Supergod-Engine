#pragma once
#include "Common/CommonDefines.h"

namespace SupergodCore { namespace Math
{
	/// <summary>
	/// Interface for things that can compare their sizes (bigger than or smaller than).
	/// </summary>
	template<class T>
	struct ISizeComparable
	{
		/// <summary>
		/// Is this bigger than other?
		/// </summary>
		inline bool operator>(const T& other) const
		{
			return TEMPLATED_INTERFACE_THIS.BiggerThan(other);
		}

		/// <summary>
		/// Is this smaller than other?
		/// </summary>
		inline bool operator<(const T& other) const
		{
			return TEMPLATED_INTERFACE_THIS.SmallerThan(other);
		}
	};

	/// <summary>
	/// Namespace that calls methods from the ISizeComparer interface.
	/// </summary>
	namespace SizeComparer
	{
		/// <summary>
		/// Is bigger actually bigger than smaller?
		/// </summary>
		template<class T>
		inline bool BiggerThan(const T& bigger, const T& smaller)
		{
			return bigger.BiggerThan(smaller);
		}

		/// <summary>
		/// Is smaller actually smaller than bigger?
		/// </summary>
		template<class T>
		inline bool SmallerThan(const T& smaller, const T& bigger)
		{
			return smaller.SmallerThan(bigger);
		}
	}
} }