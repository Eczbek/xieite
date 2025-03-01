#pragma once

#include "../trait/setc.hpp"
#include "../trait/setrref.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setcrref = x4::setc<qual, x4::setrref<qual, T>>;
}
