#pragma once

#include "../trait/isc.hpp"
#include "../trait/isrref.hpp"

namespace x4 {
	template<typename T>
	concept iscrref = x4::isc<T> && x4::isrref<T>;
}
