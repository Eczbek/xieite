#pragma once

#include "../trait/rm_cvrref_referent.hpp"
#include "../trait/rm_noex.hpp"

namespace xieite {
	template<typename T>
	using rm_cvrref_noex = xieite::rm_cvrref_referent<xieite::rm_noex<T>>;
}
