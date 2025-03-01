#pragma once

#include "../trait/setrrefreft.hpp"
#include "../trait/setvarc.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvarcrref = x4::setvarc<qual, x4::setrrefreft<qual, T>>;
}
