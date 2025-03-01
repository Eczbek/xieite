#pragma once

#include "../trait/setlrefreft.hpp"
#include "../trait/setnoex.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setlrefnoex = x4::setlrefreft<qual, x4::setnoex<qual, T>>;
}
