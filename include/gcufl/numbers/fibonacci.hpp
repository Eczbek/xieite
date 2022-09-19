#pragma once

#include <cstddef>


namespace gcufl::numbers {
	template<std::size_t N>
	constexpr std::size_t fibonacci = gcufl::numbers::fibonacci<N - 1> + gcufl::numbers::fibonacci<N - 2>;

	template<>
	constexpr std::size_t fibonacci<1> = 1;

	template<>
	constexpr std::size_t fibonacci<0> = 0;
}
