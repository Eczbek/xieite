#pragma once

#include "../trait/set_c_referent.hpp"
#include "../trait/set_lref_referent.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_clref_referent = xieite::set_c_referent<qual, xieite::set_lref_referent<qual, T>>;
}
