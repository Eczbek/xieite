#pragma once

#include <bit>
#include <cstddef>
#include <limits>
#include <xieite/hash/distribute.hpp>

namespace xieite::hash {
	[[nodiscard]]
	constexpr std::size_t combine(const std::size_t value1, const std::size_t value2) noexcept {
		return std::rotl(value1, std::numeric_limits<std::size_t>::digits / 3) ^ xieite::hash::distribute(value2);
	}
}
