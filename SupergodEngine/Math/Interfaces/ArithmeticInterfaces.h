#pragma once

#include "Common/CommonDefines.h"

namespace SupergodEngine { namespace Math
{
	#define ARITHMETIC_INTERFACE(interfaceName, functionName, sign, secondType, secondName) \
		template<class T> \
		interface SUPERGOD_API interfaceName \
		{ \
			virtual T functionName(const secondType& secondName) const = 0; \
			inline T operator sign(const secondType& secondName) const \
			{ \
				return functionName(secondName); \
			} \
			inline T operator sign=(const secondType& secondName) \
			{ \
				T& t = (T&)*this; \
				t = functionName(secondName); \
				return t; \
			} \
		}

	#define TWO_SIDED_ARITHMETIC_INTERFACE(interfaceName, functionName, sign) ARITHMETIC_INTERFACE(interfaceName, functionName, sign, T, other)
	#define SCALAR_ARITHMETIC_INTERFACE(interfaceName, functionName, sign) ARITHMETIC_INTERFACE(interfaceName, functionName, sign, float, scalar)

	/// <summary>
	/// Interface for classes that can be added.
	/// </summary>
	TWO_SIDED_ARITHMETIC_INTERFACE(IAddable, Add, +);

	/// <summary>
	/// Interface for classes that can be subtracted.
	/// </summary>
	TWO_SIDED_ARITHMETIC_INTERFACE(ISubtractable, Subtract, -);

	/// <summary>
	/// Interface for classes that can be divided.
	/// </summary>
	TWO_SIDED_ARITHMETIC_INTERFACE(IDividable, Divide, /);

	/// <summary>
	/// Interface for classes that can be divided by a scalar.
	/// </summary>
	SCALAR_ARITHMETIC_INTERFACE(IScalarDividable, Divide, /);
	
	/// <summary>
	/// Interface for classes that can be multiplied.
	/// </summary>
	TWO_SIDED_ARITHMETIC_INTERFACE(IMultipliable, Multiply, *);

	/// <summary>
	/// Interface for classes that can be multiplied by a scalar.
	/// </summary>
	SCALAR_ARITHMETIC_INTERFACE(IScalarMultipliable, Multiply, *);

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
		/// Subtracts b from a.
		/// </summary>
		template<class T>
		inline T Divide(const T& a, const T& b)
		{
			return a.Divide(b);
		}

		/// <summary>
		/// Divides target by scalar.
		/// </summary>
		template<class T>
		inline T Divide(const T& target, const float& scalar)
		{
			return target.Divide(scalar);
		}

		/// <summary>
		/// Multiplies target by scalar.
		/// </summary>
		template<class T>
		inline T Multiply(const T& target, const float& scalar)
		{
			return target.Multiply(scalar);
		}

		/// <summary>
		/// Subtracts b from a.
		/// </summary>
		template<class T>
		inline T Multiply(const T& a, const T& b)
		{
			return a.Multiply(b);
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

	#undef ARITHMETIC_INTERFACE
	#undef TWO_SIDED_ARITHMETIC_INTERFACE
	#undef SCALAR_ARITHMETIC_INTERFACE
} }

