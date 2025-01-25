#pragma once

#include "../trait/set_rref_referent.hpp"
#include "../trait/set_var_v.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var_vrref = xieite::set_var_v<qual, xieite::set_rref_referent<qual, T>>;
}
