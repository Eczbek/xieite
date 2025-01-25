#pragma once

#include "../trait/cp_clref_referent.hpp"
#include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_clref_noex = xieite::cp_clref_referent<T, xieite::cp_noex<T, U>>;
}
