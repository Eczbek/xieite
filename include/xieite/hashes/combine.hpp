#ifndef XIEITE_HEADER__HASHES__COMBINE
#	define XIEITE_HEADER__HASHES__COMBINE

#	include <bit>
#	include <cstddef>
#	include <limits>
#	include "../hashes/distribute.hpp"

namespace xieite::hashes {
	[[nodiscard]]
	constexpr std::size_t combine(const std::size_t value1, const std::size_t value2) noexcept {
		return std::rotl(value1, std::numeric_limits<std::size_t>::digits / 3) ^ xieite::hashes::distribute(value2);
	}
}

#endif
