#pragma once

#include "../trait/rmvreft.hpp"
#include "../trait/rmnoex.hpp"

namespace x4 {
	template<typename T>
	using rmvnoex = x4::rmvreft<x4::rmnoex<T>>;
}
