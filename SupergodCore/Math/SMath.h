#pragma once

#include <vector>
#include "Common/CommonDefines.h"
#include "MathConstants.h"

namespace SupergodCore { namespace Math
{
	/// <summary>
	/// Collection of common Supergod math functions.
	/// </summary>
	namespace SMath
	{
		/// <summary>
		/// Clamps target so it's never smaller than min and never bigger than max.
		/// </summary>
		template<class T>
		inline T Clamp(const T& target, const T& min, const T& max)
		{
			return target.Clamp(min, max);
		}

		/// <summary>
		/// Gets the absolute value of target..
		/// </summary>
		template<class T>
		T Abs(const T& target)
		{
			return target.Abs();
		}

		/// <summary>
		/// Checks if the distance between a and b is threshold.
		/// </summary>
		SUPERGOD_API_FUNC bool CloseEnough(float a, float b, float threshold = Constants::CLOSE_ENOUGH_DEFAULT_THRESHOLD);

		/// <summary>
		/// Clamps value so it's never smaller than min and never bigger than max.
		/// </summary>
		SUPERGOD_API_FUNC float Clamp(float value, float min, float max);

		/// <summary>
		/// Gets the absolute value of value.
		/// </summary>
		SUPERGOD_API_FUNC float Abs(float value);
	
		/// <summary>
		/// Gets the sign (+ (1) or - (-1)) of value.
		/// </summary>
		/// <param name="value">The value to get the sign of.</param>
		SUPERGOD_API_FUNC int Sign(float value);

		/// <summary>
		/// Gets the factorial of n.
		/// </summary>
		SUPERGOD_API_FUNC uint Factorial(uint n);

		/// <summary>
		/// Gets the avrage of a list of numbers.
		/// </summary>
		/// <param name="numbers">The list of numbers to get the avrage of.</param>
		SUPERGOD_API_FUNC float Average(const std::vector<float>& numbers);

		/// <summary>
		/// Does value NOT exist?
		/// </summary>
		SUPERGOD_API_FUNC bool IsNaN(float value);
		
		#pragma region Rounding functions.
		/// <summary>
		/// Gets the smallest integer of value.
		/// </summary>
		SUPERGOD_API_FUNC int Floor(float value);

		/// <summary>
		/// Gets the biggest integer of value.
		/// </summary>
		SUPERGOD_API_FUNC int Ceil(float value);

		/// <summary>
		/// Rounds value to 0 numbers after the decimal point.
		/// </summary>
		/// <param name="value">The value to round.</param>
		SUPERGOD_API_FUNC int Round(float value);

		/// <summary>
		/// Rounds value to decimals numbers after the decimal point.
		/// </summary>
		/// <param name="value">The value to round.</param>
		/// <param name="decimals">The amount of decimals the number should be rounded to.</param>
		SUPERGOD_API_FUNC float Round(float value, int decimals);
		#pragma endregion

		#pragma region Wrap functions.
		/// <summary>
		/// Wraps value so when it gets smaller than min by n it wraps back to max-n again and if it gets bigger than max by n it wraps back to min+n.
		/// </summary>
		/// <param name="value">The value to wrap.</param>
		/// <param name="min">The minimum value in the range.</param>
		/// <param name="max">The maximum value in the range.</param>
		/// <returns>Value wrapped between min and max.</returns>
		SUPERGOD_API_FUNC float Wrap(float value, float min, float max);

		/// <summary>
		/// Wraps value between 0 to length. See <seealso cref="Wrap(float, float, float)"/>.
		/// </summary>
		SUPERGOD_API_FUNC float Wrap(float value, float length);
		#pragma endregion

		#pragma region Powers, roots, exponentials and logarithms.
		/// <summary>
		/// Gets the n'th root of x.
		/// </summary>
		SUPERGOD_API_FUNC float Root(float x, float n);

		/// <summary>
		/// Gets the square root of x.
		/// </summary>
		SUPERGOD_API_FUNC float Sqrt(float x);

		/// <summary>
		/// Returns e raised to the power of x.
		/// </summary>
		SUPERGOD_API_FUNC float Exp(float x);

		/// <summary>
		/// Returns x to the power of y.
		/// </summary>
		SUPERGOD_API_FUNC float Pow(float base, float exponent);

		/// <summary>
		/// Returns value to the power of 2 (value times value).
		/// </summary>
		SUPERGOD_API_FUNC float Squared(float value);

		/// <summary>
		/// Returns value to the power of 3 (value times value times value).
		/// </summary>
		SUPERGOD_API_FUNC float Cubed(float value);

		/// <summary>
		/// base to the power of what equals x?
		/// </summary>
		/// <param name="x">Number to try to get to.</param>
		/// <param name="base">Base of the logarithm.</param>
		SUPERGOD_API_FUNC float Log(float x, float base);

		/// <summary>
		/// 10 to the power of what equals x?
		/// </summary>
		SUPERGOD_API_FUNC float Log10(float x);

		/// <summary>
		/// e to the power of what equals x?
		/// </summary>
		SUPERGOD_API_FUNC float Ln(float x);
		#pragma endregion

		#pragma region Min/Max.
		/// <summary>
		/// Gets the bigger number of the two.
		/// </summary>
		SUPERGOD_API_FUNC const float& Max(const float& a, const float& b);

		/// <summary>
		/// Gets the bigger number of the two.
		/// </summary>
		SUPERGOD_API_FUNC float& Max(float& a, float& b);

		/// <summary>
		/// Gets the biggest number in the values array.
		/// </summary>
		SUPERGOD_API_FUNC float Max(const std::vector<float>& values);

		/// <summary>
		/// Gets the smallest number between the two.
		/// </summary>
		SUPERGOD_API_FUNC const float& Min(const float& a, const float& b);

		/// <summary>
		/// Gets the smallest number between the two.
		/// </summary>
		SUPERGOD_API_FUNC float& Min(float& a, float& b);

		/// <summary>
		/// Gets the smallest number in the values array.
		/// </summary>
		SUPERGOD_API_FUNC float Min(const std::vector<float>& values);
		#pragma endregion

		// TODO: Move those to the Angle struct OR make them take/return an Angle.
		#pragma region Trig functions
		/// <summary>
		/// Gets the sine of angle theta (in radians).
		/// </summary>
		SUPERGOD_API_FUNC float Sin(float theta);

		/// <summary>
		/// Gets the cosine of angle theta (in radians).
		/// </summary>
		SUPERGOD_API_FUNC float Cos(float theta);

		/// <summary>
		/// Gets the tangent of angle theta (in radians).
		/// </summary>
		SUPERGOD_API_FUNC float Tan(float theta);

		/// <summary>
		/// Gets the angle (in radians) whos sine is sin.
		/// </summary>
		SUPERGOD_API_FUNC float Asin(float sin);

		/// <summary>
		/// Gets the angle (in radians) whos cosine is cos.
		/// </summary>
		SUPERGOD_API_FUNC float Acos(float cos);

		/// <summary>
		/// Gets the angle (in radians) whos tangent is tan.
		/// </summary>
		SUPERGOD_API_FUNC float Atan(float tan);

		/// <summary>
		/// Gets the angle (in radians) whos tangent is y/x.
		/// </summary>
		SUPERGOD_API_FUNC float Atan2(float y, float x);
		#pragma endregion
	}
} }