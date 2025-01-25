#pragma once

#include "../trait/add_noex.hpp"
#include "../trait/add_v_referent.hpp"

namespace xieite {
	template<typename T>
	using add_v_noex = xieite::add_v_referent<xieite::add_noex<T>>;
}
