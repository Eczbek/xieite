#pragma once

#include "../trait/setrrefreft.hpp"
#include "../trait/setvar.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvarrref = x4::setvar<qual, x4::setrrefreft<qual, T>>;
}
