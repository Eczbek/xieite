#pragma once

#include "../trait/cp_cvrref_referent.hpp"
#include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_cvrref_noex = xieite::set_cvrref_referent<T, xieite::cp_noex<T, U>>;
}
