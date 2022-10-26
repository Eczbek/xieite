#pragma once
#include <chrono>
#include <cstdint>
#include <xieite/concepts/Arithmetic.hpp>
#include <ratio>

namespace xieite::traits {
	template<typename>
	constexpr bool isDuration = false;

	template<xieite::concepts::Arithmetic R, std::intmax_t N, std::intmax_t D>
	constexpr bool isDuration<std::chrono::duration<R, std::ratio<N, D>>> = true;
}
