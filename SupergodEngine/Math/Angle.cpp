#include "Angle.h"

namespace SupergodEngine { namespace Math
{
	Angle::Angle()
	{
		SetRadians(0);
	}

	Angle::Angle(const float& angle, const Measurement& measurement)
	{
		switch (measurement)
		{
		case Measurement::Degrees:
			SetDegrees(angle);
			break;

		case Measurement::Radians:
			SetRadians(angle);
			break;

		case Measurement::Revolutions:
			SetRevolutions(angle);
			break;
		}
	}
} }