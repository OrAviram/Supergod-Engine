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

		// TODO: Add AxisCombinationTests.

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
	};
}