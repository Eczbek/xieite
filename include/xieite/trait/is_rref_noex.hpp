#pragma once

#include "../trait/is_rref_referent.hpp"
#include "../trait/is_m_fn_ptr.hpp"
#include "../trait/is_noex.hpp"

namespace xieite {
	template<typename T>
	concept is_rref_noex = (!xieite::is_m_fn_ptr<T> || xieite::is_rref_referent<T>) && xieite::is_noex<T>;
}
