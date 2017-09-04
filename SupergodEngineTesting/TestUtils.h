#pragma once
#include <functional>

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

/// <summary>
/// Runs a test multiple times with customization to how it's ran.
/// </summary>
/// <param name="start">The start index of the loop.</param>
/// <param name="end">The end index of the loop.</param>
/// <param name="speed">How much should the current counter in the loop be increased by each iteration?</param>
/// <param name="test">The test to run.</param>
void TestMultiple(float start, float end, float speed, std::function<void(float)> test)
{
	for (float i = start; i < end; i += speed)
		test(i);
}

/// <summary>
/// Runs a test length amount of times.
/// </summary>
/// <param name="length">The amount of times to run the test.</param>
/// <param name="test">The test to run.</param>
void TestMultiple(int length, std::function<void(int)> test)
{
	TestMultiple(0, (float)length, 1, [&](float f) { test((int)f); });
}

/// <summary>
/// Runs test 30 times.
/// </summary>
/// <param name="test">The test to run.</param>
void Test50(std::function<void(int)> test)
{
	TestMultiple(30, test);
}

/// <summary>
/// Runs a test counting from 0 to 1 with a speed of speed.
/// </summary>
/// <param name="speed">How much should the counter increase by each iteration?</param>
/// <param name="test">The test to run.</param>
void Test01(float speed, std::function<void(float)> test)
{
	TestMultiple(0, 1, speed, test);
}

/// <summary>
/// Runs a test counting from 0 to 1 with a speed of 0.01.
/// </summary>
/// <param name="test">The test to run each iteration.</param>
void Test01(std::function<void(float)> test)
{
	Test01(.01f, test);
}