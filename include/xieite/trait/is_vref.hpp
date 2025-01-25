#pragma once

#include "../trait/is_vlref.hpp"
#include "../trait/is_vrref.hpp"

namespace xieite {
	template<typename T>
	concept is_vref = xieite::is_vlref<T> || xieite::is_vrref<T>;
}
