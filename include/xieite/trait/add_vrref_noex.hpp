#pragma once

#include "../trait/add_noex.hpp"
#include "../trait/add_vrref_referent.hpp"

namespace xieite {
	template<typename T>
	using add_vrref_noex = xieite::add_vrref_referent<xieite::add_noex<T>>;
}
