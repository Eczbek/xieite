#ifndef DETAIL_XIEITE_HEADER_MATH_HASH_COMBINE
#	define DETAIL_XIEITE_HEADER_MATH_HASH_COMBINE
#
#	include <bit>
#	include <concepts>
#	include <cstddef>
#	include "../math/bit_size.hpp"
#	include "../math/hash_dist.hpp"

namespace xieite {
	template<std::integral T = std::size_t, std::convertible_to<T>... Ts>
	[[nodiscard]] constexpr T hash_combine(T first, Ts... rest) noexcept {
		(..., (first = std::rotl(first, static_cast<int>(xieite::bit_size<T> / 3)) ^ xieite::hash_dist(static_cast<T>(rest))));
		return first;
	}
}

#endif
