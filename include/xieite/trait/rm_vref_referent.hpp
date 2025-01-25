#pragma once

#include "../trait/rm_ref_referent.hpp"
#include "../trait/rm_v_referent.hpp"

namespace xieite {
	template<typename T>
	using rm_vref_referent = xieite::rm_v_referent<xieite::rm_ref_referent<T>>;
}
