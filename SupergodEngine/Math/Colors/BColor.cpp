#include "BColor.h"
#include "FColor.h"

namespace SupergodEngine { namespace Math
{
	BColor::BColor()
		: red(0), green(0), blue(0), alpha(0)
	{
	}

	BColor::BColor(uint value)
		: value(value)
	{
	}

	BColor::BColor(const byte& red, const byte& green, const byte& blue, const byte& alpha)
		: red(red), green(green), blue(blue), alpha(alpha)
	{
	}

	BColor::operator FColor() const
	{
		return FColor((float)red / 255, (float)green / 255, (float)blue / 255, (float)alpha / 255);
	}
} }