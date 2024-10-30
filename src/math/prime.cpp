export module xieite:prime;

import std;

export namespace xieite {
	template<std::integral T>
	[[nodiscard]] constexpr bool prime(T value) noexcept {
		if constexpr (!std::same_as<T, bool>) {
			if (value < 4) {
				return value > 1;
			}
			if (!(value % 2) || !(value % 3)) {
				return false;
			}
			const T sqrt = static_cast<T>(std::sqrt(value));
			for (T i = 5; i <= sqrt; i += 6) {
				if (!(value % i) || !(value % (i + 2))) {
					return false;
				}
			}
		}
		return true;
	}
}
