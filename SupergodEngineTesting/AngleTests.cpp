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
	};
}