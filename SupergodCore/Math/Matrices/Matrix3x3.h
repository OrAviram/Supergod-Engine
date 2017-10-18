#pragma once

#include "MatrixCommon.h"
#include "../Interfaces/ITransformer.h"
#include "../Interfaces/IRotator.h"
#include "../Vectors/Vector3D.h"

namespace SupergodCore { namespace Math
{
	// Inheriting from IRotator2D caused a few problems, so I removed it. The interface will probably be gone later, so it doesn't matter.

	struct Angle;
	struct Vector2D;
	struct Matrix2x2;

	/// <summary>
	/// Represents a 3 by 3 mathematical matrix. Useful for affine transformations in 2D.
	/// </summary>
	struct SUPERGOD_API_CLASS Matrix3x3 : public MatrixBase<Matrix3x3, Vector3D>//, public IRotator2D<Matrix3x3>
	{
		#pragma region Presets for common matrices.
		/// <summary>
		/// The multiplicative identity:<para/>
		/// [1 0 0 0]<para/>
		/// [0 1 0 0]<para/>
		/// [0 0 1 0]<para/>
		/// [0 0 0 1]
		/// </summary>
		DEFINE_STRUCT_VALUE_PRESET(Matrix3x3, Identity, (1))

		/// <summary>
		/// The additive identity:<para/>
		/// [0 0 0 0]<para/>
		/// [0 0 0 0]<para/>
		/// [0 0 0 0]<para/>
		/// [0 0 0 0]
		/// </summary>
		DEFINE_STRUCT_VALUE_PRESET(Matrix3x3, Zero, )

		/// <summary>
		/// The component-wise multiplicative identity:<para/>
		/// [1 1 1 1]<para/>
		/// [1 1 1 1]<para/>
		/// [1 1 1 1]<para/>
		/// [1 1 1 1]
		/// </summary>
		DEFINE_STRUCT_VALUE_PRESET(Matrix3x3, One, (1, 1, 1, 1, 1, 1, 1, 1, 1))
		#pragma endregion

		union
		{
			struct
			{
				float r0c0, r0c1, r0c2;
				float r1c0, r1c1, r1c2;
				float r2c0, r2c1, r2c2;
			};

			/// <summary>
			/// The elements of the matrix as a float array where:<para/>
			/// --<para/>
			///		index = 0: r0c0<para/>
			///		index = 1: r0c1<para/>
			///		index = 2: r0c2<para/>
			/// --<para/>
			///		index = 3: r1c0<para/>
			///		index = 4: r1c1<para/>
			///		index = 5: r1c2<para/>
			/// --<para/>
			///		index = 6: r2c0<para/>
			///		index = 7: r2c1<para/>
			///		index = 8: r2c2
			/// </summary>
			float elements9[9];

			/// <summary>
			/// The elements of the matrix as an array of float arrays where the index in the first array is the row and the index in the second array is the column.
			/// </summary>
			float elements3x3[3][3];
		};

		/// <summary>
		/// Creates a 2 by 2 matrix and initializes all of its elements to 0.
		/// </summary>
		Matrix3x3();

		/// <summary>
		/// Creates a new 3 by 3 matrix with a specified value for every element.
		/// </summary>
		Matrix3x3(
			float r0c0, float r0c1, float r0c2,
			float r1c0, float r1c1, float r1c2,
			float r2c0, float r2c1, float r2c2);

		/// <summary>
		/// Creates a new 3 by 3 matrix with a specified value for its diagonal elements. The other elements will be initialized to 0.
		/// </summary>
		/// <param name="diagonal">The value of the diagonal elements.</param>
		Matrix3x3(float diagonal);

		/// <summary>
		/// Gets a 2 by 2 matrix with the top left corner of this.
		/// </summary>
		explicit operator Matrix2x2();

		#pragma region Basic construction methods.
		/// <summary>
		/// Creates a new matrix with vectors for the rows.
		/// </summary>
		static Matrix3x3 FromRows(
			const Vector3D& firstRow,
			const Vector3D& secondRow,
			const Vector3D& thirdRow);

		/// <summary>
		/// Creates a new matrix with vectors for the columns.
		/// </summary>
		static Matrix3x3 FromColumns(
			const Vector3D& firstColumn,
			const Vector3D& secondColumn,
			const Vector3D& thirdColumn);
		#pragma endregion

		#pragma region Transformation construction methods.
		/// <summary>
		/// Creates a scale matrix.
		/// </summary>
		/// <param name="x">The scale along the x axis.</param>
		/// <param name="y">The scale along the y axis.</param>
		static Matrix3x3 Scale(float x, float y);

		/// <summary>
		/// Creates a scale matrix.
		/// </summary>
		/// <param name="scale">The scale along the x and y axes.</param>
		static Matrix3x3 Scale(const Vector2D& scale);

		/// <summary>
		/// Creates a rotation matrix.
		/// </summary>
		/// <param name="rotation">The angle of rotation.</param>
		static Matrix3x3 Rotate(Angle rotation);

		/// <summary>
		/// Creates a shear matrix.
		/// </summary>
		/// <param name="x">The amount of shear along the x axis.</param>
		/// <param name="y">The amount of shear along the y axis.</param>
		static Matrix3x3 Shear(float x, float y);

		/// <summary>
		/// Creates a shear matrix.
		/// </summary>
		/// <param name="shear">The amount of shear along the x and y axes.</param>
		static Matrix3x3 Shear(const Vector2D& shear);

		/// <summary>
		/// Creates a translation matrix.
		/// </summary>
		/// <param name="x">The amount of translation along the x axis.</param>
		/// <param name="y">The amount of translation along the y axis.</param>
		static Matrix3x3 Translate(float x, float y);

		/// <summary>
		/// Creates a translation matrix.
		/// </summary>
		/// <param name="translation">The amount of translation along the x and y axes.</param>
		static Matrix3x3 Translate(const Vector2D& translation);
		#pragma endregion

		#pragma region Indexers.
		/// <summary>
		/// Gets a reference to the row at the index of index.
		/// </summary>
		const Vector3D& GetRow(int index) const;

		/// <summary>
		/// Gets a reference to the row at the index of index.
		/// </summary>
		Vector3D& GetRow(int index);

		/// <summary>
		/// Gets the value of the column at the index of index. (Will construct a new vector.)
		/// </summary>
		/// <param name="index">The index of the column.</param>
		Vector3D GetColumn(int index) const;

		/// <summary>
		/// Sets the value of the column at the index of index.
		/// </summary>
		/// <param name="index">The index of the column.</param>
		/// <returns>The new value of the column.</returns>
		Vector3D SetColumn(int index, const Vector3D& value);

		/// <summary>
		/// Gets a reference to the element at index.
		/// </summary>
		const float& operator[](int index) const;

		/// <summary>
		/// Gets a reference to the element at index.
		/// </summary>
		float& operator[](int index);

		/// <summary>
		/// Gets a reference to the element at the row of row and column of column.
		/// </summary>
		const float& operator() (int row, int column) const;

		/// <summary>
		/// Gets a reference to the element at the row of row and column of column.
		/// </summary>
		float& operator() (int row, int column);
		#pragma endregion

		#pragma region Comparison methods(Equals, Operators, GetHashCode, CloseEnough).
		/// <summary>
		/// Is the distance between each element in this and its corresponding elemtn in other smaller or equal to threshold?
		/// </summary>
		bool CloseEnough(const Matrix3x3& other, float threshold = Constants::CLOSE_ENOUGH_DEFAULT_THRESHOLD) const;

		/// <summary>
		/// Is every element of this the same as its corresponding component in other?
		/// </summary>
		bool Equals(const Matrix3x3& other) const;
		#pragma endregion

		#pragma region Multiplication and division.
		/// <summary>
		/// Multiplies every component of this by its corresponding component in other.
		/// </summary>
		Matrix3x3 MultiplyComponentWise(const Matrix3x3& other) const;

		/// <summary>
		/// Multiplies this matrix by other.
		/// </summary>
		Matrix3x3 Multiply(const Matrix3x3& other) const;

		/// <summary>
		/// Multiplies this by vector (where vector is a column vector). This will transform vector.
		/// </summary>
		Vector3D Multiply(const Vector3D& vector) const;

		/// <summary>
		/// Multiplies every component of this by scalar.
		/// </summary>
		Matrix3x3 Multiply(float scalar) const;

		/// <summary>
		/// Divides every elemnt of this by scalar.
		/// </summary>
		Matrix3x3 Divide(float scalar) const;
		#pragma endregion

		#pragma region Addition and subtraction.
		/// <summary>Adds every element of this to the corresponding element in other.</summary>
		Matrix3x3 Add(const Matrix3x3& other) const;

		/// <summary>Subtracts every element of this by the corresponding element in other.</summary>
		Matrix3x3 Subtract(const Matrix3x3& other) const;
		#pragma endregion

		#pragma region Negating, transposing, minor, cofactor and absolute value.
		/// <summary>
		/// The matrix with all of its elements negated (multiplied by -1).
		/// </summary>
		Matrix3x3 Negated() const;

		/// <summary>
		/// Gets the transpose (replaced rows with columns and columns with rows) of this matrix.
		/// </summary>
		Matrix3x3 Transposed() const;

		/// <summary>
		/// Gets the minor matrix of this.
		/// </summary>
		Matrix3x3 Minor() const;

		/// <summary>
		/// Gets the cofactor matrix of this.
		/// </summary>
		Matrix3x3 Cofactor() const;

		/// <summary>
		/// Gets a new matrix where each element has the absolute value of the corresponding element in this.
		/// </summary>
		Matrix3x3 Abs() const;
		#pragma endregion

		#pragma region Determinant and trace.
		/// <summary>The determinant (Volume between the vectors of the three columns) of this matrix.</summary>
		float Determinant() const;

		/// <summary>Gest the trace (sum of diagonal elements) of this matrix.</summary>
		float Trace() const;
		#pragma endregion

		#pragma region Clamp methods (Clamp, ClampElements, ClampRows. ClampColumns).
		/// <summary>Clamps each element of this so it's never smaller than the corresponding element in min and never bigger than the corresponding element in max.</summary>
		Matrix3x3 Clamp(const Matrix3x3& min, const Matrix3x3& max) const;

		/// <summary>Clamps each element of this so it's never smaller than min and never bigger than max.</summary>
		Matrix3x3 ClampElements(float min, float max) const;

		/// <summary>Clamps each element of each row in this so that it's never smaller than the corresponding element in min and never bigger than the corresponding element in max.</summary>
		Matrix3x3 ClampRows(const Vector3D& min, const Vector3D& max) const;

		/// <summary>Clamps each element of each column in this so that it's never smaller than the corresponding element in min and never bigger than the corresponding element in max.</summary>
		Matrix3x3 ClampColumns(const Vector3D& min, const Vector3D& max) const;
		#pragma endregion
	};
} }