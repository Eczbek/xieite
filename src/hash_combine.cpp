export module xieite:hash_combine;

import std;
import :bit_size;
import :hash_dist;

export namespace xieite {
	template<std::integral T = std::size_t, std::convertible_to<T>... Ts>
	[[nodiscard]] constexpr T hash_combine(T first, Ts... rest) noexcept {
		(..., (first = std::rotl(first, xieite::bit_size<T> / 3) ^ xieite::hash_dist(static_cast<T>(rest))));
		return first;
	}
}
