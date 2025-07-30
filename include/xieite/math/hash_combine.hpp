#ifndef DETAIL_XIEITE_HEADER_MATH_HASH_COMBINE
#	define DETAIL_XIEITE_HEADER_MATH_HASH_COMBINE
#
#	include <bit>
#	include <concepts>
#	include <cstddef>
#	include "../math/bit_size.hpp"
#	include "../math/hash_distribute.hpp"

namespace xieite {
	template<std::integral Int = std::size_t>
	[[nodiscard]] constexpr Int hash_combine(Int first, std::integral auto... rest) noexcept {
		(..., (first = std::rotl(first, static_cast<int>(xieite::bit_size<Int> / 3)) ^ xieite::hash_distribute(static_cast<Int>(rest))));
		return first;
	}
}

#endif
