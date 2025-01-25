#pragma once

#include "../trait/cp_c_referent.hpp"
#include "../trait/cp_rref_referent.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_crref_referent = xieite::cp_c_referent<T, xieite::cp_rref_referent<T, U>>;
}
