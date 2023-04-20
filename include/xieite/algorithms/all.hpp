#pragma once

#include <xieite/concepts/NothrowConvertibleTo.hpp>

namespace xieite::algorithms {
	[[nodiscard]]
	constexpr bool all(xieite::concepts::NoThrowConvertibleTo<bool> auto&&... values) noexcept {
		return (static_cast<bool>(values) && ...);
	}
}
