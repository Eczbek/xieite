#pragma once

#include "../pp/ar.hpp"
#include "../trait/addc.hpp"

namespace x4 {
	constexpr auto asc =
		[]<typename T>[[nodiscard]](T&& x)
			X4AR(const_cast<x4::add_c<T&&>>(x));
}
