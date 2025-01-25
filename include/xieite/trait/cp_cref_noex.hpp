#pragma once

#include "../trait/cp_cref_referent.hpp"
#include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_cref_noex = xieite::cp_cref_referent<T, xieite::cp_noex<T, U>>;
}
