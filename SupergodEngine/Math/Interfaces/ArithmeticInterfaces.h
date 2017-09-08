#pragma once
#include "../../Common/CommonDefines.h"

namespace SupergodEngine { namespace Math
{
	#define TWO_SIDED_ARITHMETIC_INTERFACE(interfaceName, functionName, sign) \
		template<class T> \
		interface SUPERGOD_API interfaceName \
		{ \
			virtual T functionName(const T& other) const = 0; \
			inline T operator sign(const T& other) const \
			{ \
				return functionName(other); \
			} \
			inline T operator sign=(const T& other) \
			{ \
				T& t = (T&)*this; \
				t = functionName(other); \
				return t; \
			} \
		}

	/// <summary>
	/// Interface for classes that can be added.
	/// </summary>
	TWO_SIDED_ARITHMETIC_INTERFACE(IAddable, Add, +);

	/// <summary>
	/// Interface for classes that can be subtracted.
	/// </summary>
	TWO_SIDED_ARITHMETIC_INTERFACE(ISubtractable, Subtract, -);

	/// <summary>
	/// Interface for classes that can be subtracted.
	/// </summary>
	template<class T>
	interface SUPERGOD_API INegatable
	{
		virtual T Negated() const = 0;

		/// <summary>
		/// Negates this.
		/// </summary>
		inline T operator-() const
		{
			return Negated();
		}
	};

	/// <summary>
	/// Namespace with functions that are called from the arithmetic related interfaces.
	/// </summary>
	namespace ArithmeticOps
	{
		/// <summary>
		/// Adds a and b (implementation is class-specific).
		/// </summary>
		template<class T>
		inline T Add(const T& a, const T& b)
		{
			return a.Add(b);
		}

		/// <summary>
		/// Subtracts b from a.
		/// </summary>
		template<class T>
		inline T Subtract(const T& a, const T& b)
		{
			return a.Subtract(b);
		}

		/// <summary>
		/// Negates target.
		/// </summary>
		template<class T>
		inline T Negate(const T& target)
		{
			return target.Negated();
		}
	}

	#undef TWO_SIDED_ARITHMETIC_INTERFACE
} }

