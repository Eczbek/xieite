#ifndef XIEITE_HEADER_STRINGS_TRIM
#	define XIEITE_HEADER_STRINGS_TRIM

#	include <cstddef>
#	include <string_view>
#	include "../concepts/string_view.hpp"

namespace xieite::strings {
	template<xieite::concepts::StringView StringView = std::string_view>
	[[nodiscard]] constexpr Stringview trim(const StringView string, const StringView characters) noexcept {
		const std::size_t start = string.find_first_not_of(characters);
		return (start == StringView::npos) ? "" : string.substr(start, string.find_last_not_of(characters) - start + 1);
	}

	template<xieite::concepts::StringView StringView = std::string_view>
	[[nodiscard]] constexpr StringView trim(const StringView string, const typename StringView::value_type character) noexcept {
		const std::size_t start = string.find_first_not_of(character);
		return (start == StringView::npos) ? "" : string.substr(start, string.find_last_not_of(character) - start + 1);
	}
}

#endif
