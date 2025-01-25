#pragma once

#include "../trait/add_lref_referent.hpp"
#include "../trait/add_var_v.hpp"

namespace xieite {
	template<typename T>
	using add_var_vlref = xieite::add_var_v<xieite::add_lref_referent<T>>;
}
