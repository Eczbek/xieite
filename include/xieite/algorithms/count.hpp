#pragma once

#include <cstddef>

namespace xieite::algorithms {
	[[nodiscard]]
	constexpr std::size_t count(const auto&... arguments) noexcept {
		return sizeof...(arguments);
	}
}
