#pragma once

#include "../pp/ar.hpp"
#include "../trait/rmvreft.hpp"

namespace x4 {
	constexpr auto asnvreft =
		[]<typename T>[[nodiscard]](T&& x)
			X4AR(const_cast<x4::rmvreft<T&&>>(x));
}
