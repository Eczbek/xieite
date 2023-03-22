#pragma once

#include <cstddef>

namespace xieite::algorithms {
	[[nodiscard]]
	constexpr std::size_t count(auto&&... arguments) noexcept {
		return sizeof...(arguments);
	}
}
