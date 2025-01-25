#pragma once

#include "../trait/add_lref_referent.hpp"
#include "../trait/add_v_referent.hpp"

namespace xieite {
	template<typename T>
	using add_vlref_referent = xieite::add_v_referent<xieite::add_lref_referent<T>>;
}
