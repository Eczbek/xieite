#pragma once

#include "../trait/cp_cv_referent.hpp"
#include "../trait/cp_lref_referent.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_cvlref_referent = xieite::cp_cv_referent<T, xieite::cp_lref_referent<T, U>>;
}
