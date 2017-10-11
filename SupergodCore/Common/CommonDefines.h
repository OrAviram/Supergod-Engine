#pragma once

#define SUPERGOD_API_FUNC __declspec(dllexport)
#define SUPERGOD_API_CLASS __declspec(dllexport, empty_bases)
#define ARRAY_ELEMENTS_COUNT(array) sizeof(array) / sizeof(*array)

/// <summary>
/// Simply defines a struct.<para/>
/// It used to use the __interface keyword, but apparently you can't export those to the dll.<para/>
/// Use this just to be explicit it's an interface, but it's simply a struct.
/// </summary>
#define interface struct

/// <summary>
/// Defines a preset value for a struct (because you can't use const with those). This is being undefined in SupergodEngine.h.
/// </summary>
#define DEFINE_STRUCT_VALUE_PRESET(type, name, value) \
			inline static const type& name() \
			{ \
				static const type val value; \
				return val; \
			}

/// <summary>
/// A templated interface is an interface where the type of class for the template parameter is the type that implements the interface.<para/>
/// This macro will use a static cast to cast this into a reference to the template type, where its name is templateName.<para/>
/// Undefined in SupergodEngine.h.
/// </summary>
#define TEMPLATED_INTERFACE_THIS_CUSTOM_NAME(templateName) static_cast<const templateName&>(*this)

/// <summary>
/// A templated interface is an interface where the type of class for the template parameter is the type that implements the interface.<para/>
/// This macro will use a static cast to cast this into a reference to the template type, where its name is T.<para/>
/// Undefined in SupergodEngine.h.
/// </summary>
#define TEMPLATED_INTERFACE_THIS TEMPLATED_INTERFACE_THIS_CUSTOM_NAME(T)

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