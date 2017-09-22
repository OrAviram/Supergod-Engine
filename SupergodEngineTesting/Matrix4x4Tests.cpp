#include "TestUtils.h"

namespace SupergodEngineTesting
{
	using namespace Math;

	TEST_CLASS(Matrix4x4Tests)
	{
	public:
		// I still don't have equality methods for matrix, so this is a utility method to check for that.
		void CheckMatrixEquality(const Matrix4x4& a, const Matrix4x4& b)
		{
			for (int i = 0; i < 16; i++)
			{
				Assert::AreEqual(a.elements16[i], b.elements16[i]);
			}
		}

		TEST_METHOD(ConstructorTest)
		{
			Matrix4x4 test1(
				1, 2, 3, 4,
				5, 6, 7, 8,
				9, 10, 11, 12,
				13, 14, 15, 16);

			Matrix4x4 test2 = Matrix4x4::FromRows(
				Vector4D(1, 2, 3, 4),
				Vector4D(5, 6, 7, 8),
				Vector4D(9, 10, 11, 12),
				Vector4D(13, 14, 15, 16));

			CheckMatrixEquality(test1, test2);

			Assert::AreEqual(test1.r0c0, 1.f);
			Assert::AreEqual(test1.r0c1, 2.f);
			Assert::AreEqual(test1.r0c2, 3.f);
			Assert::AreEqual(test1.r0c3, 4.f);

			Assert::AreEqual(test1.r1c0, 5.f);
			Assert::AreEqual(test1.r1c1, 6.f);
			Assert::AreEqual(test1.r1c2, 7.f);
			Assert::AreEqual(test1.r1c3, 8.f);

			Assert::AreEqual(test1.r2c0, 9.f);
			Assert::AreEqual(test1.r2c1, 10.f);
			Assert::AreEqual(test1.r2c2, 11.f);
			Assert::AreEqual(test1.r2c3, 12.f);

			Assert::AreEqual(test1.r3c0, 13.f);
			Assert::AreEqual(test1.r3c1, 14.f);
			Assert::AreEqual(test1.r3c2, 15.f);
			Assert::AreEqual(test1.r3c3, 16.f);

			TestMultiple(10, [&](int index)
			{
				float value = RandFloat(-10, 10);
				Matrix4x4 test3(value);
				for (int row = 0; row < 4; row++)
				{
					for (int column = 0; column < 4; column++)
					{
						if (column == row)
							Assert::AreEqual(test3.elements4x4[row][column], value);
						else
							Assert::AreEqual(test3.elements4x4[row][column], 0.f);
					}
				}
			});
			CheckMatrixEquality(Matrix4x4(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), Matrix4x4());
		}
	};
}