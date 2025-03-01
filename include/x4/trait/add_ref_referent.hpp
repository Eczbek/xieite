#pragma once

#include <type_traits>
#include "../trait/addlrefreft.hpp"
#include "../trait/addrrefreft.hpp"
#include "../trait/islrefreft.hpp"
#include "../trait/isrrefreft.hpp"

namespace x4 {
	template<typename T, typename U>
	using addrefreft = std::conditional_t<x4::islrefreft<T>, x4::add_lrefreft<U>, std::conditional_t<x4::isrrefreft<T>, x4::add_rrefreft<U>, U>>;
}
