#pragma once

#include <cstddef>


namespace gcufl::numbers {
	template<unsigned long long N>
	constexpr unsigned long long fibonacci = gcufl::numbers::fibonacci<N - 1> + gcufl::numbers::fibonacci<N - 2>;

	template<>
	constexpr unsigned long long fibonacci<1> = 1;

	template<>
	constexpr unsigned long long fibonacci<0> = 0;
}
