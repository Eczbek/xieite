#pragma once

#include <type_traits>
#include "../trait/addcreft.hpp"
#include "../trait/rmcreft.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setcreft = std::conditional_t<qual, x4::add_creft<T>, x4::rmcreft<T>>;
}
