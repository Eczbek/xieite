#pragma once

#include "../trait/setcvreft.hpp"
#include "../trait/setnoex.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setcvnoex = x4::setcvreft<qual, x4::setnoex<qual, T>>;
}
