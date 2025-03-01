#pragma once

#include <type_traits>
#include "../trait/isunsign.hpp"

namespace x4 {
	template<typename T>
	using trysign = std::conditional_t<x4::isunsign<T>, std::make_signed<T>, std::type_identity<T>>::type;
}
