#pragma once

#include "../trait/rm_rref_referent.hpp"
#include "../trait/rm_v_referent.hpp"

namespace xieite {
	template<typename T>
	using rm_vrref_referent = xieite::rm_v_referent<xieite::rm_rref_referent<T>>;
}
