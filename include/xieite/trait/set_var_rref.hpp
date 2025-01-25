#pragma once

#include "../trait/set_rref_referent.hpp"
#include "../trait/set_var.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var_rref = xieite::set_var<qual, xieite::set_rref_referent<qual, T>>;
}
