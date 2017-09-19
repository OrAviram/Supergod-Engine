#include "FColor.h"

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
} }