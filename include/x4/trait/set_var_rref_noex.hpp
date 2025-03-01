#pragma once

#include "../trait/setnoex.hpp"
#include "../trait/setvarrref.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvarrrefnoex = x4::setvarrref<qual, x4::setnoex<qual, T>>;
}
