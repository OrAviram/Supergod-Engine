#include "FColor.h"
#include "../SMath.h"
#include "../Vectors/Vector4D.h"

namespace SupergodEngine { namespace Math
{
	FColor::FColor()
		: red(0), green(0), blue(0), alpha(0)
	{
	}

	FColor::FColor(const float& red, const float& green, const float& blue, const float& alpha)
		: red(red), green(green), blue(blue), alpha(alpha)
	{
	}

	FColor::operator Vector4D() const
	{
		return Vector4D(red, green, blue, alpha);
	}

	bool FColor::Equals(const FColor& other) const
	{
		return red == other.red && green == other.green && blue == other.blue && alpha == other.alpha;
	}

	bool FColor::CloseEnough(const FColor& other, const float& threshold) const
	{
		return SMath::CloseEnough(red, other.red, threshold) && SMath::CloseEnough(green, other.green, threshold) && SMath::CloseEnough(blue, other.blue, threshold) && SMath::CloseEnough(alpha, other.alpha, threshold);
	}

	FColor FColor::Add(const FColor& other) const
	{
		return FColor(red + other.red, green + other.green, blue + other.blue, alpha + other.alpha);
	}

	FColor FColor::Subtract(const FColor& other) const
	{
		return FColor(red - other.red, green - other.green, blue - other.blue, alpha - other.alpha);
	}

	FColor FColor::Multiply(const FColor& other) const
	{
		return FColor(red * other.red, green * other.green, blue * other.blue, alpha * other.alpha);
	}

	FColor FColor::Multiply(const float& scalar) const
	{
		return FColor(red * scalar, green * scalar, blue * scalar, alpha * scalar);
	}

	FColor FColor::Divide(const FColor& other) const
	{
		return FColor(red / other.red, green / other.green, blue / other.blue, alpha / other.alpha);
	}

	FColor FColor::Divide(const float& scalar) const
	{
		return FColor(red / scalar, green / scalar, blue / scalar, alpha / scalar);
	}

	FColor FColor::Inverted() const
	{
		return FColor(1 - red, 1 - blue, 1 - green, alpha);
	}
} }