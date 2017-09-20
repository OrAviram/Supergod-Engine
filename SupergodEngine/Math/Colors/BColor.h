#pragma once
#include "Common/CommonDefines.h"

namespace SupergodEngine { namespace Math
{
	struct FColor;

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
		/// Creates a new color as a 4-byte unsigned integer.
		/// </summary>
		BColor(uint value);

		/// <summary>
		/// Creates a new color with specified red, green, blue and alpha values.
		/// </summary>
		BColor(const byte& red, const byte& green, const byte& blue, const byte& alpha);

		/// <summary>
		/// Creates a new color made of 4 floats that is the same color as this.
		/// </summary>
		operator FColor() const;

		/// <summary>
		/// Gets the value of this as a 32-bit unsigned integer.
		/// </summary>
		inline operator uint()
		{
			return value;
		}

		/// <summary>
		/// Gets a reference to the component at the index of index.
		/// </summary>
		/// <param name="index">The index of the component (0, 1, 2 or 3).</param>
		inline byte& operator[](int index)
		{
			return components[index];
		}

		/// <summary>
		/// Gets a reference to the component at the index of index.
		/// </summary>
		/// <param name="index">The index of the component (0, 1, 2 or 3).</param>
		inline const byte& operator[](int index) const
		{
			return components[index];
		}
	};
} }