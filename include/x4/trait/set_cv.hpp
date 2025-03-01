#pragma once

#include "../trait/setc.hpp"
#include "../trait/setv.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setcv = x4::setc<qual, x4::setv<qual, T>>;
}
