#pragma once

#include "../trait/set_v_referent.hpp"
#include "../trait/set_lref_referent.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_vlref_referent = xieite::set_v_referent<qual, xieite::set_lref_referent<qual, T>>;
}
