#pragma once

#include "Common/CommonDefines.h"
#include "IMatrix.h"

namespace SupergodCore { namespace Math
{
	struct Vector4D;

	/// <summary>
	/// Represents a 4 by 4 mathematical matrix.
	/// </summary>
	struct SUPERGOD_API Matrix4x4 final
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

		/// <summary>
		/// Creates a new matrix with vectors for the rows.
		/// </summary>
		static Matrix4x4 FromRows(
			Vector4D firstRow,
			Vector4D secondRow,
			Vector4D thirdRow,
			Vector4D fourthRow);

		/// <summary>
		/// Creates a new matrix with vectors for the columns.
		/// </summary>
		static Matrix4x4 FromColumns(
			Vector4D firstColumn,
			Vector4D secondColumn,
			Vector4D thirdColumn,
			Vector4D fourthColumn);
	};
} }