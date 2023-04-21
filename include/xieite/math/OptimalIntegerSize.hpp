#pragma once

#include <climits>
#include <cstddef>
#include <type_traits>

namespace xieite::math {
	template<std::size_t bits>
	using OptimalIntegerSize = std::conditional_t<bits <= (sizeof(short) * CHAR_BIT), short, std::conditional_t<bits <= (sizeof(int) * CHAR_BIT), int, std::conditional_t<bits <= (sizeof(long) * CHAR_BIT), long, long long>>>;
}