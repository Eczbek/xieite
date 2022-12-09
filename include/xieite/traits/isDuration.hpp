#pragma once
#include <chrono> // std::chrono::duration
#include <cstdint> // std::intmax_t
#include <ratio> // std::ratio
#include <xieite/concepts/Arithmetic.hpp> // xieite::concepts::Arithmetic

namespace xieite::traits {
	template<typename>
	constexpr bool isDuration = false;

	template<xieite::concepts::Arithmetic R, std::intmax_t N, std::intmax_t D>
	constexpr bool isDuration<std::chrono::duration<R, std::ratio<N, D>>> = true;
}
