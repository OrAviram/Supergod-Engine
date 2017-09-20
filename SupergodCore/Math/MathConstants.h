#pragma once

namespace SupergodCore { namespace Math
{
	/// <summary>
	/// A collection of common mathematical constants.
	/// </summary>
	namespace Constants
	{
		/// <summary>
		/// The default threshold to CloseEnough functions. It's very small and good to fix floating point errors.
		/// </summary>
		constexpr float CLOSE_ENOUGH_DEFAULT_THRESHOLD = 0.0001f;

		/// <summary>
		/// If the ratio of two lengths to each other is the same as the ratio of their sum to the bigger length, their ratio is the golden ratio.
		/// </summary>
		constexpr float GOLDEN_RATIO = 1.61803398875f;

		/// <summary>
		/// The ratio of a circle's circumference to its diameter.
		/// </summary>
		constexpr float PI = 3.14159265359f;

		/// <summary>
		/// The ratio of a circle's circumference to its radius.
		/// </summary>
		constexpr float TAU = 2 * PI;

		/// <summary>
		/// The base for the natural logarithm.
		/// </summary>
		constexpr float E = 2.71828182846f;

		constexpr float SQRT2 = 1.41421356237f;
		constexpr float SQRT2_OVER2 = SQRT2 / 2;
		constexpr float SQRT2_OVER3 = SQRT2 / 3;
		constexpr float SQRT2_OVER5 = SQRT2 / 5;
		constexpr float SQRT2_OVER10 = SQRT2 / 10;

		constexpr float SQRT3 = 1.73205080757f;
		constexpr float SQRT3_OVER2 = SQRT3 / 2;
		constexpr float SQRT3_OVER3 = SQRT3 / 3;
		constexpr float SQRT3_OVER5 = SQRT3 / 5;
		constexpr float SQRT3_OVER10 = SQRT3 / 10;
		
		constexpr float SQRT5 = 2.2360679775f;
		constexpr float SQRT5_OVER2 = SQRT5 / 2;
		constexpr float SQRT5_OVER3 = SQRT5 / 3;
		constexpr float SQRT5_OVER5 = SQRT5 / 5;
		constexpr float SQRT5_OVER10 = SQRT5 / 10;
	}
} }