#pragma once

#include <type_traits>
#include "../trait/isrref.hpp"
#include "../trait/rmref.hpp"

namespace x4 {
	template<typename T>
	using rmrref = std::conditional_t<x4::isrref<T>, x4::rmref<T>, T>;
}
