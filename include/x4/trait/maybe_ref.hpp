#pragma once

#include <type_traits>
#include "../trait/hastrivcp.hpp"

namespace x4 {
	template<typename T>
	using maybe_ref = std::conditional_t<(sizeof(T) <= (sizeof(int*) * 2)) && x4::hastrivcp<T>, T, const T&>; 
}
