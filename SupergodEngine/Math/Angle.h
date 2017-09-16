#pragma once

#include "../Common/CommonDefines.h"
#include "MathConstants.h"
#include "SMath.h"

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

		#pragma region Wrapping for floats.
		/// <summary>
        /// Wraps value between 0 to 2pi using SMath::Wrap.
        /// </summary>
        static float WrapRadians(const float& value)
        {
            return SMath::Wrap(value, Constants::TAU);
        }

        /// <summary>
        /// Wraps value between 0 to 2pi using SMath::Wrap.
        /// </summary>
        static float WrapDegrees(const float& value)
        {
            return SMath::Wrap(value, 360);
        }

        /// <summary>
        /// Wraps value between 0 to 2pi using SMath::Wrap.
        /// </summary>
        static float WrapRevolutions(const float& value)
        {
            return SMath::Wrap(value, 1);
        }
		#pragma endregion

		#pragma region Getters/setters.
		/// <summary>
		/// Sets the angle as radians from 0 to 2pi.
		/// </summary>
		inline float GetRadians() { return _radians; }

		/// <summary>
		/// Sets the angle as radians from 0 to 2pi.
		/// </summary>
		inline float SetRadians(const float& value) { return _radians = WrapRadians(value); }

		/// <summary>
		/// Gets the angle as radians from -pi to pi.
		/// </summary>
		inline float GetNegativeRadians() { return GetRadians() - Constants::PI; }

		/// <summary>
		/// Sets the angle as radians from -pi to pi.
		/// </summary>
		inline float SetNegativeRadians(const float& value) { return SetRadians(value + Constants::PI); }

		/// <summary>
		/// Gets the angle as degrees from 0 to 360.
		/// </summary>
		inline float GetDegrees() { return GetRadians() * RAD_TO_DEG; }

		/// <summary>
		/// Sets the angle as degrees from 0 to 360.
		/// </summary>
		inline float SetDegrees(const float& value) { return SetRadians(value * DEG_TO_RAD); }

		/// <summary>
		/// Gets the angle as degrees from -180 to 180.
		/// </summary>
		inline float GetNegativeDegrees() { return GetDegrees() - 180; }

		/// <summary>
		/// Sets the angle as degrees from -180 to 180.
		/// </summary>
		inline float SetNegativeDegrees(const float& value) { return SetDegrees(value + 180); }

		/// <summary>
		/// Gets the angle as revolutions from 0 to 1.
		/// </summary>
		inline float GetRevolutions() { return GetRadians() * RAD_TO_REV; }

		/// <summary>
		/// Sets the angle as revolutions from 0 to 1.
		/// </summary>
		inline float SetRevolutions(const float& value) { return SetRadians(value * REV_TO_RAD); }

		/// <summary>
		/// Gets the angle as revolutions from -0.5 to 0.5.
		/// </summary>
		inline float GetNegativeRevolutions() { return GetRevolutions() - .5f; }

		/// <summary>
		/// Sets the angle as revolutions from -0.5 to 0.5.
		/// </summary>
		inline float SetNegativeRevolutions(const float& value) { return SetRevolutions(value + .5f); }
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

		/// <summary>
		/// Creates a new angle and sets it to 0.
		/// </summary>
		Angle();

		/// <summary>
		/// Creates a new angle with a value and wraps it to a valid range for angles.
		/// </summary>
		/// <param name="angle">The value of the angle.</param>
		/// <param name="measurement">The type of measurement to measure the angles with.</param>
		Angle(const float& angle, const Measurement& measurement = Measurement::Radians);

	private:
		float _radians;
	};
} }