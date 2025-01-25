#pragma once

#include <type_traits>
#include "../trait/add_var.hpp"
#include "../trait/rm_var.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var = std::conditional_t<qual, xieite::add_var<T>, xieite::rm_var<T>>;
}
