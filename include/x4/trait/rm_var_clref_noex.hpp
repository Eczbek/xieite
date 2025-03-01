#pragma once

#include "../trait/rmnoex.hpp"
#include "../trait/rmvarclref.hpp"

namespace x4 {
	template<typename T>
	using rmvarclrefnoex = x4::rmvarclref<x4::rmnoex<T>>;
}
