#pragma once

#include <type_traits>
#include "../trait/addvreft.hpp"
#include "../trait/rmvreft.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvreft = std::conditional_t<qual, x4::add_vreft<T>, x4::rmvreft<T>>;
}
