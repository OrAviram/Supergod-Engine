#include "Angle.h"

namespace SupergodCore { namespace Math
{
	Angle::Angle()
	{
		SetRadians(0);
	}

	Angle::Angle(float angle, const Measurement& measurement)
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

	bool Angle::Equals(Angle other) const
	{
		return GetRadians() == other.GetRadians();
	}

	bool Angle::CloseEnough(Angle other, float threshold) const
	{
		return SMath::CloseEnough(GetRadians(), other.GetRadians(), threshold);
	}

	bool Angle::BiggerThan(Angle other) const
	{
		return GetRadians() > other.GetRadians();
	}

	bool Angle::SmallerThan(Angle other) const
	{
		return GetRadians() < other.GetRadians();
	}

	Angle Angle::Multiply(float scalar) const
	{
		return GetRadians() * scalar;
	}
	
	Angle Angle::Divide(float scalar) const
	{
		return GetRadians() / scalar;
	}

	Angle Angle::Add(Angle other) const
	{
		return GetRadians() + other.GetRadians();
	}

	Angle Angle::Subtract(Angle other) const
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

	Angle Angle::Clamp(Angle min, Angle max) const
	{
		return SMath::Clamp(GetRadians(), min, max);
	}
} }