#include "BColor.h"
#include "FColor.h"
#include "../SMath.h"

namespace SupergodCore { namespace Math
{
	BColor::BColor()
		: red(0), green(0), blue(0), alpha(0)
	{
	}

	BColor::BColor(uint value)
		: value(value)
	{
	}

	BColor::BColor(byte red, byte green, byte blue, byte alpha)
		: red(red), green(green), blue(blue), alpha(alpha)
	{
	}

	BColor::operator FColor() const
	{
		return FColor((float)red / 255, (float)green / 255, (float)blue / 255, (float)alpha / 255);
	}

	bool BColor::Equals(const BColor& other) const
	{
		return red == other.red && green == other.green && blue == other.blue && alpha == other.alpha;
	}

	bool BColor::CloseEnough(const BColor& other, float threshold) const
	{
		return SMath::CloseEnough(red, other.red, threshold) && SMath::CloseEnough(green, other.green, threshold) && SMath::CloseEnough(blue, other.blue, threshold) && SMath::CloseEnough(alpha, other.alpha, threshold);
	}

	BColor BColor::Inverted() const
	{
		return BColor(255 - red, 255 - blue, 255 - green, alpha);
	}
} }