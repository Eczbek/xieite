#pragma once

#include "../trait/set_c_referent.hpp"
#include "../trait/set_noex.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_c_noex = xieite::set_c_referent<qual, xieite::set_noex<qual, T>>;
}
