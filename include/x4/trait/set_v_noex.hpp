#pragma once

#include "../trait/setnoex.hpp"
#include "../trait/setvreft.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvnoex = x4::setvreft<qual, x4::setnoex<qual, T>>;
}
