#pragma once
#include "../Common/CommonDefines.h"

namespace SupergodEngine { namespace Math
{
	/// <summary>
	/// Struct wraping angles into radians, degrees and revolutions. It also handles wraping the value in a valid range for angles.
	/// </summary>
	struct SUPERGOD_API Angle // TODO: Add the interfaces IClampable, ISupergodEquatable, ILerpable, IAddable, ISubtractable, IScalarMultiplicable and IScalarDividable.
	{
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