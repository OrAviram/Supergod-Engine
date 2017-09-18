#include "TestUtils.h"

namespace SupergodEngineTesting
{
	using namespace Math;
	
	TEST_CLASS(AngleTests)
	{
	public:
		#pragma region Angle conversion tests.
		TEST_METHOD(Deg2RadTest)
		{
			float test = 45 * Angle::DEG_TO_RAD;
			Assert::AreEqual(test, 0.25f * Constants::PI);

			test = 90 * Angle::DEG_TO_RAD;
			Assert::AreEqual(test, 0.5f * Constants::PI);

			test = 180 * Angle::DEG_TO_RAD;
			Assert::AreEqual(test, Constants::PI);

			test = 270 * Angle::DEG_TO_RAD;
			Assert::AreEqual(test, 1.5f * Constants::PI);

			test = 360 * Angle::DEG_TO_RAD;
			Assert::AreEqual(test, 2 * Constants::PI);
		}
		
		TEST_METHOD(Deg2RevTest)
		{
			float test = 45 * Angle::DEG_TO_REV;
			Assert::AreEqual(test, .125f);

			test = 90 * Angle::DEG_TO_REV;
			Assert::AreEqual(test, .25f);

			test = 180 * Angle::DEG_TO_REV;
			Assert::AreEqual(test, .5f);

			test = 270 * Angle::DEG_TO_REV;
			Assert::AreEqual(test, .75f);

			test = 360 * Angle::DEG_TO_REV;
			Assert::AreEqual(test, 1.f);
		}
		
		TEST_METHOD(Rad2DegTest)
		{
			float test = 0.25f * Constants::PI * Angle::RAD_TO_DEG;
			Assert::AreEqual(test, 45.f);

			test = 0.5f * Constants::PI * Angle::RAD_TO_DEG;
			Assert::AreEqual(test, 90.f);

			test = Constants::PI * Angle::RAD_TO_DEG;
			Assert::AreEqual(test, 180.f);

			test = 1.5f * Constants::PI * Angle::RAD_TO_DEG;
			Assert::AreEqual(test, 270.f);

			test = 2 * Constants::PI * Angle::RAD_TO_DEG;
			Assert::AreEqual(test, 360.f);
		}

		TEST_METHOD(Rad2RevTest)
		{
			float test = 0.25f * Constants::PI * Angle::RAD_TO_REV;
			Assert::AreEqual(test, .125f);

			test = 0.5f * Constants::PI * Angle::RAD_TO_REV;
			Assert::AreEqual(test, .25f);

			test = Constants::PI * Angle::RAD_TO_REV;
			Assert::AreEqual(test, .5f);

			test = 1.5f * Constants::PI * Angle::RAD_TO_REV;
			Assert::AreEqual(test, .75f);

			test = 2 * Constants::PI * Angle::RAD_TO_REV;
			Assert::AreEqual(test, 1.f);
		}

		TEST_METHOD(Rev2DegTest)
		{
			float test = .125f * Angle::REV_TO_DEG;
			Assert::AreEqual(test, 45.f);

			test = .25f * Angle::REV_TO_DEG;
			Assert::AreEqual(test, 90.f);

			test = .5f * Angle::REV_TO_DEG;
			Assert::AreEqual(test, 180.f);

			test = .75f * Angle::REV_TO_DEG;
			Assert::AreEqual(test, 270.f);

			test = Angle::REV_TO_DEG;
			Assert::AreEqual(test, 360.f);
		}

		TEST_METHOD(Rev2RadTest)
		{
			float test = .125f * Angle::REV_TO_RAD;
			Assert::AreEqual(test, Constants::PI / 4);

			test = .25f * Angle::REV_TO_RAD;
			Assert::AreEqual(test, Constants::PI / 2);

			test = .5f * Angle::REV_TO_RAD;
			Assert::AreEqual(test, Constants::PI);

			test = .75f * Angle::REV_TO_RAD;
			Assert::AreEqual(test, Constants::PI * 1.5f);

			test = Angle::REV_TO_RAD;
			Assert::AreEqual(test, 2 * Constants::PI);
		}
		#pragma endregion

		TEST_METHOD(FloatWrappingTests)
		{
			AssertUtils::CloseEnough(Angle::WrapDegrees(1080), 360);
			AssertUtils::CloseEnough(Angle::WrapDegrees(900), 180);
			AssertUtils::CloseEnough(Angle::WrapDegrees(360), 360);
			AssertUtils::CloseEnough(Angle::WrapDegrees(180), 180);
			
			AssertUtils::CloseEnough(Angle::WrapRadians(Constants::PI * 6), Constants::PI * 2);
			AssertUtils::CloseEnough(Angle::WrapRadians(Constants::PI * 5), Constants::PI);
			AssertUtils::CloseEnough(Angle::WrapRadians(Constants::PI * 2), Constants::PI * 2);
			AssertUtils::CloseEnough(Angle::WrapRadians(Constants::PI), Constants::PI);
			
			AssertUtils::CloseEnough(Angle::WrapRevolutions(3), 1);
			AssertUtils::CloseEnough(Angle::WrapRevolutions(2.5f), .5f);
			AssertUtils::CloseEnough(Angle::WrapRevolutions(1), 1);
			AssertUtils::CloseEnough(Angle::WrapRevolutions(.5f), .5f);
		}

		TEST_METHOD(ConstructorTest)
		{
			Angle angle(1080, Angle::Measurement::Degrees);
			AssertUtils::CloseEnough(angle.GetRadians(), Constants::PI * 2);

			angle = Angle(180, Angle::Measurement::Degrees);
			Assert::AreEqual(angle.GetRadians(), Constants::PI);

			angle = Angle(2, Angle::Measurement::Revolutions);
			Assert::AreEqual(angle.GetRadians(), Constants::PI * 2);

			angle = Angle(.5f, Angle::Measurement::Revolutions);
			Assert::AreEqual(angle.GetRadians(), Constants::PI);

			angle = Angle(Constants::PI * 2, Angle::Measurement::Radians);
			Assert::AreEqual(angle.GetRadians(), Constants::PI * 2);

			angle = Angle(Constants::PI * 3, Angle::Measurement::Radians);
			AssertUtils::CloseEnough(angle.GetRadians(), Constants::PI);
		}

		TEST_METHOD(SettersTest)
		{
			Angle angle;
			angle.SetRadians(Constants::PI * 8);
			AssertUtils::CloseEnough(angle.GetRadians(), Constants::PI * 2);
			AssertUtils::CloseEnough(angle.GetDegrees(), 360);
			AssertUtils::CloseEnough(angle.GetRevolutions(), 1);

			angle.SetDegrees(540);
			AssertUtils::CloseEnough(angle.GetRadians(), Constants::PI);
			AssertUtils::CloseEnough(angle.GetDegrees(), 180);
			AssertUtils::CloseEnough(angle.GetRevolutions(), .5f);

			angle.SetRevolutions(2.25f);
			AssertUtils::CloseEnough(angle.GetRadians(), Constants::PI / 2);
			AssertUtils::CloseEnough(angle.GetDegrees(), 90);
			AssertUtils::CloseEnough(angle.GetRevolutions(), .25f);
		}

		TEST_METHOD(NegativeSettersTest)
		{
			Angle angle;
			// Setting negative radians.
			angle.SetNegativeRadians(Constants::PI * 3);
			Assert::AreEqual(angle.GetNegativeRadians(), Constants::PI);
			Assert::AreEqual(angle.GetNegativeDegrees(), 180.f);
			Assert::AreEqual(angle.GetNegativeRevolutions(), .5f);
			Assert::AreEqual(angle.GetRadians(), Constants::PI * 2.f);
			Assert::AreEqual(angle.GetDegrees(), 360.f);
			Assert::AreEqual(angle.GetRevolutions(), 1.f);

			angle.SetNegativeRadians(0);
			Assert::AreEqual(angle.GetNegativeRadians(), 0.f);
			Assert::AreEqual(angle.GetNegativeDegrees(), 0.f);
			Assert::AreEqual(angle.GetNegativeRevolutions(), 0.f);
			Assert::AreEqual(angle.GetRadians(), Constants::PI);
			Assert::AreEqual(angle.GetDegrees(), 180.f);
			Assert::AreEqual(angle.GetRevolutions(), .5f);

			angle.SetNegativeRadians(-Constants::PI);
			Assert::AreEqual(angle.GetNegativeRadians(), -Constants::PI);
			Assert::AreEqual(angle.GetNegativeDegrees(), -180.f);
			Assert::AreEqual(angle.GetNegativeRevolutions(), -.5f);
			Assert::AreEqual(angle.GetRadians(), 0.f);
			Assert::AreEqual(angle.GetDegrees(), 0.f);
			Assert::AreEqual(angle.GetRevolutions(), 0.f);

			// Setting degrees.
			angle.SetNegativeDegrees(540);
			Assert::AreEqual(angle.GetNegativeRadians(), Constants::PI);
			Assert::AreEqual(angle.GetNegativeDegrees(), 180.f);
			Assert::AreEqual(angle.GetNegativeRevolutions(), .5f);
			Assert::AreEqual(angle.GetRadians(), Constants::PI * 2);
			Assert::AreEqual(angle.GetDegrees(), 360.f);
			Assert::AreEqual(angle.GetRevolutions(), 1.f);

			angle.SetNegativeDegrees(0);
			Assert::AreEqual(angle.GetNegativeRadians(), 0.f);
			Assert::AreEqual(angle.GetNegativeDegrees(), 0.f);
			Assert::AreEqual(angle.GetNegativeRevolutions(), 0.f);
			Assert::AreEqual(angle.GetRadians(), Constants::PI);
			Assert::AreEqual(angle.GetDegrees(), 180.f);
			Assert::AreEqual(angle.GetRevolutions(), .5f);

			angle.SetNegativeDegrees(-180);
			Assert::AreEqual(angle.GetNegativeRadians(), -Constants::PI);
			Assert::AreEqual(angle.GetNegativeDegrees(), -180.f);
			Assert::AreEqual(angle.GetNegativeRevolutions(), -.5f);
			Assert::AreEqual(angle.GetRadians(), 0.f);
			Assert::AreEqual(angle.GetDegrees(), 0.f);
			Assert::AreEqual(angle.GetRevolutions(), 0.f);

			// Setting revolutions.
			angle.SetNegativeRevolutions(1.5f);
			Assert::AreEqual(angle.GetNegativeRadians(), Constants::PI);
			Assert::AreEqual(angle.GetNegativeDegrees(), 180.f);
			Assert::AreEqual(angle.GetNegativeRevolutions(), .5f);
			Assert::AreEqual(angle.GetRadians(), Constants::PI * 2);
			Assert::AreEqual(angle.GetDegrees(), 360.f);
			Assert::AreEqual(angle.GetRevolutions(), 1.f);

			angle.SetNegativeRevolutions(0);
			Assert::AreEqual(angle.GetNegativeRadians(), 0.f);
			Assert::AreEqual(angle.GetNegativeDegrees(), 0.f);
			Assert::AreEqual(angle.GetNegativeRevolutions(), 0.f);
			Assert::AreEqual(angle.GetRadians(), Constants::PI);
			Assert::AreEqual(angle.GetDegrees(), 180.f);
			Assert::AreEqual(angle.GetRevolutions(), .5f);

			angle.SetNegativeRevolutions(-.5f);
			Assert::AreEqual(angle.GetNegativeRadians(), -Constants::PI);
			Assert::AreEqual(angle.GetNegativeDegrees(), -180.f);
			Assert::AreEqual(angle.GetNegativeRevolutions(), -.5f);
			Assert::AreEqual(angle.GetRadians(), 0.f);
			Assert::AreEqual(angle.GetDegrees(), 0.f);
			Assert::AreEqual(angle.GetRevolutions(), 0.f);
		}

		TEST_METHOD(ConversionTests)
		{
			Angle angle = Constants::PI * 3;
			AssertUtils::CloseEnough(angle, Constants::PI);
			AssertUtils::CloseEnough(angle.GetRadians(), Constants::PI);
			AssertUtils::CloseEnough(angle.GetDegrees(), 180);
			AssertUtils::CloseEnough(angle.GetRevolutions(), .5f);

			angle = Constants::PI / 2;
			AssertUtils::CloseEnough(angle, Constants::PI / 2);
			AssertUtils::CloseEnough(angle.GetRadians(), Constants::PI / 2);
			AssertUtils::CloseEnough(angle.GetDegrees(), 90);
			AssertUtils::CloseEnough(angle.GetRevolutions(), .25f);
		}

		TEST_METHOD(EqualityTests)
		{
			Angle a(180, Angle::Measurement::Degrees);
			Angle b(Constants::PI, Angle::Measurement::Radians);

			Assert::IsTrue(a == b);
			Assert::IsFalse(a != b);
			AssertUtils::AreEqual(a, b);
			Assert::IsTrue(a.Equals(b));
			Assert::IsTrue(a.Equals((float)b));

			b = Angle(Constants::PI * 2, Angle::Measurement::Radians);

			Assert::IsFalse(a == b);
			Assert::IsTrue(a != b);
			AssertUtils::AreNotEqual(a, b);
			Assert::IsFalse(a.Equals(b));
			Assert::IsFalse(a.Equals((float)b));

			a = Angle(180, Angle::Measurement::Degrees);
			b = Angle(Constants::PI, Angle::Measurement::Radians);

			Assert::IsTrue(a.CloseEnough(b));
			Assert::IsTrue(SupergodEquatable::CloseEnough(a, b));
			AssertUtils::CloseEnough(a, b);

			a = Angle(0, Angle::Measurement::Degrees);
			
			Assert::IsFalse(a.CloseEnough(b));
			Assert::IsFalse(SupergodEquatable::CloseEnough(a, b));
			Assert::IsTrue(a.CloseEnough(b, Constants::PI));
			Assert::IsTrue(SupergodEquatable::CloseEnough(a, b, Constants::PI));
		}

		TEST_METHOD(BiggerSmallerThanTests)
		{
			Angle a(180, Angle::Measurement::Degrees);
			Angle b(90, Angle::Measurement::Degrees);

			Assert::IsTrue(a > b);
			Assert::IsFalse(b > a);
			Assert::IsTrue(SizeComparer::BiggerThan(a, b));
			Assert::IsFalse(SizeComparer::BiggerThan(b, a));

			Assert::IsTrue(b < a);
			Assert::IsFalse(a < b);
			Assert::IsTrue(b.SmallerThan(a));
			Assert::IsFalse(a.SmallerThan(b));

			Assert::IsFalse(a == b);
			Assert::IsTrue(a >= b);
			Assert::IsFalse(a <= b);

			Assert::IsFalse(b >= a);
			Assert::IsTrue(b <= a);

			a = Angle(180, Angle::Measurement::Degrees);
			b = Angle(180, Angle::Measurement::Degrees);

			Assert::IsFalse(a > b);
			Assert::IsFalse(b > a);
			Assert::IsFalse(a.BiggerThan(b));
			Assert::IsFalse(b.BiggerThan(a));

			Assert::IsFalse(b < a);
			Assert::IsFalse(a < b);
			Assert::IsFalse(SizeComparer::SmallerThan(b, a));
			Assert::IsFalse(SizeComparer::SmallerThan(a, b));

			Assert::IsTrue(a == b);
			Assert::IsTrue(a >= b);
			Assert::IsTrue(a <= b);

			Assert::IsTrue(b >= a);
			Assert::IsTrue(b <= a);
		}

		TEST_METHOD(ScalingTests)
		{
			Angle angle(180, Angle::Measurement::Degrees);
			float scalar = 2;
			Angle result1 = angle * scalar;
			Angle result2 = scalar * angle;

			AssertUtils::AreEqual(result1, result2);
			AssertUtils::AreEqual(result1, angle.Multiply(scalar));
			AssertUtils::AreEqual(result1, ArithmeticOps::Multiply(angle, scalar));
			AssertUtils::AreEqual(result1.GetDegrees(), 360.f);
			AssertUtils::AreEqual(result1.GetRadians(), Constants::PI * 2);
			AssertUtils::AreEqual(result1.GetRevolutions(), 1.f);

			result1 = angle / scalar;

			AssertUtils::AreEqual(result1, ArithmeticOps::Divide(angle, scalar));
			AssertUtils::AreEqual(result1, angle.Divide(scalar));
			AssertUtils::AreEqual(result1.GetDegrees(), 90.f);
			AssertUtils::AreEqual(result1.GetRadians(), Constants::PI / 2);
			AssertUtils::AreEqual(result1.GetRevolutions(), .25f);
		}

		TEST_METHOD(AdditionSubtractionTests)
		{
			Angle a(180, Angle::Measurement::Degrees);
			Angle b(270, Angle::Measurement::Degrees);
			Angle add = a + b;
			Angle sub1 = a - b;
			Angle sub2 = b - a;

			AssertUtils::CloseEnough(add, Angle(90, Angle::Measurement::Degrees));
			AssertUtils::CloseEnough(add, a.Add(b));
			AssertUtils::CloseEnough(add, ArithmeticOps::Add(a, b));

			AssertUtils::AreEqual(sub1, Angle(270, Angle::Measurement::Degrees));
			AssertUtils::AreEqual(sub1, a.Subtract(b));
			AssertUtils::AreEqual(sub1, ArithmeticOps::Subtract(a, b));

			AssertUtils::CloseEnough(sub2, Angle(90, Angle::Measurement::Degrees));
			AssertUtils::CloseEnough(sub2, Angle(90, Angle::Measurement::Degrees));
			AssertUtils::CloseEnough(sub2, b.Subtract(a));
			AssertUtils::CloseEnough(sub2, ArithmeticOps::Subtract(b, a));
		}

		TEST_METHOD(FlippingReflectingTests)
		{
			Angle angle = 0;
			AssertUtils::AreEqual(angle.Flipped(), Angle(180, Angle::Measurement::Degrees));
			AssertUtils::AreEqual(angle.Flipped(), Angle::Flip(angle));
			AssertUtils::AreEqual(-angle, Angle::FullRotation());
			AssertUtils::AreEqual(-angle, angle.Reflection());
			AssertUtils::AreEqual(-angle, Angle::Reflect(angle));

			angle = Constants::PI / 2;
			AssertUtils::AreEqual(angle.Flipped(), Angle(270, Angle::Measurement::Degrees));
			AssertUtils::AreEqual(angle.Flipped(), Angle::Flip(angle));
			AssertUtils::AreEqual(-angle, Angle::StraightAndHalf());
			AssertUtils::AreEqual(-angle, angle.Reflection());
			AssertUtils::AreEqual(-angle, Angle::Reflect(angle));

			angle = Constants::PI;
			AssertUtils::AreEqual(angle.Flipped(), Angle::Zero());
			AssertUtils::AreEqual(angle.Flipped(), Angle::Flip(angle));
			AssertUtils::AreEqual(-angle, Angle::Straight());
			AssertUtils::AreEqual(-angle, angle.Reflection());
			AssertUtils::AreEqual(-angle, Angle::Reflect(angle));

			angle = Constants::PI * 1.5f;
			AssertUtils::CloseEnough(angle.Flipped(), Angle(90, Angle::Measurement::Degrees));
			AssertUtils::AreEqual(angle.Flipped(), Angle::Flip(angle));
			AssertUtils::CloseEnough(-angle, Angle::Right());
			AssertUtils::AreEqual(-angle, angle.Reflection());
			AssertUtils::AreEqual(-angle, Angle::Reflect(angle));

			angle = Constants::PI * 2;
			AssertUtils::AreEqual(angle.Flipped(), Angle(180, Angle::Measurement::Degrees));
			AssertUtils::AreEqual(angle.Flipped(), Angle::Flip(angle));
			AssertUtils::AreEqual(-angle, Angle::Zero());
			AssertUtils::AreEqual(-angle, angle.Reflection());
			AssertUtils::AreEqual(-angle, Angle::Reflect(angle));
		}
	};
}