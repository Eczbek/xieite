#pragma once

#include "../trait/setnoex.hpp"
#include "../trait/setvarclref.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvarclrefnoex = x4::setvarclref<qual, x4::setnoex<qual, T>>;
}
