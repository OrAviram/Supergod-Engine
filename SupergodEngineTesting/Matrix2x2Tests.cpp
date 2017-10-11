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

		#pragma region Basic math operation tests.
		TEST_METHOD(MultiplicationTest)
		{
			Matrix2x2 a = Matrix2x2(
				2, 34,
				-1, 10);

			Matrix2x2 b = Matrix2x2(
				2, -2,
				.3f, 32.3f);

			Matrix2x2 result1 = a * b;
			Matrix2x2 result2 = b * a;

			AssertUtils::AreNotEqual(result1, result2);
			AssertUtils::CloseEnough(result1, Matrix2x2(14.2f, 1094.2f, 1, 325));
			AssertUtils::CloseEnough(result2, Matrix2x2(6, 48, -31.7f, 333.2f));

			AssertUtils::AreEqual(result1, a.Multiply(b));
			AssertUtils::AreEqual(result1, Matrix::Multiply(a, b));

			AssertUtils::AreEqual(result2, b.Multiply(a));
			AssertUtils::AreEqual(result2, Matrix::Multiply(b, a));
		}

		TEST_METHOD(ScalarMultiplicationTest)
		{
			Matrix2x2 matrix = Matrix2x2(3, -1, 2, 10);
			float scalar = 3.5f;
			Matrix2x2 result = matrix * scalar;

			AssertUtils::AreEqual(result, Matrix2x2(10.5f, -3.5f, 7, 35));
			AssertUtils::AreEqual(result, scalar * matrix);
			AssertUtils::AreEqual(result, ArithmeticOps::Multiply(matrix, scalar));
			AssertUtils::AreEqual(result, matrix.Multiply(scalar));

			matrix = Matrix2x2(4, -322, 1, -1.5f);
			scalar = -2;
			result = matrix * scalar;

			AssertUtils::AreEqual(result, Matrix2x2(-8, 644, -2, 3));
			AssertUtils::AreEqual(result, scalar * matrix);
			AssertUtils::AreEqual(result, ArithmeticOps::Multiply(matrix, scalar));
			AssertUtils::AreEqual(result, matrix.Multiply(scalar));
		}

		TEST_METHOD(VectorMatrixMultiplicationTest)
		{
			Vector2D vector = Vector2D(3, 2);
			Matrix2x2 matrix = Matrix2x2(0, 1, -4, .5f);
			AssertUtils::AreEqual(vector * matrix, Vector2D(-8, 4));

			AssertUtils::AreEqual(matrix * vector, Vector2D(2, -11));
			AssertUtils::AreEqual(matrix.Multiply(vector), Vector2D(2, -11));

			vector = Vector2D(0, .5f);
			matrix = Matrix2x2(2, 1, 5, -1);
			AssertUtils::AreEqual(vector * matrix, Vector2D(2.5f, -.5f));
			AssertUtils::AreEqual(matrix * vector, Vector2D(.5f, -.5f));
		}

		TEST_METHOD(AdditionSubtractionTests)
		{
			Matrix2x2 a = Matrix2x2(2, 3, 4, 10);
			Matrix2x2 b = Matrix2x2(-1.5f, -5, 3.5f, 3);
			Matrix2x2 result = a + b;

			AssertUtils::AreEqual(result, Matrix2x2(.5f, -2, 7.5f, 13));
			AssertUtils::AreEqual(result, b + a);
			AssertUtils::AreEqual(result, a.Add(b));
			AssertUtils::AreEqual(result, b.Add(a));
			AssertUtils::AreEqual(result, ArithmeticOps::Add(a, b));
			AssertUtils::AreEqual(result, ArithmeticOps::Add(b, a));

			result = a - b;
			Matrix2x2 result2 = b - a;

			AssertUtils::AreEqual(result, Matrix2x2(3.5f, 8, .5f, 7));
			AssertUtils::AreEqual(result2, Matrix2x2(-3.5f, -8, -.5f, -7));
			AssertUtils::AreNotEqual(result, result2);

			AssertUtils::AreEqual(result, a.Subtract(b));
			AssertUtils::AreEqual(result2, b.Subtract(a));
			AssertUtils::AreEqual(result, ArithmeticOps::Subtract(a, b));
			AssertUtils::AreEqual(result2, ArithmeticOps::Subtract(b, a));
		}
		#pragma endregion

		#pragma region Negate, transposing, inversing, determinant and abs tests.
		TEST_METHOD(NegatingTest)
		{
			Matrix2x2 matrix = Matrix2x2(2, -1, .2f, -32.1f);
			Matrix2x2 result = -matrix;

			AssertUtils::AreEqual(result, Matrix2x2(-2, 1, -.2f, 32.1f));
			AssertUtils::AreNotEqual(result, matrix);

			AssertUtils::AreEqual(result, matrix.Negated());
			AssertUtils::AreEqual(result, ArithmeticOps::Negate(matrix));
			AssertUtils::AreEqual(result, matrix * -1);
		}

		TEST_METHOD(TransposingTest)
		{
			Matrix2x2 matrix = Matrix2x2(
				2, -1,
				3, 8);

			Matrix2x2 transposed = matrix.Transposed();

			AssertUtils::AreNotEqual(transposed, matrix);
			AssertUtils::AreEqual(transposed, Matrix::Transpose(matrix));
			AssertUtils::AreEqual(transposed, Matrix2x2(
				2, 3,
				-1, 8));

			Vector2D vectorTest = Vector2D(2, -1);
			AssertUtils::AreEqual(matrix * vectorTest, vectorTest * matrix.Transposed());
			AssertUtils::AreEqual(vectorTest * matrix, matrix.Transposed() * vectorTest);
		}

		TEST_METHOD(DeterminantTest)
		{
			Matrix2x2 matrix = Matrix2x2(2, -1, 2.5f, -10.12f);
			float det = matrix.Determinant();

			Assert::AreEqual(det, -17.74f);
			Assert::AreEqual(det, Matrix::Det(matrix));

			matrix = Matrix2x2::Rotate(90 * Angle::DEG_TO_RAD);
			Assert::AreEqual(matrix.Determinant(), 1.f);

			matrix = Matrix2x2::Shear(1, 1);
			Assert::AreEqual(matrix.Determinant(), 0.f);

			matrix = Matrix2x2::Scale(Vector2D::One() * 2);
			Assert::AreEqual(matrix.Determinant(), 4.f);

			matrix = Matrix2x2::Scale(2, 1);
			Assert::AreEqual(matrix.Determinant(), 2.f);

			matrix = Matrix2x2::Scale(.5f, 10);
			Assert::AreEqual(matrix.Determinant(), 5.f);
		}

		TEST_METHOD(InverseTest)
		{
			Matrix2x2 matrix = Matrix2x2(20, -15, 5, 6);
			Matrix2x2 inverse = matrix.Inverted();
			AssertUtils::AreEqual(inverse, Matrix::Invert(matrix));

			AssertUtils::CloseEnough(matrix * inverse, Matrix2x2::Identity());
			AssertUtils::CloseEnough(inverse * matrix, Matrix2x2::Identity());

			matrix = Matrix2x2(432, -321.321f, 421.132f, -32132);
			inverse = matrix.Inverted();
			AssertUtils::AreEqual(inverse, Matrix::Invert(matrix));

			AssertUtils::CloseEnough(matrix * inverse, Matrix2x2::Identity());
			AssertUtils::CloseEnough(inverse * matrix, Matrix2x2::Identity());

			matrix = Matrix2x2::Rotate(Constants::PI / 2);
			Vector2D vector = Vector2D(1, 0);
			Vector2D transformed = matrix * vector;

			AssertUtils::CloseEnough(transformed, Vector2D(0, 1));
			AssertUtils::CloseEnough(matrix.Inverted() * transformed, Vector2D(1, 0));
		}

		TEST_METHOD(AbsTest)
		{
			Matrix2x2 matrix = Matrix2x2(2, -1, 2, .1f);
			AssertUtils::AreEqual(matrix.Abs(), SMath::Abs(matrix));
			AssertUtils::AreEqual(matrix.Abs(), Matrix2x2(2, 1, 2, .1f));

			matrix = Matrix2x2(-3, 1, -.2f, -102.2f);
			AssertUtils::AreEqual(matrix.Abs(), SMath::Abs(matrix));
			AssertUtils::AreEqual(matrix.Abs(), Matrix2x2(3, 1, .2f, 102.2f));
		}

		#pragma endregion

		#pragma region Clamping tests.
		TEST_METHOD(ClampTest)
		{
			Matrix2x2 matrix = Matrix2x2(1, 2, 3, 4);
			Matrix2x2 min = Matrix2x2(-1, 2, 3, 5);
			Matrix2x2 max = Matrix2x2(0, 3, 4, 8);

			Matrix2x2 clamped = matrix.Clamp(min, max);

			AssertUtils::AreEqual(clamped, Matrix2x2(0, 2, 3, 5));
			AssertUtils::AreEqual(clamped, SMath::Clamp(matrix, min, max));

			matrix = Matrix2x2(1, 2, 3, 4);
			min = Matrix2x2(5, 3, 0, 0);
			max = Matrix2x2(5, 4, 2, 2);

			clamped = matrix.Clamp(min, max);

			AssertUtils::AreEqual(clamped, Matrix2x2(5, 3, 2, 2));
			AssertUtils::AreEqual(clamped, SMath::Clamp(matrix, min, max));
		}

		TEST_METHOD(ClampElementsTest)
		{
			Matrix2x2 matrix = Matrix2x2(3213, 2, 10, -1);
			float min = 15;
			float max = 3000;

			AssertUtils::AreEqual(matrix.ClampElements(min, max), Matrix::ClampElements(matrix, min, max));
			AssertUtils::AreEqual(matrix.ClampElements(min, max), Matrix2x2(3000, 15, 15, 15));

			min = 0;
			max = 5;
			AssertUtils::AreEqual(matrix.ClampElements(min, max), Matrix::ClampElements(matrix, min, max));
			AssertUtils::AreEqual(matrix.ClampElements(min, max), Matrix2x2(5, 2, 5, 0));
		}

		TEST_METHOD(ClampRowsTest)
		{
			Matrix2x2 matrix = Matrix2x2(
				2423, 2,
				10, -1);

			Vector2D min = Vector2D(3000, 1);
			Vector2D max = Vector2D(3500, 5);

			AssertUtils::AreEqual(matrix.ClampRows(min, max), Matrix::ClampRows(matrix, min, max));
			AssertUtils::AreEqual(matrix.ClampRows(min, max), Matrix2x2(
				3000, 2,
				3000, 1));

			min = Vector2D(5, -2);
			max = Vector2D(7, 0);
			AssertUtils::AreEqual(matrix.ClampRows(min, max), Matrix::ClampRows(matrix, min, max));
			AssertUtils::AreEqual(matrix.ClampRows(min, max), Matrix2x2(
				7, 0,
				7, -1));
		}

		TEST_METHOD(ClampColumnsTest)
		{
			Matrix2x2 matrix = Matrix2x2(
				3356, 2,
				10, -1);

			Vector2D min = Vector2D(
				3000,
				1);

			Vector2D max = Vector2D(
				3500,
				5);

			AssertUtils::AreEqual(matrix.ClampColumns(min, max), Matrix::ClampColumns(matrix, min, max));
			AssertUtils::AreEqual(matrix.ClampColumns(min, max), Matrix2x2(
				3356, 3000,
				5, 1));

			min = Vector2D(
				5,
				-2);

			max = Vector2D(
				7,
				0);

			AssertUtils::AreEqual(matrix.ClampColumns(min, max), Matrix::ClampColumns(matrix, min, max));
			AssertUtils::AreEqual(matrix.ClampColumns(min, max), Matrix2x2(
				7, 5,
				0, -1));
		}
		#pragma endregion

		#pragma region Transformation tests.
		TEST_METHOD(ShearTest)
		{
			Matrix2x2 matrix = Matrix2x2::Shear(Vector2D(2, 0));
			Vector2D vector = Vector2D(1, 1);
			AssertUtils::AreEqual(matrix * vector, Vector2D(3, 1));

			matrix = Matrix2x2::Shear(-1, 5);
			vector = Vector2D(2, 2);
			AssertUtils::AreEqual(matrix * vector, Vector2D(0, 12));
		}

		TEST_METHOD(ScaleTests)
		{
			Matrix2x2 matrix = Matrix2x2::Scale(Vector2D::One());
			AssertUtils::AreEqual(matrix, Matrix2x2::Identity());

			matrix = Matrix2x2::Scale(Vector2D::Zero());
			AssertUtils::AreEqual(matrix, Matrix2x2::Zero());

			matrix = Matrix2x2::Scale(2, 3);
			AssertUtils::AreEqual(matrix * Vector2D(3, 2), Vector2D(6, 6));

			matrix = Matrix2x2::Scale(3, -1);
			AssertUtils::AreEqual(matrix * Vector2D(0, 10), Vector2D(0, -10));
		}

		TEST_METHOD(RotationTest)
		{
			Matrix2x2 op = Matrix2x2::Rotate(0);
			Assert::IsTrue(op.r0c0 == 1);
			Assert::IsTrue(op.r0c1 == 0);
			Assert::IsTrue(op.r1c0 == 0);
			Assert::IsTrue(op.r1c1 == 1);

			op = Matrix2x2::Rotate(Constants::PI);
			Assert::IsTrue(op.r0c0 == -1);
			Assert::IsTrue(SMath::CloseEnough(op.r0c1, 0));
			Assert::IsTrue(SMath::CloseEnough(op.r1c0, 0));
			Assert::IsTrue(op.r1c1 == -1);

			op = Matrix2x2::Rotate(Constants::PI / 2);
			Assert::IsTrue(SMath::CloseEnough(op.r0c0, 0));
			Assert::IsTrue(op.r0c1 == -1);
			Assert::IsTrue(op.r1c0 == 1);
			Assert::IsTrue(SMath::CloseEnough(op.r1c1, 0));

			const float sqrt2Over2 = 0.70710678118f;
			op = Matrix2x2::Rotate(Constants::PI / 4);
			Assert::IsTrue(SMath::CloseEnough(op.r0c0, sqrt2Over2));
			Assert::IsTrue(SMath::CloseEnough(op.r0c1, -sqrt2Over2));
			Assert::IsTrue(SMath::CloseEnough(op.r1c0, sqrt2Over2));
			Assert::IsTrue(SMath::CloseEnough(op.r1c1, sqrt2Over2));

			op = Matrix2x2::Rotate(-Constants::PI / 4);
			Assert::IsTrue(SMath::CloseEnough(op.r0c0, sqrt2Over2));
			Assert::IsTrue(SMath::CloseEnough(op.r0c1, sqrt2Over2));
			Assert::IsTrue(SMath::CloseEnough(op.r1c0, -sqrt2Over2));
			Assert::IsTrue(SMath::CloseEnough(op.r1c1, sqrt2Over2));

			const float sqrt3Over2 = 0.86602540378f;
			op = Matrix2x2::Rotate(Constants::PI / 3);
			Assert::IsTrue(SMath::CloseEnough(op.r0c0, .5f));
			Assert::IsTrue(SMath::CloseEnough(op.r0c1, -sqrt3Over2));
			Assert::IsTrue(SMath::CloseEnough(op.r1c0, sqrt3Over2));
			Assert::IsTrue(SMath::CloseEnough(op.r1c1, .5f));

			op = Matrix2x2::Rotate(-Constants::PI / 3);
			Assert::IsTrue(SMath::CloseEnough(op.r0c0, .5f));
			Assert::IsTrue(SMath::CloseEnough(op.r0c1, sqrt3Over2));
			Assert::IsTrue(SMath::CloseEnough(op.r1c0, -sqrt3Over2));
			Assert::IsTrue(SMath::CloseEnough(op.r1c1, .5f));
		}
		#pragma endregion

		TEST_METHOD(LerpTest)
		{
			Matrix2x2 a = Matrix2x2(-10, -5, 2, 3);
			Matrix2x2 b = Matrix2x2(2, .5f, 344, 324.432f);
			Matrix2x2 difference = b - a;

			Test01([&](float alpha)
			{
				Matrix2x2 result1 = Lerper::Lerp(a, b, alpha);
				Matrix2x2 result1NonStatic = a.Lerp(b, alpha);
				Matrix2x2 result2 = a + alpha * difference;

				Assert::IsTrue(result1.CloseEnough(result2));
				Assert::IsTrue(result1NonStatic.CloseEnough(result2));
			});
		}

		TEST_METHOD(ConversionTests)
		{
			// TODO: Bring back when Matrix3x3 and Matrix4x4 exist.

			//Test50([&](int i)
			//{
			//	Matrix2x2 matrix = Matrix2x2(RandFloat100(), RandFloat100(), RandFloat100(), RandFloat100());
			//
			//	Matrix3x3 threeBy3 = matrix;
			//	Matrix4x4 fourBy4 = matrix;
			//
			//	Assert::AreEqual(threeBy3.r2c2, 1.f);
			//	Assert::AreEqual(fourBy4.r2c2, 1.f);
			//	Assert::AreEqual(fourBy4.r3c3, 1.f);
			//
			//	for (int r = 0; r < 2; r++)
			//	{
			//		for (int c = 0; c < 2; c++)
			//		{
			//			Assert::AreEqual(threeBy3[r, c], matrix[r, c]);
			//			Assert::AreEqual(fourBy4[r, c], matrix[r, c]);
			//		}
			//	}
			//});
		}
	};
}