#pragma once

#include "../trait/is_m_fn_ptr.hpp"
#include "../trait/is_noex.hpp"
#include "../trait/is_vrref_referent.hpp"

namespace xieite {
	template<typename T>
	concept is_vrref_noex = (!xieite::is_m_fn_ptr<T> || xieite::is_vrref_referent<T>) && xieite::is_noex<T>;
}
