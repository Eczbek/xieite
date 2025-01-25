#pragma once

#include "../trait/rm_crref_referent.hpp"
#include "../trait/rm_noex.hpp"

namespace xieite {
	template<typename T>
	using rm_crref_noex = xieite::rm_crref_referent<xieite::rm_noex<T>>;
}
