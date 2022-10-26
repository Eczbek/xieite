#pragma once
#include <xieite/concepts/Arithmetic.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic N>
	struct NumberRange {
		N begin;
		N end;

		constexpr NumberRange(const N begin, const N end) noexcept
		: begin(begin), end(end) {}
	};
}
