export module xieite:log;

import std;
import :is_arith;

export namespace xieite {
	template<xieite::is_arith T, xieite::is_arith U = std::common_type_t<T, double>>
	[[nodiscard]] constexpr U log(T base, T n) noexcept {
		return static_cast<U>(std::log(n) / std::log(base));
		// https://quick-bench.com/q/ZhKXMlnjYG6n-xrgtAtjy6kYPFc
	}
}
