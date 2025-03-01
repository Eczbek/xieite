#pragma once

#include <type_traits>
#include "../trait/issame_any.hpp"
#include "../trait/iswide_ch.hpp"
#include "../trait/rmcv.hpp"

namespace x4 {
	template<typename T>
	concept isch = x4::iswide_ch<T> || x4::issame_any<x4::rmcv<T>, char, char8_t>;
}
