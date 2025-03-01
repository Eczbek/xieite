#pragma once

#include "../trait/setvreft.hpp"
#include "../trait/setvarc.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvarcv = x4::setvarc<qual, x4::setvreft<qual, T>>;
}
