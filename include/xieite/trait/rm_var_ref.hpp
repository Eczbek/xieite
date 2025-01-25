#pragma once

#include "../trait/rm_ref_referent.hpp"
#include "../trait/rm_var.hpp"

namespace xieite {
	template<typename T>
	using rm_var_ref = xieite::rm_var<xieite::rm_ref_referent<T>>;
}
