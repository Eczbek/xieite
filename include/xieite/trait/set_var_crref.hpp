#pragma once

#include "../trait/set_rref_referent.hpp"
#include "../trait/set_var_c.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var_crref = xieite::set_var_c<qual, xieite::set_rref_referent<qual, T>>;
}
