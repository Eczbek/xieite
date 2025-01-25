#pragma once

#include "../trait/rm_clref_referent.hpp"
#include "../trait/rm_noex.hpp"

namespace xieite {
	template<typename T>
	using rm_clref_noex = xieite::rm_clref_referent<xieite::rm_noex<T>>;
}
