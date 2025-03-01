#pragma once

#include "../trait/cpcreft.hpp"
#include "../trait/cpvreft.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpcvreft = x4::cpcreft<T, x4::cpvreft<T, U>>;
}
