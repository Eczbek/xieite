#pragma once

#include "../trait/cp_c_referent.hpp"
#include "../trait/cp_lref_referent.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_clref_referent = xieite::cp_c_referent<T, xieite::cp_lref_referent<T, U>>;
}
