#include "TestUtils.h"

namespace SupergodEngineTesting
{		
	TEST_CLASS(MathTests)
	{
	public:
		TEST_METHOD(CloseEnoughTest)
		{
			Assert::IsTrue(Math::SMath::CloseEnough(1, 2, 1));
			Assert::IsTrue(Math::SMath::CloseEnough(1, 1.0000001f, 0.000001f));
			Assert::IsTrue(Math::SMath::CloseEnough(1, 1.0000001f));
			
			Assert::IsFalse(Math::SMath::CloseEnough(1, 2, .5f));
			Assert::IsFalse(Math::SMath::CloseEnough(1, 1.0000001f, 0.000000001f));
		}
	};
}