#pragma once

#include "../trait/rm_rref_referent.hpp"
#include "../trait/rm_var.hpp"

namespace xieite {
	template<typename T>
	using rm_var_rref = xieite::rm_var<xieite::rm_rref_referent<T>>;
}
