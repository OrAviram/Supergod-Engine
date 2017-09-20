#pragma once
#include "Common/CommonDefines.h"

namespace SupergodCore { namespace Math
{
	/// <summary>
	/// Interface for things that can compare their sizes (bigger than or smaller than).
	/// </summary>
	template<class T>
	interface ISizeComparable
	{
		virtual bool BiggerThan(const T& other) const = 0;
		virtual bool SmallerThan(const T& other) const = 0;

		/// <summary>
		/// Is this bigger than other?
		/// </summary>
		inline bool operator>(const T& other) const
		{
			return BiggerThan(other);
		}

		/// <summary>
		/// Is this smaller than other?
		/// </summary>
		inline bool operator<(const T& other) const
		{
			return SmallerThan(other);
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
		inline bool BiggerThan(const ISizeComparable<T>& bigger, const T& smaller)
		{
			return bigger.BiggerThan(smaller);
		}

		/// <summary>
		/// Is smaller actually smaller than bigger?
		/// </summary>
		template<class T>
		inline bool SmallerThan(const ISizeComparable<T>& smaller, const T& bigger)
		{
			return smaller.SmallerThan(bigger);
		}
	}
} }