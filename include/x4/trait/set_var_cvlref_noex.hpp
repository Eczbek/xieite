#pragma once

#include "../trait/setnoex.hpp"
#include "../trait/setvarcvlref.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvarcvlrefnoex = x4::setvarcvlref<qual, x4::setnoex<qual, T>>;
}
