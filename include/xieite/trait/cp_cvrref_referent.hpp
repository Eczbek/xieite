#pragma once

#include "../trait/cp_cv_referent.hpp"
#include "../trait/cp_rref_referent.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_cvrref_referent = xieite::cp_cv_referent<T, xieite::cp_rref_referent<T, U>>;
}
