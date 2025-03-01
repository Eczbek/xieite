#pragma once

#include "../trait/setcvlrefreft.hpp"
#include "../trait/setnoex.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setcvlrefnoex = x4::setcvlrefreft<qual, x4::setnoex<qual, T>>;
}
