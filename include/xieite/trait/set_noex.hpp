#pragma once

#include "../trait/add_noex.hpp"
#include "../trait/rm_noex.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_noex = std::conditional_t<qual, xieite::add_noex<T>, xieite::rm_noex<T>>;
}
