#pragma once

#include "../../Common/CommonDefines.h"
#include "../Interfaces/ISupergodEquatable.h"
#include "../Interfaces/IAbsolutable.h"
#include "../Interfaces/IClampable.h"

namespace std
{
	template<class T>
	class function;
}

namespace SupergodEngine { namespace Math
{
	// TODO: Add ILerpable once you figure out how to fixe the problem you have because of the lack of extension methods in C++.
	
	/// <summary>
	/// Interface vector structs can implement.<para/>
	/// T is the type of the vector.
	/// </summary>
	template<class T>
	interface SUPERGOD_API IVector : public ISupergodEquatable<T>, public IAbsolutable<T>, public IClampable<T>
	{
		virtual T Add(const T& other) const = 0;
		virtual T Subtract(const T& other) const = 0;
		virtual T Negated() const = 0;

		virtual T Multiply(const T& other) const = 0;
		virtual T Multiply(const float& scalar) const = 0;
		virtual T Divide(const float& scalar) const = 0;

		virtual float Magnitude() const = 0;
		virtual float SqrMagnitude() const = 0;
		virtual T Normalized() const = 0;

		virtual const float& BiggestComponent() const = 0;
		virtual const float& SmallestComponent() const = 0;
		virtual float Dot(const T& other) const = 0;

		virtual bool ContainsComponent(std::function<void(const float&)> test) const = 0;
		virtual T ClampComponents(const float& min, const float& max) const = 0;
	};
} }