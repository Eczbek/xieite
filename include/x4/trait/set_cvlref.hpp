#pragma once

#include "../trait/setcv.hpp"
#include "../trait/setlref.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setcvlref = x4::setcv<qual, x4::setlref<qual, T>>;
}
