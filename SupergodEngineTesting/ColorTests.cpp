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
	};
}