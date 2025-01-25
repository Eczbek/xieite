#pragma once

#include "../trait/rm_c_referent.hpp"
#include "../trait/rm_lref_referent.hpp"

namespace xieite {
	template<typename T>
	using rm_clref_referent = xieite::rm_c_referent<xieite::rm_lref_referent<T>>;
}
