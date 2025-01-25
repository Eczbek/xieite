#pragma once

#include "../trait/rm_var.hpp"
#include "../trait/rm_vrref_referent.hpp"

namespace xieite {
	template<typename T>
	using rm_var_vrref = xieite::rm_var<xieite::rm_vrref_referent<T>>;
}
