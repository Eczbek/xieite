#pragma once

#include "../trait/rm_noex.hpp"
#include "../trait/rm_vref_referent.hpp"

namespace xieite {
	template<typename T>
	using rm_vref_noex = xieite::rm_vref_referent<xieite::rm_noex<T>>;
}
