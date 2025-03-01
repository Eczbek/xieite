#pragma once

#include "../trait/setnoex.hpp"
#include "../trait/setvar.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvarnoex = x4::setvar<qual, x4::setnoex<qual, T>>;
}
