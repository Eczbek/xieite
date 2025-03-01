#pragma once

#include "../trait/setclrefreft.hpp"
#include "../trait/setnoex.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setclrefnoex = x4::setclrefreft<qual, x4::setnoex<qual, T>>;
}
