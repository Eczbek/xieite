#pragma once

namespace xieite::numbers {
	template<unsigned long long N>
	constexpr unsigned long long fibonacci = xieite::numbers::fibonacci<N - 1> + xieite::numbers::fibonacci<N - 2>;

	template<>
	constexpr unsigned long long fibonacci<1> = 1;

	template<>
	constexpr unsigned long long fibonacci<0> = 0;
}
