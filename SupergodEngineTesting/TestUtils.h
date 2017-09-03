#pragma once

#include <CppUnitTest.h>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// TODO: not hardcode the paths.
#include "../SupergodEngine/Math/FMath.h"
#include "../SupergodEngine/Math/MathConstants.h"
#include "../SupergodEngine/Math/SMath.h"
using namespace SupergodEngine::Math;

namespace AssertUtils
{
	void CloseEnough(float a, float b, float threshold = Constants::CLOSE_ENOUGH_DEFAULT_THRESHOLD)
	{
		// TODO: Make more detailed fail message.
		Assert::IsTrue(SMath::CloseEnough(a, b, threshold), L"Close enough failed!");
	}
}