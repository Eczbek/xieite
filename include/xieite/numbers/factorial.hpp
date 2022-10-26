#pragma once

namespace xieite::numbers {
	template<unsigned long long N>
	constexpr unsigned long long factorial = N * xieite::numbers::factorial<N - 1>;

	template<>
	constexpr unsigned long long factorial<0> = 1;
}
