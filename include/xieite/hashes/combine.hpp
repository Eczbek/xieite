#ifndef XIEITE_HEADER_HASHES_COMBINE
#	define XIEITE_HEADER_HASHES_COMBINE

#	include <bit>
#	include <concepts>
#	include <cstddef>
#	include "../hashes/distribute.hpp"
#	include "../types/size_bits.hpp"

namespace xieite::hashes {
	template<std::integral Hash_ = std::size_t, std::convertible_to<Hash_>... Hashes_>
	[[nodiscard]] constexpr Hash_ combine(Hash_ firstHash, const Hashes_... restHashes) noexcept {
		(..., (firstHash = std::rotl(firstHash, xieite::types::sizeBits<Hash_> / 3) ^ xieite::hashes::distribute<Hash_>(restHashes)));
		return firstHash;
	}
}

#endif
