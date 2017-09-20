#pragma once

#include "Common/CommonDefines.h"
#include "IColor.h"
#include "../Interfaces/ArithmeticInterfaces.h"
#include "../Interfaces/ILerpable.h"
#include "../Interfaces/IClampable.h"

namespace SupergodEngine { namespace Math
{
	struct Vector4D;
	struct BColor;

	/// <summary>
	/// Represents a color as 4 floats from 0 to 1.
	/// </summary>
	struct SUPERGOD_API FColor final : public IColor<FColor>, public ILerpable<FColor>, public IClampable<FColor>, public ISubtractable<FColor>, public IDividable<FColor>, public IScalarDividable<FColor>, public IMultipliable<FColor>
	{
		#pragma region Presets for common colors.
		
        #pragma region Simple RGB and clear.
        /// <summary>Clear color. RGBA is (0, 0, 0, 0).</summary>
		DEFINE_STRUCT_VALUE_PRESET(FColor, Clear, (0, 0, 0, 0))

        /// <summary>Red color. RGBA is (1, 0, 0, 1).</summary>
		DEFINE_STRUCT_VALUE_PRESET(FColor, Red, (1, 0, 0, 1))

        /// <summary>Green color. RGBA is (0, 1, 0, 1).</summary>
		DEFINE_STRUCT_VALUE_PRESET(FColor, Green, (0, 1, 0, 1))

        /// <summary>Blue color. RGBA is (0, 0, 1, 1).</summary>
		DEFINE_STRUCT_VALUE_PRESET(FColor, Blue, (0, 0, 1, 1))
		#pragma endregion

        #pragma region Basic combinations (yellow, pink, cyan).
        /// <summary>Blue color. RGBA is (1, 1, 0, 1).</summary>
		DEFINE_STRUCT_VALUE_PRESET(FColor, Yellow, (1, 1, 0, 1))

        /// <summary>Pink color. RGBA is (1, 0, 1, 1).</summary>
		DEFINE_STRUCT_VALUE_PRESET(FColor, Pink, (1, 0, 1, 1))

        /// <summary>Cyan color. RGBA is (0, 1, 1, 1).</summary>
		DEFINE_STRUCT_VALUE_PRESET(FColor, Cyan, (0, 1, 1, 1))
		#pragma endregion

        #pragma region Complex combinations (purple, teal and orange).
        /// <summary>Purple color. RGBA is (0.3, 0, 1, 1).</summary>
		DEFINE_STRUCT_VALUE_PRESET(FColor, Purple, (.3f, 0, 1, 1))

        /// <summary>Teal color. RGBA is (0, 1, 0.6, 1).</summary>
		DEFINE_STRUCT_VALUE_PRESET(FColor, Teal, (0, 1, .6f, 1))

        /// <summary>Orange color. RGBA is (1, 0.2, 0, 1).</summary>
		DEFINE_STRUCT_VALUE_PRESET(FColor, Orange, (1, .2f, 0, 1))
		#pragma endregion

        #pragma region No hue.
        /// <summary>White color. RGBA is (1, 1, 1, 1).</summary>
		DEFINE_STRUCT_VALUE_PRESET(FColor, White, (1, 1, 1, 1))

        /// <summary>Black color. RGBA is (0, 0, 0, 1).</summary>
		DEFINE_STRUCT_VALUE_PRESET(FColor, Black, (0, 0, 0, 1))

        /// <summary>Very dark gray color. RGBA is (0.02, 0.02, 0.02, 1).</summary>
		DEFINE_STRUCT_VALUE_PRESET(FColor, VeryDarkGray, (.02f, .02f, .02f, 1))

        /// <summary>Dark gray color. RGBA is (0.1, 0.1, 0.1, 1).</summary>
		DEFINE_STRUCT_VALUE_PRESET(FColor, DarkGray, (.1f, .1f, .1f, 1))

        /// <summary>Medium gray color. RGBA is (0.5, 0.5, 0.5, 1).</summary>
		DEFINE_STRUCT_VALUE_PRESET(FColor, Gray, (.5f, .5f, .5f, 1))

        /// <summary>Light gray color. RGBA is (0.75, 0.75, 0.75, 1).</summary>
		DEFINE_STRUCT_VALUE_PRESET(FColor, LightGray, (.75f, .75f, .75f, 1))
        #pragma endregion

		#pragma endregion

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
		FColor(const float& red, const float& green, const float& blue, const float& alpha);

		/// <summary>
		/// Creates a new Vector4D with its x y z w components set to red green blue alpha (in that order).
		/// </summary>
		operator Vector4D() const;

		/// <summary>
		/// Creates a new color made of 4 bytes that is the same as this one. Some precision might be lost.
		/// </summary>
		explicit operator BColor() const;

		#pragma region Comparison methods.
		/// <summary>
		/// Are all of the components of this equal to other?
		/// </summary>
		bool Equals(const FColor& other) const override;

		/// <summary>
		/// Is the distance between each component of this and its corresponding component in other smaller or equal to threshold?
		/// </summary>
		bool CloseEnough(const FColor& other, const float& threshold = Constants::CLOSE_ENOUGH_DEFAULT_THRESHOLD) const override;
		#pragma endregion

		#pragma region Addition and subtraction.
		/// <summary>
		/// Adds every component of this to its corresponding component in other.
		/// </summary>
		FColor Add(const FColor& other) const override;

		/// <summary>
		/// Subtracts every component of other from its corresponding component in this.
		/// </summary>
		FColor Subtract(const FColor& other) const override;
		#pragma endregion

		#pragma region Multiplication and division.
		/// <summary>
		/// Multiplies every component of this by its corresponding component in other.
		/// </summary>
		FColor Multiply(const FColor& other) const override;

		/// <summary>
		/// Multiplies every component of this by scalar.
		/// </summary>
		FColor Multiply(const float& scalar) const override;

		/// <summary>
		/// Divides every component of this by its corresponding component in other.
		/// </summary>
		FColor Divide(const FColor& other) const override;

		/// <summary>
		/// Divides every component of this by scalar.
		/// </summary>
		FColor Divide(const float& scalar) const override;

		/// <summary>
		/// Multiplies every component of color by scalar.
		/// </summary>
		friend FColor operator*(const float& scalar, const FColor& color)
		{
			return color.Multiply(scalar);
		}
		#pragma endregion

		#pragma region Inversion.
		/// <summary>
		/// Invertes (subtracts every component OTHER THAN ALPGA from 1) this color. The alpha won't change.
		/// </summary>
		FColor Inverted() const override;
		#pragma endregion

		#pragma region Clamping and normalizing.
		/// <summary>
		/// Clamps every component of this between its corresponding component in min and its corresponding component in max.
		/// </summary>
		FColor Clamp(const FColor& min, const FColor& max) const override;

		/// <summary>
		/// Gets a version of this with all of its components clamped between 0 and 1. The returned value will always be a valid color.
		/// </summary>
		inline FColor Normalized() const
		{
			return Clamp(Black(), White());
		}

		/// <summary>
		/// Gets a version of color with all of its components clamped between 0 and 1. The returned value will always be a valid color.
		/// </summary>
		static inline FColor Normalize(const FColor& color)
		{
			return color.Normalized();
		}
		#pragma endregion
	};
} }