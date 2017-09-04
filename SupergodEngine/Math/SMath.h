#pragma once

#include "MathConstants.h"
#include "../Common/CommonDefines.h"

namespace SupergodEngine { namespace Math
{
	/// <summary>
	/// Special supergod math functions.
	/// </summary>
	namespace SMath
	{
		/// <summary>
		/// Checks if the distance between a and b is threshold.
		/// </summary>
		SUPERGOD_API bool CloseEnough(float a, float b, float threshold = Constants::CLOSE_ENOUGH_DEFAULT_THRESHOLD);
	}
} }