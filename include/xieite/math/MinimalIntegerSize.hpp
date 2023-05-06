#pragma once

#include <cstddef>
#include <cstdint>
#include <limits>
#include <type_traits>

namespace xieite::math {
	template<std::size_t bits>
	using MinimalIntegerSize = std::conditional_t<(bits * std::numeric_limits<unsigned char>::digits) <= sizeof(std::int8_t), std::int8_t, std::conditional_t<(bits * std::numeric_limits<unsigned char>::digits) <= sizeof(std::int16_t), std::int16_t, std::conditional_t<(bits * std::numeric_limits<unsigned char>::digits) <= sizeof(std::int32_t), std::int32_t, std::int64_t>>>;
}
