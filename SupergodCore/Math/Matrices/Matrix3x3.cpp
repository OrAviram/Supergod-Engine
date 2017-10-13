#include "Matrix3x3.h"
#include "Matrix2x2.h"
#include "../Angle.h"
#include "../Vectors/Vector2D.h"
#include "../Vectors/Vector3D.h"
#include <memory>

namespace SupergodCore { namespace Math
{
	Matrix3x3::Matrix3x3()
	{
		memset(this, 0, sizeof(Matrix3x3));
	}

	Matrix3x3::Matrix3x3(
		float r0c0, float r0c1, float r0c2,
		float r1c0, float r1c1, float r1c2,
		float r2c0, float r2c1, float r2c2)
		: r0c0(r0c0), r0c1(r0c1), r0c2(r0c2),
		r1c0(r1c0), r1c1(r1c1), r1c2(r1c2),
		r2c0(r2c0), r2c1(r2c1), r2c2(r2c2)
	{
	}

	Matrix3x3::Matrix3x3(float diagonal)
		: r0c0(diagonal), r0c1(0), r0c2(0),
		r1c0(0), r1c1(diagonal), r1c2(0),
		r2c0(0), r2c1(0), r2c2(diagonal)
	{
	}

	Matrix3x3 Matrix3x3::FromRows(
		const Vector3D& firstRow,
		const Vector3D& secondRow,
		const Vector3D& thirdRow)
	{
		return Matrix3x3(
			firstRow.x, firstRow.y, firstRow.z,
			secondRow.x, secondRow.y, secondRow.z,
			thirdRow.x, thirdRow.y, thirdRow.z);
	}

	Matrix3x3 Matrix3x3::FromColumns(
		const Vector3D& firstColumn,
		const Vector3D& secondColumn,
		const Vector3D& thirdColumn)
	{
		return Matrix3x3(
			firstColumn.x, secondColumn.x, thirdColumn.x,
			firstColumn.y, secondColumn.y, thirdColumn.y,
			firstColumn.z, secondColumn.z, thirdColumn.z);
	}

	Matrix3x3 Matrix3x3::Scale(float x, float y)
	{
		return Matrix3x3(
			x, 0, 0,
			0, y, 0,
			0, 0, 1);
	}

	Matrix3x3 Matrix3x3::Scale(const Vector2D& scale)
	{
		return Scale(scale.x, scale.y);
	}

	Matrix3x3 Matrix3x3::Rotate(Angle rotation)
	{
		float sin = SMath::Sin(rotation);
		float cos = SMath::Cos(rotation);

		return Matrix3x3(
			cos, -sin, 0,
			sin, cos, 0,
			0, 0, 1);
	}

	Matrix3x3 Matrix3x3::Shear(float x, float y)
	{
		return Matrix3x3(
			1, x, 0,
			y, 1, 0,
			0, 0, 1);
	}

	Matrix3x3 Matrix3x3::Shear(const Vector2D& shear)
	{
		return Shear(shear.x, shear.y);
	}

	Matrix3x3 Matrix3x3::Translate(float x, float y)
	{
		return Matrix3x3(
			1, 0, x,
			0, 1, y,
			0, 0, 1);
	}

	Matrix3x3 Matrix3x3::Translate(const Vector2D& translation)
	{
		return Translate(translation.x, translation.y);
	}

	const Vector3D& Matrix3x3::GetRow(int index) const
	{
		return *(Vector3D*)elements3x3[index];
	}

	Vector3D& Matrix3x3::GetRow(int index)
	{
		return *(Vector3D*)elements3x3[index];
	}

	Vector3D Matrix3x3::GetColumn(int index) const
	{
		return Vector3D(elements3x3[0][index], elements3x3[1][index], elements3x3[2][index]);
	}

	Vector3D Matrix3x3::SetColumn(int index, const Vector3D& value)
	{
		elements3x3[0][index] = value.x;
		elements3x3[1][index] = value.y;
		elements3x3[2][index] = value.z;
		return value;
	}

	const float& Matrix3x3::operator[](int index) const
	{
		return elements9[index];
	}

	float& Matrix3x3::operator[](int index)
	{
		return elements9[index];
	}

	const float& Matrix3x3::operator()(int row, int column) const
	{
		return elements3x3[row][column];
	}

	float& Matrix3x3::operator()(int row, int column)
	{
		return elements3x3[row][column];
	}

	bool Matrix3x3::CloseEnough(const Matrix3x3& other, float threshold) const
	{
		return
			GetRow(0).CloseEnough(other.GetRow(0), threshold) &&
			GetRow(1).CloseEnough(other.GetRow(1), threshold) &&
			GetRow(2).CloseEnough(other.GetRow(2), threshold);
	}

	bool Matrix3x3::Equals(const Matrix3x3& other) const
	{
		return
			GetRow(0) == other.GetRow(0) &&
			GetRow(1) == other.GetRow(1) &&
			GetRow(2) == other.GetRow(2);
	}

	Matrix3x3 Matrix3x3::MultiplyComponentWise(const Matrix3x3& other) const
	{
		return FromRows(
			GetRow(0) * other.GetRow(0),
			GetRow(1) * other.GetRow(1),
			GetRow(2) * other.GetRow(2));
	}

	Matrix3x3 Matrix3x3::Multiply(const Matrix3x3& other) const
	{
		return Matrix3x3(
			GetRow(0).Dot(other.GetColumn(0)),
			GetRow(0).Dot(other.GetColumn(1)),
			GetRow(0).Dot(other.GetColumn(2)),

			GetRow(1).Dot(other.GetColumn(0)),
			GetRow(1).Dot(other.GetColumn(1)),
			GetRow(1).Dot(other.GetColumn(2)),
			
			GetRow(2).Dot(other.GetColumn(0)),
			GetRow(2).Dot(other.GetColumn(1)),
			GetRow(2).Dot(other.GetColumn(2)));
	}

	Vector3D Matrix3x3::Multiply(const Vector3D& vector) const
	{
		return vector.x * GetColumn(0) + vector.y * GetColumn(1) + vector.z * GetColumn(2);
	}

	Matrix3x3 Matrix3x3::Multiply(float scalar) const
	{
		return FromRows(
			GetRow(0) * scalar,
			GetRow(1) * scalar,
			GetRow(2) * scalar);
	}

	Matrix3x3 Matrix3x3::Divide(float scalar) const
	{
		return FromRows(
			GetRow(0) / scalar,
			GetRow(1) / scalar,
			GetRow(2) / scalar);
	}

	Matrix3x3 Matrix3x3::Add(const Matrix3x3& other) const
	{
		return FromRows(
			GetRow(0) + other.GetRow(0),
			GetRow(1) + other.GetRow(1),
			GetRow(2) + other.GetRow(2));
	}

	Matrix3x3 Matrix3x3::Subtract(const Matrix3x3& other) const
	{
		return FromRows(
			GetRow(0) - other.GetRow(0),
			GetRow(1) - other.GetRow(1),
			GetRow(2) - other.GetRow(2));
	}

	Matrix3x3 Matrix3x3::Negated() const
	{
		return FromRows(
			-GetRow(0),
			-GetRow(1),
			-GetRow(2));
	}

	Matrix3x3 Matrix3x3::Transposed() const
	{
		return FromColumns(
			GetRow(0),
			GetRow(1),
			GetRow(2));
	}

	Matrix3x3 Matrix3x3::Minor() const
	{
		return Matrix3x3(
			Matrix2x2(r1c1, r1c2, r2c1, r2c2).Determinant(),
			Matrix2x2(r1c0, r1c2, r2c0, r2c2).Determinant(),
			Matrix2x2(r1c0, r1c1, r2c0, r2c1).Determinant(),

			Matrix2x2(r0c1, r0c2, r2c1, r2c2).Determinant(),
			Matrix2x2(r0c0, r0c2, r2c0, r2c2).Determinant(),
			Matrix2x2(r0c0, r0c1, r2c0, r2c1).Determinant(),

			Matrix2x2(r0c1, r0c2, r1c1, r1c2).Determinant(),
			Matrix2x2(r0c0, r0c2, r1c0, r1c2).Determinant(),
			Matrix2x2(r0c0, r0c1, r1c0, r1c1).Determinant()
			);
	}

	Matrix3x3 Matrix3x3::Cofactor() const
	{
		return Minor().MultiplyComponentWise(Matrix3x3(
			1, -1, 1,
			-1, 1, -1,
			1, -1, 1));
	}

	Matrix3x3 Matrix3x3::Abs() const
	{
		return FromRows(
			GetRow(0).Abs(),
			GetRow(1).Abs(),
			GetRow(2).Abs());
	}

	float Matrix3x3::Determinant() const
	{
		return
			r0c0 * Matrix2x2(r1c1, r1c2, r2c1, r2c2).Determinant() -
			r0c1 * Matrix2x2(r1c0, r1c2, r2c0, r2c2).Determinant() +
			r0c2 * Matrix2x2(r1c0, r1c1, r2c0, r2c1).Determinant();
	}

	float Matrix3x3::Trace() const
	{
		return r0c0 + r1c1 + r2c2;
	}

	Matrix3x3 Matrix3x3::Clamp(const Matrix3x3& min, const Matrix3x3& max) const
	{
		return FromRows(
			GetRow(0).Clamp(min.GetRow(0), max.GetRow(0)),
			GetRow(1).Clamp(min.GetRow(1), max.GetRow(1)),
			GetRow(2).Clamp(min.GetRow(2), max.GetRow(2)));
	}

	Matrix3x3 Matrix3x3::ClampElements(float min, float max) const
	{
		return FromRows(
			GetRow(0).ClampComponents(min, max),
			GetRow(1).ClampComponents(min, max),
			GetRow(2).ClampComponents(min, max));
	}

	Matrix3x3 Matrix3x3::ClampRows(const Vector3D& min, const Vector3D& max) const
	{
		return FromRows(
			GetRow(0).Clamp(min, max),
			GetRow(1).Clamp(min, max),
			GetRow(2).Clamp(min, max));
	}

	Matrix3x3 Matrix3x3::ClampColumns(const Vector3D& min, const Vector3D& max) const
	{
		return FromColumns(
			GetColumn(0).Clamp(min, max),
			GetColumn(1).Clamp(min, max),
			GetColumn(2).Clamp(min, max));
	}
} }