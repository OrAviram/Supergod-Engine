#pragma once

#define SUPERGOD_API __declspec(dllexport)
#define ARRAY_ELEMENTS_COUNT(array) sizeof(array) / sizeof(*array)

/// <summary>
/// Simply defines a struct.<para/>
/// It used to use the __interface keyword, but apparently you can't export those to the dll.<para/>
/// Use this just to be explicit it's an interface, but it's simply a struct.
/// </summary>
#define interface struct


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