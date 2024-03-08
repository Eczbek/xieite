#ifndef XIEITE_HEADER_STRINGS_IS_ISOGRAM
#	define XIEITE_HEADER_STRINGS_IS_ISOGRAM

#	include <cstddef>
#	include <string_view>
#	include "../concepts/string_view.hpp"
#	include "../strings/characters.hpp"

namespace xieite::strings {
	template<xieite::concepts::StringView StringView = std::string_view>
	[[nodiscard]] constexpr bool isIsogram(const StringView value) noexcept {
		for (std::size_t i = 0; i < xieite::strings::characters::alphabetSize; ++i) {
			if (!value.contains(static_cast<StringView::value_type>(xieite::strings::characters::uppercase[i])) && !value.contains(static_cast<StringView::value_type>(xieite::strings::characters::lowercase[i]))) {
				return false;
			}
		}
		return true;
	}
}

#endif
