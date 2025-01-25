#pragma once

#include "../trait/rm_lref_referent.hpp"
#include "../trait/rm_rref_referent.hpp"

namespace xieite {
	template<typename T>
	using rm_ref_referent = xieite::rm_lref_referent<xieite::rm_rref_referent<T>>;
}
