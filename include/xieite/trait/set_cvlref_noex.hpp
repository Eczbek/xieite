#pragma once

#include "../trait/set_cvlref_referent.hpp"
#include "../trait/set_noex.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_cvlref_noex = xieite::set_cvlref_referent<qual, xieite::set_noex<qual, T>>;
}
