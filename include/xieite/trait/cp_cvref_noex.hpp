#pragma once

#include "../trait/cp_cvref_referent.hpp"
#include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_cvref_noex = xieite::set_cvref_referent<T, xieite::cp_noex<T, U>>;
}
