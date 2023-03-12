#pragma once
#include <concepts> // std::convertible_to

namespace xieite::algorithms {
	template<std::convertible_to<bool>... TT>
	[[nodiscard]]
	constexpr bool all(TT&&... values) noexcept {
		return (static_cast<bool>(values) && ...);
	}
}
