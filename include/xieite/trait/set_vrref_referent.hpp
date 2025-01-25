#pragma once

#include "../trait/set_v_referent.hpp"
#include "../trait/set_rref_referent.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_vrref_referent = xieite::set_v_referent<qual, xieite::set_rref_referent<qual, T>>;
}
