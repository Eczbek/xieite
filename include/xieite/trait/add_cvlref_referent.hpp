#pragma once

#include "../trait/add_cv_referent.hpp"
#include "../trait/add_lref_referent.hpp"

namespace xieite {
	template<typename T>
	using add_cvlref_referent = xieite::add_cv_referent<xieite::add_lref_referent<T>>;
}
