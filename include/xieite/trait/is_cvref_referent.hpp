#pragma once

#include "../trait/is_cvlref_referent.hpp"
#include "../trait/is_cvrref_referent.hpp"

namespace xieite {
	template<typename T>
	concept is_cvref_referent = xieite::is_cvlref_referent<T> || xieite::is_cvrref_referent<T>;
}
