#include "SMath.h"
#include "FMath.h"

namespace SupergodEngine { namespace Math
{
	bool SMath::CloseEnough(float a, float b, float threshold)
	{
		return FMath::Abs(a - b) <= threshold;
	}
} }