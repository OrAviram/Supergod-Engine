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
		/// Adds this and other (implementation is class-specific).
		/// </summary>
		inline T operator+(const T& other) const
		{
			return Add(other);
		}

		/// <summary>
		/// Adds other to this.
		/// </summary>
		inline T operator+=(const T& other)
		{
			T& t = (T&)*this;
			t = Add(other);
			return t;
		}
	};

	/// <summary>
	/// Interface for classes that can be subtracted.
	/// </summary>
	template<class T>
	interface SUPERGOD_API ISubtractable
	{
		virtual T Subtract(const T& other) const = 0;

		/// <summary>
		/// Subtracts other from this.
		/// </summary>
		inline T operator-(const T& other) const
		{
			return Subtract(other);
		}

		/// <summary>
		/// Subtracts other from this.
		/// </summary>
		inline T operator-=(const T& other) const
		{
			T& t = (T&)*this;
			t = Subtract(other);
			return t;
		}
	};

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
} }