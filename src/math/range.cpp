export module xieite:range;

import std;
import :unroll;

export namespace xieite {
	template<std::size_t size, auto start = 0uz, std::same_as<decltype(start)> auto step = 1uz, std::integral T = decltype(start)>
	constexpr std::array<T, size> range = xieite::unroll<size>([]<std::size_t... i> -> std::array<T, size> {
		return std::array<T, size> { (static_cast<T>(i) * step + start)... };
	});
}
