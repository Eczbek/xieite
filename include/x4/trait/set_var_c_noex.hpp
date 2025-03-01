#pragma once

#include "../trait/setnoex.hpp"
#include "../trait/setvarc.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvarcnoex = x4::setvarc<qual, x4::setnoex<qual, T>>;
}
