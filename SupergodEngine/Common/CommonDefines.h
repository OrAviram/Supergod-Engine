#pragma once

#define SUPERGOD_API __declspec(dllexport)
#define ARRAY_ELEMENTS_COUNT(array) sizeof(array) / sizeof(*array)
#define interface __interface

/// <summary>
/// Represents an 8-bit unsigned integer.
/// </summary>
typedef unsigned char byte;

/// <summary>
/// Represents an 8-bit signed integer.
/// </summary>
typedef char sbyte;

/// <summary>
/// Represents a 16-bit unsigned integer.
/// </summary>
typedef unsigned short ushort;

/// <summary>
/// Represents a 32-bit unsigned integer.
/// </summary>
typedef unsigned int uint;

/// <summary>
/// Represents a 64-bit unsigned integer.
/// </summary>
typedef unsigned long ulong;

/// <summary>
/// A 32 bit unsigned integer that is used as a boolean.
/// </summary>
typedef int Bool32;