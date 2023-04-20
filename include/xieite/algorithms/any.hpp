#pragma once

#include <xieite/concepts/NoThrowConvertibleTo.hpp>

namespace xieite::algorithms {
	[[nodiscard]]
	constexpr bool any(xieite::concepts::NoThrowConvertibleTo<bool> auto&&... values) noexcept {
		return (static_cast<bool>(values) || ...);
	}
}
