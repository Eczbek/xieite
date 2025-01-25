#pragma once

#include "../trait/set_noex.hpp"
#include "../trait/set_v_referent.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_v_noex = xieite::set_v_referent<qual, xieite::set_noex<qual, T>>;
}
