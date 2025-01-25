#pragma once

#include "../trait/set_rref_referent.hpp"
#include "../trait/set_noex.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_rref_noex = xieite::set_rref_referent<qual, xieite::set_noex<qual, T>>;
}
