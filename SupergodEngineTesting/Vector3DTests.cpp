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
	};
}