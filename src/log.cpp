export module xieite:log;

import std;
import :is_arith;

export namespace xieite {
	template<xieite::is_arith T, xieite::is_arith U = std::common_type_t<T, double>>
	[[nodiscard]] constexpr U log(T base, std::type_identity_t<T> value) noexcept {
		return static_cast<U>(std::log(value) / std::log(base));
		// `std::log` is slightly faster than `std::log2` and `std::log10` in my tests
	}
}
