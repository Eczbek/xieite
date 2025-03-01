#pragma once

#include "../trait/setnoex.hpp"
#include "../trait/setvarvlref.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvarvlrefnoex = x4::setvarvlref<qual, x4::setnoex<qual, T>>;
}
