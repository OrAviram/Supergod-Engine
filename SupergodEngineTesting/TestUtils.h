#pragma once

#include <functional>
#include <random>
#include <ctime>

#include <CppUnitTest.h>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include <SupergodCore.h>
using namespace SupergodCore;

namespace AssertUtils
{
	static void CloseEnough(float a, float b, float threshold = Math::Constants::CLOSE_ENOUGH_DEFAULT_THRESHOLD)
	{
		// TODO: Make more detailed fail message.
		Assert::IsTrue(Math::SMath::CloseEnough(a, b, threshold), L"Close enough failed!");
	}

	template<class T>
	static void CloseEnough(const Math::ISupergodEquatable<T>& a, const T& b, float threshold = Math::Constants::CLOSE_ENOUGH_DEFAULT_THRESHOLD)
	{
		// TODO: Make more detailed fail message.
		Assert::IsTrue(a.CloseEnough(b, threshold), L"Close enough failed!");
	}

	static void TooFar(float a, float b, float threshold = Math::Constants::CLOSE_ENOUGH_DEFAULT_THRESHOLD)
	{
		// TODO: Make more detailed fail message.
		Assert::IsTrue(!Math::SMath::CloseEnough(a, b, threshold), L"Close enough failed!");
	}

	template<class T>
	static void TooFar(const Math::ISupergodEquatable<T>& a, const T& b, float threshold = Math::Constants::CLOSE_ENOUGH_DEFAULT_THRESHOLD)
	{
		// TODO: Make more detailed fail message.
		Assert::IsTrue(!a.CloseEnough(b, threshold), L"Too far failed!");
	}

	template<class T>
	static void AreEqual(T a, T b)
	{
		// TODO: Make more detailed fail message.
		Assert::IsTrue(a == b, L"Are equal failed!");
	}

	template<class T>
	static void AreNotEqual(T a, T b)
	{
		// TODO: Make more detailed fail message.
		Assert::IsTrue(a != b, L"Are equal failed!");
	}
}

template<class T>
static void TestVectorProjection(T source, T target)
{
	T bNormalized = target.Normalized();
	T oldResult = source.Dot(bNormalized) * bNormalized;
	T newResult = Math::Vector::ProjectOnto(source, target);

	AssertUtils::CloseEnough(newResult, oldResult, .001f);
}

/// <summary>
/// Generates a random float between 0 and 1.
/// </summary>
static float RandFloat()
{
	return static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
}

/// <summary>
/// Generates a random float between min and max.
/// </summary>
static float RandFloat(float min, float max)
{
	return min + RandFloat() * (max - min);
}

/// <summary>
/// Runs a test multiple times with customization to how it's ran.
/// </summary>
/// <param name="start">The start index of the loop.</param>
/// <param name="end">The end index of the loop.</param>
/// <param name="speed">How much should the current counter in the loop be increased by each iteration?</param>
/// <param name="test">The test to run.</param>
static void TestMultiple(float start, float end, float speed, std::function<void(float)> test)
{
	for (float i = start; i < end; i += speed)
		test(i);
}

/// <summary>
/// Runs a test length amount of times.
/// </summary>
/// <param name="length">The amount of times to run the test.</param>
/// <param name="test">The test to run.</param>
static void TestMultiple(int length, std::function<void(int)> test)
{
	TestMultiple(0, (float)length, 1, [&](float f) { test((int)f); });
}

/// <summary>
/// Runs test 30 times.
/// </summary>
/// <param name="test">The test to run.</param>
static void Test50(std::function<void(int)> test)
{
	TestMultiple(30, test);
}

/// <summary>
/// Runs a test counting from 0 to 1 with a speed of speed.
/// </summary>
/// <param name="speed">How much should the counter increase by each iteration?</param>
/// <param name="test">The test to run.</param>
static void Test01(float speed, std::function<void(float)> test)
{
	TestMultiple(0, 1, speed, test);
}

/// <summary>
/// Runs a test counting from 0 to 1 with a speed of 0.01.
/// </summary>
/// <param name="test">The test to run each iteration.</param>
static void Test01(std::function<void(float)> test)
{
	Test01(.01f, test);
}