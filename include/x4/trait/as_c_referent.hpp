#pragma once

#include "../pp/ar.hpp"
#include "../trait/addcreft.hpp"

namespace x4 {
	constexpr auto ascreft =
		[]<typename T>[[nodiscard]](T&& x)
			X4AR(const_cast<x4::add_creft<T&&>>(x));
}
