#pragma once

#include "../trait/setnoex.hpp"
#include "../trait/setvarcvrref.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvarcvrrefnoex = x4::setvarcvrref<qual, x4::setnoex<qual, T>>;
}
