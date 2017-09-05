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

		// TODO: Maybe insert
		//        EqualsTest, NotEqualTest, BiggestSmallestComponentTest,
		//        ContainsAxisTest, CloseEnoughTest, IndexerTest here later.
		
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

			//Assert::IsTrue(vector * scalar == expectedResult);
			//Assert::IsTrue(scalar * vector == expectedResult);
			//Assert::IsTrue(Vector.Multiply(vector, scalar) == expectedResult);
			//Assert::IsTrue(vector.Multiply(scalar) == expectedResult);
			//
			//vector = new Vector2D(3, 876);
			//scalar = 2;
			//expectedResult = new Vector2D(6, 1752);
			//
			//Assert::IsTrue(vector * scalar == expectedResult);
			//Assert::IsTrue(scalar * vector == expectedResult);
			//Assert::IsTrue(Vector.Multiply(vector, scalar) == expectedResult);
			//Assert::IsTrue(vector.Multiply(scalar) == expectedResult);
			//
			//vector = new Vector2D(5, .3f);
			//scalar = -1.5f;
			//expectedResult = new Vector2D(-7.5f, -.45f);
			//
			//Assert::IsTrue((vector * scalar).CloseEnough(expectedResult));
			//Assert::IsTrue((scalar * vector).CloseEnough(expectedResult));
			//Assert::IsTrue(Vector.Multiply(vector, scalar).CloseEnough(expectedResult));
			//Assert::IsTrue(vector.Multiply(scalar).CloseEnough(expectedResult));
		}

		// TODO: JUST DO STUFF HERE LATER. >:(
	};
}