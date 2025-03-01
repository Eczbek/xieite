#pragma once

#include "../trait/setcvreft.hpp"
#include "../trait/setrrefreft.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setcvrrefreft = x4::setcvreft<qual, x4::setrrefreft<qual, T>>;
}
