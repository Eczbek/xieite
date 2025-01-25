#pragma once

#include "../trait/set_rref_referent.hpp"
#include "../trait/set_var_cv.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var_cvrref = xieite::set_var_cv<qual, xieite::set_rref_referent<qual, T>>;
}
