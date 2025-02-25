#pragma once

#include "../trait/set_noex.hpp"
#include "../trait/set_var_v.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var_v_noex = xieite::set_var_v<qual, xieite::set_noex<qual, T>>;
}
