#pragma once

#include "../trait/cp_ref_referent.hpp"
#include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_ref_noex = xieite::cp_ref_referent<T, xieite::cp_noex<T, U>>;
}
