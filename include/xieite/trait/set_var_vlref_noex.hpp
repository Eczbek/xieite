#pragma once

#include "../trait/set_noex.hpp"
#include "../trait/set_var_vlref.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var_vlref_noex = xieite::set_var_vlref<qual, xieite::set_noex<qual, T>>;
}
