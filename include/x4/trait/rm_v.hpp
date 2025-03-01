#pragma once

#include <type_traits>
#include "../trait/cpref.hpp"
#include "../trait/rmref.hpp"

namespace x4 {
	template<typename T>
	using rmv = x4::cpref<T, std::remove_volatile_t<x4::rmref<T>>>;
}
