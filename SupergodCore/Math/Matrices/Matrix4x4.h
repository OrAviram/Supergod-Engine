// TODO: Bring back this when Matrix3x3 and Matrix2x2 exist.

//#pragma once
//
//#include "Common/CommonDefines.h"
//#include "MatrixCommon.h"
//
//namespace SupergodCore { namespace Math
//{
//	struct Angle;
//	struct Vector3D;
//	struct Vector4D;
//
//	// TODO: Implement IMatrix. For now I just don't need all of its methods, so I am only implementing ISupergodEquatable.
//
//	/// <summary>
//	/// Represents a 4 by 4 mathematical matrix.
//	/// </summary>
//	struct SUPERGOD_API Matrix4x4 final : public IMatrix<Matrix4x4, Vector4D>
//	{
//		union
//		{
//			struct
//			{
//				float r0c0, r0c1, r0c2, r0c3;
//				float r1c0, r1c1, r1c2, r1c3;
//				float r2c0, r2c1, r2c2, r2c3;
//				float r3c0, r3c1, r3c2, r3c3;
//			};
//			float elements16[16];
//			float elements4x4[4][4];
//		};
//
//		/// <summary>
//		/// Creates a new 4 by 4 matrix and sets all of its components to 0.
//		/// </summary>
//		Matrix4x4();
//
//		/// <summary>
//		/// Creates a new 4 by 4 matrix with specified values for their components.
//		/// </summary>
//		Matrix4x4(
//			float r0c0, float r0c1, float r0c2, float r0c3,
//			float r1c0, float r1c1, float r1c2, float r1c3,
//			float r2c0, float r2c1, float r2c2, float r2c3,
//			float r3c0, float r3c1, float r3c2, float r3c3);
//
//		/// <summary>
//		/// Creates a new 4 by 4 matrix where the diagonal elements are set to diagonal and the other elements are set to 0.
//		/// </summary>
//		/// <param name="diagonal">The value of the diagonal elements.</param>
//		Matrix4x4(float diagonal);
//
//		#pragma region Basic construction methods.
//		/// <summary>
//		/// Creates a new matrix with vectors for the rows.
//		/// </summary>
//		static Matrix4x4 FromRows(
//			const Vector4D& firstRow,
//			const Vector4D& secondRow,
//			const Vector4D& thirdRow,
//			const Vector4D& fourthRow);
//
//		/// <summary>
//		/// Creates a new matrix with vectors for the columns.
//		/// </summary>
//		static Matrix4x4 FromColumns(
//			const Vector4D& firstColumn,
//			const Vector4D& secondColumn,
//			const Vector4D& thirdColumn,
//			const Vector4D& fourthColumn);
//		#pragma endregion
//
//		// TODO: Add conversions from other types of rotations.
//		#pragma region Basic transformation construction methods.
//		/// <summary>
//		/// Creates a scale matrix.
//		/// </summary>
//		/// <param name="x">The scale on the x axis.</param>
//		/// <param name="y">The scale on the y axis.</param>
//		/// <param name="z">The scale on the z axis.</param>
//		static Matrix4x4 Scale(float x, float y, float z);
//
//		/// <summary>
//		/// Creates a scale matrix.
//		/// </summary>
//		/// <param name="scale">The scale to make on the x, y and z axes.</param>
//		static Matrix4x4 Scale(const Vector3D& scale);
//
//		/// <summary>
//		/// Creates a translation matrix.
//		/// </summary>
//		/// <param name="x">The translation on the x axis.</param>
//		/// <param name="y">The translation on the y axis.</param>
//		/// <param name="z">The translation on the z axis.</param>
//		static Matrix4x4 Translate(float x, float y, float z);
//
//		/// <summary>
//		/// Creates a translation matrix.
//		/// </summary>
//		/// <param name="translation">The translation on the x, y and z axes.</param>
//		static Matrix4x4 Translate(const Vector3D& translation);
//
//		/// <summary>
//		/// Creates a rotation matrix that will rotate by angle around the x axis.
//		/// </summary>
//		static Matrix4x4 RotateX(const Angle& angle);
//
//		/// <summary>
//		/// Creates a rotation matrix that will rotate by angle around the y axis.
//		/// </summary>
//		static Matrix4x4 RotateY(const Angle& angle);
//
//		/// <summary>
//		/// Creates a rotation matrix that will rotate by angle around the z axis.
//		/// </summary>
//		static Matrix4x4 RotateZ(const Angle& angle);
//		#pragma endregion
//
//		#pragma region Special transformations(Look, LookAt and projection matrices).
//		// TODO: Add projection matrices when you figure out what to do about the fact that they depend on the graphics API.
//		// TODO: Add view matrices when you have multiplication for matrices.
//		#pragma endregion
//
//		#pragma region Multiplication and division.
//		/// <summary>
//		/// Multiplies every component of this by its corresponding component in other.
//		/// </summary>
//		Matrix4x4 MultiplyComponentWise(const Matrix4x4& other) const;
//
//		/// <summary>
//		/// Multiplies this matrix by other.
//		/// </summary>
//		Matrix4x4 Multiply(const Matrix4x4& other) const;
//
//		/// <summary>
//		/// Multiplies every component of this by scalar.
//		/// </summary>
//		Matrix4x4 Multiply(float scalar) const;
//
//		/// <summary>
//		/// Divides every elemnt of this by scalar.
//		/// </summary>
//		Matrix4x4 Divide(float scalar) const;
//		#pragma endregion
//		
//		#pragma region Addition and subtraction.
//		/// <summary>Adds every element of this to the corresponding element in other.</summary>
//		Matrix4x4 Add(const Matrix4x4& other) const;
//		
//		/// <summary>Subtracts every element of this by the corresponding element in other.</summary>
//		Matrix4x4 Subtract(const Matrix4x4& other) const;
//		#pragma endregion
//
//		#pragma region Negating, transposing, minor, cofactor and absolute value.
//		/// <summary>
//		/// The matrix with all of its elements negated (multiplied by -1).
//		/// </summary>
//		Matrix4x4 Negated() const;
//
//		/// <summary>
//		/// Gets the transpose (replaced rows with columns and columns with rows) of this matrix.
//		/// </summary>
//		Matrix4x4 Transposed() const;
//
//		/// <summary>
//		/// Gets the minor matrix of this.
//		/// </summary>
//		Matrix4x4 Minor() const;
//
//		/// <summary>
//		/// Gets the cofactor matrix of this.
//		/// </summary>
//		Matrix4x4 Cofactor() const;
//
//		/// <summary>
//		/// Gets a new matrix where each element has the absolute value of the corresponding element in this.
//		/// </summary>
//		Matrix4x4 Abs() const;
//		#pragma endregion
//
//		#pragma region Determinant and trace.
//		/// <summary>The determinant (how much the area of a 1x1 square will be multiplied by after it's transformed with this matrix) of this matrix.</summary>
//		float Determinant() const;
//
//		/// <summary>Gest the trace (sum of diagonal elements) of this matrix.</summary>
//		float Trace() const;
//		#pragma endregion
//
//		#pragma region Clamp methods (Clamp, ClampElements, ClampRows. ClampColumns).
//		/// <summary>Clamps each element of this so it's never smaller than the corresponding element in min and never bigger than the corresponding element in max.</summary>
//		Matrix4x4 Clamp(const Matrix4x4& min, const Matrix4x4& max) const;
//
//		/// <summary>Clamps each element of this so it's never smaller than min and never bigger than max.</summary>
//		Matrix4x4 ClampElements(float min, float max) const;
//
//		/// <summary>Clamps each element of each row in this so that it's never smaller than the corresponding element in min and never bigger than the corresponding element in max.</summary>
//		Matrix4x4 ClampRows(const Vector4D& min, const Vector4D& max) const;
//
//		Matrix4x4 ClampColumns(const Vector4D& min, const Vector4D& max) const;
//		#pragma endregion
//
//		#pragma region Comparison methods(Equals, Operators, GetHashCode, CloseEnough).
//		/// <summary>
//		/// Is the distance between each element in this and its corresponding elemtn in other smaller or equal to threshold?
//		/// </summary>
//		bool CloseEnough(const Matrix4x4& other, float threshold = Constants::CLOSE_ENOUGH_DEFAULT_THRESHOLD) const;
//		
//		/// <summary>
//		/// Is every element of this the same as its corresponding component in other?
//		/// </summary>
//		bool Equals(const Matrix4x4& other) const;
//		#pragma endregion
//	};
//} }