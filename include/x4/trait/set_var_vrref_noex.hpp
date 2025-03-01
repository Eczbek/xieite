#pragma once

#include "../trait/setnoex.hpp"
#include "../trait/setvarvrref.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvarvrrefnoex = x4::setvarvrref<qual, x4::setnoex<qual, T>>;
}
