#pragma once

#include "../trait/cpref.hpp"
#include "../trait/rmref.hpp"

namespace x4 {
	template<typename T>
	using addc = x4::cpref<T, const x4::rmref<T>>;
}
