#pragma once

#include "../trait/cp_v_referent.hpp"
#include "../trait/cp_rref_referent.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_vrref_referent = xieite::cp_v_referent<T, xieite::cp_rref_referent<T, U>>;
}
