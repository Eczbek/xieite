#pragma once

#include "../trait/setcvrrefreft.hpp"
#include "../trait/setnoex.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setcvrrefnoex = x4::setcvrrefreft<qual, x4::setnoex<qual, T>>;
}
