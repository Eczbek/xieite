#pragma once

#include "../trait/rm_noex.hpp"
#include "../trait/rm_vrref_referent.hpp"

namespace xieite {
	template<typename T>
	using rm_vrref_noex = xieite::rm_vrref_referent<xieite::rm_noex<T>>;
}
