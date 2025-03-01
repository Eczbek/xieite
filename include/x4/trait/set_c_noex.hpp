#pragma once

#include "../trait/setcreft.hpp"
#include "../trait/setnoex.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setcnoex = x4::setcreft<qual, x4::setnoex<qual, T>>;
}
