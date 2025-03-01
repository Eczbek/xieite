#pragma once

#include <type_traits>
#include "../trait/rmref.hpp"

namespace x4 {
	template<typename T>
	concept isc = std::is_const_v<x4::rmref<T>>;
}
