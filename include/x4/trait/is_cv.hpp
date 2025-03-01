#pragma once

#include "../trait/isc.hpp"
#include "../trait/isv.hpp"

namespace x4 {
	template<typename T>
	concept iscv = x4::isc<T> && x4::isv<T>;
}
