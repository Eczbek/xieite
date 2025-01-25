#pragma once

#include "../trait/rm_cv_referent.hpp"
#include "../trait/rm_ref_referent.hpp"

namespace xieite {
	template<typename T>
	using rm_cvref_referent = xieite::rm_cv_referent<xieite::rm_ref_referent<T>>;
}
