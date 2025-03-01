#pragma once

#include <type_traits>
#include "../trait/addlrefreft.hpp"
#include "../trait/rmlrefreft.hpp"

namespace x4 {
	template<bool qual, typename T>
	using setlrefreft = std::conditional_t<qual, x4::add_lrefreft<T>, x4::rmlrefreft<T>>;
}
