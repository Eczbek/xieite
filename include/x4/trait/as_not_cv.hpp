#pragma once

#include "../pp/ar.hpp"
#include "../trait/rmcv.hpp"

namespace x4 {
	constexpr auto asncv =
		[]<typename T>[[nodiscard]](T&& x)
			X4AR(const_cast<x4::rmcv<T&&>>(x));
}
