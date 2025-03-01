#pragma once

#include "../trait/cpvar.hpp"
#include "../trait/cpvrefreft.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvarvref = x4::cpvar<T, x4::cpvrefreft<T, U>>;
}
