#pragma once

#include "../trait/isc.hpp"
#include "../trait/islref.hpp"

namespace x4 {
	template<typename T>
	concept isclref = x4::isc<T> && x4::islref<T>;
}
