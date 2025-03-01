#pragma once

#include "../trait/setnoex.hpp"
#include "../trait/setvrrefreft.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvrrefnoex = x4::setvrrefreft<qual, x4::setnoex<qual, T>>;
}
