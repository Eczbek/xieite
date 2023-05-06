#pragma once

#include <cstddef>
#include <cstdint>
#include <limits>
#include <type_traits>

namespace xieite::math {
	template<std::size_t bits>
	using MinimalIntegerSize = std::conditional_t<bits <= std::numeric_limits<std::int8_t>::digits, std::int8_t, std::conditional_t<bits <= std::numeric_limits<std::int16_t>::digits, std::int16_t, std::conditional_t<bits <= std::numeric_limits<std::int32_t>::digits, std::int32_t, std::int64_t>>>;
}
