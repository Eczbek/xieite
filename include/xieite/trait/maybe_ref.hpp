#pragma once

#include <type_traits>
#include "../trait/has_trivial_cp.hpp"

namespace xieite {
	template<typename T>
	using maybe_ref = std::conditional_t<(sizeof(T) <= (sizeof(int*) * 2)) && xieite::has_trivial_cp<T>, T, const T&>; 
}
