#include "FMath.h"

namespace SupergodEngine { namespace Math
{
	float FMath::Abs(float value)
	{
		return value > 0 ? value : -value;
	}
} }