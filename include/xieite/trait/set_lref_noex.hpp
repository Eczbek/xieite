#pragma once

#include "../trait/set_lref_referent.hpp"
#include "../trait/set_noex.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_lref_noex = xieite::set_lref_referent<qual, xieite::set_noex<qual, T>>;
}
