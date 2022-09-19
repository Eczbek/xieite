#pragma once

#include <cstddef>


namespace gcufl::numbers {
	template<std::size_t N>
	constexpr std::size_t factorial = N * gcufl::numbers::factorial<N - 1>;

	template<>
	constexpr std::size_t factorial<0> = 1;
}
