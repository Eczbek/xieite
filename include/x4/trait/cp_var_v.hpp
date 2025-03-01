#pragma once

#include "../trait/cpvreft.hpp"
#include "../trait/cpvar.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvarv = x4::cpvar<T, x4::cpvreft<T, U>>;
}
