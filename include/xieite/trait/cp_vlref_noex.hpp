#pragma once

#include "../trait/cp_vlref_referent.hpp"
#include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_vlref_noex = xieite::cp_vlref_referent<T, xieite::cp_noex<T, U>>;
}
