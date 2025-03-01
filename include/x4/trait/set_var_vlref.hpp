#pragma once

#include "../trait/setlrefreft.hpp"
#include "../trait/setvarv.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvarvlref = x4::setvarv<qual, x4::setlrefreft<qual, T>>;
}
