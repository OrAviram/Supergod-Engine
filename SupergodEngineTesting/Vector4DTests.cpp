#include "TestUtils.h"

namespace SupergodEngineTesting
{
	using namespace Math;

	TEST_CLASS(Vector4DTests)
	{
	private:
		TEST_METHOD(ConstructorTest)
		{
			Vector4D test = Vector4D(1, 1, 2, 5);
			Assert::IsTrue(test.x == 1);
			Assert::IsTrue(test.y == 1);
			Assert::IsTrue(test.z == 2);
			Assert::IsTrue(test.w == 5);

			test = Vector4D(3, Vector3D(876, .5f, 2));
			Assert::IsTrue(test.x == 3);
			Assert::IsTrue(test.y == 876);
			Assert::IsTrue(test.z == .5f);
			Assert::IsTrue(test.w == 2);

			test = Vector4D(Vector3D(5, -2.3f, -3), 8);
			Assert::IsTrue(test.x == 5);
			Assert::IsTrue(test.y == -2.3f);
			Assert::IsTrue(test.z == -3);
			Assert::IsTrue(test.w == 8);

			test = Vector4D(Vector2D(5, -2.3f), -3, 8);
			Assert::IsTrue(test.x == 5);
			Assert::IsTrue(test.y == -2.3f);
			Assert::IsTrue(test.z == -3);
			Assert::IsTrue(test.w == 8);

			test = Vector4D(5, -2.3f, Vector2D(-3, 8));
			Assert::IsTrue(test.x == 5);
			Assert::IsTrue(test.y == -2.3f);
			Assert::IsTrue(test.z == -3);
			Assert::IsTrue(test.w == 8);

			test = Vector4D(5, Vector2D(-2.3f, -3), 8);
			Assert::IsTrue(test.x == 5);
			Assert::IsTrue(test.y == -2.3f);
			Assert::IsTrue(test.z == -3);
			Assert::IsTrue(test.w == 8);

			test = Vector4D(Vector2D(5, -2.3f), Vector2D(-3, 8));
			Assert::IsTrue(test.x == 5);
			Assert::IsTrue(test.y == -2.3f);
			Assert::IsTrue(test.z == -3);
			Assert::IsTrue(test.w == 8);
		}

		TEST_METHOD(EqualityTests)
		{
			Assert::IsTrue(Vector4D(10, 10, 5, 2) == Vector4D(10, 10, 5, 2));
			Assert::IsFalse(Vector4D(10, 10, 2, 1) == Vector4D(10, 10, 2, 0));
			Assert::IsTrue(Vector4D(10, 10, 5, 0).Equals(Vector4D(10, 10, 5, 0)));
			Assert::IsFalse(Vector4D(10, 10, 2, 5).Equals(Vector4D(10, 10, 2, 4)));

			Assert::IsFalse(Vector4D(10, 10, 1, 2) != Vector4D(10, 10, 1, 2));
			Assert::IsTrue(Vector4D(10, 10, 1, 5) != Vector4D(10, 10, 1, 4));

			Assert::IsTrue(Vector4D(1, 1, 1, 1).CloseEnough(Vector4D(1.000001f, 1.000001f, 1.000001f, 1.000001f)));
			Assert::IsTrue(Vector4D(1, 1, 1, 1).CloseEnough(Vector4D(2, 2, 2, 2), 1));
		}

		TEST_METHOD(ContainsAxisTest)
		{
			Vector4D vector(1, 2, 10, 6);
			Assert::IsTrue(vector.ContainsComponent([&](const float& value) { return value == 10; }));
			Assert::IsTrue(vector.ContainsComponent([&](const float& value) { return value == 2; }));
			Assert::IsTrue(vector.ContainsComponent([&](const float& value) { return value == 1; }));
			Assert::IsTrue(vector.ContainsComponent([&](const float& value) { return value == 6; }));
			Assert::IsFalse(vector.ContainsComponent([&](const float& value) { return value == 5; }));

			Assert::IsTrue(Vector::ContainsComponent(vector, [&](const float& value) { return value == 10; }));
			Assert::IsTrue(Vector::ContainsComponent(vector, [&](const float& value) { return value == 2; }));
			Assert::IsTrue(Vector::ContainsComponent(vector, [&](const float& value) { return value == 1; }));
			Assert::IsFalse(Vector::ContainsComponent(vector, [&](const float& value) { return value == 5; }));
		}

		TEST_METHOD(IndexerTest)
		{
			Vector4D vector;
			vector[0] = 2;
			vector[1] = 4;
			vector[2] = 6;
			vector[3] = 8;

			Assert::AreEqual(vector[0], vector.x);
			Assert::AreEqual(vector[0], 2.f);

			Assert::AreEqual(vector[1], vector.y);
			Assert::AreEqual(vector[1], 4.f);

			Assert::AreEqual(vector[2], vector.z);
			Assert::AreEqual(vector[2], 6.f);

			Assert::AreEqual(vector[3], vector.w);
			Assert::AreEqual(vector[3], 8.f);
		}

		TEST_METHOD(SpecificComponentsTests)
		{
			Vector4D vector(1, 2, 3, 4);

			// X y and z combinations:
			AssertUtils::AreEqual(vector.YXZ(), Vector3D(2, 1, 3));
			AssertUtils::AreEqual(vector.YZX(), Vector3D(2, 3, 1));

			AssertUtils::AreEqual(vector.ZXY(), Vector3D(3, 1, 2));
			AssertUtils::AreEqual(vector.XZY(), Vector3D(1, 3, 2));

			AssertUtils::AreEqual(vector.ZYX(), Vector3D(3, 2, 1));
			AssertUtils::AreEqual(vector.XYZ(), Vector3D(1, 2, 3));

			// Y z and w combinations:
			AssertUtils::AreEqual(vector.YZW(), Vector3D(2, 3, 4));
			AssertUtils::AreEqual(vector.YWZ(), Vector3D(2, 4, 3));

			AssertUtils::AreEqual(vector.ZYW(), Vector3D(3, 2, 4));
			AssertUtils::AreEqual(vector.WYZ(), Vector3D(4, 2, 3));

			AssertUtils::AreEqual(vector.ZWY(), Vector3D(3, 4, 2));
			AssertUtils::AreEqual(vector.WZY(), Vector3D(4, 3, 2));

			// X z and w combinations:
			AssertUtils::AreEqual(vector.XZW(), Vector3D(1, 3, 4));
			AssertUtils::AreEqual(vector.XWZ(), Vector3D(1, 4, 3));

			AssertUtils::AreEqual(vector.ZXW(), Vector3D(3, 1, 4));
			AssertUtils::AreEqual(vector.WXZ(), Vector3D(4, 1, 3));

			AssertUtils::AreEqual(vector.ZWX(), Vector3D(3, 4, 1));
			AssertUtils::AreEqual(vector.WZX(), Vector3D(4, 3, 1));

			// Y w and x combinations:
			AssertUtils::AreEqual(vector.YWX(), Vector3D(2, 4, 1));
			AssertUtils::AreEqual(vector.YXW(), Vector3D(2, 1, 4));

			AssertUtils::AreEqual(vector.XYW(), Vector3D(1, 2, 4));
			AssertUtils::AreEqual(vector.WYX(), Vector3D(4, 2, 1));

			AssertUtils::AreEqual(vector.XWY(), Vector3D(1, 4, 2));
			AssertUtils::AreEqual(vector.WXY(), Vector3D(4, 1, 2));

			// Vector2D axes:
			AssertUtils::AreEqual(vector.XY(), Vector2D(1, 2));
			AssertUtils::AreEqual(vector.YX(), Vector2D(2, 1));

			AssertUtils::AreEqual(vector.XZ(), Vector2D(1, 3));
			AssertUtils::AreEqual(vector.ZX(), Vector2D(3, 1));

			AssertUtils::AreEqual(vector.XW(), Vector2D(1, 4));
			AssertUtils::AreEqual(vector.WX(), Vector2D(4, 1));

			AssertUtils::AreEqual(vector.YZ(), Vector2D(2, 3));
			AssertUtils::AreEqual(vector.ZY(), Vector2D(3, 2));

			AssertUtils::AreEqual(vector.YW(), Vector2D(2, 4));
			AssertUtils::AreEqual(vector.WY(), Vector2D(4, 2));

			AssertUtils::AreEqual(vector.ZW(), Vector2D(3, 4));
			AssertUtils::AreEqual(vector.WZ(), Vector2D(4, 3));
		}

		TEST_METHOD(BiggestSmallestAxisTest)
		{
			Vector4D vector(5, 2, 3, 4);
			Assert::AreEqual(Vector::SmallestComponent(vector), 2.f);
			Assert::AreNotEqual(Vector::SmallestComponent(vector), 5.f);
			Assert::AreNotEqual(Vector::SmallestComponent(vector), 3.f);
			Assert::AreNotEqual(Vector::SmallestComponent(vector), 4.f);
			Assert::AreEqual(Vector::BiggestComponent(vector), 5.f);
			Assert::AreNotEqual(Vector::BiggestComponent(vector), 2.f);
			Assert::AreNotEqual(Vector::BiggestComponent(vector), 3.f);
			Assert::AreNotEqual(Vector::BiggestComponent(vector), 4.f);

			Assert::AreEqual(vector.SmallestComponent(), 2.f);
			Assert::AreNotEqual(vector.SmallestComponent(), 5.f);
			Assert::AreNotEqual(vector.SmallestComponent(), 3.f);
			Assert::AreNotEqual(vector.SmallestComponent(), 4.f);
			Assert::AreEqual(vector.BiggestComponent(), 5.f);
			Assert::AreNotEqual(vector.BiggestComponent(), 2.f);
			Assert::AreNotEqual(vector.BiggestComponent(), 3.f);
			Assert::AreNotEqual(vector.BiggestComponent(), 4.f);
		}

		TEST_METHOD(AdditionTest)
		{
			Vector4D a(2, 4, -1, 3);
			Vector4D b(8, -1, -1.5f, 0);
			Vector4D expectedResult(10, 3, -2.5f, 3);

			AssertUtils::AreEqual(a + b, expectedResult);
			AssertUtils::AreEqual(a.Add(b), expectedResult);
			AssertUtils::AreEqual(ArithmeticOps::Add(a, b), expectedResult);

			a = Vector4D(8.2f, 9, 3, 5);
			b = Vector4D(-1.4f, -1, -1.5f, 5);
			expectedResult = Vector4D(6.8f, 8, 1.5f, 10);

			Assert::IsTrue((a + b).CloseEnough(expectedResult));
			Assert::IsTrue(a.Add(b).CloseEnough(expectedResult));
			Assert::IsTrue(ArithmeticOps::Add(a, b).CloseEnough(expectedResult));

			a = Vector4D(2, 3, 4, 5);
			b = Vector4D(5, 4, 3, 2);
			expectedResult = Vector4D(7, 7, 7, 7);

			AssertUtils::AreEqual(a + b, expectedResult);
			AssertUtils::AreEqual(a.Add(b), expectedResult);
			AssertUtils::AreEqual(ArithmeticOps::Add(a, b), expectedResult);
		}

		TEST_METHOD(SubtractionTest)
		{
			Vector4D a(2, 4, -1, 3);
			Vector4D b(8, -1, -1.5f, 0);
			Vector4D expectedResult(-6, 5, .5f, 3);

			AssertUtils::AreEqual(a - b, expectedResult);
			AssertUtils::AreEqual(a.Subtract(b), expectedResult);
			AssertUtils::AreEqual(ArithmeticOps::Subtract(a, b), expectedResult);

			a = Vector4D(8.2f, 9, 3, 5);
			b = Vector4D(-1.4f, -1, -1.5f, 5);
			expectedResult = Vector4D(9.6f, 10, 4.5f, 0);

			Assert::IsTrue((a - b).CloseEnough(expectedResult));
			Assert::IsTrue(a.Subtract(b).CloseEnough(expectedResult));
			Assert::IsTrue(ArithmeticOps::Subtract(a, b).CloseEnough(expectedResult));

			a = Vector4D(2, 3, 4, 5);
			b = Vector4D(5, 4, 3, 2);
			expectedResult = Vector4D(-3, -1, 1, 3);

			AssertUtils::AreEqual(a - b, expectedResult);
			AssertUtils::AreEqual(a.Subtract(b), expectedResult);
			AssertUtils::AreEqual(ArithmeticOps::Subtract(a, b), expectedResult);
		}

		TEST_METHOD(NegatingTest)
		{
			AssertUtils::AreEqual(Vector4D(1, 2.5f, -1, -2.2f).Negated(), Vector4D(-1, -2.5f, 1, 2.2f));
			AssertUtils::AreEqual(ArithmeticOps::Negate(Vector4D(1, 2.5f, -1, -2.2f)), Vector4D(-1, -2.5f, 1, 2.2f));
			AssertUtils::AreEqual(-Vector4D(1, 2.5f, -1, -2.2f), Vector4D(-1, -2.5f, 1, 2.2f));
		}

		TEST_METHOD(ScalarMultiplicationTest)
		{
			Vector4D vector(2, 4, -1, 3);
			float scalar = 2;
			Vector4D expectedResult(4, 8, -2, 6);

			AssertUtils::AreEqual(vector * scalar, expectedResult);
			AssertUtils::AreEqual(vector.Multiply(scalar), expectedResult);
			AssertUtils::AreEqual(ArithmeticOps::Multiply(vector, scalar), expectedResult);

			vector = Vector4D(-2, 6, .2f, 5);
			scalar = 3;
			expectedResult = Vector4D(-6, 18, .6f, 15);

			AssertUtils::AreEqual(vector * scalar, expectedResult);
			AssertUtils::AreEqual(vector.Multiply(scalar), expectedResult);
			AssertUtils::AreEqual(ArithmeticOps::Multiply(vector, scalar), expectedResult);

			vector = Vector4D(-2, 6, .2f, 5);
			scalar = -.5f;
			expectedResult = Vector4D(1, -3, -.1f, -2.5f);

			AssertUtils::AreEqual(vector * scalar, expectedResult);
			AssertUtils::AreEqual(vector.Multiply(scalar), expectedResult);
			AssertUtils::AreEqual(ArithmeticOps::Multiply(vector, scalar), expectedResult);
		}

		TEST_METHOD(MultiplicationTest)
		{
			Vector4D vector(-2, 6, 1, 5);
			Vector4D scalar(-2, 6, .2f, 5);
			Vector4D expectedResult(4, 36, .2f, 25);

			AssertUtils::AreEqual(vector * scalar, expectedResult);
			AssertUtils::AreEqual(vector.Multiply(scalar), expectedResult);
			AssertUtils::AreEqual(ArithmeticOps::Multiply(vector, scalar), expectedResult);
		}

		TEST_METHOD(DivisionTest)
		{
			Vector4D a(2, 4, -1.5f, 3);
			Vector4D b(8, -1, -1.5f, 0);
			Vector4D expectedResult(0.25f, -4, 1, INFINITY);

			AssertUtils::AreEqual(a / b, expectedResult);
			AssertUtils::AreEqual(a.Divide(b), expectedResult);
			AssertUtils::AreEqual(ArithmeticOps::Divide(a, b), expectedResult);

			a = Vector4D(2, 3, 3, 5);
			b = Vector4D(5, 4, 3, 2);
			expectedResult = Vector4D(.4f, .75f, 1, 2.5f);

			AssertUtils::AreEqual(a / b, expectedResult);
			AssertUtils::AreEqual(a.Divide(b), expectedResult);
			AssertUtils::AreEqual(ArithmeticOps::Divide(a, b), expectedResult);

			a = Vector4D(8.2f, 9, 3, 5);
			float scalar = 2;
			expectedResult = Vector4D(4.1f, 4.5f, 1.5f, 2.5f);

			Assert::IsTrue((a / scalar).CloseEnough(expectedResult));
			Assert::IsTrue(a.Divide(scalar).CloseEnough(expectedResult));
			Assert::IsTrue(ArithmeticOps::Divide(a, scalar).CloseEnough(expectedResult));
		}

		TEST_METHOD(DotTest)
		{
			Vector4D left(1, 5, 10021, 0);
			Vector4D right(2, .5f, 0, 1);
			float expectedResult = 4.5f;

			Assert::AreEqual(Vector::Dot(left, right), expectedResult);
			Assert::AreEqual(left.Dot(right), expectedResult);

			left = Vector4D(-2, -4, 2, 5);
			right = Vector4D(5, 5, 5, 2);
			expectedResult = -10;

			Assert::AreEqual(Vector::Dot(left, right), expectedResult);
			Assert::AreEqual(left.Dot(right), expectedResult);

			left = Vector4D(-2, -4, 2, -20);
			right = Vector4D(5, 5, 5, 2);
			expectedResult = -60;

			Assert::AreEqual(Vector::Dot(left, right), expectedResult);
			Assert::AreEqual(left.Dot(right), expectedResult);
		}

		TEST_METHOD(MagnitudeTest)
		{
			Vector4D vec = Vector4D(5, .6f, 2, 3);
			Assert::AreEqual(vec.Magnitude(), Vector::Magnitude(vec));
			AssertUtils::CloseEnough(vec.Magnitude(), 6.19355f);

			AssertUtils::CloseEnough(vec.SqrMagnitude(), Vector::SqrMagnitude(vec));
			AssertUtils::CloseEnough(vec.SqrMagnitude(), 38.36006f);

			vec = Vector4D(-5, .2f, 5.2f, 4);
			Assert::AreEqual(vec.Magnitude(), Vector::Magnitude(vec));
			AssertUtils::CloseEnough(vec.Magnitude(), 8.25106f);
			AssertUtils::CloseEnough(vec.SqrMagnitude(), Vector::SqrMagnitude(vec));
			AssertUtils::CloseEnough(vec.SqrMagnitude(), 68.08f);
		}

		TEST_METHOD(NormalizeTest)
		{
			Vector4D vec(10, 15, 2, 3);
			AssertUtils::CloseEnough(vec.Normalized().Magnitude(), 1);
			AssertUtils::CloseEnough(Vector::Normalize(vec).Magnitude(), 1);

			vec = Vector4D(1000, -1000, 5, -423.4322f);
			AssertUtils::CloseEnough(vec.Normalized().Magnitude(), 1);
			AssertUtils::CloseEnough(Vector::Normalize(vec).Magnitude(), 1);
		}

		TEST_METHOD(ProjectOntoTest)
		{
			Vector4D source(2, 4, 2, 6);
			Vector4D target(1, 0, 2, 2.325f);
			Vector4D result = source.ProjectOnto(target);

			AssertUtils::CloseEnough(result, Vector4D(1.91723f, 0, 3.83446f, 4.45757f));

			Vector4D vectors[] =
			{
				Vector4D(1, 3, 4, 2),
				Vector4D(4.8f, 5.6f, 2, 4),
				Vector4D(0, 5, -6222, 2.5f),
				Vector4D(-3.2f, 543, 3.62f, 0),
				Vector4D(2.4f, -2.4f, 8, 0),
			};

			for (int i = 0; i < ARRAY_ELEMENTS_COUNT(vectors) - 1; i++)
			{
				TestVectorProjection(vectors[i], vectors[i + 1]);
				TestVectorProjection(vectors[i + 1], vectors[i]);
			}
			Vector4D a = Vector4D(0.5f, SMath::Sqrt(3) / 2, 0, 0);
			Vector4D b = Vector4D(SMath::Sqrt(3) / 2, 0.5f, 0, 0);
			float dot = a.Dot(b);
			AssertUtils::CloseEnough(dot, SMath::Cos(Constants::PI / 6));
		}

		TEST_METHOD(ReflectionTest)
		{
			Vector4D source(-1, 2, 3, 4);

			AssertUtils::AreEqual(source.Reflect(Vector4D::UnitX()), Vector4D(-1, -2, -3, -4));
			AssertUtils::AreEqual(source.Reflect(Vector4D::UnitY()), Vector4D(1, 2, -3, -4));
			AssertUtils::AreEqual(source.Reflect(Vector4D::UnitZ()), Vector4D(1, -2, 3, -4));
			AssertUtils::AreEqual(source.Reflect(Vector4D::UnitW()), Vector4D(1, -2, -3, 4));
		}
	};
}