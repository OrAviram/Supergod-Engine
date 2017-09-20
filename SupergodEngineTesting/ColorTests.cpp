#include "TestUtils.h"

namespace SupergodEngineTesting
{
	using namespace Math;

	TEST_CLASS(ColorTests)
	{
	public:
		TEST_METHOD(BColorTest)
		{
			std::srand((uint)std::time(0));
			
			Test50([&](int i)
			{
				byte r = std::rand();
				byte g = std::rand();
				byte b = std::rand();
				byte a = std::rand();
				
				BColor color(r, g, b, a);
				Assert::AreEqual(r, color.red);
				Assert::AreEqual(g, color.green);
				Assert::AreEqual(b, color.blue);
				Assert::AreEqual(a, color.alpha);

				Assert::AreEqual(r, color[0]);
				Assert::AreEqual(g, color[1]);
				Assert::AreEqual(b, color[2]);
				Assert::AreEqual(a, color[3]);

				uint uintValue = std::rand();
				
				color = uintValue;
				Assert::AreEqual(color.value, BColor(uintValue).value);
				Assert::AreEqual(color.value, uintValue);
				Assert::AreEqual((uint)color, uintValue);
			});
		}

		TEST_METHOD(FColorConstructionTest)
		{
			std::srand((uint)std::time(0));

			Test50([&](int i)
			{
				float r = RandFloat();
				float g = RandFloat();
				float b = RandFloat();
				float a = RandFloat();

				FColor color(r, g, b, a);
				Assert::AreEqual(r, color.red);
				Assert::AreEqual(g, color.green);
				Assert::AreEqual(b, color.blue);
				Assert::AreEqual(a, color.alpha);
			});
		}

		TEST_METHOD(AdditionSubtractionTests)
		{
			Test50([&](int i)
			{
				float aRed = RandFloat();
				float aGreen = RandFloat();
				float aBlue = RandFloat();
				float aAlpha = RandFloat();

				float bRed = RandFloat();
				float bGreen = RandFloat();
				float bBlue = RandFloat();
				float bAlpha = RandFloat();

				FColor a(aRed, aGreen, aBlue, aAlpha);
				FColor b(bRed, bGreen, bBlue, bAlpha);

				FColor result1 = a + b;
				FColor result2 = b + a;

				AssertUtils::CloseEnough(result1, result2);
				AssertUtils::CloseEnough(result1 - b, a);
				AssertUtils::CloseEnough(result2 - a, b);
				
				AssertUtils::CloseEnough(result1, FColor(aRed + bRed, aGreen + bGreen, aBlue + bBlue, aAlpha + bAlpha));
				AssertUtils::CloseEnough(result1, FColor(aRed + bRed, aGreen + bGreen, aBlue + bBlue, aAlpha + bAlpha));
			});

		}

		TEST_METHOD(ScalingTests)
		{
			FColor color(1, 1, 1, 1);
			float scalar = .5f;

			FColor result1 = color * scalar;
			FColor result2 = scalar * color;

			Assert::IsTrue(result1.red == .5f);
			Assert::IsTrue(result1.red == result2.red);

			Assert::IsTrue(result1.green == .5f);
			Assert::IsTrue(result1.green == result2.green);

			Assert::IsTrue(result1.blue == .5f);
			Assert::IsTrue(result1.blue == result2.blue);

			Assert::IsTrue(result1.alpha == .5f);
			Assert::IsTrue(result1.alpha == result2.alpha);

			result1 /= scalar;
			AssertUtils::AreEqual(result1, result2 / scalar);
			AssertUtils::AreEqual(result1, color);
		}
		
		TEST_METHOD(MultiplicationDivisionTests)
		{
			FColor a(1, 1, 1, 1);
			FColor b(2, 3, 4, -1);

			FColor result1 = a * b;
			FColor result2 = b * a;

			Assert::IsTrue(result1.red == 2);
			Assert::IsTrue(result1.red == result2.red);

			Assert::IsTrue(result1.green == 3);
			Assert::IsTrue(result1.green == result2.green);

			Assert::IsTrue(result1.blue == 4);
			Assert::IsTrue(result1.blue == result2.blue);

			Assert::IsTrue(result1.alpha == -1);
			Assert::IsTrue(result1.alpha == result2.alpha);

			result1 /= b;
			AssertUtils::AreEqual(result1, a);

			result2 /= a;
			AssertUtils::AreEqual(result2, b);
		}
	};
}