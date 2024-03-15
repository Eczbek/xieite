#ifndef XIEITE_HEADER_STRINGS_IS_ISOGRAM
#	define XIEITE_HEADER_STRINGS_IS_ISOGRAM

#	include <cstddef>
#	include <string_view>
#	include "../strings/characters.hpp"

namespace xieite::strings {
	[[nodiscard]] constexpr bool isIsogram(const std::string_view value) noexcept {
		for (std::size_t i = 0; i < xieite::strings::characters::alphabetSize; ++i) {
			if (!value.contains(xieite::strings::characters::uppercase[i]) && !value.contains(xieite::strings::characters::lowercase[i])) {
				return false;
			}
		}
		return true;
	}
}

#endif
