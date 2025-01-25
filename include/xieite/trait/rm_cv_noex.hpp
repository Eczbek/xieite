#pragma once

#include "../trait/rm_cv_referent.hpp"
#include "../trait/rm_noex.hpp"

namespace xieite {
	template<typename T>
	using rm_cv_noex = xieite::rm_cv_referent<xieite::rm_noex<T>>;
}
