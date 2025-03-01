#pragma once

#include <type_traits>
#include "../trait/addc.hpp"
#include "../trait/rmc.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setc = std::conditional_t<qual, x4::add_c<T>, x4::rmc<T>>;
}
