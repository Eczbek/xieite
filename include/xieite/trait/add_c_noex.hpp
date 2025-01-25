#pragma once

#include "../trait/add_c_referent.hpp"
#include "../trait/add_noex.hpp"

namespace xieite {
	template<typename T>
	using add_c_noex = xieite::add_c_referent<xieite::add_noex<T>>;
}
