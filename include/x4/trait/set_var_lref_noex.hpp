#pragma once

#include "../trait/setnoex.hpp"
#include "../trait/setvarlref.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvarlrefnoex = x4::setvarlref<qual, x4::setnoex<qual, T>>;
}
