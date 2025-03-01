#pragma once

#include <type_traits>
#include "../trait/addv.hpp"
#include "../trait/isv.hpp"
#include "../trait/rmv.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpv = std::conditional_t<x4::isv<T>, x4::add_v<U>, x4::rmv<U>>;
}
