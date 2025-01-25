#pragma once

#include "../trait/rm_var.hpp"
#include "../trait/rm_vlref_referent.hpp"

namespace xieite {
	template<typename T>
	using rm_var_vlref = xieite::rm_var<xieite::rm_vlref_referent<T>>;
}
