#pragma once

#include <type_traits>
#include "../trait/islref.hpp"
#include "../trait/rmref.hpp"

namespace x4 {
	template<typename T>
	using rmlref = std::conditional_t<x4::islref<T>, x4::rmref<T>, T>;
}
