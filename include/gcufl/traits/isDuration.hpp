#pragma once

#include <chrono>
#include <cstdint>
#include <gcufl/concepts/Arithmetic.hpp>
#include <ratio>


namespace gcufl::traits {
	template <typename>
	constexpr bool isDuration = false;

	template <gcufl::concepts::Arithmetic R, std::intmax_t N, std::intmax_t D>
	constexpr bool isDuration<std::chrono::duration<R, std::ratio<N, D>>> = true;
}