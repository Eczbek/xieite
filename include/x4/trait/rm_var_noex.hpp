#pragma once

#include "../trait/rmnoex.hpp"
#include "../trait/rmvar.hpp"

namespace x4 {
	template<typename T>
	using rmvarnoex = x4::rmvar<x4::rmnoex<T>>;
}
