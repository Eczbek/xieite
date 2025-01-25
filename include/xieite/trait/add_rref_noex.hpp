#pragma once

#include "../trait/add_noex.hpp"
#include "../trait/add_rref_referent.hpp"

namespace xieite {
	template<typename T>
	using add_rref_noex = xieite::add_rref_referent<xieite::add_noex<T>>;
}
