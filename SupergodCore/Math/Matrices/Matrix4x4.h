#pragma once

#include "Common/CommonDefines.h"
#include "IMatrix.h"

namespace SupergodCore { namespace Math
{
	struct Angle;
	struct Vector3D;
	struct Vector4D;

	// TODO: Implement IMatrix. For now I just don't need all of its methods, so I am only implementing ISupergodEquatable.

	/// <summary>
	/// Represents a 4 by 4 mathematical matrix.
	/// </summary>
	struct SUPERGOD_API Matrix4x4 final : public ISupergodEquatable<Matrix4x4>
	{
		union
		{
			struct
			{
				float r0c0, r0c1, r0c2, r0c3;
				float r1c0, r1c1, r1c2, r1c3;
				float r2c0, r2c1, r2c2, r2c3;
				float r3c0, r3c1, r3c2, r3c3;
			};
			float elements16[16];
			float elements4x4[4][4];
		};

		/// <summary>
		/// Creates a new 4 by 4 matrix and sets all of its components to 0.
		/// </summary>
		Matrix4x4();

		/// <summary>
		/// Creates a new 4 by 4 matrix with specified values for their components.
		/// </summary>
		Matrix4x4(
			float r0c0, float r0c1, float r0c2, float r0c3,
			float r1c0, float r1c1, float r1c2, float r1c3,
			float r2c0, float r2c1, float r2c2, float r2c3,
			float r3c0, float r3c1, float r3c2, float r3c3);

		/// <summary>
		/// Creates a new 4 by 4 matrix where the diagonal elements are set to diagonal and the other elements are set to 0.
		/// </summary>
		/// <param name="diagonal">The value of the diagonal elements.</param>
		Matrix4x4(float diagonal);

		#pragma region Basic construction methods.
		/// <summary>
		/// Creates a new matrix with vectors for the rows.
		/// </summary>
		static Matrix4x4 FromRows(
			const Vector4D& firstRow,
			const Vector4D& secondRow,
			const Vector4D& thirdRow,
			const Vector4D& fourthRow);

		/// <summary>
		/// Creates a new matrix with vectors for the columns.
		/// </summary>
		static Matrix4x4 FromColumns(
			const Vector4D& firstColumn,
			const Vector4D& secondColumn,
			const Vector4D& thirdColumn,
			const Vector4D& fourthColumn);
		#pragma endregion

		// TODO: Add conversions from other types of rotations.
		#pragma region Basic transformation construction methods.
		/// <summary>
		/// Creates a scale matrix.
		/// </summary>
		/// <param name="x">The scale on the x axis.</param>
		/// <param name="y">The scale on the y axis.</param>
		/// <param name="z">The scale on the z axis.</param>
		static Matrix4x4 Scale(float x, float y, float z);

		/// <summary>
		/// Creates a scale matrix.
		/// </summary>
		/// <param name="scale">The scale to make on the x, y and z axes.</param>
		static Matrix4x4 Scale(const Vector3D& scale);

		/// <summary>
		/// Creates a translation matrix.
		/// </summary>
		/// <param name="x">The translation on the x axis.</param>
		/// <param name="y">The translation on the y axis.</param>
		/// <param name="z">The translation on the z axis.</param>
		static Matrix4x4 Translate(float x, float y, float z);

		/// <summary>
		/// Creates a translation matrix.
		/// </summary>
		/// <param name="translation">The translation on the x, y and z axes.</param>
		static Matrix4x4 Translate(const Vector3D& translation);

		/// <summary>
		/// Creates a rotation matrix that will rotate by angle around the x axis.
		/// </summary>
		static Matrix4x4 RotateX(const Angle& angle);

		/// <summary>
		/// Creates a rotation matrix that will rotate by angle around the y axis.
		/// </summary>
		static Matrix4x4 RotateY(const Angle& angle);

		/// <summary>
		/// Creates a rotation matrix that will rotate by angle around the z axis.
		/// </summary>
		static Matrix4x4 RotateZ(const Angle& angle);
		#pragma endregion

		#pragma region Comparison methods(Equals, Operators, GetHashCode, CloseEnough).
		/// <summary>
		/// Is the distance between each element in this and its corresponding elemtn in other smaller or equal to threshold?
		/// </summary>
		bool CloseEnough(const Matrix4x4& other, float threshold = Constants::CLOSE_ENOUGH_DEFAULT_THRESHOLD) const override;
		
		/// <summary>
		/// Is every element of this the same as its corresponding component in other?
		/// </summary>
		bool Equals(const Matrix4x4& other) const override;
		#pragma endregion
	};
} }