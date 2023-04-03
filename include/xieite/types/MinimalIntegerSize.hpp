#pragma once

#include <climits>
#include <cstddef>
#include <cstdint>
#include <type_traits>

namespace xieite::types {
	template<std::size_t bits>
	using MinimalIntegerSize = std::conditional_t<(bits * CHAR_BIT) <= sizeof(std::int8_t), std::int8_t, std::conditional_t<(bits * CHAR_BIT) <= sizeof(std::int16_t), std::int16_t, std::conditional_t<(bits * CHAR_BIT) <= sizeof(std::int32_t), std::int32_t, std::int64_t>>>;
}
