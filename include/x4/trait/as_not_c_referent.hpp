#pragma once

#include "../pp/ar.hpp"
#include "../trait/rmcreft.hpp"

namespace x4 {
	constexpr auto asncreft =
		[]<typename T>[[nodiscard]](T&& x)
			X4AR(const_cast<x4::rmcreft<T&&>>(x));
}
