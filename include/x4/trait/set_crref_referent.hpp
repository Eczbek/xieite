#pragma once

#include "../trait/setcreft.hpp"
#include "../trait/setrrefreft.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setcrrefreft = x4::setcreft<qual, x4::setrrefreft<qual, T>>;
}
