#pragma once

#include "../trait/setc.hpp"
#include "../trait/setlref.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setclref = x4::setc<qual, x4::setlref<qual, T>>;
}
