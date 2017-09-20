#pragma once

#include "Common/CommonDefines.h"
#include "IColor.h"
#include "../Interfaces/ArithmeticInterfaces.h"
#include "../Interfaces/ILerpable.h"

namespace SupergodEngine { namespace Math
{
	struct Vector4D;

	/// <summary>
	/// Represents a color as 4 floats from 0 to 1.
	/// </summary>
	struct SUPERGOD_API FColor final : public IColor<FColor>, ILerpable<FColor>, public ISubtractable<FColor>, public IDividable<FColor>, IScalarDividable<FColor>, IMultipliable<FColor>
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

		/// <summary>
		/// Creates a new Vector4D with its x y z w components set to red green blue alpha (in that order).
		/// </summary>
		operator Vector4D() const;

		// TODO: Add conversion to BColor when clamping and normalizing exists.

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
	};
} }