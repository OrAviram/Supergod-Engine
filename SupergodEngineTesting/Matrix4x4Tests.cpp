// TODO: Bring back this when Matrix3x3 and Matrix2x2 exist.

//#include "TestUtils.h"
//
//namespace SupergodEngineTesting
//{
//	using namespace Math;
//
//	TEST_CLASS(Matrix4x4Tests)
//	{
//	public:
//		TEST_METHOD(ConstructorTest)
//		{
//			Matrix4x4 test1(
//				1, 2, 3, 4,
//				5, 6, 7, 8,
//				9, 10, 11, 12,
//				13, 14, 15, 16);
//
//			Matrix4x4 test2 = Matrix4x4::FromRows(
//				Vector4D(1, 2, 3, 4),
//				Vector4D(5, 6, 7, 8),
//				Vector4D(9, 10, 11, 12),
//				Vector4D(13, 14, 15, 16));
//
//			AssertUtils::AreEqual(test1, test2);
//
//			Assert::AreEqual(test1.r0c0, 1.f);
//			Assert::AreEqual(test1.r0c1, 2.f);
//			Assert::AreEqual(test1.r0c2, 3.f);
//			Assert::AreEqual(test1.r0c3, 4.f);
//
//			Assert::AreEqual(test1.r1c0, 5.f);
//			Assert::AreEqual(test1.r1c1, 6.f);
//			Assert::AreEqual(test1.r1c2, 7.f);
//			Assert::AreEqual(test1.r1c3, 8.f);
//
//			Assert::AreEqual(test1.r2c0, 9.f);
//			Assert::AreEqual(test1.r2c1, 10.f);
//			Assert::AreEqual(test1.r2c2, 11.f);
//			Assert::AreEqual(test1.r2c3, 12.f);
//
//			Assert::AreEqual(test1.r3c0, 13.f);
//			Assert::AreEqual(test1.r3c1, 14.f);
//			Assert::AreEqual(test1.r3c2, 15.f);
//			Assert::AreEqual(test1.r3c3, 16.f);
//
//			TestMultiple(10, [&](int index)
//			{
//				float value = RandFloat(-10, 10);
//				Matrix4x4 test3(value);
//				for (int row = 0; row < 4; row++)
//				{
//					for (int column = 0; column < 4; column++)
//					{
//						if (column == row)
//							Assert::AreEqual(test3.elements4x4[row][column], value);
//						else
//							Assert::AreEqual(test3.elements4x4[row][column], 0.f);
//					}
//				}
//			});
//			AssertUtils::AreEqual(Matrix4x4(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), Matrix4x4());
//		}
//
//		TEST_METHOD(EqualityTests)
//		{
//			Assert::IsTrue(Matrix4x4(10, 10, 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0) == Matrix4x4(10, 10, 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
//			Assert::IsFalse(Matrix4x4(10, 10, 2, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0) == Matrix4x4(10, 10, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
//			Assert::IsTrue(Matrix4x4(10, 10, 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0).Equals(Matrix4x4(10, 10, 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)));
//			Assert::IsFalse(Matrix4x4(10, 10, 2, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0).Equals(Matrix4x4(10, 10, 2, 442, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)));
//		
//			Assert::IsFalse(Matrix4x4(10, 10, 1, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0) != Matrix4x4(10, 10, 1, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
//			Assert::IsTrue(Matrix4x4(10, 10, 1, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0) != Matrix4x4(10, 10, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
//		
//			Matrix4x4 first(
//				1, 2, 3, 4,
//				5, 6, 7, 8,
//				9, 10, 11, 12,
//				13, 14, 15, 16
//				);
//
//			Matrix4x4 second(
//				1, 2, 3, 4,
//				5, 6, 7, 8,
//				9, 10, 11, 12,
//				13, 14, 15, 17
//				);
//
//			Assert::IsTrue(first.CloseEnough(second, 1.f));
//			Assert::IsFalse(first.CloseEnough(second, .5f));
//		}
//
//		// TODO: TEST THE TRANSFORMATIONS. I just kinda forgot I needed multiplication for that, so I already added the actual methods...
//		#pragma region Transformation tests.
//		#pragma endregion
//	};
//}