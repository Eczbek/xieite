#pragma once

#include "../pp/ar.hpp"
#include "../trait/rmc.hpp"

namespace x4 {
	constexpr auto asnc =
		[]<typename T>[[nodiscard]](T&& x)
			X4AR(const_cast<x4::rmc<T&&>>(x));
}
