#pragma once

#include "../trait/addnoex.hpp"
#include "../trait/rmnoex.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setnoex = std::conditional_t<qual, x4::addnoex<T>, x4::rmnoex<T>>;
}
