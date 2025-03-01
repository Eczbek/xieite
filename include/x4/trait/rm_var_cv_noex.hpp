#pragma once

#include "../trait/rmnoex.hpp"
#include "../trait/rmvarcv.hpp"

namespace x4 {
	template<typename T>
	using rmvarcvnoex = x4::rmvarcv<x4::rmnoex<T>>;
}
