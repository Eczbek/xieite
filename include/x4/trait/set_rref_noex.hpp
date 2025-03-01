#pragma once

#include "../trait/setrrefreft.hpp"
#include "../trait/setnoex.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setrrefnoex = x4::setrrefreft<qual, x4::setnoex<qual, T>>;
}
