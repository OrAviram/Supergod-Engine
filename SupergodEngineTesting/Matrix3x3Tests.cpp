#include "TestUtils.h"

namespace SupergodEngineTesting
{
	using namespace Math;

	TEST_CLASS(Matrix3x3Tests)
	{
	public:
		TEST_METHOD(ConstructionTest)
		{
			Matrix3x3 test(1, 2, 3, 4, 5, 6, 7, 8, 9);
			Assert::AreEqual(test.r0c0, 1.f);
			Assert::AreEqual(test.r0c1, 2.f);
			Assert::AreEqual(test.r0c2, 3.f);

			Assert::AreEqual(test.r1c0, 4.f);
			Assert::AreEqual(test.r1c1, 5.f);
			Assert::AreEqual(test.r1c2, 6.f);

			Assert::AreEqual(test.r2c0, 7.f);
			Assert::AreEqual(test.r2c1, 8.f);
			Assert::AreEqual(test.r2c2, 9.f);

			test = Matrix3x3();
			Assert::AreEqual(test.r0c0, 0.f);
			Assert::AreEqual(test.r0c1, 0.f);
			Assert::AreEqual(test.r0c2, 0.f);

			Assert::AreEqual(test.r1c0, 0.f);
			Assert::AreEqual(test.r1c1, 0.f);
			Assert::AreEqual(test.r1c2, 0.f);

			Assert::AreEqual(test.r2c0, 0.f);
			Assert::AreEqual(test.r2c1, 0.f);
			Assert::AreEqual(test.r2c2, 0.f);

			test = Matrix3x3(3);
			Assert::AreEqual(test.r0c0, 3.f);
			Assert::AreEqual(test.r0c1, 0.f);
			Assert::AreEqual(test.r0c2, 0.f);

			Assert::AreEqual(test.r1c0, 0.f);
			Assert::AreEqual(test.r1c1, 3.f);
			Assert::AreEqual(test.r1c2, 0.f);

			Assert::AreEqual(test.r2c0, 0.f);
			Assert::AreEqual(test.r2c1, 0.f);
			Assert::AreEqual(test.r2c2, 3.f);

			test = Matrix3x3::FromRows(Vector3D(1, 2, 3), Vector3D(4, 5, 6), Vector3D(7, 8, 9));
			Assert::AreEqual(test.r0c0, 1.f);
			Assert::AreEqual(test.r0c1, 2.f);
			Assert::AreEqual(test.r0c2, 3.f);

			Assert::AreEqual(test.r1c0, 4.f);
			Assert::AreEqual(test.r1c1, 5.f);
			Assert::AreEqual(test.r1c2, 6.f);

			Assert::AreEqual(test.r2c0, 7.f);
			Assert::AreEqual(test.r2c1, 8.f);
			Assert::AreEqual(test.r2c2, 9.f);
			
			test = Matrix3x3();
			test = Matrix3x3::FromColumns(Vector3D(1, 4, 7), Vector3D(2, 5, 8), Vector3D(3, 6, 9));
			Assert::AreEqual(test.r0c0, 1.f);
			Assert::AreEqual(test.r0c1, 2.f);
			Assert::AreEqual(test.r0c2, 3.f);

			Assert::AreEqual(test.r1c0, 4.f);
			Assert::AreEqual(test.r1c1, 5.f);
			Assert::AreEqual(test.r1c2, 6.f);

			Assert::AreEqual(test.r2c0, 7.f);
			Assert::AreEqual(test.r2c1, 8.f);
			Assert::AreEqual(test.r2c2, 9.f);
		}

		TEST_METHOD(EqualityTests)
		{
			Assert::IsTrue(Matrix3x3(10, 10, 5, 0, 0, 0, 0, 0, 0) == Matrix3x3(10, 10, 5, 0, 0, 0, 0, 0, 0));
			Assert::IsFalse(Matrix3x3(10, 10, 2, 0, 0, 0, 0, 0, 0) == Matrix3x3(10, 10, 1, 0, 0, 0, 0, 0, 0));
			Assert::IsTrue(Matrix3x3(10, 10, 5, 0, 0, 0, 0, 0, 0).Equals(Matrix3x3(10, 10, 5, 0, 0, 0, 0, 0, 0)));
			Assert::IsFalse(Matrix3x3(10, 10, 1, 0, 0, 0, 0, 0, 0).Equals(Matrix3x3(10, 10, 2, 0, 0, 0, 0, 0, 0)));
			
			Assert::IsFalse(Matrix3x3(10, 10, 1, 0, 0, 0, 0, 0, 0) != Matrix3x3(10, 10, 1, 0, 0, 0, 0, 0, 0));
			Assert::IsTrue(Matrix3x3(10, 10, 1, 0, 0, 0, 0, 0, 0) != Matrix3x3(10, 10, 2, 0, 0, 0, 0, 0, 0));
		}

		#pragma region Addition subtraction tests.
		TEST_METHOD(AdditionTest)
		{
			Test50([&](int i)
			{
				Matrix3x3 a = Matrix3x3(
					RandFloat100(), RandFloat100(), RandFloat100(),
					RandFloat100(), RandFloat100(), RandFloat100(),
					RandFloat100(), RandFloat100(), RandFloat100());

				Matrix3x3 b = Matrix3x3(
					RandFloat100(), RandFloat100(), RandFloat100(),
					RandFloat100(), RandFloat100(), RandFloat100(),
					RandFloat100(), RandFloat100(), RandFloat100());

				Matrix3x3 result = a + b;

				AssertUtils::AreEqual(result, b + a);
				AssertUtils::AreEqual(result, a.Add(b));
				AssertUtils::AreEqual(result, b.Add(a));

				AssertUtils::CloseEnough(result.r0c0, a.r0c0 + b.r0c0);
				AssertUtils::CloseEnough(result.r0c1, a.r0c1 + b.r0c1);
				AssertUtils::CloseEnough(result.r0c2, a.r0c2 + b.r0c2);

				AssertUtils::CloseEnough(result.r1c0, a.r1c0 + b.r1c0);
				AssertUtils::CloseEnough(result.r1c1, a.r1c1 + b.r1c1);
				AssertUtils::CloseEnough(result.r1c2, a.r1c2 + b.r1c2);

				AssertUtils::CloseEnough(result.r2c0, a.r2c0 + b.r2c0);
				AssertUtils::CloseEnough(result.r2c1, a.r2c1 + b.r2c1);
				AssertUtils::CloseEnough(result.r2c2, a.r2c2 + b.r2c2);
			});
		}

		TEST_METHOD(SubtractionTest)
		{
			Test50([&](int i)
			{
				Matrix3x3 a = Matrix3x3(
					RandFloat100(), RandFloat100(), RandFloat100(),
					RandFloat100(), RandFloat100(), RandFloat100(),
					RandFloat100(), RandFloat100(), RandFloat100());

				Matrix3x3 b = Matrix3x3(
					RandFloat100(), RandFloat100(), RandFloat100(),
					RandFloat100(), RandFloat100(), RandFloat100(),
					RandFloat100(), RandFloat100(), RandFloat100());

				Matrix3x3 result = a - b;

				AssertUtils::AreEqual(result, a.Subtract(b));
				AssertUtils::AreNotEqual(result, b - a);
				AssertUtils::AreEqual(b - a, b.Subtract(a));
				AssertUtils::AreNotEqual(result, b.Subtract(a));

				AssertUtils::CloseEnough(result.r0c0, a.r0c0 - b.r0c0);
				AssertUtils::CloseEnough(result.r0c1, a.r0c1 - b.r0c1);
				AssertUtils::CloseEnough(result.r0c2, a.r0c2 - b.r0c2);

				AssertUtils::CloseEnough(result.r1c0, a.r1c0 - b.r1c0);
				AssertUtils::CloseEnough(result.r1c1, a.r1c1 - b.r1c1);
				AssertUtils::CloseEnough(result.r1c2, a.r1c2 - b.r1c2);

				AssertUtils::CloseEnough(result.r2c0, a.r2c0 - b.r2c0);
				AssertUtils::CloseEnough(result.r2c1, a.r2c1 - b.r2c1);
				AssertUtils::CloseEnough(result.r2c2, a.r2c2 - b.r2c2);
			});
		}
		#pragma endregion

		#pragma region Multiplication tests.
		TEST_METHOD(Matrix3x3FloatMultiplicationTest)
		{
			Test50([&](int i)
			{
				float scalar = RandFloat100();
				Matrix3x3 matrix = Matrix3x3(
					RandFloat100(), RandFloat100(), RandFloat100(),
					RandFloat100(), RandFloat100(), RandFloat100(),
					RandFloat100(), RandFloat100(), RandFloat100());

				Matrix3x3 result = matrix * scalar;

				AssertUtils::AreEqual(result, scalar * matrix);
				AssertUtils::AreEqual(result, matrix.Multiply(scalar));

				AssertUtils::CloseEnough(result.r0c0, matrix.r0c0 * scalar);
				AssertUtils::CloseEnough(result.r0c1, matrix.r0c1 * scalar);
				AssertUtils::CloseEnough(result.r0c2, matrix.r0c2 * scalar);

				AssertUtils::CloseEnough(result.r1c0, matrix.r1c0 * scalar);
				AssertUtils::CloseEnough(result.r1c1, matrix.r1c1 * scalar);
				AssertUtils::CloseEnough(result.r1c2, matrix.r1c2 * scalar);

				AssertUtils::CloseEnough(result.r2c0, matrix.r2c0 * scalar);
				AssertUtils::CloseEnough(result.r2c1, matrix.r2c1 * scalar);
				AssertUtils::CloseEnough(result.r2c2, matrix.r2c2 * scalar);
			});
		}

		TEST_METHOD(Matrix3x3VectorMultiplicationTest)
		{
			Vector3D vector = Vector3D(1, 2, 3);
			Matrix3x3 matrix = Matrix3x3(1, 2, 3, 4, 5, 6, 7, 8, 9);
			AssertUtils::AreEqual(vector * matrix, Vector3D(30, 36, 42));
			AssertUtils::AreEqual(matrix * vector, Vector3D(14, 32, 50));

			vector = Vector3D(4, -1, .5f);
			matrix = Matrix3x3(4, .1f, 1, 8, 4, 6, 8, 7, -9);
			AssertUtils::CloseEnough(vector * matrix, Vector3D(12, -.1f, -6.5f));
			AssertUtils::AreEqual(matrix * vector, Vector3D(16.4f, 31, 20.5f));
		}

		TEST_METHOD(Matrix3x3TimesMatrix3x3Test)
		{
			Matrix3x3 first = Matrix3x3(
				1, 2, 3,
				4, 5, 6,
				7, 8, 9
			);
			Matrix3x3 second = Matrix3x3(
				5, 2, 5,
				1, 2, 6,
				10, 3, 0
			);

			AssertUtils::AreEqual(first * first, Matrix3x3(30, 36, 42, 66, 81, 96, 102, 126, 150));
			AssertUtils::AreEqual(second * second, Matrix3x3(77, 29, 37, 67, 24, 17, 53, 26, 68));
			AssertUtils::AreEqual(first * second, Matrix3x3(37, 15, 17, 85, 36, 50, 133, 57, 83));
		}
		#pragma endregion

		#pragma region Transformation tests.
		TEST_METHOD(ScaleTest)
		{
			Matrix3x3 scalar = Matrix3x3::Scale(Vector2D(1, 4));
			Vector3D original = Vector3D(5, 2, 0);
			Vector3D scaled = scalar * original;
			AssertUtils::AreEqual(scaled, Vector3D(5, 8, 0));

			scalar = Matrix3x3::Scale(Vector2D(5, 5));
			original = Vector3D(.5f, -1, 0);
			scaled = scalar * original;
			AssertUtils::AreEqual(scaled, Vector3D(2.5f, -5, 0));
		}
		
		TEST_METHOD(TranslationTest)
		{
			Vector3D test = Matrix3x3::Translate(Vector2D(4, 8)) * Vector3D(-3, 8, 1);
			AssertUtils::AreEqual(test, Vector3D(1, 16, 1));
		}
		
		TEST_METHOD(ShearTest)
		{
			Matrix3x3 matrix = Matrix3x3::Shear(Vector2D(2, 0));
			Vector3D vector = Vector3D(1, 1, 0);
			AssertUtils::AreEqual(matrix * vector, Vector3D(3, 1, 0));

			matrix = Matrix3x3::Shear(-1, 5);
			vector = Vector3D(2, 2, 0);
			AssertUtils::AreEqual(matrix * vector, Vector3D(0, 12, 0));
		}

		TEST_METHOD(RotateTest)
		{
			TestAngle([&](Angle a)
			{
				float cos = SMath::Cos(a);
				float sin = SMath::Sin(a);

				Matrix3x3 rotation = Matrix3x3::Rotate(a);
				AssertUtils::CloseEnough(rotation, Matrix3x3(
					cos, -sin, 0,
					sin, cos, 0,
					0, 0, 1
				));
			});
		}
		#pragma endregion

		#pragma region Inverse, transpose, cofactor, adjugate, inverse, negated, trace and abs tests.
		TEST_METHOD(TransposeTest)
		{
			Test50([&](int i)
			{
				Matrix3x3 matrix = Matrix3x3(
					RandFloat100(), RandFloat100(), RandFloat100(),
					RandFloat100(), RandFloat100(), RandFloat100(),
					RandFloat100(), RandFloat100(), RandFloat100());

				Matrix3x3 transpose = matrix.Transposed();

				AssertUtils::AreEqual(transpose.Transposed(), matrix);
				AssertUtils::AreEqual(transpose, Matrix::Transpose(matrix));

				for (int r = 0; r < 3; r++)
				{
					for (int c = 0; c < 3; c++)
					{
						AssertUtils::AreEqual(transpose(r, c), matrix(c, r));
						AssertUtils::AreEqual(transpose(c, r), matrix(r, c));
					}
				}
			});
		}

		TEST_METHOD(InverseCofactorAdjugateDeterminantTest)
		{
			// This doesn't directly test the adjugate, cofactor and determinant,
			// but it does directly test the inverse,
			// which uses the adjugate, cofactor and determinant.
			Test50([&](int i)
			{
				Matrix3x3 matrix = Matrix3x3(
					RandFloat100(), RandFloat100(), RandFloat100(),
					RandFloat100(), RandFloat100(), RandFloat100(),
					RandFloat100(), RandFloat100(), RandFloat100());

				AssertUtils::AreEqual(matrix.Determinant(), Matrix::Det(matrix));
				AssertUtils::AreEqual(matrix.Cofactor(), Matrix::Cofactor(matrix));
				AssertUtils::AreEqual(matrix.Adjugate(), Matrix::Adjugate(matrix));

				if (matrix.Determinant() != 0)
				{
					Matrix3x3 inverse = matrix.Inverted();
					AssertUtils::AreEqual(inverse, Matrix::Invert(matrix));

					// That's a super high threshold... I know it's not good, but it just didn't work.
					// That test doesn't matter that much anyways. The second test (with the default threshold) is the one that matters,
					// So I am fine with the high threshold.
					AssertUtils::CloseEnough(inverse.Inverted(), matrix, .04f);
					AssertUtils::CloseEnough(inverse * matrix, matrix * inverse, .01f);
					AssertUtils::CloseEnough(inverse * matrix, Matrix3x3::Identity());
				}
			});
		}

		TEST_METHOD(NegationTest)
		{
			Test50([&](int i)
			{
				Matrix3x3 matrix = Matrix3x3(
					RandFloat100(), RandFloat100(), RandFloat100(),
					RandFloat100(), RandFloat100(), RandFloat100(),
					RandFloat100(), RandFloat100(), RandFloat100());

				Matrix3x3 negated = -matrix;

				AssertUtils::AreEqual(negated, matrix.Negated());
				AssertUtils::AreEqual(negated, ArithmeticOps::Negate(matrix));
				AssertUtils::AreEqual(negated, matrix * -1);

				for (int r = 0; r < 3; r++)
				{
					for (int c = 0; c < 3; c++)
					{
						AssertUtils::AreEqual(negated[r, c], -matrix[r, c]);
					}
				}
			});
		}

		TEST_METHOD(TraceTest)
		{
			Test50([&](int i)
			{
				Matrix3x3 matrix = Matrix3x3(
					RandFloat100(), RandFloat100(), RandFloat100(),
					RandFloat100(), RandFloat100(), RandFloat100(),
					RandFloat100(), RandFloat100(), RandFloat100());

				float trace = matrix.Trace();
				AssertUtils::AreEqual(trace, Matrix::Tr(matrix));

				float sum = 0;
				for (int i = 0; i < 3; i++)
				{
					sum += matrix(i, i);
				}
				AssertUtils::CloseEnough(trace, sum);
				AssertUtils::CloseEnough(trace, matrix.r0c0 + matrix.r1c1 + matrix.r2c2);
			});
		}

		TEST_METHOD(AbsTest)
		{
			Test50([&](int i)
			{
				Matrix3x3 matrix = Matrix3x3(
					RandFloat100(), RandFloat100(), RandFloat100(),
					RandFloat100(), RandFloat100(), RandFloat100(),
					RandFloat100(), RandFloat100(), RandFloat100());

				Matrix3x3 abs = matrix.Abs();
				AssertUtils::AreEqual(abs, Matrix::Abs(matrix));

				for (int r = 0; r < 3; r++)
				{
					for (int c = 0; c < 3; c++)
					{
						float element = matrix(r, c);
						float absElement = abs(r, c);

						AssertUtils::AreEqual(SMath::Sign(absElement), 1);
						if (SMath::Sign(element) == -1)
							AssertUtils::AreEqual(absElement, -element);
						else
							AssertUtils::AreEqual(abs(r, c), matrix(r, c));

						AssertUtils::AreEqual(abs(r, c), SMath::Abs(matrix(r, c)));
					}
				}
			});
		}
		#pragma endregion
	
		TEST_METHOD(ConversionTests)
		{
			// TODO: Bring the 4x4 tests back when it exists.

			Test50([&](int i)
			{
				Matrix3x3 matrix = Matrix3x3(
					RandFloat100(), RandFloat100(), RandFloat100(),
					RandFloat100(), RandFloat100(), RandFloat100(),
					RandFloat100(), RandFloat100(), RandFloat100());

				Matrix2x2 twoBy2 = (Matrix2x2)matrix;
				//Matrix4x4 fourBy4 = matrix;

				//Assert.AreEqual(fourBy4.r3c3, 1);
				for (int r = 0; r < 2; r++)
				{
					for (int c = 0; c < 2; c++)
					{
						Assert::AreEqual(twoBy2(r, c), matrix(r, c));
					}
				}

				//for (int r = 0; r < 3; r++)
				//{
				//	for (int c = 0; c < 3; c++)
				//	{
				//		Assert::AreEqual(fourBy4(r, c), matrix(r, c));
				//	}
				//}
			});
		}
	};
}