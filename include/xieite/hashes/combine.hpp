#ifndef XIEITE_HEADER_HASHES_COMBINE
#	define XIEITE_HEADER_HASHES_COMBINE

#	include <bit>
#	include <concepts>
#	include <cstddef>
#	include "../bits/size.hpp"
#	include "../hashes/distribute.hpp"

namespace xieite::hashes {
	template<std::integral Hash_ = std::size_t, std::convertible_to<Hash_>... Hashes_>
	[[nodiscard]] constexpr Hash_ combine(Hash_ firstHash, const Hashes_... restHashes) noexcept {
		(..., (firstHash = std::rotl(firstHash, xieite::bits::size<Hash_> / 3) ^ xieite::hashes::distribute<Hash_>(restHashes)));
		return firstHash;
	}
}

#endif
