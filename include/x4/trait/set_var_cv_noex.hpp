#pragma once

#include "../trait/setnoex.hpp"
#include "../trait/setvarcv.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvarcvnoex = x4::setvarcv<qual, x4::setnoex<qual, T>>;
}
