#pragma once

#include "../trait/is_cv_referent.hpp"
#include "../trait/is_rref_referent.hpp"

namespace xieite {
	template<typename T>
	concept is_cvrref_referent = xieite::is_cv_referent<T> && xieite::is_rref_referent<T>;
}
