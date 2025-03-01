#pragma once

#include "../trait/cpcreft.hpp"
#include "../trait/cpvar.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvarc = x4::cpvar<T, x4::cpcreft<T, U>>;
}
