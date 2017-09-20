#include "FColor.h"
#include "../SMath.h"

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

	FColor FColor::Inverted() const
	{
		return FColor(1 - red, 1 - blue, 1 - green, alpha);
	}
} }