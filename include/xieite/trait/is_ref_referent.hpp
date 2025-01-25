#pragma once

#include "../trait/is_lref_referent.hpp"
#include "../trait/is_rref_referent.hpp"

namespace xieite {
	template<typename T>
	concept is_ref_referent = xieite::is_lref_referent<T> || xieite::is_rref_referent<T>;
}
