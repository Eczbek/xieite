#ifndef XIEITE_HEADER_HASHES_CREATE
#	define XIEITE_HEADER_HASHES_CREATE

#	include <cstddef>
#	include <string_view>

namespace xieite::hashes {
	[[nodiscard]]
	constexpr std::size_t create(const std::string_view string) noexcept {
		std::size_t result = 5381;
		for (const char character : string) {
			result = result * 33 + character;
		}
		return result;
	}
}

#endif
