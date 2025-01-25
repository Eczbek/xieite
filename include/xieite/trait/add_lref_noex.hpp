#pragma once

#include "../trait/add_lref_referent.hpp"
#include "../trait/add_noex.hpp"

namespace xieite {
	template<typename T>
	using add_lref_noex = xieite::add_lref_referent<xieite::add_noex<T>>;
}
