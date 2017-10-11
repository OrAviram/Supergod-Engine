#pragma once

#include "Common/CommonDefines.h"
#include "MatrixCommon.h"

namespace SupergodCore { namespace Math
{
	struct Vector2D;
	struct Angle;

	/// <summary>
	/// Represents a 2 by 2 mathematical matrix. This is useful for very simple transformations.<para/>
	/// For more complicated transformations in 2D, use Matrix3x3, and for more complicated transformations in 3D, use Matrix4x4.
	/// </summary>
	struct SUPERGOD_API_CLASS Matrix2x2 : public MatrixBase<Matrix2x2, Vector2D>
	{
		#pragma region Common matrices.
		/// <summary>
		/// The multiplicative identity:<para/>
		/// [1 0]<para/>
		/// [0 1]
		/// </summary>
		DEFINE_STRUCT_VALUE_PRESET(Matrix2x2, Identity, (1, 0, 0, 1))

		/// <summary>
		/// The additive identity:<para/>
		/// [0 0]<para/>
		/// [0 0]
		/// </summary>
		DEFINE_STRUCT_VALUE_PRESET(Matrix2x2, Zero, (0, 0, 0, 0))

		/// <summary>
		/// The component-wise multiplicative identity:<para/>
		/// [1 1]<para/>
		/// [1 1]
		/// </summary>
		DEFINE_STRUCT_VALUE_PRESET(Matrix2x2, One, (1, 1, 1, 1))
		#pragma endregion

		union
		{
			struct
			{
				float r0c0, r0c1;
				float r1c0, r1c1;
			};

			/// <summary>
			/// The elements of the matrix as a float array where:<para/>
			///		index = 0: r0c0<para/>
			///		index = 1: r0c1<para/>
			///		index = 2: r1c0<para/>
			///		index = 3: r1c1
			/// </summary>
			float elements4[4];

			/// <summary>
			/// Represents the matrix as a 2 dimensional float array where the first index is the row and the second is the column.
			/// </summary>
			float elements2x2[2][2];
		};

		/// <summary>
		/// Creates a new 2 by 2 matrix and initializes all of its components to 0.
		/// </summary>
		Matrix2x2();

		/// <summary>
		/// Creates a new 2 by 2 matrix with specified values for its elements.
		/// </summary>
		Matrix2x2(
			float r0c0, float r0c1,
			float r1c0, float r1c1);

		/// <summary>
		/// Creates a new 2 by 2 matrix and initializes all elements to 0 and the diagonal elements to diagonal.
		/// </summary>
		/// <param name="diagonal">The value for the diagonal elements.</param>
		Matrix2x2(float diagonal);

		#pragma region Basic construction methods.
		/// <summary>
		/// Creates a new matrix with vectors for the rows.
		/// </summary>
		static Matrix2x2 FromRows(
			const Vector2D& firstRow,
			const Vector2D& secondRow);

		/// <summary>
		/// Creates a new matrix with vectors for the columns.
		/// </summary>
		static Matrix2x2 FromColumns(
			const Vector2D& firstColumn,
			const Vector2D& secondColumn);
		#pragma endregion

		#pragma region Transformation construction methods.
		/// <summary>
		/// Creates a scale matrix
		/// </summary>
		/// <param name="x">The scale along the x axis.</param>
		/// <param name="y">The scale along the y axis.</param>
		static Matrix2x2 Scale(float x, float y);
		
		/// <summary>
		/// Creates a scale matrix.
		/// </summary>
		/// <param name="scale">The scale along the x and y axes.</param>
		static Matrix2x2 Scale(const Vector2D& scale);

		/// <summary>
		/// Creates a rotation matrix.
		/// </summary>
		/// <param name="rotation">The angle of rotation.</param>
		static Matrix2x2 Rotate(Angle rotation);

		/// <summary>
		/// Creates a shear matrix.
		/// </summary>
		/// <param name="x">The amount of shear along the x axis.</param>
		/// <param name="y">The amount of shear along the y axis.</param>
		static Matrix2x2 Shear(float x, float y);

		/// <summary>
		/// Creates a shear matrix.
		/// </summary>
		/// <param name="shear">The amount of shear along the x and y axes.</param>
		static Matrix2x2 Shear(const Vector2D& shear);
		#pragma endregion

		#pragma region Indexers.
		/// <summary>
		/// Gets a reference to the column at the index of index.
		/// </summary>
		const Vector2D& GetRow(int index) const;

		/// <summary>
		/// Gets a reference to the column at the index of index.
		/// </summary>
		Vector2D& GetRow(int index);

		/// <summary>
		/// Gets the value of the row at the index of index. (Will construct a new vector.)
		/// </summary>
		/// <param name="index">The index of the row.</param>
		Vector2D GetColumn(int index) const;

		/// <summary>
		/// Sets the value of the row at the index of index.
		/// </summary>
		/// <param name="index">The index of the row.</param>
		/// <returns>The new value of the row.</returns>
		Vector2D SetColumn(int index, const Vector2D& value);

		/// <summary>
		/// Gets a reference to the component at index.
		/// </summary>
		const float& operator[](int index) const;

		/// <summary>
		/// Gets a reference to the component at index.
		/// </summary>
		float& operator[](int index);

		/// <summary>
		/// Gets a reference to the component at the row of row and column of column.
		/// </summary>
		const float& operator() (int row, int column) const;

		/// <summary>
		/// Gets a reference to the component at the row of row and column of column.
		/// </summary>
		float& operator() (int row, int column);
		#pragma endregion

		#pragma region Comparison methods(Equals, Operators, GetHashCode, CloseEnough).
		/// <summary>
		/// Is the distance between each element in this and its corresponding elemtn in other smaller or equal to threshold?
		/// </summary>
		bool CloseEnough(const Matrix2x2& other, float threshold = Constants::CLOSE_ENOUGH_DEFAULT_THRESHOLD) const;
		
		/// <summary>
		/// Is every element of this the same as its corresponding component in other?
		/// </summary>
		bool Equals(const Matrix2x2& other) const;
		#pragma endregion

		#pragma region Multiplication and division.
		/// <summary>
		/// Multiplies every component of this by its corresponding component in other.
		/// </summary>
		Matrix2x2 MultiplyComponentWise(const Matrix2x2& other) const;

		/// <summary>
		/// Multiplies this matrix by other.
		/// </summary>
		Matrix2x2 Multiply(const Matrix2x2& other) const;
		
		/// <summary>
		/// Multiplies this by vector (where vector is a column vector). This will transform vector.
		/// </summary>
		Vector2D Multiply(const Vector2D& vector) const;

		/// <summary>
		/// Multiplies every component of this by scalar.
		/// </summary>
		Matrix2x2 Multiply(float scalar) const;

		/// <summary>
		/// Divides every elemnt of this by scalar.
		/// </summary>
		Matrix2x2 Divide(float scalar) const;
		#pragma endregion

		#pragma region Addition and subtraction.
		/// <summary>Adds every element of this to the corresponding element in other.</summary>
		Matrix2x2 Add(const Matrix2x2& other) const;
		
		/// <summary>Subtracts every element of this by the corresponding element in other.</summary>
		Matrix2x2 Subtract(const Matrix2x2& other) const;
		#pragma endregion

		#pragma region Negating, transposing, minor, cofactor and absolute value.
		/// <summary>
		/// The matrix with all of its elements negated (multiplied by -1).
		/// </summary>
		Matrix2x2 Negated() const;

		/// <summary>
		/// Gets the transpose (replaced rows with columns and columns with rows) of this matrix.
		/// </summary>
		Matrix2x2 Transposed() const;

		/// <summary>
		/// Gets the minor matrix of this.
		/// </summary>
		Matrix2x2 Minor() const;

		/// <summary>
		/// Gets the cofactor matrix of this.
		/// </summary>
		Matrix2x2 Cofactor() const;

		/// <summary>
		/// Gets a new matrix where each element has the absolute value of the corresponding element in this.
		/// </summary>
		Matrix2x2 Abs() const;
		#pragma endregion

		#pragma region Determinant and trace.
		/// <summary>The determinant (how much the area of a 1x1 square will be multiplied by after it's transformed with this matrix) of this matrix.</summary>
		float Determinant() const;

		/// <summary>Gest the trace (sum of diagonal elements) of this matrix.</summary>
		float Trace() const;
		#pragma endregion

		#pragma region Clamp methods (Clamp, ClampElements, ClampRows. ClampColumns).
		/// <summary>Clamps each element of this so it's never smaller than the corresponding element in min and never bigger than the corresponding element in max.</summary>
		Matrix2x2 Clamp(const Matrix2x2& min, const Matrix2x2& max) const;

		/// <summary>Clamps each element of this so it's never smaller than min and never bigger than max.</summary>
		Matrix2x2 ClampElements(float min, float max) const;

		/// <summary>Clamps each element of each row in this so that it's never smaller than the corresponding element in min and never bigger than the corresponding element in max.</summary>
		Matrix2x2 ClampRows(const Vector2D& min, const Vector2D& max) const;

		/// <summary>Clamps each element of each column in this so that it's never smaller than the corresponding element in min and never bigger than the corresponding element in max.</summary>
		Matrix2x2 ClampColumns(const Vector2D& min, const Vector2D& max) const;
		#pragma endregion
	};
} }