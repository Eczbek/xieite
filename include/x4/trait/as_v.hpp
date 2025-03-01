#pragma once

#include "../pp/ar.hpp"
#include "../trait/addv.hpp"

namespace x4 {
	constexpr auto asv =
		[]<typename T>[[nodiscard]](T&& x)
			X4AR(const_cast<x4::add_v<T&&>>(x));
}
