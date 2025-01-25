#pragma once

#include "../trait/rm_var.hpp"
#include "../trait/rm_crref_referent.hpp"

namespace xieite {
	template<typename T>
	using rm_var_crref = xieite::rm_var<xieite::rm_crref_referent<T>>;
}
