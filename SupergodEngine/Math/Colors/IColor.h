#pragma once

#include "Common/CommonDefines.h"
#include "../Interfaces/ISupergodEquatable.h"

namespace SupergodEngine { namespace Math
{
	/// <summary>
	/// Interface color structs can implement.
	/// </summary>
	template<class T>
	interface SUPERGOD_API IColor : public ISupergodEquatable<T>
	{
	};
} }