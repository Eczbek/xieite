#pragma once

#include "../trait/setcrrefreft.hpp"
#include "../trait/setnoex.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setcrrefnoex = x4::setcrrefreft<qual, x4::setnoex<qual, T>>;
}
