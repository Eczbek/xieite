#pragma once

#include "../pp/ar.hpp"
#include "../trait/addcv.hpp"

namespace x4 {
	constexpr auto ascv =
		[]<typename T>[[nodiscard]](T&& x)
			X4AR(const_cast<x4::add_cv<T&&>>(x));
}
