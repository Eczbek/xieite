#pragma once

#include <concepts>
#include <cstddef>
#include <limits>

namespace xieite {
	template<typename T>
	constexpr std::size_t bit_size = sizeof(T) * std::numeric_limits<unsigned char>::digits;

	template<std::integral T>
	constexpr std::size_t bit_size<T> = std::numeric_limits<T>::digits + std::numeric_limits<T>::is_signed;
}

// After a long and very intense debate between FOUR different wizards on several topics of varying relativity, it was deemed that `std::numeric_limits<unsigned char>::digits` and `CHAR_BIT` both are terrible options and there's no good way of doing anything at all
