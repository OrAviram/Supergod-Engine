#pragma once
#include "Common/CommonDefines.h"

namespace SupergodEngine { namespace Math
{
	/// <summary>
	/// Represents a 32 bit color with 4 bytes from 0 to the maximum value of a byte.
	/// </summary>
	struct SUPERGOD_API BColor
	{
		union
		{
			struct { byte red, green, blue, alpha; };
			uint value;
			byte components[4];
		};

		/// <summary>
		/// Creates a new color with all of its components set to 0.
		/// </summary>
		BColor();

		/// <summary>
		/// Creates a new color with specified red, green, blue and alpha values.
		/// </summary>
		BColor(const byte& red, const byte& green, const byte& blue, const byte& alpha);
	};
} }