#pragma once

#include "../trait/rm_clref_referent.hpp"
#include "../trait/rm_var.hpp"

namespace xieite {
	template<typename T>
	using rm_var_clref = xieite::rm_var<xieite::rm_clref_referent<T>>;
}
