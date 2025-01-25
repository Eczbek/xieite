#pragma once

#include "../trait/set_lref_referent.hpp"
#include "../trait/set_var.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var_lref = xieite::set_var<qual, xieite::set_lref_referent<qual, T>>;
}
