#pragma once

#include "../trait/cpref.hpp"
#include "../trait/rmref.hpp"

namespace x4 {
	template<typename T>
	using addv = x4::cpref<T, volatile x4::rmref<T>>;
}
