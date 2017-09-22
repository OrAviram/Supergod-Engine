#include "Matrix4x4.h"
#include "../Vectors/Vector4D.h"
#include "../Vectors/Vector3D.h"
#include <memory>

namespace SupergodCore { namespace Math
{
	Matrix4x4::Matrix4x4()
	{
		memset(this, 0, sizeof(Matrix4x4));
	}

	Matrix4x4::Matrix4x4(
		float r0c0, float r0c1, float r0c2, float r0c3,
		float r1c0, float r1c1, float r1c2, float r1c3,
		float r2c0, float r2c1, float r2c2, float r2c3,
		float r3c0, float r3c1, float r3c2, float r3c3)

		: r0c0(r0c0), r0c1(r0c1), r0c2(r0c2), r0c3(r0c3),
		  r1c0(r1c0), r1c1(r1c1), r1c2(r1c2), r1c3(r1c3),
		  r2c0(r2c0), r2c1(r2c1), r2c2(r2c2), r2c3(r2c3),
		  r3c0(r3c0), r3c1(r3c1), r3c2(r3c2), r3c3(r3c3)
	{
	}

	Matrix4x4::Matrix4x4(float diagonal)
	{
		memset(this, 0, sizeof(Matrix4x4));
		r0c0 = r1c1 = r2c2 = r3c3 = diagonal;
	}

	Matrix4x4 Matrix4x4::FromRows(const Vector4D& firstRow, const Vector4D& secondRow, const Vector4D& thirdRow, const Vector4D& fourthRow)
	{
		return Matrix4x4(
			firstRow.x, firstRow.y, firstRow.z, firstRow.w,
			secondRow.x, secondRow.y, secondRow.z, secondRow.w,
			thirdRow.x, thirdRow.y, thirdRow.z, thirdRow.w,
			fourthRow.x, fourthRow.y, fourthRow.z, fourthRow.w);
	}

	Matrix4x4 Matrix4x4::FromColumns(const Vector4D& firstColumn, const Vector4D& secondColumn, const Vector4D& thirdColumn, const Vector4D& fourthColumn)
	{
		return Matrix4x4(
			firstColumn.x, secondColumn.x, thirdColumn.x, fourthColumn.x,
			firstColumn.y, secondColumn.y, thirdColumn.y, fourthColumn.y,
			firstColumn.z, secondColumn.z, thirdColumn.z, fourthColumn.z,
			firstColumn.w, secondColumn.w, thirdColumn.w, fourthColumn.w
			);
	}

	Matrix4x4 Matrix4x4::Scale(float x, float y, float z)
	{
		return Matrix4x4(
			x, 0, 0, 0,
			0, y, 0, 0,
			0, 0, z, 0,
			0, 0, 0, 1);
	}

	Matrix4x4 Matrix4x4::Scale(const Vector3D& scale)
	{
		return Scale(scale.x, scale.y, scale.z);
	}

	Matrix4x4 Matrix4x4::Translate(float x, float y, float z)
	{
		return Matrix4x4(
			0, 0, 0, x,
			0, 0, 0, y,
			0, 0, 0, z,
			0, 0, 0, 1);
	}

	Matrix4x4 Matrix4x4::Translate(const Vector3D& translation)
	{
		return Translate(translation.x, translation.y, translation.z);
	}

	Matrix4x4 Matrix4x4::RotateX(const Angle& angle)
	{
		float cos = SMath::Cos(angle);
		float sin = SMath::Sin(angle);

		return Matrix4x4(
			1, 0, 0, 0,
			0, cos, -sin, 0,
			0, sin, cos, 0,
			0, 0, 0, 1);
	}

	Matrix4x4 Matrix4x4::RotateY(const Angle& angle)
	{
		float cos = SMath::Cos(angle);
		float sin = SMath::Sin(angle);

		return Matrix4x4(
			cos, 0, sin, 0,
			0, 1, 0, 0,
			-sin, 0, cos, 0,
			0, 0, 0, 1);
	}

	Matrix4x4 Matrix4x4::RotateZ(const Angle& angle)
	{
		float cos = SMath::Cos(angle);
		float sin = SMath::Sin(angle);

		return Matrix4x4(
			cos, -sin, 0, 0,
			sin, cos, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1);
	}

	bool Matrix4x4::CloseEnough(const Matrix4x4& other, float threshold) const
	{
		for (int i = 0; i < 16; i++)
		{
			if (!SMath::CloseEnough(elements16[i], other.elements16[i], threshold))
				return false;
		}
		return true;
	}

	bool Matrix4x4::Equals(const Matrix4x4& other) const
	{
		for (int i = 0; i < 16; i++)
		{
			if (elements16[i] != other.elements16[i])
				return false;
		}
		return true;
	}
} }