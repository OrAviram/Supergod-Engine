#pragma once

#include "Common/CommonDefines.h"
#include "IColor.h"

namespace SupergodEngine { namespace Math
{
	/// <summary>
	/// Represents a color as 4 floats from 0 to 1.
	/// </summary>
	struct SUPERGOD_API FColor final : public IColor<FColor>
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
		FColor(const float& red, const float& green, const float& blue, const float& alpha);

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

		#pragma region Inversion.
		/// <summary>
		/// Invertes (subtracts every component OTHER THAN ALPGA from 1) this color. The alpha won't change.
		/// </summary>
		FColor Inverted() const override;
		#pragma endregion
	};
} }