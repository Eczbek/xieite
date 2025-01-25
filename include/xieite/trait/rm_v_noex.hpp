#pragma once

#include "../trait/rm_v_referent.hpp"
#include "../trait/rm_noex.hpp"

namespace xieite {
	template<typename T>
	using rm_v_noex = xieite::rm_v_referent<xieite::rm_noex<T>>;
}
