#pragma once

#include "../trait/rm_cvrref_referent.hpp"
#include "../trait/rm_var.hpp"

namespace xieite {
	template<typename T>
	using rm_var_cvrref = xieite::rm_var<xieite::rm_cvrref_referent<T>>;
}
