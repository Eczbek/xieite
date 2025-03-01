#pragma once

#include <type_traits>
#include "../trait/addrrefreft.hpp"
#include "../trait/rmrrefreft.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setrrefreft = std::conditional_t<qual, x4::add_rrefreft<T>, x4::rmrrefreft<T>>;
}
