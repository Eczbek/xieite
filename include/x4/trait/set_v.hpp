#pragma once

#include <type_traits>
#include "../trait/addv.hpp"
#include "../trait/rmv.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setv = std::conditional_t<qual, x4::add_v<T>, x4::rmv<T>>;
}
