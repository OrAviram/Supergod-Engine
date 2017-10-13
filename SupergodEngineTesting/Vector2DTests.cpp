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

		TEST_METHOD(BiggestSmallestComponentTest)
		{
			Vector2D vector(5, 2);
			Assert::AreEqual(Vector::SmallestComponent(vector), 2.f);
			Assert::AreNotEqual(Vector::SmallestComponent(vector), 5.f);
			Assert::AreEqual(Vector::BiggestComponent(vector), 5.f);
			Assert::AreNotEqual(Vector::BiggestComponent(vector), 2.f);
			
			Assert::AreEqual(vector.SmallestComponent(), 2.f);
			Assert::AreNotEqual(vector.SmallestComponent(), 5.f);
			Assert::AreEqual(vector.BiggestComponent(), 5.f);
			Assert::AreNotEqual(vector.BiggestComponent(), 2.f);

			vector.SmallestComponent() = 0;
			Assert::AreEqual(vector.y, 0.f);
			Assert::AreEqual(vector.SmallestComponent(), 0.f);

			vector.BiggestComponent() = 2;
			Assert::AreEqual(vector.x, 2.f);
			Assert::AreEqual(vector.BiggestComponent(), 2.f);
		}
		
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

		TEST_METHOD(IndexerTest)
		{
			Vector2D vec;

			vec[0] = 10;
			vec[1] = 4;

			Assert::AreEqual(vec[0], 10.f);
			Assert::AreEqual(vec[0], vec.x);
			
			Assert::AreEqual(vec[1], 4.f);
			Assert::AreEqual(vec[1], vec.y);
		}

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

		TEST_METHOD(ProjectOntoTest)
		{
			Vector2D source(2, 4);
			Vector2D target(1, 0);
			Vector2D result = source.ProjectOnto(target);

			AssertUtils::AreEqual(result, Vector2D(2, 0));

			Vector2D vectors[] =
			{
				Vector2D(1, 3),
				Vector2D(4.8f, 5.6f),
				Vector2D(0, 5),
				Vector2D(-3.2f, 4.9f),
				Vector2D(2.4f, -99.6f),
			};

			for (int i = 0; i < ARRAY_ELEMENTS_COUNT(vectors) - 1; i++)
			{
				TestVectorProjection(vectors[i], vectors[i + 1]);
				TestVectorProjection(vectors[i + 1], vectors[i]);
			}
			Vector2D a = Vector2D(0.5f, SMath::Sqrt(3) / 2);
			Vector2D b = Vector2D(SMath::Sqrt(3) / 2, 0.5f);
			float dot = a.Dot(b);
			AssertUtils::CloseEnough(dot, SMath::Cos(Constants::PI / 6));
		}

		TEST_METHOD(ReflectionTest)
		{
			Vector2D source(1, 1);
			
			AssertUtils::AreEqual(source.Reflect(Vector2D::UnitY()), Vector2D(-1, 1));
			AssertUtils::AreEqual(source.Reflect(Vector2D::UnitX()), Vector2D(1, -1));
			AssertUtils::AreEqual(source.Reflect(Vector2D::UnitX() * 2), Vector2D(1, -1));
		}

		TEST_METHOD(AngleTest)
		{
			Vector2D a(10, 0);
			Vector2D b(0, 10);

			AssertUtils::CloseEnough(a.SmallestAngle(b), Constants::PI / 2);
			AssertUtils::CloseEnough(Vector::SmallestAngle(a, b), Constants::PI / 2);
			AssertUtils::CloseEnough(a.BiggestAngle(b), Constants::PI * 1.5f);
			AssertUtils::CloseEnough(Vector::BiggestAngle(a, b), Constants::PI * 1.5f);

			b = Vector2D(-10, 0);
			AssertUtils::CloseEnough(a.SmallestAngle(b), Constants::PI);
			AssertUtils::CloseEnough(Vector::SmallestAngle(a, b), Constants::PI);
			AssertUtils::CloseEnough(a.BiggestAngle(b), Constants::PI);
			AssertUtils::CloseEnough(Vector::BiggestAngle(a, b), Constants::PI);

			b = Vector2D(5, 5);
			AssertUtils::CloseEnough(a.SmallestAngle(b), Constants::PI / 4);
			AssertUtils::CloseEnough(Vector::SmallestAngle(a, b), Constants::PI / 4);
			AssertUtils::CloseEnough(a.BiggestAngle(b), 5.4977871437821382f);
			AssertUtils::CloseEnough(Vector::BiggestAngle(a, b), 5.4977871437821382f);

			AssertUtils::CloseEnough(Vector::SmallestAngle(Vector2D(1, 0), Vector2D(1, 0), false, false), 0);
			AssertUtils::CloseEnough(Vector::SmallestAngle(Vector2D(-1, 0), Vector2D(1, 0), false, false), Constants::PI);
			AssertUtils::CloseEnough(Vector::SmallestAngle(Vector2D(0, 1), Vector2D(1, 0), false, false), Constants::PI / 2);

			AssertUtils::CloseEnough(Vector::BiggestAngle(Vector2D(1, 0), Vector2D(1, 0), false, false), Constants::PI * 2);
			AssertUtils::CloseEnough(Vector::BiggestAngle(Vector2D(-1, 0), Vector2D(1, 0), false, false), Constants::PI);
			AssertUtils::CloseEnough(Vector::BiggestAngle(Vector2D(0, 1), Vector2D(1, 0), false, false), Constants::PI * 1.5f);
		}

		TEST_METHOD(LookPointAtTests)
		{
			Vector2D a(10, 0);
			Vector2D b(-10, 0);
			Vector2D lookAt = a.LookAt(b);
			Vector2D pointAt = a.PointAt(b);

			AssertUtils::AreEqual(lookAt, Vector::LookAt(a, b));
			AssertUtils::AreEqual(pointAt, Vector::PointAt(a, b));
			AssertUtils::AreEqual(lookAt, Vector2D(-20, 0));
			AssertUtils::AreEqual(pointAt, Vector2D(-1, 0));

			a = Vector2D(0, 0);
			b = Vector2D(-10, 0);
			lookAt = a.LookAt(b);
			pointAt = a.PointAt(b);

			AssertUtils::AreEqual(lookAt, Vector::LookAt(a, b));
			AssertUtils::AreEqual(pointAt, Vector::PointAt(a, b));
			AssertUtils::AreEqual(lookAt, Vector2D(-10, 0));
			AssertUtils::AreEqual(pointAt, Vector2D(-1, 0));

			a = Vector2D(0, 0);
			b = Vector2D(-10, 10);
			lookAt = a.LookAt(b);
			pointAt = a.PointAt(b);

			AssertUtils::AreEqual(lookAt, Vector::LookAt(a, b));
			AssertUtils::AreEqual(pointAt, Vector::PointAt(a, b));
			AssertUtils::AreEqual(lookAt, Vector2D(-10, 10));
			AssertUtils::AreEqual(pointAt, Vector2D(-0.70710678f, 0.70710678f));

			a = Vector2D(0, 5);
			b = Vector2D(0, -5);
			lookAt = a.LookAt(b);
			pointAt = a.PointAt(b);

			AssertUtils::AreEqual(lookAt, Vector::LookAt(a, b));
			AssertUtils::AreEqual(pointAt, Vector::PointAt(a, b));
			AssertUtils::AreEqual(lookAt, Vector2D(0, -10));
			AssertUtils::AreEqual(pointAt, Vector2D(0, -1));
		}

		TEST_METHOD(DistanceTest)
		{
			Vector2D a(10, 0);
			Vector2D b(-10, 0);
			float dist = a.Distance(b);
			float sqrDist = a.SqrDistance(b);

			Assert::AreEqual(dist, Vector::Distance(a, b));
			Assert::AreEqual(sqrDist, Vector::SqrDistance(a, b));
			Assert::AreEqual(dist, 20.f);
			Assert::AreEqual(sqrDist, 400.f);

			a = Vector2D(0, 0);
			b = Vector2D(-10, 0);
			dist = a.Distance(b);
			sqrDist = a.SqrDistance(b);

			Assert::AreEqual(dist, Vector::Distance(a, b));
			Assert::AreEqual(sqrDist, Vector::SqrDistance(a, b));
			Assert::AreEqual(dist, 10.f);
			Assert::AreEqual(sqrDist, 100.f);

			a = Vector2D(0, 0);
			b = Vector2D(-10, 10);
			dist = a.Distance(b);
			sqrDist = a.SqrDistance(b);

			Assert::AreEqual(dist, Vector::Distance(a, b));
			Assert::AreEqual(sqrDist, Vector::SqrDistance(a, b));
			Assert::AreEqual(dist, Constants::SQRT2 * 10);
			Assert::AreEqual(sqrDist, SMath::Squared(Constants::SQRT2 * 10));

			a = Vector2D(0, 5);
			b = Vector2D(0, -5);
			dist = a.Distance(b);
			sqrDist = a.SqrDistance(b);

			Assert::AreEqual(dist, Vector::Distance(a, b));
			Assert::AreEqual(sqrDist, Vector::SqrDistance(a, b));
			Assert::AreEqual(dist, 10.f);
			Assert::AreEqual(sqrDist, 100.f);
		}

		TEST_METHOD(ClampingTests)
		{
			Vector2D vector = Vector2D(0, 10).Clamp(Vector2D(-2, 15), Vector2D(2, 20));
			AssertUtils::AreEqual(vector, Vector2D(0, 15));

			vector = Vector2D(2, 2).ClampComponents(0, 1);
			AssertUtils::AreEqual(vector, Vector2D(1, 1));

			vector = Vector2D(2, 2).ClampComponents(3, 4);
			AssertUtils::AreEqual(vector, Vector2D(3, 3));

			Vector2D lengthVector = Vector2D(1, 1);
			Vector2D oldLengthVector = lengthVector;
			lengthVector = lengthVector.ClampMagnitude(.5f, .7f);

			Assert::AreEqual(lengthVector.Magnitude(), .7f);
			AssertUtils::AreEqual(lengthVector.Normalized(), oldLengthVector.Normalized());

			lengthVector = Vector2D(10, 10);
			oldLengthVector = lengthVector;
			lengthVector = lengthVector.ClampMagnitude(18, 20);

			Assert::AreEqual(lengthVector.Magnitude(), 18.f);
			AssertUtils::AreEqual(lengthVector.Normalized(), oldLengthVector.Normalized());

			lengthVector = Vector2D(5, 5);
			oldLengthVector = lengthVector;
			lengthVector = lengthVector.ClampMagnitude(-10, 10);
			Assert::AreEqual(lengthVector.Magnitude(), oldLengthVector.Magnitude());
			AssertUtils::AreEqual(lengthVector.Normalized(), oldLengthVector.Normalized());

			AssertUtils::AreEqual(Vector2D(-1, -2).Abs(), Vector2D(1, 2));
			AssertUtils::AreEqual(SMath::Abs(Vector2D(1, 2)), Vector2D(1, 2));
		}

		TEST_METHOD(LerpTest)
		{
			Vector2D a(-10, -5);
			Vector2D b(2, .5f);
			Vector2D difference = b - a;

			Test01([&](float alpha)
			{
				Vector2D result1 = Lerper::Lerp(a, b, alpha);
				Vector2D result1NonStatic = a.Lerp(b, alpha);
				Vector2D result2 = a + alpha * difference;

				AssertUtils::CloseEnough(result1.x, result2.x);
				AssertUtils::CloseEnough(result1.y, result2.y);
				
				AssertUtils::CloseEnough(result1NonStatic.x, result2.x);
				AssertUtils::CloseEnough(result1NonStatic.y, result2.y);
			});
		}

		TEST_METHOD(AdditionTest)
		{
			Vector2D left(1, 1);
			Vector2D right(3, 5);
			Vector2D expectedResult(4, 6);

			Assert::IsTrue(left + right == expectedResult);
			Assert::IsTrue(left.Add(right) == expectedResult);
			Assert::IsTrue(ArithmeticOps::Add(left, right) == expectedResult);

			left = Vector2D(3, 876);
			right = Vector2D(-1, -500);
			expectedResult = Vector2D(2, 376);

			Assert::IsTrue(left + right == expectedResult);
			Assert::IsTrue(left.Add(right) == expectedResult);
			Assert::IsTrue(ArithmeticOps::Add(left, right) == expectedResult);

			left = Vector2D(5, -2.3f);
			right = Vector2D(5, 0.3f);
			expectedResult = Vector2D(10, -2);

			Assert::IsTrue(left + right == expectedResult);
			Assert::IsTrue(left.Add(right) == expectedResult);
			Assert::IsTrue(ArithmeticOps::Add(left, right) == expectedResult);
		}

		TEST_METHOD(SubtractionTest)
		{
			Vector2D left(1, 1);
			Vector2D right(3, 5);
			Vector2D expectedResult(-2, -4);

			Assert::IsTrue(left - right == expectedResult);
			Assert::IsTrue(left.Subtract(right) == expectedResult);
			Assert::IsTrue(ArithmeticOps::Subtract(left, right) == expectedResult);

			left = Vector2D(3, 876);
			right = Vector2D(-1, -500);
			expectedResult = Vector2D(4, 1376);

			Assert::IsTrue(left - right == expectedResult);
			Assert::IsTrue(left.Subtract(right) == expectedResult);
			Assert::IsTrue(ArithmeticOps::Subtract(left, right) == expectedResult);

			left = Vector2D(5, -2.3f);
			right = Vector2D(5, 0.3f);
			expectedResult = Vector2D(0, -2.6f);

			Assert::IsTrue(left - right == expectedResult);
			Assert::IsTrue(left.Subtract(right) == expectedResult);
		}
		
		TEST_METHOD(NegatingTest)
		{
			Vector2D vector(1, 1);
			Vector2D expectedResult(-1, -1);

			Assert::IsTrue(-vector == expectedResult);
			Assert::IsTrue(vector.Negated() == expectedResult);
			Assert::IsTrue(ArithmeticOps::Negate(vector) == expectedResult);

			vector = Vector2D(2, 5);
			expectedResult = Vector2D(-2, -5);

			Assert::IsTrue(-vector == expectedResult);
			Assert::IsTrue(vector.Negated() == expectedResult);
			Assert::IsTrue(ArithmeticOps::Negate(vector) == expectedResult);

			vector = Vector2D(-2, 6.5f);
			expectedResult = Vector2D(2, -6.5f);

			Assert::IsTrue(-vector == expectedResult);
			Assert::IsTrue(vector.Negated() == expectedResult);
			Assert::IsTrue(ArithmeticOps::Negate(vector) == expectedResult);
		}

		TEST_METHOD(ScalarMultiplicationTest)
		{
			Vector2D vector(1, 1);
			float scalar = 5;
			Vector2D expectedResult(5, 5);

			Assert::IsTrue(vector * scalar == expectedResult);
			Assert::IsTrue(scalar * vector == expectedResult);
			Assert::IsTrue(ArithmeticOps::Multiply(vector, scalar) == expectedResult);
			Assert::IsTrue(vector.Multiply(scalar) == expectedResult);
			
			vector = Vector2D(3, 876);
			scalar = 2;
			expectedResult = Vector2D(6, 1752);
			
			Assert::IsTrue(vector * scalar == expectedResult);
			Assert::IsTrue(scalar * vector == expectedResult);
			Assert::IsTrue(ArithmeticOps::Multiply(vector, scalar) == expectedResult);
			Assert::IsTrue(vector.Multiply(scalar) == expectedResult);
			
			vector = Vector2D(5, .3f);
			scalar = -1.5f;
			expectedResult = Vector2D(-7.5f, -.45f);
			
			Assert::IsTrue((vector * scalar).CloseEnough(expectedResult));
			Assert::IsTrue((scalar * vector).CloseEnough(expectedResult));
			Assert::IsTrue(ArithmeticOps::Multiply(vector, scalar).CloseEnough(expectedResult));
			Assert::IsTrue(vector.Multiply(scalar).CloseEnough(expectedResult));
		}

		TEST_METHOD(DivisionTest)
		{
			Vector2D vector(5, 2);
			float scalar = 2;
			Vector2D expectedResult(2.5f, 1);
		
			AssertUtils::AreEqual(vector / scalar, expectedResult);
			AssertUtils::AreEqual(vector.Divide(scalar), expectedResult);
			AssertUtils::AreEqual(ArithmeticOps::Divide(vector, scalar), expectedResult);
		
			vector = Vector2D(.5f, -5);
			scalar = .5f;
			expectedResult = Vector2D(1, -10);
		
			AssertUtils::AreEqual(vector / scalar, expectedResult);
			AssertUtils::AreEqual(vector.Divide(scalar), expectedResult);
			AssertUtils::AreEqual(ArithmeticOps::Divide(vector, scalar), expectedResult);
		
			vector = Vector2D(5, 2);
			Vector2D vector2 = Vector2D(2, -2);
			expectedResult = Vector2D(2.5f, -1);
		
			AssertUtils::AreEqual(vector / vector2, expectedResult);
			AssertUtils::AreEqual(vector.Divide(vector2), expectedResult);
			AssertUtils::AreEqual(ArithmeticOps::Divide(vector, vector2), expectedResult);
		
			vector = Vector2D(1, -5);
			vector2 = Vector2D(5, 2);
			expectedResult = Vector2D(.2f, -2.5f);
		
			AssertUtils::AreEqual(vector / vector2, expectedResult);
			AssertUtils::AreEqual(vector.Divide(vector2), expectedResult);
			AssertUtils::AreEqual(ArithmeticOps::Divide(vector, vector2), expectedResult);
		}

		TEST_METHOD(MultiplicationTest)
		{
			Vector2D left = Vector2D(1, 1);
			Vector2D right = Vector2D(2, 0);
			Vector2D expectedResult = Vector2D(2, 0);

			Assert::IsTrue(left * right == expectedResult);
			Assert::IsTrue(left.Multiply(right) == expectedResult);
			Assert::IsTrue(ArithmeticOps::Multiply(left, right) == expectedResult);

			left = Vector2D(3, 10);
			right = Vector2D(-1, 1.5f);
			expectedResult = Vector2D(-3, 15);

			Assert::IsTrue(left * right == expectedResult);
			Assert::IsTrue(left.Multiply(right) == expectedResult);
			Assert::IsTrue(ArithmeticOps::Multiply(left, right) == expectedResult);

			left = Vector2D(3, 5);
			right = Vector2D(5, -.5f);
			expectedResult = Vector2D(15, -2.5f);

			Assert::IsTrue(left * right == expectedResult);
			Assert::IsTrue(left.Multiply(right) == expectedResult);
			Assert::IsTrue(ArithmeticOps::Multiply(left, right) == expectedResult);
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

		TEST_METHOD(ConversionTests)
		{
			Vector3D threeD = Vector2D(1, 2);
			Assert::IsTrue(threeD == Vector3D(1, 2, 0));

			Vector4D fourD = Vector2D(-1, 2.2f);
			Assert::IsTrue(fourD == Vector4D(-1, 2.2f, 0, 0));
		}
	};
}