#pragma once

#include "../trait/setvreft.hpp"
#include "../trait/setrrefreft.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvrrefreft = x4::setvreft<qual, x4::setrrefreft<qual, T>>;
}
