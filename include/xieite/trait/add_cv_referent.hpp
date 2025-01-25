#pragma once

#include "../trait/add_c_referent.hpp"
#include "../trait/add_v_referent.hpp"

namespace xieite {
	template<typename T>
	using add_cv_referent = xieite::add_c_referent<xieite::add_v_referent<T>>;
}
