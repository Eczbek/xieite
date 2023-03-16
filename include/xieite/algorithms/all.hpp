#pragma once
#include <concepts> // std::convertible_to

namespace xieite::algorithms {
	[[nodiscard]]
	constexpr bool all(std::convertible_to<bool> auto&&... values) noexcept {
		return (static_cast<bool>(values) && ...);
	}
}
