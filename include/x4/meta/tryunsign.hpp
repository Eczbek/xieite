#pragma once

#include <concepts>
#include <type_traits>

namespace x4 {
	template<typename T>
	using tryunsign = std::conditional_t<std::signed_integral<T>, std::make_unsigned<T>, std::type_identity<T>>::type;
}
