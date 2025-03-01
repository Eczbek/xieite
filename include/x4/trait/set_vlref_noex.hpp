#pragma once

#include "../trait/setnoex.hpp"
#include "../trait/setvlrefreft.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvlrefnoex = x4::setvlrefreft<qual, x4::setnoex<qual, T>>;
}
