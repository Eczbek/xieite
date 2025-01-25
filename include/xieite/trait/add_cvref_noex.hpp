#pragma once

#include "../trait/add_cvref_referent.hpp"
#include "../trait/add_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using add_cvref_noex = xieite::add_cvref_referent<T, xieite::add_noex<U>>;
}
