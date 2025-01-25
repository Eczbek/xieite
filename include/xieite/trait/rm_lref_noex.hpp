#pragma once

#include "../trait/rm_lref_referent.hpp"
#include "../trait/rm_noex.hpp"

namespace xieite {
	template<typename T>
	using rm_lref_noex = xieite::rm_lref_referent<xieite::rm_noex<T>>;
}
