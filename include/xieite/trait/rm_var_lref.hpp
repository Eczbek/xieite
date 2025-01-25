#pragma once

#include "../trait/rm_lref_referent.hpp"
#include "../trait/rm_var.hpp"

namespace xieite {
	template<typename T>
	using rm_var_lref = xieite::rm_var<xieite::rm_lref_referent<T>>;
}
