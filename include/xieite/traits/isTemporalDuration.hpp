#pragma once

#include <chrono>
#include <cstdint>
#include <ratio>
#include <xieite/concepts/Arithmetic.hpp>

namespace xieite::traits {
	template<typename>
	constexpr bool isTemporalDuration = false;

	template<xieite::concepts::Arithmetic Number, std::intmax_t numerator, std::intmax_t denominator>
	constexpr bool isTemporalDuration<std::chrono::duration<Number, std::ratio<numerator, denominator>>> = true;
}
