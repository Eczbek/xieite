#pragma once

#include "../trait/add_cv_referent.hpp"
#include "../trait/add_noex.hpp"

namespace xieite {
	template<typename T>
	using add_cv_noex = xieite::add_cv_referent<xieite::add_noex<T>>;
}
