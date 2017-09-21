#include "FColor.h"
#include "BColor.h"
#include "../SMath.h"
#include "../Vectors/Vector4D.h"

namespace SupergodCore { namespace Math
{
	FColor::FColor()
		: red(0), green(0), blue(0), alpha(0)
	{
	}

	FColor::FColor(float red, float green, float blue, float alpha)
		: red(red), green(green), blue(blue), alpha(alpha)
	{
	}

	FColor::operator Vector4D() const
	{
		return Vector4D(red, green, blue, alpha);
	}

	FColor::operator BColor() const
	{
		#define FLOAT_TO_BYTE(source) (byte)(source * 255)
		FColor source = Normalized();
		return BColor(FLOAT_TO_BYTE(source.red), FLOAT_TO_BYTE(source.green), FLOAT_TO_BYTE(source.blue), FLOAT_TO_BYTE(source.alpha));
		#undef FLOAT_TO_BYTE
	}
	
	bool FColor::Equals(const FColor& other) const
	{
		return red == other.red && green == other.green && blue == other.blue && alpha == other.alpha;
	}

	bool FColor::CloseEnough(const FColor& other, float threshold) const
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

	FColor FColor::Multiply(const FColor& other) const
	{
		return FColor(red * other.red, green * other.green, blue * other.blue, alpha * other.alpha);
	}

	FColor FColor::Multiply(float scalar) const
	{
		return FColor(red * scalar, green * scalar, blue * scalar, alpha * scalar);
	}

	FColor FColor::Divide(const FColor& other) const
	{
		return FColor(red / other.red, green / other.green, blue / other.blue, alpha / other.alpha);
	}

	FColor FColor::Divide(float scalar) const
	{
		return FColor(red / scalar, green / scalar, blue / scalar, alpha / scalar);
	}

	FColor FColor::Inverted() const
	{
		return FColor(1 - red, 1 - blue, 1 - green, alpha);
	}

	FColor FColor::Clamp(const FColor& min, const FColor& max) const
	{
		return FColor(SMath::Clamp(red, min.red, max.red), SMath::Clamp(green, min.green, max.green), SMath::Clamp(blue, min.blue, max.blue), SMath::Clamp(alpha, min.alpha, max.alpha));
	}
} }