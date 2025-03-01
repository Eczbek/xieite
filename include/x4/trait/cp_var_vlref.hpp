#pragma once

#include "../trait/cpvar.hpp"
#include "../trait/cpvlrefreft.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvarvlref = x4::cpvar<T, x4::cpvlrefreft<T, U>>;
}
