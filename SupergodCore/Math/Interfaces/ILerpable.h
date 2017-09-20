#pragma once

#include "../SMath.h"
#include "ArithmeticInterfaces.h"

namespace SupergodCore { namespace Math
{
	template<class T>
	interface SUPERGOD_API ILerpable : public IAddable<T>, public IScalarMultipliable<T>
	{
		/// <summary>
		/// Linearly interpolates between this and target by alpha.
		/// </summary>
		/// <param name="target">The value to interpolate to.</param>
		/// <param name="alpha">The interpolation factor.</param>
		/// <param name="clampAlpha">Should alpha be clamped between 0 and 1?</param>
		inline T Lerp(const T& target, float alpha, bool clampAlpha = true) const
		{
			if (clampAlpha)
				alpha = SMath::Clamp(alpha, 0, 1);

			return ArithmeticOps::Add(*this * (1 - alpha), target * alpha);
		}
	};
	
	/// <summary>
	/// Namespace with functions managing linear interpolation.
	/// </summary>
	namespace Lerper
	{
		/// <summary>
		/// Linearly interpolates between source and target by alpha.
		/// </summary>
		/// <param name="source">The initial value.</param>
		/// <param name="target">The value to interpolate to.</param>
		/// <param name="alpha">The interpolation factor.</param>
		/// <param name="clampAlpha">Should alpha be clamped between 0 and 1?</param>
		template<class T>
		inline T Lerp(const ILerpable<T>& source, const T& target, float alpha, bool clampAlpha = true)
		{
			return source.Lerp(target, alpha, clampAlpha);
		}

		/// <summary>
		/// Linearly interpolates between source and target by alpha.
		/// </summary>
		/// <param name="source">The initial value.</param>
		/// <param name="target">The value to interpolate to.</param>
		/// <param name="alpha">The interpolation factor.</param>
		/// <param name="clampAlpha">Should alpha be clamped between 0 and 1?</param>
		inline float Lerp(const float& source, const float& target, float alpha, bool clampAlpha = true)
		{
			if (clampAlpha)
				alpha = SMath::Clamp(alpha, 0, 1);

			return source * (1 - alpha) + target * alpha;
		}
	}
} }