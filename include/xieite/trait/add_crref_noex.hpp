#pragma once

#include "../trait/add_crref_referent.hpp"
#include "../trait/add_noex.hpp"

namespace xieite {
	template<typename T>
	using add_crref_noex = xieite::add_crref_referent<xieite::add_noex<T>>;
}
