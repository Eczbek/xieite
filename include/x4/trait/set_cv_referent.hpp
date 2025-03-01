#pragma once

#include "../trait/setcreft.hpp"
#include "../trait/setvreft.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setcvreft = x4::setcreft<qual, x4::setvreft<qual, T>>;
}
