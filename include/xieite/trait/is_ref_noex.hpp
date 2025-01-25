#pragma once

#include "../trait/is_ref_referent.hpp"
#include "../trait/is_m_fn_ptr.hpp"
#include "../trait/is_noex.hpp"

namespace xieite {
	template<typename T>
	concept is_ref_noex = (!xieite::is_m_fn_ptr<T> || xieite::is_ref_referent<T>) && xieite::is_noex<T>;
}
