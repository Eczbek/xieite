#pragma once
#include <gcufl/concepts/Arithmetic.hpp>
#include <gcufl/math/difference.hpp>

namespace gcufl::math {
	template<gcufl::concepts::Arithmetic N>
	[[nodiscard]]
	constexpr N farthestFrom(const N target, const N a, const N b) noexcept {
		return (a >= target)
			? (b >= target)
				? (a > b)
					? a
					: b
				: (gcufl::math::difference(target, a) < gcufl::math::difference(target, b))
					? a
					: b
			: (b < target)
				? (a < b)
					? a
					: b
				: (gcufl::math::difference(target, a) > gcufl::math::difference(target, b))
					? a
					: b;
	}
}
