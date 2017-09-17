#pragma once

#include "../Common/CommonDefines.h"
#include "MathConstants.h"
#include "SMath.h"
#include "Interfaces/ISupergodEquatable.h"
#include "Interfaces/ISizeComparable.h"
#include "Interfaces/ArithmeticInterfaces.h"

namespace SupergodEngine { namespace Math
{
	// TODO: Add the interfaces IClampable and ILerpable.
	/// <summary>
	/// Struct wraping angles into radians, degrees and revolutions. It also handles wraping the value in a valid range for angles.
	/// </summary>
	struct SUPERGOD_API Angle final : public ISupergodEquatable<Angle>, public ISizeComparable<Angle>, IScalarMultipliable<Angle>, IScalarDividable<Angle>, IAddable<Angle>, ISubtractable<Angle>
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
		inline float GetRadians() const { return _radians; }

		/// <summary>
		/// Sets the angle as radians from 0 to 2pi.
		/// </summary>
		inline float SetRadians(const float& value) { return _radians = WrapRadians(value); }

		/// <summary>
		/// Gets the angle as radians from -pi to pi.
		/// </summary>
		inline float GetNegativeRadians() const { return GetRadians() - Constants::PI; }

		/// <summary>
		/// Sets the angle as radians from -pi to pi.
		/// </summary>
		inline float SetNegativeRadians(const float& value) { return SetRadians(value + Constants::PI); }

		/// <summary>
		/// Gets the angle as degrees from 0 to 360.
		/// </summary>
		inline float GetDegrees() const { return GetRadians() * RAD_TO_DEG; }

		/// <summary>
		/// Sets the angle as degrees from 0 to 360.
		/// </summary>
		inline float SetDegrees(const float& value) { return SetRadians(value * DEG_TO_RAD); }

		/// <summary>
		/// Gets the angle as degrees from -180 to 180.
		/// </summary>
		inline float GetNegativeDegrees() const { return GetDegrees() - 180; }

		/// <summary>
		/// Sets the angle as degrees from -180 to 180.
		/// </summary>
		inline float SetNegativeDegrees(const float& value) { return SetDegrees(value + 180); }

		/// <summary>
		/// Gets the angle as revolutions from 0 to 1.
		/// </summary>
		inline float GetRevolutions() const { return GetRadians() * RAD_TO_REV; }

		/// <summary>
		/// Sets the angle as revolutions from 0 to 1.
		/// </summary>
		inline float SetRevolutions(const float& value) { return SetRadians(value * REV_TO_RAD); }

		/// <summary>
		/// Gets the angle as revolutions from -0.5 to 0.5.
		/// </summary>
		inline float GetNegativeRevolutions() const { return GetRevolutions() - .5f; }

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

		/// <summary>
		/// Gets the angle as radians.
		/// </summary>
		inline operator float() const
		{
			return GetRadians();
		}

		#pragma region Comparison methods.
		/// <summary>
		/// Are the radians of this the same as the radians of other?
		/// </summary>
		bool Equals(const Angle& other) const override;

		/// <summary>
		/// Is the distance between the radians of this and the radians of other smaller or equal to threshold?
		/// </summary>
		bool CloseEnough(const Angle& other, const float& threshold = Constants::CLOSE_ENOUGH_DEFAULT_THRESHOLD) const override;
		
		/// <summary>
		/// Are the radians of this bigger than the radians of other?
		/// </summary>
		bool BiggerThan(const Angle& other) const override;

		/// <summary>
		/// Are the radians of this smaller than the radians of other?
		/// </summary>
		bool SmallerThan(const Angle& other) const override;
		#pragma endregion
		
		#pragma region Scaling (scalar multiplication and division).
		/// <summary>
		/// Multiplies the radians of this by scalar.
		/// </summary>
		Angle Multiply(const float& scalar) const override;

		/// <summary>
		/// Multiplies scalar by the radians of angle.
		/// </summary>
		friend Angle operator*(const float& scalar, const Angle& angle)
		{
			return angle.Multiply(scalar);
		}

		/// <summary>
		/// Divides the radians of this by scalar.
		/// </summary>
		Angle Divide(const float& scalar) const override;
		#pragma endregion

		#pragma region Addition and subtraction.
		/// <summary>
		/// Adds the radians of this and the radians of other.
		/// </summary>
		Angle Add(const Angle& other) const override;

		/// <summary>
		/// Subtracts the radians of other from the radians of this.
		/// </summary>
		Angle Subtract(const Angle& other) const override;
		#pragma endregion

	private:
		float _radians;
	};
} }