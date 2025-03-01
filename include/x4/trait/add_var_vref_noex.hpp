#pragma once

#include "../trait/addnoex.hpp"
#include "../trait/addvarvref.hpp"

namespace x4 {
	template<typename T, typename U>
	using addvarvrefnoex = x4::add_varvref<T, x4::addnoex<U>>;
}
