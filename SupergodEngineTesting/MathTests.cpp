#include "TestUtils.h"

namespace SupergodEngineTesting
{
	using namespace Math;

	// TODO: Unit test Clamp when I have it (probably in SMath).
	TEST_CLASS(MathTests)
	{
	public:
		TEST_METHOD(CloseEnoughTest)
		{
			Assert::IsTrue(SMath::CloseEnough(1, 2, 1));
			Assert::IsTrue(SMath::CloseEnough(1, 1.0000001f, 0.000001f));
			Assert::IsTrue(SMath::CloseEnough(1, 1.0000001f));
			
			Assert::IsFalse(SMath::CloseEnough(1, 2, .5f));
			Assert::IsFalse(SMath::CloseEnough(1, 1.0000001f, 0.000000001f));
		}

		TEST_METHOD(SignTest)
		{
			int sign = FMath::Sign(123);
			Assert::AreEqual(sign, 1);

			sign = FMath::Sign(0);
			Assert::AreEqual(sign, 1);

			sign = FMath::Sign(.2f);
			Assert::AreEqual(sign, 1);

			sign = FMath::Sign(-123);
			Assert::AreEqual(sign, -1);

			sign = FMath::Sign(-.2f);
			Assert::AreEqual(sign, -1);

			sign = FMath::Sign(-0);
			Assert::AreEqual(sign, 1);
		}

		TEST_METHOD(FactorialTest)
		{
			int x = FMath::Factorial(5);
			Assert::AreEqual(x, 120);

			x = FMath::Factorial(0);
			Assert::AreEqual(x, 1);

			x = FMath::Factorial(1);
			Assert::AreEqual(x, 1);
		}

		TEST_METHOD(AvrageTest)
		{
			float x = FMath::Average({ 2, 5, -1, 8, 5.5f, 2.3f, 0 });
			Assert::AreEqual(x, 3.1142857142857f);

			x = FMath::Average({ 3232, .32131f, .3232f, 321, 10101010, 0, 0, 0, 0, 1000 });
			Assert::AreEqual(x, 1010556.364451f);

			x = FMath::Average({ -1, -2, -3, -4, -5, 5, 4, 3, 2, 1, 1.5f, 2.5f, .4f, 10, 10000, 0, 0, 0, 0, 0, 0, 0, -1001 });
			Assert::AreEqual(x, 391.88695652174f);
		}

		TEST_METHOD(RootsPowersTests)
		{
			float test = FMath::Pow(3, 2);
			Assert::AreEqual(test, 9.f);

			test = FMath::Pow(.5f, 5);
			Assert::AreEqual(test, 0.03125f);

			test = FMath::Pow(-5, 10);
			AssertUtils::CloseEnough(test, 9765625);

			test = FMath::Pow(10, 2);
			AssertUtils::CloseEnough(test, 100);

			TestMultiple(1, 50, .1f, [&](float i)
			{
				test = FMath::Pow(i, -1);
				AssertUtils::CloseEnough(test, 1 / i);

				test = FMath::Pow(i, -2);
				AssertUtils::CloseEnough(test, 1 / (i * i));

				test = FMath::Pow(i, -i);
				AssertUtils::CloseEnough(test, 1 / FMath::Pow(i, i));

				test = FMath::Pow(i, 0);
				Assert::AreEqual(test, 1.f);

				test = FMath::Exp(i);
				Assert::AreEqual(test, FMath::Pow(Constants::E, i));

				test = FMath::Squared(i);
				Assert::AreEqual(test, i * i);
				Assert::AreEqual(test, FMath::Pow(i, 2));

				test = FMath::Cubed(i);
				AssertUtils::CloseEnough(test, i * i * i, .00785f);
				AssertUtils::CloseEnough(test, FMath::Pow(i, 3), .00785f);

				test = FMath::Sqrt(i);
				AssertUtils::CloseEnough(FMath::Squared(test), i);

				TestMultiple(1, 10, .1f, [&](float n)
				{
					test = FMath::Root(i, n);
					AssertUtils::CloseEnough(FMath::Pow(test, n), i);
				});

				test = FMath::Ln(i);
				AssertUtils::CloseEnough(FMath::Exp(test), i);

				test = FMath::Log10(i);
				AssertUtils::CloseEnough(FMath::Pow(10, test), i);

				TestMultiple(-10, 10, .1f, [&](float base)
				{
					test = FMath::Log(i, base);
					if (!FMath::IsNaN(test))
						AssertUtils::CloseEnough(FMath::Pow(base, test), i);
				});
			});
		}

		TEST_METHOD(AbsTest)
		{
			Assert::AreEqual(5.f, FMath::Abs(5));
			Assert::AreEqual(5.f, FMath::Abs(-5));
			Assert::AreNotEqual(4.f, FMath::Abs(-5));
		}

		TEST_METHOD(WrapTest)
		{
			float test = FMath::Wrap(2, 0, 3);
			Assert::AreEqual(2.f, test);

			test = FMath::Wrap(4, 3);
			Assert::AreEqual(1.f, test);

			test = FMath::Wrap(5, 0, 2);
			Assert::AreEqual(1.f, test);

			test = FMath::Wrap(360, 0, 180);
			Assert::AreEqual(180.f, test);

			test = FMath::Wrap(540, 360);
			Assert::AreEqual(180.f, test);

			test = FMath::Wrap(5, 10, 20);
			Assert::AreEqual(15.f, test);

			test = FMath::Wrap(9, 15, 20);
			Assert::AreEqual(19.f, test);

			test = FMath::Wrap(15, 15, 20);
			Assert::AreEqual(15.f, test);

			test = FMath::Wrap(20, 15, 20);
			Assert::AreEqual(20.f, test);

			test = FMath::Wrap(17, 15, 20);
			Assert::AreEqual(17.f, test);

			test = FMath::Wrap(0, 15, 20);
			Assert::AreEqual(15.f, test);

			test = FMath::Wrap(21, 15, 20);
			Assert::AreEqual(16.f, test);
		}

		TEST_METHOD(MaxTest)
		{
			float test = FMath::Max(5, .1f);
			Assert::AreEqual(test, 5.f);

			test = FMath::Max(-1, 0);
			Assert::AreEqual(test, 0.f);

			test = FMath::Max({ 1, 4, 1, .2f, -20 });
			Assert::AreEqual(test, 4.f);
		}

		TEST_METHOD(MinTest)
		{
			float test = FMath::Min(5, .1f);
			Assert::AreEqual(test, .1f);

			test = FMath::Min(-1, 0);
			Assert::AreEqual(test, -1.f);

			test = FMath::Min({ 1, 4, 1, .2f, -20 });
			Assert::AreEqual(test, -20.f);

		}

		TEST_METHOD(SinTest)
		{
			float test = FMath::Sin(0);
			Assert::IsTrue(SMath::CloseEnough(test, 0));

			test = FMath::Sin(Constants::PI);
			Assert::IsTrue(SMath::CloseEnough(test, 0));

			test = FMath::Sin(10);
			Assert::IsTrue(SMath::CloseEnough(test, -0.544021110889f));

			test = FMath::Sin(Constants::PI / 4);
			Assert::IsTrue(SMath::CloseEnough(test, 0.707106781187f));
		}
	
		TEST_METHOD(CosTest)
		{
			float test = FMath::Cos(0);
			Assert::IsTrue(SMath::CloseEnough(test, 1));

			test = FMath::Cos(Constants::PI);
			Assert::IsTrue(SMath::CloseEnough(test, -1));

			test = FMath::Cos(10);
			Assert::IsTrue(SMath::CloseEnough(test, -0.839071529076f));

			test = FMath::Cos(Constants::PI / 4);
			Assert::IsTrue(SMath::CloseEnough(test, 0.707106781187f));
		}
		
		TEST_METHOD(TanTest)
		{
			float test = FMath::Tan(0);
			Assert::IsTrue(SMath::CloseEnough(test, 0));

			test = FMath::Tan(Constants::PI);
			Assert::IsTrue(SMath::CloseEnough(test, 0));

			test = FMath::Tan(10);
			Assert::IsTrue(SMath::CloseEnough(test, 0.648360827459f));

			test = FMath::Tan(Constants::PI / 4);
			Assert::IsTrue(SMath::CloseEnough(test, 1));
		}

		TEST_METHOD(AsinTest)
		{
			float test = FMath::Asin(-1);
			Assert::IsTrue(SMath::CloseEnough(test, -Constants::PI / 2));

			test = FMath::Asin(-.5f);
			Assert::IsTrue(SMath::CloseEnough(test, -30 * Constants::DEG_TO_RAD));

			test = FMath::Asin(0);
			Assert::IsTrue(SMath::CloseEnough(test, 0));

			test = FMath::Asin(.5f);
			Assert::IsTrue(SMath::CloseEnough(test, 30 * Constants::DEG_TO_RAD));

			test = FMath::Asin(1);
			Assert::IsTrue(SMath::CloseEnough(test, Constants::PI * .5f));
		}

		TEST_METHOD(AcosTest)
		{
			float test = FMath::Acos(1);
			Assert::IsTrue(SMath::CloseEnough(test, 0));

			test = FMath::Acos(.5f);
			Assert::IsTrue(SMath::CloseEnough(test, 1.04719755f));

			test = FMath::Acos(0);
			Assert::IsTrue(SMath::CloseEnough(test, 1.57079633f));

			test = FMath::Acos(-.5f);
			Assert::IsTrue(SMath::CloseEnough(test, 2.0943951f));

			test = FMath::Acos(-1);
			Assert::IsTrue(SMath::CloseEnough(test, 3.14159265f));

		}

		TEST_METHOD(AtanTest)
		{
			float test = FMath::Atan(-1);
			Assert::IsTrue(SMath::CloseEnough(test, -0.785398163397f));

			test = FMath::Atan(-.5f);
			Assert::IsTrue(SMath::CloseEnough(test, -0.463647609001f));

			test = FMath::Atan(0);
			Assert::IsTrue(SMath::CloseEnough(test, 0));

			test = FMath::Atan(.5f);
			Assert::IsTrue(SMath::CloseEnough(test, 0.463647609001f));

			test = FMath::Atan(1);
			Assert::IsTrue(SMath::CloseEnough(test, 0.785398163397f));
		}

		TEST_METHOD(Atan2Tests)
		{
			float test = FMath::Atan2(0, 1);
			Assert::IsTrue(SMath::CloseEnough(test, 0));

			test = FMath::Atan2(1, 0);
			Assert::IsTrue(SMath::CloseEnough(test, 1.5708f));

			test = FMath::Atan2(1, 1);
			Assert::IsTrue(SMath::CloseEnough(test, 0.7854f));

			test = FMath::Atan2(1, 2);
			Assert::IsTrue(SMath::CloseEnough(test, 0.4636f));

			test = FMath::Atan2(2, 1);
			Assert::IsTrue(SMath::CloseEnough(test, 1.1071f));
		}
	};
}