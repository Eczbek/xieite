#pragma once

#include "../trait/set_c_referent.hpp"
#include "../trait/set_v_referent.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_cv_referent = xieite::set_c_referent<qual, xieite::set_v_referent<qual, T>>;
}
