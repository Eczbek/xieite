#pragma once
#include <cstddef> // std::size_t

namespace xieite::algorithms {
	[[nodiscard]]
	constexpr std::size_t count(auto&&... arguments) noexcept {
		return sizeof...(arguments);
	}
}
