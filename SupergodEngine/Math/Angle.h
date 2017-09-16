#pragma once

#include "../Common/CommonDefines.h"
#include "MathConstants.h"

namespace SupergodEngine { namespace Math
{
	/// <summary>
	/// Struct wraping angles into radians, degrees and revolutions. It also handles wraping the value in a valid range for angles.
	/// </summary>
	struct SUPERGOD_API Angle // TODO: Add the interfaces IClampable, ISupergodEquatable, ILerpable, IAddable, ISubtractable, IScalarMultiplicable and IScalarDividable.
	{
		#pragma region Angle conversions constants.
		/// <summary>Multiply a radian by this to get the equivelant angle in degrees.</summary>
		static constexpr float RAD_TO_DEG = 360 / Constants::TAU;
		
		/// <summary>Multiply a radian by this to get the equivelant angle in revolutions.</summary>
		static constexpr float RAD_TO_REV = 1 / Constants::TAU;

		/// <summary>Multiply degrees by this to get the equivelant angle in radians.</summary>
		static constexpr float DEG_TO_RAD = Constants::TAU / 360;

		/// <summary>Multiply degrees by this to get the equivelant angle in revolutions.</summary>
		static constexpr float DEG_TO_REV = 1 / 360.f;

		/// <summary>Multiply revolutions by this to get the equivelant angle in degrees.</summary>
		static constexpr float REV_TO_DEG = 360;

		/// <summary>Multiply revolutions by this to get the equivelant angle in radians.</summary>
		static constexpr float REV_TO_RAD = Constants::TAU;
		#pragma endregion

		/// <summary>
		/// Types of angle measurments.
		/// </summary>
		enum class Measurement
		{
			/// <summary>
			/// Angle measurment of degrees (full circle = 360).
			/// </summary>
			Degrees = 1,

			/// <summary>
			/// Angle measurment of radians (full circle = 2pi).
			/// </summary>
			Radians = 2,

			/// <summary>
			/// Angle measurment of revolutions (full circle = 1).
			/// </summary>
			Revolutions = 3,
		};

	private:
		float _radians;
	};
} }