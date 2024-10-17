export module xieite:math.range;

import std;
import :functors.unroll;

export namespace xieite::math {
	template<std::size_t size, auto start = 0uz, std::same_as<decltype(start)> auto step = 1uz, std::integral Value = decltype(start)>
	constexpr std::array<Value, size> range = xieite::functors::unroll<size>([]<std::size_t... i> {
		return std::array<Value, size> { (static_cast<Value>(i) * step + start)... };
	});
}
