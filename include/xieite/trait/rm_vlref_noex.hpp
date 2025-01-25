#pragma once

#include "../trait/rm_noex.hpp"
#include "../trait/rm_vlref_referent.hpp"

namespace xieite {
	template<typename T>
	using rm_vlref_noex = xieite::rm_vlref_referent<xieite::rm_noex<T>>;
}
