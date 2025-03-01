#pragma once

#include "../trait/setcvreft.hpp"
#include "../trait/setlrefreft.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setcvlrefreft = x4::setcvreft<qual, x4::setlrefreft<qual, T>>;
}
