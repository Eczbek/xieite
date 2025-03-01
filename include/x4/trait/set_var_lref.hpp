#pragma once

#include "../trait/setlrefreft.hpp"
#include "../trait/setvar.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvarlref = x4::setvar<qual, x4::setlrefreft<qual, T>>;
}
