#include "TestUtils.h"

namespace SupergodEngineTesting
{
	using namespace Math;

	TEST_CLASS(Vector3DTests)
	{
	private:
		TEST_METHOD(ConstructorTest)
		{
			Vector3D first(1, 1, 2);
			Assert::AreEqual(first.x, 1.f);
			Assert::AreEqual(first.y, 1.f);
			Assert::AreEqual(first.z, 2.f);

			Vector3D second(3, Vector2D(876, .5f));
			Assert::AreEqual(second.x, 3.f);
			Assert::AreEqual(second.y, 876.f);
			Assert::AreEqual(second.z, .5f);

			Vector3D third(Vector2D(5, -2.3f), -3);
			Assert::AreEqual(third.x, 5.f);
			Assert::AreEqual(third.y, -2.3f);
			Assert::AreEqual(third.z, -3.f);
		}

		TEST_METHOD(AxisCombinationTests)
		{
			Vector3D vector(2, 4, 6);

			Assert::IsTrue(vector.XZ() == Vector2D(2, 6));
			Assert::IsTrue(vector.ZX() == Vector2D(6, 2));

			Assert::IsTrue(vector.XY() == Vector2D(2, 4));
			Assert::IsTrue(vector.YX() == Vector2D(4, 2));

			Assert::IsTrue(vector.YZ() == Vector2D(4, 6));
			Assert::IsTrue(vector.ZY() == Vector2D(6, 4));
		}

		TEST_METHOD(EqualityTests)
		{
			Assert::IsTrue(Vector3D(10, 10, 5) == Vector3D(10, 10, 5));
			Assert::IsFalse(Vector3D(10, 10, 2) == Vector3D(10, 10, 1));
			Assert::IsTrue(Vector3D(10, 10, 5).Equals(Vector3D(10, 10, 5)));
			Assert::IsFalse(Vector3D(10, 10, 1).Equals(Vector3D(10, 10, 2)));

			Assert::IsFalse(Vector3D(10, 10, 1) != Vector3D(10, 10, 1));
			Assert::IsTrue(Vector3D(10, 10, 1) != Vector3D(10, 10, 2));
		}

		TEST_METHOD(BiggestSmallestAxisTest)
		{
			Vector3D vector(5, 2, 3);
			Assert::AreEqual(Vector::SmallestComponent(vector), 2.f);
			Assert::AreNotEqual(Vector::SmallestComponent(vector), 5.f);
			Assert::AreNotEqual(Vector::SmallestComponent(vector), 3.f);
			Assert::AreEqual(Vector::BiggestComponent(vector), 5.f);
			Assert::AreNotEqual(Vector::BiggestComponent(vector), 2.f);
			Assert::AreNotEqual(Vector::BiggestComponent(vector), 3.f);
			
			Assert::AreEqual(vector.SmallestComponent(), 2.f);
			Assert::AreNotEqual(vector.SmallestComponent(), 5.f);
			Assert::AreNotEqual(vector.SmallestComponent(), 3.f);
			Assert::AreEqual(vector.BiggestComponent(), 5.f);
			Assert::AreNotEqual(vector.BiggestComponent(), 2.f);
			Assert::AreNotEqual(vector.BiggestComponent(), 3.f);
		}

		TEST_METHOD(ContainsAxisTest)
		{
			Vector3D vector(1, 2, 10);
			Assert::IsTrue(vector.ContainsComponent([&](float comp) { return comp == 10; }));
			Assert::IsTrue(vector.ContainsComponent([&](float comp) { return comp == 2; }));
			Assert::IsTrue(vector.ContainsComponent([&](float comp) { return comp == 1; }));
			Assert::IsFalse(vector.ContainsComponent([&](float comp) { return comp == 5; }));

			vector = Vector3D(1, 2, 10);
			Assert::IsTrue(Vector::ContainsComponent(vector, [&](float comp) { return comp == 10; }));
			Assert::IsTrue(Vector::ContainsComponent(vector, [&](float comp) { return comp == 2; }));
			Assert::IsTrue(Vector::ContainsComponent(vector, [&](float comp) { return comp == 1; }));
			Assert::IsFalse(Vector::ContainsComponent(vector, [&](float comp) { return comp == 5; }));
		}

		TEST_METHOD(IndexerTest)
		{
			Vector3D vec;

			vec[0] = 10;
			vec[1] = 4;
			vec[2] = -4;

			Assert::AreEqual(vec[0], 10.f);
			Assert::AreEqual(vec[0], vec.x);
			
			Assert::AreEqual(vec[1], 4.f);
			Assert::AreEqual(vec[1], vec.y);
			
			Assert::AreEqual(vec[2], -4.f);
			Assert::AreEqual(vec[2], vec.z);
		}

		TEST_METHOD(MagnitudeTest)
		{
			Vector3D vec(5, .6f, 2);
			Assert::AreEqual(vec.Magnitude(), Vector::Magnitude(vec));
			AssertUtils::CloseEnough(vec.Magnitude(), 5.41849f);
			
			AssertUtils::CloseEnough(vec.SqrMagnitude(), Vector::SqrMagnitude(vec));
			AssertUtils::CloseEnough(vec.SqrMagnitude(), 29.3600338801f);

			vec = Vector3D(-5, .2f, 5.2f);
			Assert::AreEqual(vec.Magnitude(), Vector::Magnitude(vec));
			AssertUtils::CloseEnough(vec.Magnitude(), 7.21665f);
			
			AssertUtils::CloseEnough(vec.SqrMagnitude(), Vector::SqrMagnitude(vec));
			AssertUtils::CloseEnough(vec.SqrMagnitude(), 52.0800372226f);
		}

		TEST_METHOD(NormalizeTest)
		{
			Vector3D vec(10, 15, -3.4f);
			AssertUtils::CloseEnough(vec.Normalized().Magnitude(), 1);
			AssertUtils::CloseEnough(Vector::Normalize(vec).Magnitude(), 1);

			vec = Vector3D(1000, -1000, 432);
			AssertUtils::CloseEnough(vec.Normalized().Magnitude(), 1);
			AssertUtils::CloseEnough(Vector::Normalize(vec).Magnitude(), 1);
		}

		TEST_METHOD(ProjectOntoTest)
		{
			Vector3D source(1, 3, 2);
			Vector3D target(2, 0, 0);
			Vector3D result = source.ProjectOnto(target);

			AssertUtils::AreEqual(result, Vector3D(1, 0, 0));

			Vector3D vectors[] =
			{
				Vector3D(1, 3, 4),
				Vector3D(4.8f, 5.6f, 2),
				Vector3D(0, 5, -6222),
				Vector3D(-3.2f, 543, 0),
				Vector3D(2.4f, -2.4f, 0),
			};

			for (int i = 0; i < ARRAY_ELEMENTS_COUNT(vectors) - 1; i++)
			{
				TestVectorProjection(vectors[i], vectors[i + 1]);
				TestVectorProjection(vectors[i + 1], vectors[i]);
			}
			Vector3D a = Vector3D(0.5f, Constants::SQRT3_OVER2, 0);
			Vector3D b = Vector3D(Constants::SQRT3_OVER2, 0.5f, 0);
			float dot = a.Dot(b);
			AssertUtils::CloseEnough(dot, SMath::Cos(Constants::PI / 6));
		}

		TEST_METHOD(ReflectionTest)
		{
			Vector3D source(1, 1, -1);

			AssertUtils::AreEqual(source.Reflect(Vector3D::Up()), Vector3D(-1, 1, 1));
			AssertUtils::AreEqual(source.Reflect(Vector3D::Right()), Vector3D(1, -1, 1));
			AssertUtils::AreEqual(source.Reflect(Vector3D::Forward()), Vector3D(-1, -1, -1));
			AssertUtils::AreEqual(source.Reflect(Vector3D::Forward() * 2), Vector3D(-1, -1, -1));
		}

		TEST_METHOD(AngleTest)
		{
			Vector3D a(0, 0, 10);
			Vector3D b(0, 10, 0);

			AssertUtils::CloseEnough(a.SmallestAngle(b), Constants::PI / 2);
			AssertUtils::CloseEnough(Vector::SmallestAngle(a, b), Constants::PI / 2);
			AssertUtils::CloseEnough(a.BiggestAngle(b), Constants::PI * 1.5f);
			AssertUtils::CloseEnough(Vector::BiggestAngle(a, b), Constants::PI * 1.5f);

			b = Vector3D(0, 0, -10);
			AssertUtils::CloseEnough(a.SmallestAngle(b), Constants::PI);
			AssertUtils::CloseEnough(Vector::SmallestAngle(a, b), Constants::PI);
			AssertUtils::CloseEnough(a.BiggestAngle(b), Constants::PI);
			AssertUtils::CloseEnough(Vector::BiggestAngle(a, b), Constants::PI);

			b = Vector3D(5, 0, 5);
			AssertUtils::CloseEnough(a.SmallestAngle(b), Constants::PI / 4);
			AssertUtils::CloseEnough(Vector::SmallestAngle(a, b), Constants::PI / 4);
			AssertUtils::CloseEnough(a.BiggestAngle(b), 5.4977871437821382f);
			AssertUtils::CloseEnough(Vector::BiggestAngle(a, b), 5.4977871437821382f);

			AssertUtils::CloseEnough(Vector::SmallestAngle(Vector3D(1, 0, 0), Vector3D(1, 0, 0), false, false), 0);
			AssertUtils::CloseEnough(Vector::SmallestAngle(Vector3D(0, 0, 1), Vector3D(0, 0, 1), false, false), 0);
			AssertUtils::CloseEnough(Vector::SmallestAngle(Vector3D(-1, 0, 0), Vector3D(1, 0, 0), false, false), Constants::PI);
			AssertUtils::CloseEnough(Vector::SmallestAngle(Vector3D(0, 1, -1), Vector3D(1, 0, 1), false, false), Constants::PI);
			AssertUtils::CloseEnough(Vector::SmallestAngle(Vector3D(0, 1, 0), Vector3D(1, 0, 0), false, false), Constants::PI / 2);
			AssertUtils::CloseEnough(Vector::SmallestAngle(Vector3D(0, 1, 0), Vector3D(0, 0, 1), false, false), Constants::PI / 2);
			AssertUtils::CloseEnough(Vector::SmallestAngle(Vector3D(1, 0, 0), Vector3D(0, 0, -1), false, false), Constants::PI / 2);

			AssertUtils::CloseEnough(Vector::BiggestAngle(Vector3D(1, 0, 0), Vector3D(1, 0, 0), false, false), Constants::PI * 2);
			AssertUtils::CloseEnough(Vector::BiggestAngle(Vector3D(0, 0, 1), Vector3D(0, 0, 1), false, false), Constants::PI * 2);
			AssertUtils::CloseEnough(Vector::BiggestAngle(Vector3D(-1, 0, 0), Vector3D(1, 0, 0), false, false), Constants::PI);
			AssertUtils::CloseEnough(Vector::BiggestAngle(Vector3D(0, 1, -1), Vector3D(1, 0, 1), false, false), Constants::PI);
			AssertUtils::CloseEnough(Vector::BiggestAngle(Vector3D(0, 1, 0), Vector3D(1, 0, 0), false, false), Constants::PI * 1.5f);
			AssertUtils::CloseEnough(Vector::BiggestAngle(Vector3D(0, 1, 0), Vector3D(0, 0, 1), false, false), Constants::PI * 1.5f);
			AssertUtils::CloseEnough(Vector::BiggestAngle(Vector3D(1, 0, 0), Vector3D(0, 0, -1), false, false), Constants::PI * 1.5f);
		}

		TEST_METHOD(LookPointAtTests)
		{
			Vector3D a(10, 0, 0);
			Vector3D b(-10, 0, 0);
			Vector3D lookAt = a.LookAt(b);
			Vector3D pointAt = a.PointAt(b);

			AssertUtils::AreEqual(lookAt, Vector::LookAt(a, b));
			AssertUtils::AreEqual(pointAt, Vector::PointAt(a, b));
			AssertUtils::AreEqual(lookAt, Vector3D(-20, 0, 0));
			AssertUtils::AreEqual(pointAt, Vector3D(-1, 0, 0));

			a = Vector3D(0, 0, 0);
			b = Vector3D(-10, 0, 0);
			lookAt = a.LookAt(b);
			pointAt = a.PointAt(b);

			AssertUtils::AreEqual(lookAt, Vector::LookAt(a, b));
			AssertUtils::AreEqual(pointAt, Vector::PointAt(a, b));
			AssertUtils::AreEqual(lookAt, Vector3D(-10, 0, 0));
			AssertUtils::AreEqual(pointAt, Vector3D(-1, 0, 0));

			a = Vector3D(0, 0, 0);
			b = Vector3D(-10, 10, -5);
			lookAt = a.LookAt(b);
			pointAt = a.PointAt(b);

			AssertUtils::AreEqual(lookAt, Vector::LookAt(a, b));
			AssertUtils::AreEqual(pointAt, Vector::PointAt(a, b));
			AssertUtils::AreEqual(lookAt, Vector3D(-10, 10, -5));
			AssertUtils::AreEqual(pointAt, Vector3D(-0.6666666666f, 0.6666666666f, -0.33333333333333f));

			a = Vector3D(0, 5, 0);
			b = Vector3D(0, -5, 0);
			lookAt = a.LookAt(b);
			pointAt = a.PointAt(b);

			AssertUtils::AreEqual(lookAt, Vector::LookAt(a, b));
			AssertUtils::AreEqual(pointAt, Vector::PointAt(a, b));
			AssertUtils::AreEqual(lookAt, Vector3D(0, -10, 0));
			AssertUtils::AreEqual(pointAt, Vector3D(0, -1, 0));

			a = Vector3D(0, 5, -5);
			b = Vector3D(0, -5, 5);
			lookAt = a.LookAt(b);
			pointAt = a.PointAt(b);

			AssertUtils::AreEqual(lookAt, Vector::LookAt(a, b));
			AssertUtils::AreEqual(pointAt, Vector::PointAt(a, b));
			AssertUtils::AreEqual(lookAt, Vector3D(0, -10, 10));
			AssertUtils::AreEqual(pointAt, Vector3D(0, -0.70710678f, 0.70710678f));
		}

		TEST_METHOD(DistanceTests)
		{
			Vector3D a(10, 0, 0);
			Vector3D b(-10, 0, 0);
			float dist = a.Distance(b);
			float sqrDist = a.SqrDistance(b);

			Assert::AreEqual(dist, Vector::Distance(a, b));
			Assert::AreEqual(sqrDist, Vector::SqrDistance(a, b));
			Assert::AreEqual(dist, 20.f);
			Assert::AreEqual(sqrDist, 400.f);

			a = Vector3D(0, 0, 0);
			b = Vector3D(-10, 0, 0);
			dist = a.Distance(b);
			sqrDist = a.SqrDistance(b);

			Assert::AreEqual(dist, Vector::Distance(a, b));
			Assert::AreEqual(sqrDist, Vector::SqrDistance(a, b));
			Assert::AreEqual(dist, 10.f);
			Assert::AreEqual(sqrDist, 100.f);

			a = Vector3D(0, 0, 0);
			b = Vector3D(-10, 10, -5);
			dist = a.Distance(b);
			sqrDist = a.SqrDistance(b);

			Assert::AreEqual(dist, Vector::Distance(a, b));
			Assert::AreEqual(sqrDist, Vector::SqrDistance(a, b));
			Assert::AreEqual(dist, 15.f);
			Assert::AreEqual(sqrDist, 225.f);

			a = Vector3D(0, 5, 0);
			b = Vector3D(0, -5, 0);
			dist = a.Distance(b);
			sqrDist = a.SqrDistance(b);

			Assert::AreEqual(dist, Vector::Distance(a, b));
			Assert::AreEqual(sqrDist, Vector::SqrDistance(a, b));
			Assert::AreEqual(dist, 10.f);
			Assert::AreEqual(sqrDist, 100.f);

			a = Vector3D(0, 5, -5);
			b = Vector3D(0, -5, 5);
			dist = a.Distance(b);
			sqrDist = a.SqrDistance(b);

			Assert::AreEqual(dist, Vector::Distance(a, b));
			Assert::AreEqual(sqrDist, Vector::SqrDistance(a, b));
			Assert::AreEqual(dist, Constants::SQRT2 * 10);
			Assert::AreEqual(sqrDist, SMath::Squared(Constants::SQRT2 * 10));
		}

		TEST_METHOD(ClampingTest)
		{
			Vector3D vector = Vector3D(0, 10, 3).Clamp(Vector3D(-2, 15, 6), Vector3D(2, 20, 10));
			AssertUtils::AreEqual(vector, Vector3D(0, 15, 6));

			vector = Vector3D(2, 2, 2).ClampComponents(0, 1);
			AssertUtils::AreEqual(vector, Vector3D(1, 1, 1));

			vector = Vector3D(2, 2, 10).ClampComponents(3, 4);
			AssertUtils::AreEqual(vector, Vector3D(3, 3, 4));

			Vector3D lengthVector = Vector3D(1, 1, 1);
			Vector3D oldLengthVector = lengthVector;
			lengthVector = lengthVector.ClampMagnitude(.5f, .7f);

			AssertUtils::AreEqual(lengthVector.Magnitude(), .7f);
			AssertUtils::AreEqual(lengthVector.Normalized(), oldLengthVector.Normalized());

			lengthVector = Vector3D(10, 10, 6);
			oldLengthVector = lengthVector;
			lengthVector = lengthVector.ClampMagnitude(18, 20);

			AssertUtils::CloseEnough(lengthVector.Magnitude(), 18);
			AssertUtils::CloseEnough(lengthVector.Normalized(), oldLengthVector.Normalized());

			lengthVector = Vector3D(5, 5, 5);
			oldLengthVector = lengthVector;
			lengthVector = lengthVector.ClampMagnitude(-10, 10);
			AssertUtils::AreEqual(lengthVector.Magnitude(), oldLengthVector.Magnitude());
			AssertUtils::AreEqual(lengthVector.Normalized(), oldLengthVector.Normalized());

			AssertUtils::AreEqual(Vector3D(-1, -2, -3).Abs(), Vector3D(1, 2, 3));
			AssertUtils::AreEqual(Vector::Abs(Vector3D(1, 2, 3)), Vector3D(1, 2, 3));
		}

		TEST_METHOD(LerpTest)
		{
			Vector3D a(-10, -5, 2);
			Vector3D b(2, .5f, 344);
			Vector3D difference = b - a;

			Test01([&](float alpha)
			{
				Vector3D result1 = Lerper::Lerp(a, b, alpha);
				Vector3D result1NonStatic = a.Lerp(b, alpha);
				Vector3D result2 = a + alpha * difference;

				AssertUtils::CloseEnough(result1.x, result2.x);
				AssertUtils::CloseEnough(result1.y, result2.y);
				AssertUtils::CloseEnough(result1.z, result2.z);
				
				AssertUtils::CloseEnough(result1NonStatic.x, result2.x);
				AssertUtils::CloseEnough(result1NonStatic.y, result2.y);
				AssertUtils::CloseEnough(result1NonStatic.z, result2.z);
			});
		}

		TEST_METHOD(AdditionTest)
		{
			Vector3D left(1, 1, 2);
			Vector3D right(3, 5, 2);
			Vector3D expectedResult(4, 6, 4);

			Assert::IsTrue(left + right == expectedResult);
			Assert::IsTrue(left.Add(right) == expectedResult);
			Assert::IsTrue(ArithmeticOps::Add(left, right) == expectedResult);

			left = Vector3D(3, 876, 6);
			right = Vector3D(-1, -500, -1);
			expectedResult = Vector3D(2, 376, 5);

			Assert::IsTrue(left + right == expectedResult);
			Assert::IsTrue(left.Add(right) == expectedResult);
			Assert::IsTrue(ArithmeticOps::Add(left, right) == expectedResult);

			left = Vector3D(5, -2.3f, 3);
			right = Vector3D(5, 0.3f, -3);
			expectedResult = Vector3D(10, -2, 0);

			Assert::IsTrue(left + right == expectedResult);
			Assert::IsTrue(left.Add(right) == expectedResult);
			Assert::IsTrue(ArithmeticOps::Add(left, right) == expectedResult);
		}

		TEST_METHOD(SubtractionTest)
		{
			Vector3D left(1, 1, 0);
			Vector3D right(3, 5, 1);
			Vector3D expectedResult(-2, -4, -1);

			Assert::IsTrue(left - right == expectedResult);
			Assert::IsTrue(left.Subtract(right) == expectedResult);
			Assert::IsTrue(ArithmeticOps::Subtract(left, right) == expectedResult);

			left = Vector3D(3, 876, 0);
			right = Vector3D(-1, -500, 0);
			expectedResult = Vector3D(4, 1376, 0);

			Assert::IsTrue(left - right == expectedResult);
			Assert::IsTrue(left.Subtract(right) == expectedResult);
			Assert::IsTrue(ArithmeticOps::Subtract(left, right) == expectedResult);

			left = Vector3D(5, -2.3f, 3.5f);
			right = Vector3D(5, 0.3f, 3.6f);
			expectedResult = Vector3D(0, -2.6f, -.1f);

			Assert::IsTrue((left - right).CloseEnough(expectedResult));
			Assert::IsTrue(left.Subtract(right).CloseEnough(expectedResult));
			Assert::IsTrue(ArithmeticOps::Subtract(left, right).CloseEnough(expectedResult));
		}

		TEST_METHOD(NegationTest)
		{
			Vector3D vector(1, 1, 1);
			Vector3D expectedResult(-1, -1, -1);

			Assert::IsTrue(-vector == expectedResult);
			Assert::IsTrue(vector.Negated() == expectedResult);
			Assert::IsTrue(ArithmeticOps::Negate(vector) == expectedResult);

			vector = Vector3D(2, 5, -2);
			expectedResult = Vector3D(-2, -5, 2);

			Assert::IsTrue(-vector == expectedResult);
			Assert::IsTrue(vector.Negated() == expectedResult);
			Assert::IsTrue(ArithmeticOps::Negate(vector) == expectedResult);

			vector = Vector3D(-2, 6.5f, .5f);
			expectedResult = Vector3D(2, -6.5f, -.5f);

			Assert::IsTrue(-vector == expectedResult);
			Assert::IsTrue(vector.Negated() == expectedResult);
			Assert::IsTrue(ArithmeticOps::Negate(vector) == expectedResult);
		}

		TEST_METHOD(ScalarMultiplicationTest)
		{
			Vector3D vector(1, 1, 1);
			float scalar = 5;
			Vector3D expectedResult(5, 5, 5);

			Assert::IsTrue(vector * scalar == expectedResult);
			Assert::IsTrue(scalar * vector == expectedResult);
			Assert::IsTrue(ArithmeticOps::Multiply(vector, scalar) == expectedResult);
			Assert::IsTrue(vector.Multiply(scalar) == expectedResult);

			vector = Vector3D(3, 876, -62);
			scalar = 2;
			expectedResult = Vector3D(6, 1752, -124);

			Assert::IsTrue(vector * scalar == expectedResult);
			Assert::IsTrue(scalar * vector == expectedResult);
			Assert::IsTrue(ArithmeticOps::Multiply(vector, scalar) == expectedResult);
			Assert::IsTrue(vector.Multiply(scalar) == expectedResult);

			vector = Vector3D(5, .3f, 8);
			scalar = -1.5f;
			expectedResult = Vector3D(-7.5f, -.45f, -12);

			Assert::IsTrue((vector * scalar).CloseEnough(expectedResult));
			Assert::IsTrue((scalar * vector).CloseEnough(expectedResult));
			Assert::IsTrue(ArithmeticOps::Multiply(vector, scalar).CloseEnough(expectedResult));
			Assert::IsTrue(vector.Multiply(scalar).CloseEnough(expectedResult));
		}

		TEST_METHOD(DivisionTest)
		{
			Vector3D vector(5, 2, 0);
			float scalar = 2;
			Vector3D expectedResult(2.5f, 1, 0);

			AssertUtils::AreEqual(vector / scalar, expectedResult);
			AssertUtils::AreEqual(vector.Divide(scalar), expectedResult);
			AssertUtils::AreEqual(ArithmeticOps::Divide(vector, scalar), expectedResult);

			vector = Vector3D(.5f, -5, 2);
			scalar = .5f;
			expectedResult = Vector3D(1, -10, 4);

			AssertUtils::AreEqual(vector / scalar, expectedResult);
			AssertUtils::AreEqual(vector.Divide(scalar), expectedResult);
			AssertUtils::AreEqual(ArithmeticOps::Divide(vector, scalar), expectedResult);

			vector = Vector3D(5, 2, 3);
			Vector3D vector2 = Vector3D(2, -2, 6);
			expectedResult = Vector3D(2.5f, -1, .5f);

			AssertUtils::AreEqual(vector / vector2, expectedResult);
			AssertUtils::AreEqual(vector.Divide(vector2), expectedResult);
			AssertUtils::AreEqual(ArithmeticOps::Divide(vector, vector2), expectedResult);

			vector = Vector3D(1, -5, 1);
			vector2 = Vector3D(5, 2, 0);
			expectedResult = Vector3D(.2f, -2.5f, INFINITY);

			AssertUtils::AreEqual(vector / vector2, expectedResult);
			AssertUtils::AreEqual(vector.Divide(vector2), expectedResult);
			AssertUtils::AreEqual(ArithmeticOps::Divide(vector, vector2), expectedResult);
		}

		TEST_METHOD(MultiplicationTest)
		{
			Vector3D left(1, 1, 2);
			Vector3D right(2, 0, 2);
			Vector3D expectedResult(2, 0, 4);

			Assert::IsTrue(left * right == expectedResult);
			Assert::IsTrue(left.Multiply(right) == expectedResult);
			Assert::IsTrue(ArithmeticOps::Multiply(left, right) == expectedResult);

			left = Vector3D(3, 10, 2);
			right = Vector3D(-1, 1.5f, -3);
			expectedResult = Vector3D(-3, 15, -6);

			Assert::IsTrue(left * right == expectedResult);
			Assert::IsTrue(left.Multiply(right) == expectedResult);
			Assert::IsTrue(ArithmeticOps::Multiply(left, right) == expectedResult);

			left = Vector3D(3, 5, 5);
			right = Vector3D(5, -.5f, -10.5f);
			expectedResult = Vector3D(15, -2.5f, -52.5f);

			Assert::IsTrue(left * right == expectedResult);
			Assert::IsTrue(left.Multiply(right) == expectedResult);
			Assert::IsTrue(ArithmeticOps::Multiply(left, right) == expectedResult);
		}

		TEST_METHOD(DotTest)
		{
			Vector3D firstLeft(1, 5, 3);
			Vector3D firstRight(2, .5f, 4);
			float first = Vector::Dot(firstLeft, firstRight);
			Assert::IsTrue(first == 16.5f);

			Vector3D secondLeft = Vector3D(-2, -4, 1);
			Vector3D secondRight = Vector3D(5, 5, 3);
			float second = Vector::Dot(secondLeft, secondRight);
			Assert::IsTrue(second == -27);

			Vector3D thirdLeft = Vector3D(-2, -4, 6);
			Vector3D thirdRight = Vector3D(5, 5, 3.5f);
			float third = thirdLeft.Dot(thirdRight);
			Assert::IsTrue(third == -9);
		}

		TEST_METHOD(CrossTest)
		{
			Vector3D left(1, 5, .4f);
			Vector3D right(2, .5f, 0);

			Vector3D result = Vector3D::Cross(left, right);
			AssertUtils::AreEqual(result, Vector3D(-.2f, .8f, -9.5f));

			left = Vector3D(3, -5, 8);
			right = Vector3D(0, -3, 11);
			result = Vector3D::Cross(left, right);
			AssertUtils::AreEqual(result, Vector3D(-31, -33, -9));

			left = Vector3D(8, 6, 9);
			right = Vector3D(.1f, .1f, .1f);
			result = left.Cross(right);
			AssertUtils::CloseEnough(result, Vector3D(-.3f, .1f, .2f));
		}

		TEST_METHOD(ConversionTests)
		{
			Vector2D twoD = (Vector2D)Vector3D(1, 2, 3);
			Assert::IsTrue(twoD == Vector2D(1, 2));

			Vector4D fourD = Vector3D(-1, 2.2f, 3);
			Assert::IsTrue(fourD == Vector4D(-1, 2.2f, 3, 0));

			// TODO: Bring those back when EulerAngles exists.
			// Euler angles.
			//{
			//	Vector3D vec = Vector3D(RandFloat100(), RandFloat100(), RandFloat100());
			//	EulerAngles angles = vec;
			//	AssertUtils::CloseEnough(angles.Pitch, Angle::WrapRadians(vec.x));
			//	AssertUtils::CloseEnough(angles.Yaw, Angle::WrapRadians(vec.y));
			//	AssertUtils::CloseEnough(angles.Roll, Angle::WrapRadians(vec.z));
			//}
		}
	};
}