#pragma once

#include "../trait/add_c_referent.hpp"
#include "../trait/add_lref_referent.hpp"

namespace xieite {
	template<typename T>
	using add_clref_referent = xieite::add_c_referent<xieite::add_lref_referent<T>>;
}
