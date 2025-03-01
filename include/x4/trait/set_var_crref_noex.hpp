#pragma once

#include "../trait/setnoex.hpp"
#include "../trait/setvarcrref.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvarcrrefnoex = x4::setvarcrref<qual, x4::setnoex<qual, T>>;
}
