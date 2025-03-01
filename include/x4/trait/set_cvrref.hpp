#pragma once

#include "../trait/setcv.hpp"
#include "../trait/setrref.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setcvrref = x4::setcv<qual, x4::setrref<qual, T>>;
}
