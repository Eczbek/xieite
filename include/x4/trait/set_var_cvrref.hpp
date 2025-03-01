#pragma once

#include "../trait/setrrefreft.hpp"
#include "../trait/setvarcv.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvarcvrref = x4::setvarcv<qual, x4::setrrefreft<qual, T>>;
}
