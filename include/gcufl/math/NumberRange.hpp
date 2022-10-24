#pragma once
#include <gcufl/concepts/Arithmetic.hpp>

namespace gcufl::math {
	template<gcufl::concepts::Arithmetic N>
	struct NumberRange {
		N begin;
		N end;

		constexpr NumberRange(const N begin, const N end) noexcept
		: begin(begin), end(end) {}
	};
}
