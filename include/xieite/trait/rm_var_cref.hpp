#pragma once

#include "../trait/rm_cref_referent.hpp"
#include "../trait/rm_var.hpp"

namespace xieite {
	template<typename T>
	using rm_var_cref = xieite::rm_var<xieite::rm_cref_referent<T>>;
}
