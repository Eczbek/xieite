#pragma once

#include <type_traits>
#include "../trait/addvar.hpp"
#include "../trait/rmvar.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setvar = std::conditional_t<qual, x4::add_var<T>, x4::rmvar<T>>;
}
