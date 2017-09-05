#include "TestUtils.h"

namespace SupergodEngineTesting
{
	using namespace Math;

	TEST_CLASS(Vector2DTests)
	{
	private:
		TEST_METHOD(ConstructorTest)
		{
			Vector2D first(1, 1);
			Assert::AreEqual(first.x, 1.f);
			Assert::AreEqual(first.y, 1.f);

			Vector2D second(3, 876);
			Assert::AreEqual(second.x, 3.f);
			Assert::AreEqual(second.y, 876.f);

			Vector2D third(5, -2.3f);
			Assert::AreEqual(third.x, 5.f);
			Assert::AreEqual(third.y, -2.3f);
		}

		TEST_METHOD(EqualityTests)
		{
			Assert::IsTrue(Vector2D(10, 10) == Vector2D(10, 10));
			Assert::IsFalse(Vector2D(5, 10) == Vector2D(10, 10));
			Assert::IsTrue(Vector2D(10, 10).Equals(Vector2D(10, 10)));
			Assert::IsFalse(Vector2D(10, 10).Equals(Vector2D(10, 4)));

			Assert::IsFalse(Vector2D(10, 10) != Vector2D(10, 10));
			Assert::IsTrue(Vector2D(5, 10) != Vector2D(10, 10));
		}

		// TODO: Maybe insert BiggestSmallestComponentTest here later.
		
		TEST_METHOD(ContainsAxisTest)
		{
			Vector2D vector(1, 2);
			Assert::IsTrue(vector.ContainsComponent([](float x) { return x == 1; }));
			Assert::IsTrue(vector.ContainsComponent([](float x) { return x == 2; }));
			Assert::IsFalse(vector.ContainsComponent([](float x) { return x == 3; }));
		}

		TEST_METHOD(CloseEnoughTest)
		{
			Vector2D left(4, 2);
			Vector2D right(2, 4);

			Assert::IsTrue(!left.CloseEnough(right));
			Assert::IsTrue(!right.CloseEnough(left));

			Assert::IsTrue(left.CloseEnough(right, 2));
			Assert::IsTrue(right.CloseEnough(left, 2));
		}

		// TODO: Maybe insert IndexerTest here later.

		TEST_METHOD(MagnitudeTest)
		{
			Vector2D vec(5, .6f);
			Assert::AreEqual(vec.Magnitude(), Vector::Magnitude(vec));
			AssertUtils::CloseEnough(vec.Magnitude(), 5.03587f);

			AssertUtils::CloseEnough(vec.SqrMagnitude(), Vector::SqrMagnitude(vec));
			AssertUtils::CloseEnough(vec.SqrMagnitude(), 25.36f);
			
			vec = Vector2D(-5, .2f);
			Assert::IsTrue(vec.Magnitude() == Vector::Magnitude(vec) && SMath::CloseEnough(vec.Magnitude(), 5.004f));
			Assert::IsTrue(SMath::CloseEnough(vec.SqrMagnitude(), Vector::SqrMagnitude(vec)) && SMath::CloseEnough(vec.SqrMagnitude(), 25.04f));
		}

		// TODO: Maybe insert
		//        ProjectOntoTest, ReflectionTest, AngleTest, DistanceTests,
		//        LookPointAtTests, ClampingTests, LerpTests, AdditionTest,
		//        SubtractionTest, NegatingTest here later.

		// TODO: Finish test.
		TEST_METHOD(ScalarMultiplicationTest)
		{
			Vector2D vector(1, 1);
			float scalar = 5;
			Vector2D expectedResult(5, 5);

			Assert::IsTrue(vector * scalar == expectedResult);
			Assert::IsTrue(scalar * vector == expectedResult);
			//Assert::IsTrue(Vector.Multiply(vector, scalar) == expectedResult);
			//Assert::IsTrue(vector.Multiply(scalar) == expectedResult);
			
			vector = Vector2D(3, 876);
			scalar = 2;
			expectedResult = Vector2D(6, 1752);
			
			Assert::IsTrue(vector * scalar == expectedResult);
			Assert::IsTrue(scalar * vector == expectedResult);
			//Assert::IsTrue(Vector.Multiply(vector, scalar) == expectedResult);
			//Assert::IsTrue(vector.Multiply(scalar) == expectedResult);
			
			vector = Vector2D(5, .3f);
			scalar = -1.5f;
			expectedResult = Vector2D(-7.5f, -.45f);
			
			Assert::IsTrue((vector * scalar).CloseEnough(expectedResult));
			Assert::IsTrue((scalar * vector).CloseEnough(expectedResult));
			//Assert::IsTrue(Vector.Multiply(vector, scalar).CloseEnough(expectedResult));
			//Assert::IsTrue(vector.Multiply(scalar).CloseEnough(expectedResult));
		}

		// TODO: Test division.

		// TODO: Finish test.
		TEST_METHOD(MultiplicationTest)
		{
			Vector2D left = Vector2D(1, 1);
			Vector2D right = Vector2D(2, 0);
			Vector2D expectedResult = Vector2D(2, 0);

			Assert::IsTrue(left * right == expectedResult);
			Assert::IsTrue(left.Multiply(right) == expectedResult);
			//Assert::IsTrue(Vector.Multiply(left, right) == expectedResult);

			left = Vector2D(3, 10);
			right = Vector2D(-1, 1.5f);
			expectedResult = Vector2D(-3, 15);

			Assert::IsTrue(left * right == expectedResult);
			Assert::IsTrue(left.Multiply(right) == expectedResult);
			//Assert::IsTrue(Vector.Multiply(left, right) == expectedResult);

			left = Vector2D(3, 5);
			right = Vector2D(5, -.5f);
			expectedResult = Vector2D(15, -2.5f);

			Assert::IsTrue(left * right == expectedResult);
			Assert::IsTrue(left.Multiply(right) == expectedResult);
			//Assert::IsTrue(Vector.Multiply(left, right) == expectedResult);
		}

		TEST_METHOD(DotTest)
		{
			Vector2D firstLeft(1, 5);
			Vector2D firstRight(2, .5f);
			float first = Vector::Dot(firstLeft, firstRight);
			Assert::IsTrue(first == 4.5f);

			Vector2D secondLeft = Vector2D(-2, -4);
			Vector2D secondRight = Vector2D(5, 5);
			float second = Vector::Dot(secondLeft, secondRight);
			Assert::IsTrue(second == -30);

			Vector2D thirdLeft = Vector2D(-2, -4);
			Vector2D thirdRight = Vector2D(5, 5);
			float third = thirdLeft.Dot(thirdRight);
			Assert::IsTrue(third == -30);
		}

		// TODO: MAYBE test conversions (depends on if they will even exist).
	};
}