#pragma once

#include <type_traits>
#include "../trait/rmref.hpp"

namespace x4 {
	template<typename T>
	concept isv = std::is_volatile_v<x4::rmref<T>>;
}
