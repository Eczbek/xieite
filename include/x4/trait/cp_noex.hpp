#pragma once

#include "../trait/isnoex.hpp"
#include "../trait/setnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpnoex = x4::setnoex<x4::isnoex<T>, U>;
}
