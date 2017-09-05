#pragma once

#include "../../Common/CommonDefines.h"

namespace SupergodEngine { namespace Math
{
	/// <summary>
	/// Interface that types that can be clamped between a minimum and a maximum can implement.<para/>
	/// T is the type that can be clamped.
	/// </summary>
	template<class T>
	interface SUPERGOD_API IClampable
	{
		virtual T Clamp(const T& min, const T& max) const = 0;
	};
} }