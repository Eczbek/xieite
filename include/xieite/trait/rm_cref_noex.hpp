#pragma once

#include "../trait/rm_cref_referent.hpp"
#include "../trait/rm_noex.hpp"

namespace xieite {
	template<typename T>
	using rm_cref_noex = xieite::rm_cref_referent<xieite::rm_noex<T>>;
}
