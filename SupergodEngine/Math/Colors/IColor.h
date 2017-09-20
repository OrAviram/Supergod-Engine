#pragma once

#include "Common/CommonDefines.h"
#include "../Interfaces/ISupergodEquatable.h"

namespace SupergodEngine { namespace Math
{
	/// <summary>
	/// Interface color structs can implement.
	/// </summary>
	template<class T>
	interface SUPERGOD_API IColor : public ISupergodEquatable<T>
	{
		virtual T Inverted() const = 0;
	};

	/// <summary>
	/// Functions that call methods from the IColor interface.
	/// </summary>
	namespace Color
	{
		/// <summary>
		/// Inverts color.
		/// </summary>
		template<class T>
		inline T Invert(const IColor<T>& color)
		{
			return color.Inverted();
		}
	}
} }