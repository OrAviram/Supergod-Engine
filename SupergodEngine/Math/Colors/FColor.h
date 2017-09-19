#pragma once
#include "Common/CommonDefines.h"

namespace SupergodEngine { namespace Math
{
	/// <summary>
	/// Represents a color as 4 floats from 0 to 1.
	/// </summary>
	struct SUPERGOD_API FColor
	{
		union
		{
			struct { float red, green, blue, alpha; };
			float components[4];
		};

		/// <summary>
		/// Creates a new color with all of its components set to 0.
		/// </summary>
		FColor();

		/// <summary>
		/// Creates a new color with specified red, green, blue and alpha values.
		/// </summary>
		explicit FColor(const float& red, const float& green, const float& blue, const float& alpha);
	};
} }