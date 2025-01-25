#pragma once

#include "../trait/set_cv_referent.hpp"
#include "../trait/set_rref_referent.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_cvrref_referent = xieite::set_cv_referent<qual, xieite::set_rref_referent<qual, T>>;
}
