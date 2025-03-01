#pragma once

#include "../trait/issame_any.hpp"
#include "../trait/rmcv.hpp"

namespace x4 {
	template<typename T>
	concept isordinarych = x4::issame_any<x4::rmcv<T>, char, unsigned char, signed char>;
}
