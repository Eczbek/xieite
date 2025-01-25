#pragma once

#include "../trait/set_noex.hpp"
#include "../trait/set_var_lref.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var_lref_noex = xieite::set_var_lref<qual, xieite::set_noex<qual, T>>;
}
