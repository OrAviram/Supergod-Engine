#pragma once

namespace SupergodEngine { namespace Math
{
	/// <summary>
	/// A collection of common mathematical constants.
	/// </summary>
	namespace Constants
	{
		constexpr float CLOSE_ENOUGH_DEFAULT_THRESHOLD = 0.0001f;

		constexpr float PI = 3.14159265359f;
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
		
		constexpr float DEG_TO_RAD = PI / 180;
		constexpr float RAD_TO_DEG = 180 / PI;
	}
} }