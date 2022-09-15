#pragma once

#include <gcufl/concepts/Arithmetic.hpp>


namespace gcufl::math {
	template<gcufl::concepts::Arithmetic N>
	constexpr int sign(const N value) noexcept {
		const auto comparison = value <=> 0;
		return -(comparison < 0) || comparison > 0;
	}
}
