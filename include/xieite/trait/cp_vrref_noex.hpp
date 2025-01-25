#pragma once

#include "../trait/cp_vrref_referent.hpp"
#include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_vrref_noex = xieite::cp_vrref_referent<T, xieite::cp_noex<T, U>>;
}
