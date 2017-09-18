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

	bool Angle::Equals(const Angle& other) const
	{
		return GetRadians() == other.GetRadians();
	}

	bool Angle::CloseEnough(const Angle& other, const float& threshold) const
	{
		return SMath::CloseEnough(GetRadians(), other.GetRadians(), threshold);
	}

	bool Angle::BiggerThan(const Angle& other) const
	{
		return GetRadians() > other.GetRadians();
	}

	bool Angle::SmallerThan(const Angle& other) const
	{
		return GetRadians() < other.GetRadians();
	}

	Angle Angle::Multiply(const float& scalar) const
	{
		return GetRadians() * scalar;
	}
	
	Angle Angle::Divide(const float& scalar) const
	{
		return GetRadians() / scalar;
	}

	Angle Angle::Add(const Angle& other) const
	{
		return GetRadians() + other.GetRadians();
	}

	Angle Angle::Subtract(const Angle& other) const
	{
		return GetRadians() - other.GetRadians();
	}

	Angle Angle::Flipped() const
	{
		return GetRadians() - Constants::PI;
	}

	Angle Angle::Reflection() const
	{
		return Constants::TAU - GetRadians();
	}

	Angle Angle::Clamp(const Angle& min, const Angle& max) const
	{
		return SMath::Clamp(GetRadians(), min, max);
	}
} }