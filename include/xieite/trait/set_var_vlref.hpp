#pragma once

#include "../trait/set_lref_referent.hpp"
#include "../trait/set_var_v.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var_vlref = xieite::set_var_v<qual, xieite::set_lref_referent<qual, T>>;
}
