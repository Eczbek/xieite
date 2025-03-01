#pragma once

#include <type_traits>
#include "../trait/addrref.hpp"
#include "../trait/rmref.hpp"
#include "../trait/rmrref.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setrref = std::conditional_t<qual, x4::add_rref<x4::rmref<T>>, x4::rmrref<T>>;
}
