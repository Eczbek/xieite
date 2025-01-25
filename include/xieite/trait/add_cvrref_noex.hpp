#pragma once

#include "../trait/add_cvrref_referent.hpp"
#include "../trait/add_noex.hpp"

namespace xieite {
	template<typename T>
	using add_cvrref_noex = xieite::add_cvrref_referent<xieite::add_noex<T>>;
}
