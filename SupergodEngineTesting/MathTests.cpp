#include "TestUtils.h"

namespace SupergodEngineTesting
{		
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
	};
}