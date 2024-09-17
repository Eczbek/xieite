export module xieite:hashes.combine;

import std;
import :bits.size;
import :hashes.distribute;

export namespace xieite::hashes {
	template<std::integral Hash = std::size_t, std::convertible_to<Hash>... Hashes>
	[[nodiscard]] constexpr Hash combine(Hash firstHash, const Hashes... restHashes) noexcept {
		(..., (firstHash = std::rotl(firstHash, xieite::bits::size<Hash> / 3) ^ xieite::hashes::distribute(static_cast<Hash>(restHashes))));
		return firstHash;
	}
}
