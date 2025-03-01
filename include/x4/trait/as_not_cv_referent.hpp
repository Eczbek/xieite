#pragma once

#include "../pp/ar.hpp"
#include "../trait/rmcvreft.hpp"

namespace x4 {
	constexpr auto asncvreft =
		[]<typename T>[[nodiscard]](T&& x)
			X4AR(const_cast<x4::rmcvreft<T&&>>(x));
}
