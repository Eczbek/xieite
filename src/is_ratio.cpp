export module xieite:is_ratio;

import std;

export namespace xieite {
	template<typename T>
	concept is_ratio = requires { ([]<std::intmax_t numer, std::intmax_t denom>(std::type_identity<std::ratio<numer, denom>>) {})(std::type_identity<std::remove_cv_t<T>>()); };
}
