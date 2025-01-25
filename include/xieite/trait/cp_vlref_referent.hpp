#pragma once

#include "../trait/cp_v_referent.hpp"
#include "../trait/cp_lref_referent.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_vlref_referent = xieite::cp_v_referent<T, xieite::cp_lref_referent<T, U>>;
}
