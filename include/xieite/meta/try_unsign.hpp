#pragma once

#include <concepts>
#include <type_traits>
#include "../meta/t.hpp"

namespace xieite {
	template<typename T>
	using try_unsign = std::conditional_t<std::signed_integral<T>, std::make_unsigned<T>, xieite::t<T>>::type;
}
