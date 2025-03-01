#pragma once

#include "../trait/setvreft.hpp"
#include "../trait/setlrefreft.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvlrefreft = x4::setvreft<qual, x4::setlrefreft<qual, T>>;
}
