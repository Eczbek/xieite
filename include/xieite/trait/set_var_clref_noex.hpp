#pragma once

#include "../trait/set_noex.hpp"
#include "../trait/set_var_clref.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var_clref_noex = xieite::set_var_clref<qual, xieite::set_noex<qual, T>>;
}
