#pragma once

#include <type_traits>
#include "../trait/add_v.hpp"
#include "../trait/is_v.hpp"
#include "../trait/rm_v.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_v = std::conditional_t<xieite::is_v<T>, xieite::add_v<U>, xieite::rm_v<U>>;
}
