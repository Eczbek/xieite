#pragma once

#include <type_traits>
#include "../trait/addlrefreft.hpp"
#include "../trait/islrefreft.hpp"
#include "../trait/cprrefreft.hpp"
#include "../trait/rmrefreft.hpp"

namespace x4 {
	template<typename T, typename U>
	using cprefreft = std::conditional_t<x4::islrefreft<T>, x4::add_lrefreft<U>, x4::cprrefreft<T, x4::rmrefreft<U>>>;
}
