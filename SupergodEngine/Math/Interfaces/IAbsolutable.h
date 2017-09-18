#pragma once

#pragma once

#include "Common/CommonDefines.h"
#include "../MathConstants.h"

namespace SupergodEngine { namespace Math
{
	/// <summary>
	/// Not sure if that's a word, but I had an interface in my previous system that only had the Abs method in it, so I decided to keep it...<para/>
	/// T is the type you can get the absolute value of.
	/// </summary>
	template<class T>
	interface SUPERGOD_API IAbsolutable
	{
		virtual T Abs() const = 0;
	};

	/// <summary>
	/// Namespace with functions that call methods from the IAbsolutable interface.
	/// </summary>
	namespace Absolutable
	{
		/// <summary>
		/// Gets the absolute value of target..
		/// </summary>
		template<class T>
		T Abs(const IAbsolutable<T>& target)
		{
			return target.Abs();
		}
	}
} }