#pragma once

#include "../trait/rm_ref_referent.hpp"
#include "../trait/rm_noex.hpp"

namespace xieite {
	template<typename T>
	using rm_ref_noex = xieite::rm_ref_referent<xieite::rm_noex<T>>;
}
