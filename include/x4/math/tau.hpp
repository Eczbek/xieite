#pragma once

#include "../math/pi.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	constexpr T tau = x4::pi<T> * 2;
}
