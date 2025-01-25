#pragma once

#include "../trait/rm_c_referent.hpp"
#include "../trait/rm_var.hpp"

namespace xieite {
	template<typename T>
	using rm_var_c = xieite::rm_var<xieite::rm_c_referent<T>>;
}
