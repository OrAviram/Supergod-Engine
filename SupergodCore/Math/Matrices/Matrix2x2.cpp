#include "Matrix2x2.h"
#include "../Vectors/Vector2D.h"
#include <memory>

namespace SupergodCore { namespace Math
{
	Matrix2x2::Matrix2x2()
		: r0c0(0), r0c1(0), r1c0(0), r1c1(0)
	{
	}

	Matrix2x2::Matrix2x2(float r0c0, float r0c1, float r1c0, float r1c1)
		: r0c0(r0c0), r0c1(r0c1), r1c0(r1c0), r1c1(r1c1)
	{
	}

	Matrix2x2::Matrix2x2(float diagonal)
		: r0c0(diagonal), r0c1(0), r1c0(0), r1c1(diagonal)
	{
	}

	Matrix2x2 Matrix2x2::FromRows(const Vector2D& firstRow, const Vector2D& secondRow)
	{
		return Matrix2x2(
			firstRow.x, firstRow.y,
			secondRow.x, secondRow.y);
	}

	Matrix2x2 Matrix2x2::FromColumns(const Vector2D& firstRow, const Vector2D& secondRow)
	{
		return Matrix2x2(
			firstRow.x, secondRow.x,
			firstRow.y, secondRow.y);
	}

	Matrix2x2 Matrix2x2::Scale(float x, float y)
	{
		return Matrix2x2(
			x, 0,
			0, y);
	}

	Matrix2x2 Matrix2x2::Scale(const Vector2D& scale)
	{
		return Scale(scale.x, scale.y);
	}

	Matrix2x2 Matrix2x2::Rotate(const Angle& rotation)
	{
		float sin = SMath::Sin(rotation);
		float cos = SMath::Cos(rotation);

		return Matrix2x2(
			cos, -sin,
			sin, cos);
	}

	Matrix2x2 Matrix2x2::Shear(float x, float y)
	{
		return Matrix2x2(
			1, x,
			y, 1);
	}

	Matrix2x2 Matrix2x2::Shear(const Vector2D& shear)
	{
		return Shear(shear.x, shear.y);
	}

	const Vector2D& Matrix2x2::GetColumn(int index) const
	{
		return *(Vector2D*)elements2x2[index];
	}

	Vector2D& Matrix2x2::GetColumn(int index)
	{
		return *(Vector2D*)elements2x2[index];
	}

	// TODO: There is no way this is correct, but I will only be sure after testing...
	const Vector2D& Matrix2x2::GetRow(int index) const
	{
		return *(Vector2D*)&elements2x2[0][index];
	}

	Vector2D& Matrix2x2::GetRow(int index)
	{
		return *(Vector2D*)&elements2x2[0][index];
	}

	const float& Matrix2x2::operator[](int index) const
	{
		return elements4[index];
	}

	float& Matrix2x2::operator[](int index)
	{
		return elements4[index];
	}

	const float& Matrix2x2::operator() (int row, int column) const
	{
		return elements2x2[row][column];
	}

	float& Matrix2x2::operator() (int row, int column)
	{
		return elements2x2[row][column];
	}

	bool Matrix2x2::CloseEnough(const Matrix2x2& other, float threshold) const
	{
		return
			SMath::CloseEnough(r0c0, other.r0c0, threshold) && SMath::CloseEnough(r0c1, other.r0c1, threshold) &&
			SMath::CloseEnough(r1c0, other.r1c0, threshold) && SMath::CloseEnough(r1c1, other.r1c1, threshold);
	}

	bool Matrix2x2::Equals(const Matrix2x2& other) const
	{
		return
			r0c0 == other.r0c0 && r0c1 == other.r0c1 &&
			r1c0 == other.r1c0 && r1c1 == other.r1c1;
	}

	Matrix2x2 Matrix2x2::MultiplyComponentWise(const Matrix2x2& other) const
	{
		return Matrix2x2(
			r0c0 * other.r0c0, r0c1 * other.r0c1,
			r1c0 * other.r1c0, r1c1 * other.r1c1);
	}

	Matrix2x2 Matrix2x2::Multiply(const Matrix2x2& other) const
	{
		return Matrix2x2(
			GetRow(0).Dot(other.GetColumn(0)), GetRow(0).Dot(other.GetColumn(1)),
			GetRow(1).Dot(other.GetColumn(0)), GetRow(1).Dot(other.GetColumn(1)));
	}

	Vector2D Matrix2x2::Multiply(const Vector2D& vector) const
	{
		return
			vector.x * GetColumn(0) +
			vector.y * GetColumn(1);
	}

	Vector2D Matrix2x2::Multiply(const Vector2D& vector, const Matrix2x2& matrix)
	{
		return Vector2D(
			vector.Dot(matrix.GetColumn(0)),
			vector.Dot(matrix.GetColumn(1)));
	}

	Matrix2x2 Matrix2x2::Multiply(float scalar) const
	{
		return Matrix2x2(
			r0c0 * scalar, r0c1 * scalar,
			r1c0 * scalar, r1c1 * scalar);
	}

	Matrix2x2 Matrix2x2::Divide(float scalar) const
	{
		return Matrix2x2(
			r0c0 / scalar, r0c1 / scalar,
			r1c0 / scalar, r1c1 / scalar);
	}

	Matrix2x2 Matrix2x2::Add(const Matrix2x2& other) const
	{
		return Matrix2x2(
			r0c0 + other.r0c0, r0c1 + other.r0c1,
			r1c0 + other.r1c0, r1c1 + other.r1c1);
	}

	Matrix2x2 Matrix2x2::Subtract(const Matrix2x2& other) const
	{
		return Matrix2x2(
			r0c0 / other.r0c0, r0c1 / other.r0c1,
			r1c0 / other.r1c0, r1c1 / other.r1c1);
	}

	Matrix2x2 Matrix2x2::Negated() const
	{
		return Matrix2x2(
			-r0c0, -r0c1,
			-r1c0, -r1c1);
	}

	Matrix2x2 Matrix2x2::Transposed() const
	{
		return Matrix2x2(
			r0c0, r1c0,
			r0c1, r1c1);
	}

	Matrix2x2 Matrix2x2::Minor() const
	{
		return Matrix2x2(
			r1c1, r1c0,
			r0c1, r0c0);
	}

	Matrix2x2 Matrix2x2::Cofactor() const
	{
		return Minor().MultiplyComponentWise(Matrix2x2(
			+1, -1,
			-1, +1));
	}

	Matrix2x2 Matrix2x2::Abs() const
	{
		return Matrix2x2(
			SMath::Abs(r0c0), SMath::Abs(r0c1),
			SMath::Abs(r1c0), SMath::Abs(r1c1));
	}

	float Matrix2x2::Determinant() const
	{
		return r0c0 * r1c1 - r0c1 * r1c0;
	}

	float Matrix2x2::Trace() const
	{
		return r0c0 + r1c1;
	}

	Matrix2x2 Matrix2x2::Clamp(const Matrix2x2& min, const Matrix2x2& max) const
	{
		return Matrix2x2(
			SMath::Clamp(r0c0, min.r0c0, max.r0c0), SMath::Clamp(r0c1, min.r0c1, max.r0c1),
			SMath::Clamp(r1c0, min.r1c0, max.r1c0), SMath::Clamp(r1c1, min.r1c1, max.r1c1));
	}

	Matrix2x2 Matrix2x2::ClampElements(float min, float max) const
	{
		return Matrix2x2(
			SMath::Clamp(r0c0, min, max), SMath::Clamp(r0c1, min, max),
			SMath::Clamp(r1c0, min, max), SMath::Clamp(r1c1, min, max));
	}

	Matrix2x2 Matrix2x2::ClampRows(const Vector2D& min, const Vector2D& max) const
	{
		return FromRows(
			GetRow(0).Clamp(min, max),
			GetRow(0).Clamp(min, max));
	}

	Matrix2x2 Matrix2x2::ClampColumns(const Vector2D& min, const Vector2D& max) const
	{
		return FromColumns(
			GetColumn(0).Clamp(min, max),
			GetColumn(0).Clamp(min, max));
	}
} }