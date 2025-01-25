#pragma once

#include "../trait/is_var.hpp"
#include "../trait/set_var.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var = xieite::set_var<xieite::is_var<T>, U>;
}
