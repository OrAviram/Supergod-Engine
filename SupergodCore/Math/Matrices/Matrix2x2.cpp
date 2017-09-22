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

	static Matrix2x2 FromRows(const Vector2D& firstRow, const Vector2D& secondRow)
	{
		return Matrix2x2(
			firstRow.x, firstRow.y,
			secondRow.x, secondRow.y);
	}

	static Matrix2x2 FromColumns(const Vector2D& firstRow, const Vector2D& secondRow)
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

	// TODO: Figure out how to do that.
	const Vector2D& Matrix2x2::GetRow(int index) const
	{
		
	}

	Vector2D& Matrix2x2::GetRow(int index)
	{
	}
} }