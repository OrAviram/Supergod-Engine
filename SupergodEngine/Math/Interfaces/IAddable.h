#pragma once
#include "../../Common/CommonDefines.h"

namespace SupergodEngine { namespace Math
{
	/// <summary>
	/// Interface for classes that can be added.
	/// </summary>
	template<class T>
	interface SUPERGOD_API IAddable
	{
		virtual T Add(const T& other) const = 0;

		/// <summary>
		/// Adds a and b (implementation is class-specific).
		/// </summary>
		T operator+(const T& other) const
		{
			return Add(other);
		}

		/// <summary>
		/// Adds a and b (implementation is class-specific).
		/// </summary>
		static T Add(const T& a, const T& b)
		{
			return a + b;
		}
	};

	/// <summary>
	/// Namespace with methods that call methods from the IAddable interface.
	/// </summary>
	namespace Addable
	{
		/// <summary>
		/// Adds a and b (implementation is class-specific).
		/// </summary>
		template<class T>
		inline T Add(const T& a, const T& b)
		{
			return a + b;
		}
	}
} }