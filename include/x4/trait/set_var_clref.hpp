#pragma once

#include "../trait/setlrefreft.hpp"
#include "../trait/setvarc.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvarclref = x4::setvarc<qual, x4::setlrefreft<qual, T>>;
}
