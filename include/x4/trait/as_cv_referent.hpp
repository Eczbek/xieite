#pragma once

#include "../pp/ar.hpp"
#include "../trait/addcvreft.hpp"

namespace x4 {
	constexpr auto ascvreft =
		[]<typename T>[[nodiscard]](T&& x)
			X4AR(const_cast<x4::add_cvreft<T&&>>(x));
}
