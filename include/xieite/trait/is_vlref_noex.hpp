#pragma once

#include "../trait/is_m_fn_ptr.hpp"
#include "../trait/is_noex.hpp"
#include "../trait/is_vlref_referent.hpp"

namespace xieite {
	template<typename T>
	concept is_vlref_noex = (!xieite::is_m_fn_ptr<T> || xieite::is_vlref_referent<T>) && xieite::is_noex<T>;
}
