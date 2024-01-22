#ifndef XIEITE_HEADER_HASHES_COMBINE
#	define XIEITE_HEADER_HASHES_COMBINE

#	include <bit>
#	include <concepts>
#	include <cstddef>
#	include "../hashes/distribute.hpp"
#	include "../types/size_bits.hpp"

namespace xieite::hashes {
	template<std::integral Hash = std::size_t, std::convertible_to<Hash>... Hashes>
	[[nodiscard]] constexpr Hash combine(Hash firstHash, const Hashes... restHashes) noexcept {
		(..., (firstHash = std::rotl(firstHash, xieite::types::sizeBits<Hash> / 3) ^ xieite::hashes::distribute<Hash>(restHashes)));
		return firstHash;
	}
}

#endif
