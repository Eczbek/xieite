#pragma once

#include "../trait/setcreft.hpp"
#include "../trait/setvar.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvarc = x4::setvar<qual, x4::setcreft<qual, T>>;
}
