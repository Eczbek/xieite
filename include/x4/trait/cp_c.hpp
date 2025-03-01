#pragma once

#include "../trait/setc.hpp"
#include "../trait/isc.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpc = x4::setc<x4::isc<T>, U>;
}
