#pragma once

#include "../trait/setnoex.hpp"
#include "../trait/setvarv.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvarvnoex = x4::setvarv<qual, x4::setnoex<qual, T>>;
}
