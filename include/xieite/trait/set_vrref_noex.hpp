#pragma once

#include "../trait/set_noex.hpp"
#include "../trait/set_vrref_referent.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_vrref_noex = xieite::set_vrref_referent<qual, xieite::set_noex<qual, T>>;
}
