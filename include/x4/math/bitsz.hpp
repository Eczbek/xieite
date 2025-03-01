#pragma once

#include <concepts>
#include <cstddef>
#include <limits>

namespace x4 {
	template<typename T>
	constexpr std::size_t bitsz = sizeof(T) * std::numeric_limits<unsigned char>::digits;

	template<std::integral T>
	constexpr std::size_t bitsz<T> = std::numeric_limits<T>::digits + std::numeric_limits<T>::is_signed;
}
