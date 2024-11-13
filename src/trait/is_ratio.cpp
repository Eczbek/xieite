export module xieite:is_ratio;

import std;

export namespace xieite {
	template<typename T>
	concept is_ratio = requires {
		([]<std::intmax_t numer, std::intmax_t denom>(std::ratio<numer, denom>) {})(std::declval<std::remove_cv_t<T>>());
	};
}
