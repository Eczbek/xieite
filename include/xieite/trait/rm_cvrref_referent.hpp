#pragma once

#include "../trait/rm_cv_referent.hpp"
#include "../trait/rm_rref_referent.hpp"

namespace xieite {
	template<typename T>
	using rm_cvrref_referent = xieite::rm_cv_referent<xieite::rm_rref_referent<T>>;
}
