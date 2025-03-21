#pragma once

#include "../trait/set_cvrref_referent.hpp"
#include "../trait/set_noex.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_cvrref_noex = xieite::set_cvrref_referent<qual, xieite::set_noex<qual, T>>;
}
