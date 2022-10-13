#pragma once
#include <cstddef>

namespace gcufl::numbers {
	template<unsigned long long N>
	constexpr unsigned long long factorial = N * gcufl::numbers::factorial<N - 1>;

	template<>
	constexpr unsigned long long factorial<0> = 1;
}
