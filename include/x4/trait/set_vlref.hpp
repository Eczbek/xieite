#pragma once

#include "../trait/setv.hpp"
#include "../trait/setlref.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvlref = x4::setv<qual, x4::setlref<qual, T>>;
}
