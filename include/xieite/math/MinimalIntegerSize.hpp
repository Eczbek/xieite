#pragma once

#include <cstddef>
#include <cstdint>
#include <limits>
#include <type_traits>

namespace xieite::math {
	template<std::size_t bits>
	using MinimalIntegerSize = std::conditional_t<bits <= std::numeric_limits<std::uint8_t>::digits, std::uint8_t, std::conditional_t<bits <= std::numeric_limits<std::uint16_t>::digits, std::uint16_t, std::conditional_t<bits <= std::numeric_limits<std::uint32_t>::digits, std::uint32_t, std::uint64_t>>>;
}
