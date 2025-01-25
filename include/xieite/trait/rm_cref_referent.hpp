#pragma once

#include "../trait/rm_clref_referent.hpp"
#include "../trait/rm_rref_referent.hpp"

namespace xieite {
	template<typename T>
	using rm_cref_referent = xieite::rm_clref_referent<xieite::rm_rref_referent<T>>;
}
