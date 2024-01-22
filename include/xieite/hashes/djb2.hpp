#ifndef XIEITE_HEADER_HASHES_DJB2
#	define XIEITE_HEADER_HASHES_DJB2

#	include <cstddef>
#	include <string_view>

namespace xieite::hashes {
	[[nodiscard]] constexpr std::size_t djb2(const std::string_view value) noexcept {
		std::size_t result = 5381;
		for (const char character : value) {
			result = result * 33 + character;
		}
		return result;
	}
}

#endif
