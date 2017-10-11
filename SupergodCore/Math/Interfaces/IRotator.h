#pragma once

#include "Common/CommonDefines.h"
#include "../Interfaces/ISupergodEquatable.h"

// TODO: See what should be done with this file.

namespace SupergodCore { namespace Math
{
	struct Vector3D;
	struct Vector2D;

	/// <summary>
	/// The base interface for IRotator3D and IRotator2D. When implementing, use one of those two.
	/// </summary>
	template<class TRotator, class TVector>
	struct SUPERGOD_API_CLASS IRotatorBase : public ISupergodEquatable<TRotator>
	{
		//virtual TRotator CombineRotations(const TRotator& other) const = 0;
		//virtual TVector RotateVector(const TVector& vector) const = 0;
	};

	/// <summary>
	/// Interface for 3D rotators.
	/// </summary>
	template<class TRotator>
	struct SUPERGOD_API_CLASS IRotator3D : IRotatorBase<TRotator, Vector3D>
	{
		// TODO: Add those. Currently it just uses the C# syntax because I simply copied it from the C# version, but it will change.
		/*
		Quaternion Quaternion { get; set; }
        Matrix4x4 RotationMatrix { get; set; }
        AxisAngle AxisAngle { get; set; }
        EulerAngles EulerAngles { get; set; }
		*/
	};

	/// <summary>
	/// Interface for 2D rotators.
	/// </summary>
	template<class TRotator>
	struct SUPERGOD_API_CLASS IRotator2D : IRotatorBase<TRotator, Vector2D>
	{
		// TODO: Do what I did in IRotator3D except the conversion are between the Complex struct I will make, the Angle struct and Matrix3x3.
	};

	/// <summary>
	/// Namespace containing rotation methods.
	/// </summary>
	namespace Rotator
	{
		/// <summary>
		/// Rotates vector by rotator.
		/// </summary>
		/// <param name="vector">Vector to rotate.</param>
		/// <param name="rotator">Rotation to apply.</param>
		/// <returns>The rotated vector</returns>
		template<class TRotator, class TVector>
		inline TVector RotateVector(const TVector& vector, const IRotatorBase<TRotator, TVector>& rotator)
		{
			return rotator.RotateVector(vector);
		}

		/// <summary>
		/// Rotates vector by rotator.
		/// </summary>
		/// <param name="rotator">Rotation to apply.</param>
		/// <param name="vector">Vector to rotate.</param>
		/// <returns>The rotated vector</returns>
		template<class TRotator, class TVector>
		inline TVector RotateVector(const IRotatorBase<TRotator, TVector>& rotator, const TVector& vector)
		{
			return RotateVector(vector, rotator);
		}

		/// <summary>
		/// Combines first and second so the first rotation performed is first and the second is second.
		/// </summary>
		/// <param name="first">The first rotation to apply.</param>
		/// <param name="second">The rotation to combine first with.</param>
		/// <returns>A new rotation that will first perform first and then second.</returns>
		template<class TRotator, class TVector>
		inline TRotator Combine(const IRotatorBase<TRotator, TVector>& first, const TRotator& second)
		{
			return first.CombineRotations(second);
		}
	}
} }