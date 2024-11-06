export module xieite:fib;

import std;
import :is_arith;
import :make_array;
import :add_overflow;

export namespace xieite {
	template<xieite::is_arith T>
	constexpr auto fib = ([] {
		static constexpr auto get = [] -> std::vector<T> {
			std::vector<T> result = { 0, 1 };
			for (std::size_t i = 2; !xieite::add_overflow(result[i - 1], result[i - 2]); ++i) {
				result.push_back(result[i - 1] + result[i - 2]);
			}
			return result;
		};
		return xieite::make_array<T, get().size()>(get());
	})();
}
