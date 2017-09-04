#pragma once

#include <CppUnitTest.h>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include <SupergodEngine.h>
using namespace SupergodEngine;

namespace AssertUtils
{
	void CloseEnough(float a, float b, float threshold = Math::Constants::CLOSE_ENOUGH_DEFAULT_THRESHOLD)
	{
		// TODO: Make more detailed fail message.
		Assert::IsTrue(Math::SMath::CloseEnough(a, b, threshold), L"Close enough failed!");
	}
}