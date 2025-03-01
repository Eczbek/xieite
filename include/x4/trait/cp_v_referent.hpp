#pragma once

#include <type_traits>
#include "../trait/addvreft.hpp"
#include "../trait/isvreft.hpp"
#include "../trait/rmvreft.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvreft = std::conditional_t<x4::isvreft<T>, x4::add_vreft<U>, x4::rmvreft<U>>;
}
