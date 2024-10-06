export module xieite:math.range;

import std;

export namespace xieite::math {
	template<std::size_t size, auto start = 0uz, std::same_as<decltype(start)> auto step = 1uz, std::integral Value = decltype(start)>
	constexpr std::array<Value, size> range = ([] {
		return ([]<std::size_t... i>(std::index_sequence<i...>) {
			return std::array<Value, size> { (static_cast<Value>(i) * step + start)... };
		})(std::make_index_sequence<size>());
	})();
}
