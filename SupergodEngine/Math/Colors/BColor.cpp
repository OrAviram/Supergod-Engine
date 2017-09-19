#include "BColor.h"

namespace SupergodEngine { namespace Math
{
	BColor::BColor()
		: red(0), green(0), blue(0), alpha(0)
	{
	}

	BColor::BColor(const byte& red, const byte& green, const byte& blue, const byte& alpha)
		: red(red), green(green), blue(blue), alpha(alpha)
	{
	}
} }