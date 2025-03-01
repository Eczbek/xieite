#pragma once

#include "../trait/setcreft.hpp"
#include "../trait/setlrefreft.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setclrefreft = x4::setcreft<qual, x4::setlrefreft<qual, T>>;
}
