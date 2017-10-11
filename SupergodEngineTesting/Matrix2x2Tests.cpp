#include "TestUtils.h"

namespace SupergodEngineTesting
{
	using namespace Math;
	
	TEST_CLASS(Matrix2x2Tests)
	{
	public:
		TEST_METHOD(ConstructorTest)
		{
			Matrix2x2 matrix = Matrix2x2(1, 3, 2, -1);
			Assert::IsTrue(matrix.r0c0 == 1 && matrix.r0c1 == 3 && matrix.r1c0 == 2 && matrix.r1c1 == -1);

			matrix = Matrix2x2(.5f, 1, 0, 0);
			Assert::IsTrue(matrix.r0c0 == .5f && matrix.r0c1 == 1 && matrix.r1c0 == 0 && matrix.r1c1 == 0);

			matrix = Matrix2x2(1);
			Assert::IsTrue(
				matrix.r0c0 == Matrix2x2::Identity().r0c0 && matrix.r0c1 == Matrix2x2::Identity().r0c1
				&& matrix.r1c0 == Matrix2x2::Identity().r1c0 && matrix.r1c1 == Matrix2x2::Identity().r1c1);

			matrix = Matrix2x2();
			Assert::IsTrue(
				matrix.r0c0 == Matrix2x2::Zero().r0c0 && matrix.r0c1 == Matrix2x2::Zero().r0c1
				&& matrix.r1c0 == Matrix2x2::Zero().r1c0 && matrix.r1c1 == Matrix2x2::Zero().r1c1);

			matrix = Matrix2x2::FromRows(Vector2D(1, 3), Vector2D(2, -1));
			Assert::IsTrue(matrix.r0c0 == 1 && matrix.r0c1 == 3 && matrix.r1c0 == 2 && matrix.r1c1 == -1);
			
			matrix = Matrix2x2::FromColumns(Vector2D(1, 3), Vector2D(2, -1));
			Assert::IsTrue(matrix.r0c0 == 1 && matrix.r0c1 == 2 && matrix.r1c0 == 3 && matrix.r1c1 == -1);
		}

		TEST_METHOD(EqualityTests)
		{
			Assert::IsTrue(Matrix2x2(0, 1, 0, 1) == Matrix2x2(0, 1, 0, 1));
			Assert::IsFalse(Matrix2x2(0, 1, 0, 1) == Matrix2x2(1, 0, 1, 0));
			Assert::IsTrue(Matrix2x2(0, 4, 2, 1).Equals(Matrix2x2(0, 4, 2, 1)));
			Assert::IsFalse(Matrix2x2(0, 0, 1, 1).Equals(Matrix2x2(0, 1, 0, 0)));
			Assert::IsFalse(Matrix2x2(0, 1, 1, 1).Equals(1));

			Assert::IsTrue(Matrix2x2(1, 1, 1, 1) != Matrix2x2());
			Assert::IsFalse(Matrix2x2(1, 1, 1, 1) != Matrix2x2(1, 1, 1, 1));

			Matrix2x2 a = Matrix2x2(1, 2, 3, 4);
			Matrix2x2 b = Matrix2x2(4, 3, .2f, -.1f);
			Assert::IsFalse(a.CloseEnough(b));
			Assert::IsFalse(SupergodEquatable::CloseEnough(a, b));

			a = Matrix2x2(1, 2, 3, 4);
			b = Matrix2x2(1, 2, 3, 4);
			Assert::IsTrue(a.CloseEnough(b));
			Assert::IsTrue(SupergodEquatable::CloseEnough(a, b));

			a = Matrix2x2(1, 2, 3, 4);
			b = Matrix2x2(2, 3, 4, 5);
			Assert::IsFalse(a.CloseEnough(b));
			Assert::IsFalse(SupergodEquatable::CloseEnough(a, b));
			Assert::IsTrue(a.CloseEnough(b, 1));
			Assert::IsTrue(SupergodEquatable::CloseEnough(a, b, 1));
		}

		#pragma region Getters and setters.
		TEST_METHOD(IndexerTest)
		{
			Matrix2x2 getTest = Matrix2x2(3, 1, .4f, 2);
			Assert::IsTrue(getTest(0, 0) == 3);
			Assert::IsTrue(getTest(0, 1) == 1);
			Assert::IsTrue(getTest(1, 0) == .4f);
			Assert::IsTrue(getTest(1, 1) == 2);

			Matrix2x2 setTest = Matrix2x2();
			for (int row = 0; row < 2; row++)
			{
				for (int column = 0; column < 2; column++)
				{
					setTest(row, column) = (float)row * (float)column;
				}
			}
			Assert::IsTrue(setTest == Matrix2x2(0, 0, 0, 1));

			for (int row = 0; row < 2; row++)
			{
				for (int column = 0; column < 2; column++)
				{
					setTest(row, column) = 5;
				}
			}
			Assert::IsTrue(setTest == Matrix2x2(5, 5, 5, 5));
		}

		TEST_METHOD(GettersAndSettersTests)
		{
			Matrix2x2 matrix = Matrix2x2();

			matrix.GetRow(0) = Vector2D(2, 3);
			AssertUtils::AreEqual(matrix.GetRow(0), Vector2D(2, 3));
			Assert::AreEqual(matrix.r0c0, 2.f);
			Assert::AreEqual(matrix.r0c1, 3.f);
			Assert::AreEqual(matrix.r1c0, 0.f);
			Assert::AreEqual(matrix.r1c1, 0.f);

			matrix.GetRow(1) = Vector2D(4, 5);
			AssertUtils::AreEqual(matrix.GetRow(1), Vector2D(4, 5));
			Assert::AreEqual(matrix.r0c0, 2.f);
			Assert::AreEqual(matrix.r0c1, 3.f);
			Assert::AreEqual(matrix.r1c0, 4.f);
			Assert::AreEqual(matrix.r1c1, 5.f);

			matrix.SetColumn(0, Vector2D(6, 7));
			AssertUtils::AreEqual(matrix.GetColumn(0), Vector2D(6, 7));
			Assert::AreEqual(matrix.r0c0, 6.f);
			Assert::AreEqual(matrix.r1c0, 7.f);
			Assert::AreEqual(matrix.r0c1, 3.f);
			Assert::AreEqual(matrix.r1c1, 5.f);

			matrix.SetColumn(1, Vector2D(8, 9));
			AssertUtils::AreEqual(matrix.GetColumn(1), Vector2D(8, 9));
			Assert::AreEqual(matrix.r0c0, 6.f);
			Assert::AreEqual(matrix.r1c0, 7.f);
			Assert::AreEqual(matrix.r0c1, 8.f);
			Assert::AreEqual(matrix.r1c1, 9.f);
		}
		#pragma endregion
	};
}