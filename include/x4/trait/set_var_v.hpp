#pragma once

#include "../trait/setvreft.hpp"
#include "../trait/setvar.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvarv = x4::setvar<qual, x4::setvreft<qual, T>>;
}
