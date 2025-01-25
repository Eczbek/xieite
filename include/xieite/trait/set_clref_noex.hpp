#pragma once

#include "../trait/set_clref_referent.hpp"
#include "../trait/set_noex.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_clref_noex = xieite::set_clref_referent<qual, xieite::set_noex<qual, T>>;
}
