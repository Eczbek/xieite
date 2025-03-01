#pragma once

#include <concepts>
#include "../trait/isordinary_ch.hpp"
#include "../trait/rmcv.hpp"

namespace x4 {
	template<typename T>
	concept isnarrowch = x4::isordinary_ch<T> || std::same_as<x4::rmcv<T>, char8_t>;
}
