#include "TestUtils.h"

namespace SupergodEngineTesting
{
	using namespace Math;

	TEST_CLASS(SMathTests)
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

		TEST_METHOD(ClampTest)
		{
			float test = SMath::Clamp(5, 6, 10);
			Assert::AreEqual(test, 6.f);

			test = SMath::Clamp(5, 4, 10);
			Assert::AreEqual(test, 5.f);

			test = SMath::Clamp(20, 4, 10);
			Assert::AreEqual(test, 10.f);
		}

		TEST_METHOD(SignTest)
		{
			int sign = SMath::Sign(123);
			Assert::AreEqual(sign, 1);

			sign = SMath::Sign(0);
			Assert::AreEqual(sign, 1);

			sign = SMath::Sign(.2f);
			Assert::AreEqual(sign, 1);

			sign = SMath::Sign(-123);
			Assert::AreEqual(sign, -1);

			sign = SMath::Sign(-.2f);
			Assert::AreEqual(sign, -1);

			sign = SMath::Sign(-0);
			Assert::AreEqual(sign, 1);
		}

		TEST_METHOD(FactorialTest)
		{
			int x = SMath::Factorial(5);
			Assert::AreEqual(x, 120);

			x = SMath::Factorial(0);
			Assert::AreEqual(x, 1);

			x = SMath::Factorial(1);
			Assert::AreEqual(x, 1);
		}

		TEST_METHOD(AvrageTest)
		{
			float x = SMath::Average({ 2, 5, -1, 8, 5.5f, 2.3f, 0 });
			Assert::AreEqual(x, 3.1142857142857f);

			x = SMath::Average({ 3232, .32131f, .3232f, 321, 10101010, 0, 0, 0, 0, 1000 });
			Assert::AreEqual(x, 1010556.364451f);

			x = SMath::Average({ -1, -2, -3, -4, -5, 5, 4, 3, 2, 1, 1.5f, 2.5f, .4f, 10, 10000, 0, 0, 0, 0, 0, 0, 0, -1001 });
			Assert::AreEqual(x, 391.88695652174f);
		}

		TEST_METHOD(RootsPowersTests)
		{
			float test = SMath::Pow(3, 2);
			Assert::AreEqual(test, 9.f);

			test = SMath::Pow(.5f, 5);
			Assert::AreEqual(test, 0.03125f);

			test = SMath::Pow(-5, 10);
			AssertUtils::CloseEnough(test, 9765625);

			test = SMath::Pow(10, 2);
			AssertUtils::CloseEnough(test, 100);

			TestMultiple(1, 50, .1f, [&](float i)
			{
				test = SMath::Pow(i, -1);
				AssertUtils::CloseEnough(test, 1 / i);

				test = SMath::Pow(i, -2);
				AssertUtils::CloseEnough(test, 1 / (i * i));

				test = SMath::Pow(i, -i);
				AssertUtils::CloseEnough(test, 1 / SMath::Pow(i, i));

				test = SMath::Pow(i, 0);
				Assert::AreEqual(test, 1.f);

				test = SMath::Exp(i);
				Assert::AreEqual(test, SMath::Pow(Constants::E, i));

				test = SMath::Squared(i);
				Assert::AreEqual(test, i * i);
				Assert::AreEqual(test, SMath::Pow(i, 2));

				test = SMath::Cubed(i);
				AssertUtils::CloseEnough(test, i * i * i, .00785f);
				AssertUtils::CloseEnough(test, SMath::Pow(i, 3), .00785f);

				test = SMath::Sqrt(i);
				AssertUtils::CloseEnough(SMath::Squared(test), i);

				TestMultiple(1, 10, .1f, [&](float n)
				{
					test = SMath::Root(i, n);
					AssertUtils::CloseEnough(SMath::Pow(test, n), i);
				});

				test = SMath::Ln(i);
				AssertUtils::CloseEnough(SMath::Exp(test), i);

				test = SMath::Log10(i);
				AssertUtils::CloseEnough(SMath::Pow(10, test), i);

				TestMultiple(-10, 10, .1f, [&](float base)
				{
					test = SMath::Log(i, base);
					if (!SMath::IsNaN(test))
						AssertUtils::CloseEnough(SMath::Pow(base, test), i);
				});
			});
		}

		TEST_METHOD(AbsTest)
		{
			Assert::AreEqual(5.f, SMath::Abs(5));
			Assert::AreEqual(5.f, SMath::Abs(-5));
			Assert::AreNotEqual(4.f, SMath::Abs(-5));
		}

		TEST_METHOD(WrapTest)
		{
			float test = SMath::Wrap(2, 0, 3);
			Assert::AreEqual(2.f, test);

			test = SMath::Wrap(4, 3);
			Assert::AreEqual(1.f, test);

			test = SMath::Wrap(5, 0, 2);
			Assert::AreEqual(1.f, test);

			test = SMath::Wrap(360, 0, 180);
			Assert::AreEqual(180.f, test);

			test = SMath::Wrap(540, 360);
			Assert::AreEqual(180.f, test);

			test = SMath::Wrap(5, 10, 20);
			Assert::AreEqual(15.f, test);

			test = SMath::Wrap(9, 15, 20);
			Assert::AreEqual(19.f, test);

			test = SMath::Wrap(15, 15, 20);
			Assert::AreEqual(15.f, test);

			test = SMath::Wrap(20, 15, 20);
			Assert::AreEqual(20.f, test);

			test = SMath::Wrap(17, 15, 20);
			Assert::AreEqual(17.f, test);

			test = SMath::Wrap(0, 15, 20);
			Assert::AreEqual(15.f, test);

			test = SMath::Wrap(21, 15, 20);
			Assert::AreEqual(16.f, test);
		}

		TEST_METHOD(MaxTest)
		{
			float test = SMath::Max(5, .1f);
			Assert::AreEqual(test, 5.f);

			test = SMath::Max(-1, 0);
			Assert::AreEqual(test, 0.f);

			test = SMath::Max({ 1, 4, 1, .2f, -20 });
			Assert::AreEqual(test, 4.f);
		}

		TEST_METHOD(MinTest)
		{
			float test = SMath::Min(5, .1f);
			Assert::AreEqual(test, .1f);

			test = SMath::Min(-1, 0);
			Assert::AreEqual(test, -1.f);

			test = SMath::Min({ 1, 4, 1, .2f, -20 });
			Assert::AreEqual(test, -20.f);

		}

		TEST_METHOD(SinTest)
		{
			float test = SMath::Sin(0);
			Assert::IsTrue(SMath::CloseEnough(test, 0));

			test = SMath::Sin(Constants::PI);
			Assert::IsTrue(SMath::CloseEnough(test, 0));

			test = SMath::Sin(10);
			Assert::IsTrue(SMath::CloseEnough(test, -0.544021110889f));

			test = SMath::Sin(Constants::PI / 4);
			Assert::IsTrue(SMath::CloseEnough(test, 0.707106781187f));
		}
	
		TEST_METHOD(CosTest)
		{
			float test = SMath::Cos(0);
			Assert::IsTrue(SMath::CloseEnough(test, 1));

			test = SMath::Cos(Constants::PI);
			Assert::IsTrue(SMath::CloseEnough(test, -1));

			test = SMath::Cos(10);
			Assert::IsTrue(SMath::CloseEnough(test, -0.839071529076f));

			test = SMath::Cos(Constants::PI / 4);
			Assert::IsTrue(SMath::CloseEnough(test, 0.707106781187f));
		}
		
		TEST_METHOD(TanTest)
		{
			float test = SMath::Tan(0);
			Assert::IsTrue(SMath::CloseEnough(test, 0));

			test = SMath::Tan(Constants::PI);
			Assert::IsTrue(SMath::CloseEnough(test, 0));

			test = SMath::Tan(10);
			Assert::IsTrue(SMath::CloseEnough(test, 0.648360827459f));

			test = SMath::Tan(Constants::PI / 4);
			Assert::IsTrue(SMath::CloseEnough(test, 1));
		}

		TEST_METHOD(AsinTest)
		{
			float test = SMath::Asin(-1);
			Assert::IsTrue(SMath::CloseEnough(test, -Constants::PI / 2));

			test = SMath::Asin(-.5f);
			Assert::IsTrue(SMath::CloseEnough(test, -30 * Constants::DEG_TO_RAD));

			test = SMath::Asin(0);
			Assert::IsTrue(SMath::CloseEnough(test, 0));

			test = SMath::Asin(.5f);
			Assert::IsTrue(SMath::CloseEnough(test, 30 * Constants::DEG_TO_RAD));

			test = SMath::Asin(1);
			Assert::IsTrue(SMath::CloseEnough(test, Constants::PI * .5f));
		}

		TEST_METHOD(AcosTest)
		{
			float test = SMath::Acos(1);
			Assert::IsTrue(SMath::CloseEnough(test, 0));

			test = SMath::Acos(.5f);
			Assert::IsTrue(SMath::CloseEnough(test, 1.04719755f));

			test = SMath::Acos(0);
			Assert::IsTrue(SMath::CloseEnough(test, 1.57079633f));

			test = SMath::Acos(-.5f);
			Assert::IsTrue(SMath::CloseEnough(test, 2.0943951f));

			test = SMath::Acos(-1);
			Assert::IsTrue(SMath::CloseEnough(test, 3.14159265f));

		}

		TEST_METHOD(AtanTest)
		{
			float test = SMath::Atan(-1);
			Assert::IsTrue(SMath::CloseEnough(test, -0.785398163397f));

			test = SMath::Atan(-.5f);
			Assert::IsTrue(SMath::CloseEnough(test, -0.463647609001f));

			test = SMath::Atan(0);
			Assert::IsTrue(SMath::CloseEnough(test, 0));

			test = SMath::Atan(.5f);
			Assert::IsTrue(SMath::CloseEnough(test, 0.463647609001f));

			test = SMath::Atan(1);
			Assert::IsTrue(SMath::CloseEnough(test, 0.785398163397f));
		}

		TEST_METHOD(Atan2Tests)
		{
			float test = SMath::Atan2(0, 1);
			Assert::IsTrue(SMath::CloseEnough(test, 0));

			test = SMath::Atan2(1, 0);
			Assert::IsTrue(SMath::CloseEnough(test, 1.5708f));

			test = SMath::Atan2(1, 1);
			Assert::IsTrue(SMath::CloseEnough(test, 0.7854f));

			test = SMath::Atan2(1, 2);
			Assert::IsTrue(SMath::CloseEnough(test, 0.4636f));

			test = SMath::Atan2(2, 1);
			Assert::IsTrue(SMath::CloseEnough(test, 1.1071f));
		}
	};
}