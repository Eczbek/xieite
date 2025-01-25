#pragma once

#include "../trait/set_cv_referent.hpp"
#include "../trait/set_lref_referent.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_cvlref_referent = xieite::set_cv_referent<qual, xieite::set_lref_referent<qual, T>>;
}
