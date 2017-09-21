#include "SMath.h"
#include "MathConstants.h"
#include <cmath>

namespace SupergodCore { namespace Math
{
	bool SMath::CloseEnough(float a, float b, float threshold)
	{
		return SMath::Abs(a - b) <= threshold;
	}
	
	float SMath::Clamp(float value, float min, float max)
	{
		if (value < min)
			return min;

		if (value > max)
			return max;

		return value;
	}

	float SMath::Abs(float value)
	{
		return value > 0 ? value : -value;
	}

	int SMath::Sign(float value)
	{
		return value >= 0 ? 1 : -1;
	}

	uint SMath::Factorial(uint n)
	{
		if (n == 0 || n == 1)
			return 1;

		return Factorial(n - 1) * n;
	}

	float SMath::Average(const std::vector<float>& numbers)
	{
		float sum = 0;
		for (size_t i = 0; i < numbers.size(); i++)
			sum += numbers[i];

		return sum / numbers.size();
	}

	bool SMath::IsNaN(float value)
	{
		return value != value;
	}

	// TODO: Add custom floor and ceil functionality.
	#pragma region Rounding functions.
	int SMath::Floor(float value)
	{
		return (int)std::floor(value);
	}

	int SMath::Ceil(float value)
	{
		return (int)std::ceil(value);
	}

	int SMath::Round(float value)
	{
		return value < .5f ? Floor(value) : Ceil(value);
	}

	float SMath::Round(float value, int decimals)
	{
		float tenToDecimals = Pow(10, (float)decimals);
		return Round(value * tenToDecimals) / tenToDecimals;
	}
	#pragma endregion

	#pragma region Wrap functions.
	float SMath::Wrap(float value, float min, float max)
	{
		float minToMaxRange = Abs(max - min);
		if (value > max)
		{
			while (value > max)
				value -= minToMaxRange;
		}
		else
		{
			while (value < min)
				value += minToMaxRange;
		}
		return value;
	}

	float SMath::Wrap(float value, float length)
	{
		return Wrap(value, 0, length);
	}
	#pragma endregion

	// TODO: Make custom implementation for Pow and Log.
	#pragma region Powers, roots, exponentionals and logarithms.
	float SMath::Root(float x, float n)
	{
		return Pow(x, 1 / n);
	}

	float SMath::Sqrt(float x)
	{
		return Root(x, 2);
	}

	float SMath::Exp(float x)
	{
		return Pow(Constants::E, x);
	}

	float SMath::Pow(float base, float exponent)
	{
		return std::pow(base, exponent);
	}

	float SMath::Squared(float value)
	{
		return value * value;
	}

	float SMath::Cubed(float value)
	{
		return Squared(value) * value;
	}

	float SMath::Log(float x, float base)
	{
		return std::log10(x) / std::log10(base);
	}

	float SMath::Log10(float x)
	{
		return Log(x, 10);
	}

	float SMath::Ln(float x)
	{
		return Log(x, Constants::E);
	}
	#pragma endregion

	#pragma region Min/Max.
	const float& SMath::Max(const float& a, const float& b)
	{
		return a > b ? a : b;
	}

	float& SMath::Max(float& a, float& b)
	{
		return a > b ? a : b;
	}

	float SMath::Max(const std::vector<float>& values)
	{
		float biggest = values[0];
		for (size_t i = 0; i < values.size(); i++)
		{
			if (values[i] > biggest)
				biggest = values[i];
		}
		return biggest;
	}

	const float& SMath::Min(const float& a, const float& b)
	{
		return a < b ? a : b;
	}

	float& SMath::Min(float& a, float& b)
	{
		return a < b ? a : b;
	}

	float SMath::Min(const std::vector<float>& values)
	{
		float smallest = values[0];
		for (size_t i = 0; i < values.size(); i++)
		{
			if (values[i] < smallest)
				smallest = values[i];
		}
		return smallest;
	}
	#pragma endregion

	// TODO: Make custom implementation for Sin and the inverse functions.
	#pragma region Trig functions.
	float SMath::Sin(float theta)
	{
		return std::sin(theta);
	}

	float SMath::Cos(float theta)
	{
		return Sin(Constants::PI / 2 - theta);
	}

	float SMath::Tan(float theta)
	{
		return Sin(theta) / cos(theta);
	}

	float SMath::Asin(float sin)
	{
		return std::asin(sin);
	}

	float SMath::Acos(float cos)
	{
		return std::acos(cos);
	}

	float SMath::Atan(float tan)
	{
		return std::atan(tan);
	}

	float SMath::Atan2(float y, float x)
	{
		return std::atan2(y, x);
	}
	#pragma endregion
} }