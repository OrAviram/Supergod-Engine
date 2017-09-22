#include "Matrix4x4.h"
#include "../Vectors/Vector4D.h"
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

	Matrix4x4 Matrix4x4::FromRows(Vector4D firstRow, Vector4D secondRow, Vector4D thirdRow, Vector4D fourthRow)
	{
		return Matrix4x4(
			firstRow.x, firstRow.y, firstRow.z, firstRow.w,
			secondRow.x, secondRow.y, secondRow.z, secondRow.w,
			thirdRow.x, thirdRow.y, thirdRow.z, thirdRow.w,
			fourthRow.x, fourthRow.y, fourthRow.z, fourthRow.w);
	}

	Matrix4x4 Matrix4x4::FromColumns(Vector4D firstColumn, Vector4D secondColumn, Vector4D thirdColumn, Vector4D fourthColumn)
	{
		return Matrix4x4(
			firstColumn.x, secondColumn.x, thirdColumn.x, fourthColumn.x,
			firstColumn.y, secondColumn.y, thirdColumn.y, fourthColumn.y,
			firstColumn.z, secondColumn.z, thirdColumn.z, fourthColumn.z,
			firstColumn.w, secondColumn.w, thirdColumn.w, fourthColumn.w
			);
	}
} }