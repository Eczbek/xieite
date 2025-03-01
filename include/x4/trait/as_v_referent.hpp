#pragma once

#include "../pp/ar.hpp"
#include "../trait/addvreft.hpp"

namespace x4 {
	constexpr auto asvreft =
		[]<typename T>[[nodiscard]](T&& x)
			X4AR(const_cast<x4::add_vreft<T&&>>(x));
}
