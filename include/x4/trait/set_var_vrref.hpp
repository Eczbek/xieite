#pragma once

#include "../trait/setrrefreft.hpp"
#include "../trait/setvarv.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvarvrref = x4::setvarv<qual, x4::setrrefreft<qual, T>>;
}
