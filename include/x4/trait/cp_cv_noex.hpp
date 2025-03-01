#pragma once

#include "../trait/cpcvreft.hpp"
#include "../trait/cpnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpcvnoex = x4::setcvreft<T, x4::cpnoex<T, U>>;
}
