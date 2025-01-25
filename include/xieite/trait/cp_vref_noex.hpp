#pragma once

#include "../trait/cp_vref_referent.hpp"
#include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_vref_noex = xieite::cp_vref_referent<T, xieite::cp_noex<T, U>>;
}
