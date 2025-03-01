#pragma once

#include "../pp/ar.hpp"
#include "../trait/rmv.hpp"

namespace x4 {
	constexpr auto asnv =
		[]<typename T>[[nodiscard]](T&& x)
			X4AR(const_cast<x4::rmv<T&&>>(x));
}
