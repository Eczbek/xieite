#pragma once

#include "../trait/setv.hpp"
#include "../trait/setrref.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvrref = x4::setv<qual, x4::setrref<qual, T>>;
}
