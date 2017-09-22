// TODO: Bring back this when Matrix3x3 and Matrix2x2 exist.

//#include "Matrix4x4.h"
//#include "../Vectors/Vector4D.h"
//#include "../Vectors/Vector3D.h"
//#include <memory>
//#include <exception>
//
//namespace SupergodCore { namespace Math
//{
//	Matrix4x4::Matrix4x4()
//	{
//		memset(this, 0, sizeof(Matrix4x4));
//	}
//
//	Matrix4x4::Matrix4x4(
//		float r0c0, float r0c1, float r0c2, float r0c3,
//		float r1c0, float r1c1, float r1c2, float r1c3,
//		float r2c0, float r2c1, float r2c2, float r2c3,
//		float r3c0, float r3c1, float r3c2, float r3c3)
//
//		: r0c0(r0c0), r0c1(r0c1), r0c2(r0c2), r0c3(r0c3),
//		  r1c0(r1c0), r1c1(r1c1), r1c2(r1c2), r1c3(r1c3),
//		  r2c0(r2c0), r2c1(r2c1), r2c2(r2c2), r2c3(r2c3),
//		  r3c0(r3c0), r3c1(r3c1), r3c2(r3c2), r3c3(r3c3)
//	{
//	}
//
//	Matrix4x4::Matrix4x4(float diagonal)
//	{
//		memset(this, 0, sizeof(Matrix4x4));
//		r0c0 = r1c1 = r2c2 = r3c3 = diagonal;
//	}
//
//	Matrix4x4 Matrix4x4::FromRows(const Vector4D& firstRow, const Vector4D& secondRow, const Vector4D& thirdRow, const Vector4D& fourthRow)
//	{
//		return Matrix4x4(
//			firstRow.x, firstRow.y, firstRow.z, firstRow.w,
//			secondRow.x, secondRow.y, secondRow.z, secondRow.w,
//			thirdRow.x, thirdRow.y, thirdRow.z, thirdRow.w,
//			fourthRow.x, fourthRow.y, fourthRow.z, fourthRow.w);
//	}
//
//	Matrix4x4 Matrix4x4::FromColumns(const Vector4D& firstColumn, const Vector4D& secondColumn, const Vector4D& thirdColumn, const Vector4D& fourthColumn)
//	{
//		return Matrix4x4(
//			firstColumn.x, secondColumn.x, thirdColumn.x, fourthColumn.x,
//			firstColumn.y, secondColumn.y, thirdColumn.y, fourthColumn.y,
//			firstColumn.z, secondColumn.z, thirdColumn.z, fourthColumn.z,
//			firstColumn.w, secondColumn.w, thirdColumn.w, fourthColumn.w
//			);
//	}
//
//	Matrix4x4 Matrix4x4::Scale(float x, float y, float z)
//	{
//		return Matrix4x4(
//			x, 0, 0, 0,
//			0, y, 0, 0,
//			0, 0, z, 0,
//			0, 0, 0, 1);
//	}
//
//	Matrix4x4 Matrix4x4::Scale(const Vector3D& scale)
//	{
//		return Scale(scale.x, scale.y, scale.z);
//	}
//
//	Matrix4x4 Matrix4x4::Translate(float x, float y, float z)
//	{
//		return Matrix4x4(
//			0, 0, 0, x,
//			0, 0, 0, y,
//			0, 0, 0, z,
//			0, 0, 0, 1);
//	}
//
//	Matrix4x4 Matrix4x4::Translate(const Vector3D& translation)
//	{
//		return Translate(translation.x, translation.y, translation.z);
//	}
//
//	Matrix4x4 Matrix4x4::RotateX(const Angle& angle)
//	{
//		float cos = SMath::Cos(angle);
//		float sin = SMath::Sin(angle);
//
//		return Matrix4x4(
//			1, 0, 0, 0,
//			0, cos, -sin, 0,
//			0, sin, cos, 0,
//			0, 0, 0, 1);
//	}
//
//	Matrix4x4 Matrix4x4::RotateY(const Angle& angle)
//	{
//		float cos = SMath::Cos(angle);
//		float sin = SMath::Sin(angle);
//
//		return Matrix4x4(
//			cos, 0, sin, 0,
//			0, 1, 0, 0,
//			-sin, 0, cos, 0,
//			0, 0, 0, 1);
//	}
//
//	Matrix4x4 Matrix4x4::RotateZ(const Angle& angle)
//	{
//		float cos = SMath::Cos(angle);
//		float sin = SMath::Sin(angle);
//
//		return Matrix4x4(
//			cos, -sin, 0, 0,
//			sin, cos, 0, 0,
//			0, 0, 1, 0,
//			0, 0, 0, 1);
//	}
//
//	Matrix4x4 Matrix4x4::MultiplyComponentWise(const Matrix4x4& other) const
//	{
//		return Matrix4x4(
//			r0c0 * other.r0c0, r0c1 * other.r0c1, r0c2 * other.r0c2, r0c3 * other.r0c3,
//			r1c0 * other.r1c0, r1c1 * other.r1c1, r1c2 * other.r1c2, r1c3 * other.r1c3,
//			r2c0 * other.r2c0, r2c1 * other.r2c1, r2c2 * other.r2c2, r2c3 * other.r2c3,
//			r3c0 * other.r3c0, r3c1 * other.r3c1, r3c2 * other.r3c2, r3c3 * other.r3c3);
//	}
//
//	Matrix4x4 Matrix4x4::Multiply(const Matrix4x4& other) const
//	{
//		return Matrix4x4(
//			GetRow(0).Dot(other.GetColumn(0)), GetRow(0).Dot(other.GetColumn(1)), GetRow(0).Dot(other.GetColumn(2)), GetRow(0).Dot(other.GetColumn(3)),
//			GetRow(1).Dot(other.GetColumn(0)), GetRow(1).Dot(other.GetColumn(1)), GetRow(1).Dot(other.GetColumn(2)), GetRow(1).Dot(other.GetColumn(3)),
//			GetRow(2).Dot(other.GetColumn(0)), GetRow(2).Dot(other.GetColumn(1)), GetRow(2).Dot(other.GetColumn(2)), GetRow(2).Dot(other.GetColumn(3)),
//			GetRow(3).Dot(other.GetColumn(0)), GetRow(3).Dot(other.GetColumn(1)), GetRow(3).Dot(other.GetColumn(2)), GetRow(3).Dot(other.GetColumn(3)));
//	}
//
//	Matrix4x4 Matrix4x4::Multiply(float scalar) const
//	{
//		return Matrix4x4(
//			r0c0 * scalar, r0c1 * scalar, r0c2 * scalar, r0c3 * scalar,
//			r1c0 * scalar, r1c1 * scalar, r1c2 * scalar, r1c3 * scalar,
//			r2c0 * scalar, r2c1 * scalar, r2c2 * scalar, r2c3 * scalar,
//			r3c0 * scalar, r3c1 * scalar, r3c2 * scalar, r3c3 * scalar);
//	}
//
//	Matrix4x4 Matrix4x4::Divide(float scalar) const
//	{
//		return Matrix4x4(
//			r0c0 / scalar, r0c1 / scalar, r0c2 / scalar, r0c3 / scalar,
//			r1c0 / scalar, r1c1 / scalar, r1c2 / scalar, r1c3 / scalar,
//			r2c0 / scalar, r2c1 / scalar, r2c2 / scalar, r2c3 / scalar,
//			r3c0 / scalar, r3c1 / scalar, r3c2 / scalar, r3c3 / scalar);
//	}
//
//	Matrix4x4 Matrix4x4::Add(const Matrix4x4& other) const
//	{
//		return Matrix4x4(
//			r0c0 + other.r0c0, r0c1 + other.r0c1, r0c2 + other.r0c2, r0c3 + other.r0c3,
//			r1c0 + other.r1c0, r1c1 + other.r1c1, r1c2 + other.r1c2, r1c3 + other.r1c3,
//			r2c0 + other.r2c0, r2c1 + other.r2c1, r2c2 + other.r2c2, r2c3 + other.r2c3,
//			r3c0 + other.r3c0, r3c1 + other.r3c1, r3c2 + other.r3c2, r3c3 + other.r3c3);
//	}
//
//	Matrix4x4 Matrix4x4::Subtract(const Matrix4x4& other) const
//	{
//		return Matrix4x4(
//			r0c0 - other.r0c0, r0c1 - other.r0c1, r0c2 - other.r0c2, r0c3 - other.r0c3,
//			r1c0 - other.r1c0, r1c1 - other.r1c1, r1c2 - other.r1c2, r1c3 - other.r1c3,
//			r2c0 - other.r2c0, r2c1 - other.r2c1, r2c2 - other.r2c2, r2c3 - other.r2c3,
//			r3c0 - other.r3c0, r3c1 - other.r3c1, r3c2 - other.r3c2, r3c3 - other.r3c3);
//	}
//
//	Matrix4x4 Matrix4x4::Negated() const
//	{
//		return Matrix4x4(
//			-r0c0, -r0c1, -r0c2, -r0c3,
//			-r1c0, -r1c1, -r1c2, -r1c3,
//			-r2c0, -r2c1, -r2c2, -r2c3,
//			-r3c0, -r3c1, -r3c2, -r3c3);
//	}
//
//	Matrix4x4 Matrix4x4::Transposed() const
//	{
//		return Matrix4x4(
//			r0c0, r1c0, r2c0, r3c0,
//			r0c1, r1c1, r2c1, r3c1,
//			r0c2, r1c2, r2c2, r3c2,
//			r0c3, r1c3, r2c3, r3c3);
//	}
//
//	// TODO: Actually implement it when Matrix3x3 exists.
//	Matrix4x4 Matrix4x4::Minor() const
//	{
//		return Matrix4x4(1);
//		//return Matrix4x4(
//		//	// First row:
//		//	Matrix3x3(r1c1, r1c2, r1c3, r2c1, r2c2, r2c3, r3c1, r3c2, r3c3).Determinant(),
//		//	Matrix3x3(r1c0, r1c2, r1c3, r2c0, r2c2, r2c3, r3c0, r3c2, r3c3).Determinant(),
//		//	Matrix3x3(r1c0, r1c1, r1c3, r2c0, r2c1, r2c3, r3c0, r3c1, r3c3).Determinant(),
//		//	Matrix3x3(r1c0, r1c1, r1c2, r2c0, r2c1, r2c2, r3c0, r3c1, r3c2).Determinant(),
//		//
//		//	// Second row:
//		//	Matrix3x3(r0c1, r0c2, r0c3, r2c1, r2c2, r2c3, r3c1, r3c2, r3c3).Determinant(),
//		//	Matrix3x3(r0c0, r0c2, r0c3, r2c0, r2c2, r2c3, r3c0, r3c2, r3c3).Determinant(),
//		//	Matrix3x3(r0c0, r0c1, r0c3, r2c0, r2c1, r2c3, r3c0, r3c1, r3c3).Determinant(),
//		//	Matrix3x3(r0c0, r0c1, r0c2, r2c0, r2c1, r2c2, r3c0, r3c1, r3c2).Determinant(),
//		//
//		//	// Third row:
//		//	Matrix3x3(r0c1, r0c2, r0c3, r1c1, r1c2, r1c3, r3c1, r3c2, r3c3).Determinant(),
//		//	Matrix3x3(r0c0, r0c2, r0c3, r1c0, r1c2, r1c3, r3c0, r3c2, r3c3).Determinant(),
//		//	Matrix3x3(r0c0, r0c1, r0c3, r1c0, r1c1, r1c3, r3c0, r3c1, r3c3).Determinant(),
//		//	Matrix3x3(r0c0, r0c1, r0c2, r1c0, r1c1, r1c2, r3c0, r3c1, r3c2).Determinant(),
//		//
//		//	// Fourth row:
//		//	Matrix3x3(r0c1, r0c2, r0c3, r1c1, r1c2, r1c3, r2c1, r2c2, r2c3).Determinant(),
//		//	Matrix3x3(r0c0, r0c2, r0c3, r1c0, r1c2, r1c3, r2c0, r2c2, r2c3).Determinant(),
//		//	Matrix3x3(r0c0, r0c1, r0c3, r1c0, r1c1, r1c3, r2c0, r2c1, r2c3).Determinant(),
//		//	Matrix3x3(r0c0, r0c1, r0c2, r1c0, r1c1, r1c2, r2c0, r2c1, r2c2).Determinant()
//		//	);
//	}
//
//	Matrix4x4 Matrix4x4::Cofactor() const
//	{
//		return Minor().MultiplyComponentWise(Matrix4x4(
//			+1, -1, +1, -1,
//			-1, +1, -1, +1,
//			+1, -1, +1, -1,
//			-1, +1, -1, +1));
//	}
//
//	Matrix4x4 Matrix4x4::Abs() const
//	{
//		return new Matrix4x4(
//			SMath::Abs(r0c0), SMath::Abs(r0c1), SMath::Abs(r0c2), SMath::Abs(r0c3),
//			SMath::Abs(r1c0), SMath::Abs(r1c1), SMath::Abs(r1c2), SMath::Abs(r1c3),
//			SMath::Abs(r2c0), SMath::Abs(r2c1), SMath::Abs(r2c2), SMath::Abs(r2c3),
//			SMath::Abs(r3c0), SMath::Abs(r3c1), SMath::Abs(r3c2), SMath::Abs(r3c3));
//	}
//
//	float Matrix4x4::Determinant() const
//	{
//		throw std::runtime_error("TODO: Make the determinant actually do something.");
//		return 0;
//		//return
//		//	r0c0 * Matrix3x3(r1c1, r1c2, r1c3, r2c1, r2c2, r2c3, r3c1, r3c2, r3c3).Determinant -
//		//	r0c1 * Matrix3x3(r1c0, r1c2, r1c3, r2c0, r2c2, r2c3, r3c0, r3c2, r3c3).Determinant +
//		//	r0c2 * Matrix3x3(r1c0, r1c1, r1c3, r2c0, r2c1, r2c3, r3c0, r3c1, r3c3).Determinant -
//		//	r0c3 * Matrix3x3(r1c0, r1c1, r1c2, r2c0, r2c1, r2c2, r3c0, r3c1, r3c2).Determinant;
//	}
//
//	bool Matrix4x4::CloseEnough(const Matrix4x4& other, float threshold) const
//	{
//		for (int i = 0; i < 16; i++)
//		{
//			if (!SMath::CloseEnough(elements16[i], other.elements16[i], threshold))
//				return false;
//		}
//		return true;
//	}
//
//	bool Matrix4x4::Equals(const Matrix4x4& other) const
//	{
//		for (int i = 0; i < 16; i++)
//		{
//			if (elements16[i] != other.elements16[i])
//				return false;
//		}
//		return true;
//	}
//} }