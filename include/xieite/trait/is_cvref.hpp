#pragma once

#include "../trait/is_cvlref.hpp"
#include "../trait/is_cvrref.hpp"

namespace xieite {
	template<typename T>
	concept is_cvref = xieite::is_cvlref<T> || xieite::is_cvrref<T>;
}
