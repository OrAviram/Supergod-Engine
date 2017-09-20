#pragma once

#include "Common/CommonDefines.h"
#include "IColor.h"

namespace SupergodEngine { namespace Math
{
	struct FColor;

	/// <summary>
	/// Represents a 32 bit color with 4 bytes from 0 to the maximum value of a byte.
	/// </summary>
	struct SUPERGOD_API BColor final : public IColor<BColor>
	{
		#pragma region Presets for common colors.
		
        #pragma region Simple RGB and clear.
        /// <summary>Clear color. RGBA is (0, 0, 0, 0).</summary>
		DEFINE_STRUCT_VALUE_PRESET(BColor, Clear, (0, 0, 0, 0))

        /// <summary>Red color. RGBA is (1, 0, 0, 1).</summary>
		DEFINE_STRUCT_VALUE_PRESET(BColor, Red, (255, 0, 0, 255))

        /// <summary>Green color. RGBA is (0, 255, 0, 1).</summary>
		DEFINE_STRUCT_VALUE_PRESET(BColor, Green, (0, 255, 0, 255))

        /// <summary>Blue color. RGBA is (0, 0, 255, 1).</summary>
		DEFINE_STRUCT_VALUE_PRESET(BColor, Blue, (0, 0, 255, 255))
		#pragma endregion

        #pragma region Basic combinations (yellow, pink, cyan).
        /// <summary>Blue color. RGBA is (255, 255, 0, 255).</summary>
		DEFINE_STRUCT_VALUE_PRESET(BColor, Yellow, (255, 255, 0, 255))

        /// <summary>Pink color. RGBA is (255, 0, 255, 255).</summary>
		DEFINE_STRUCT_VALUE_PRESET(BColor, Pink, (255, 0, 255, 255))

        /// <summary>Cyan color. RGBA is (0, 255, 255, 255).</summary>
		DEFINE_STRUCT_VALUE_PRESET(BColor, Cyan, (0, 255, 255, 255))
		#pragma endregion

        #pragma region Complex combinations (purple, teal, orange).
        /// <summary>Purple color. RGBA is (77, 0, 255, 255).</summary>
		DEFINE_STRUCT_VALUE_PRESET(BColor, Purple, (77, 0, 255, 255))

        /// <summary>Teal color. RGBA is (0, 255, 153, 255).</summary>
		DEFINE_STRUCT_VALUE_PRESET(BColor, Teal, (0, 255, 153, 255))

        /// <summary>Orange color. RGBA is (255, 51, 0, 255).</summary>
		DEFINE_STRUCT_VALUE_PRESET(BColor, Orange, (255, 51, 0, 255))
		#pragma endregion

        #pragma region No hue.
        /// <summary>White color. RGBA is (255, 255, 255, 255).</summary>
		DEFINE_STRUCT_VALUE_PRESET(BColor, White, (255, 255, 255, 255))

        /// <summary>Black color. RGBA is (0, 0, 0, 255).</summary>
		DEFINE_STRUCT_VALUE_PRESET(BColor, Black, (0, 0, 0, 255))
		
        /// <summary>Very dark gray color. RGBA is (5, 5, 5, 255).</summary>
		DEFINE_STRUCT_VALUE_PRESET(BColor, VeryDarkGray, (5, 5, 5, 255))

        /// <summary>Dark gray color. RGBA is (26, 26, 26, 255).</summary>
		DEFINE_STRUCT_VALUE_PRESET(BColor, DarkGray, (26, 26, 26, 255))

        /// <summary>Medium gray color. RGBA is (128, 128, 128, 255).</summary>
		DEFINE_STRUCT_VALUE_PRESET(BColor, Gray, (128, 128, 128, 255))

        /// <summary>Light gray color. RGBA is (191, 191, 191, 255).</summary>
        DEFINE_STRUCT_VALUE_PRESET(BColor, LightGray, (191, 191, 191, 255))
        #pragma endregion

		#pragma endregion

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
	
		#pragma region Comparison methods.
		/// <summary>
		/// Are all of the components of this equal to other?
		/// </summary>
		bool Equals(const BColor& other) const override;

		/// <summary>
		/// Is the distance between each component of this and its corresponding component in other smaller or equal to threshold?
		/// </summary>
		bool CloseEnough(const BColor& other, const float& threshold = Constants::CLOSE_ENOUGH_DEFAULT_THRESHOLD) const override;
		#pragma endregion
	};
} }