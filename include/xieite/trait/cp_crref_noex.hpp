#pragma once

#include "../trait/cp_crref_referent.hpp"
#include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_crref_noex = xieite::cp_crref_referent<T, xieite::cp_noex<T, U>>;
}
