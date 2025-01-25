#pragma once

#include "../trait/set_noex.hpp"
#include "../trait/set_var_vrref.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var_vrref_noex = xieite::set_var_vrref<qual, xieite::set_noex<qual, T>>;
}
