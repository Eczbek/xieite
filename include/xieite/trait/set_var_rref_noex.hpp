#pragma once

#include "../trait/set_noex.hpp"
#include "../trait/set_var_rref.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var_rref_noex = xieite::set_var_rref<qual, xieite::set_noex<qual, T>>;
}
