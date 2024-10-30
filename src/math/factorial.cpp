export module xieite:factorial;

import std;
import :is_arith;
import :make_array;
import :mul_overflow;

export namespace xieite {
	template<xieite::is_arith T>
	constexpr auto factorial = ([] {
		static constexpr auto get = [] {
			std::vector<T> result = { 1 };
			for (std::size_t i = 1; !xieite::mul_overflow(static_cast<T>(i), result[i - 1]); ++i) {
				result.push_back(static_cast<T>(i) * result[i - 1]);
			}
			return result;
		};
		return xieite::make_array<T, get().size()>(get());
	})();
}
