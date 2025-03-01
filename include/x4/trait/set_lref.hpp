#pragma once

#include <type_traits>
#include "../trait/addlref.hpp"
#include "../trait/rmlref.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setlref = std::conditional_t<qual, x4::add_lref<T>, x4::rmlref<T>>;
}
