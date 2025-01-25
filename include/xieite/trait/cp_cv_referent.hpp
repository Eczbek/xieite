#pragma once

#include "../trait/cp_c_referent.hpp"
#include "../trait/cp_v_referent.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_cv_referent = xieite::cp_c_referent<T, xieite::cp_v_referent<T, U>>;
}
