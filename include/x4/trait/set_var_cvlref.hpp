#pragma once

#include "../trait/setlrefreft.hpp"
#include "../trait/setvarcv.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvarcvlref = x4::setvarcv<qual, x4::setlrefreft<qual, T>>;
}
