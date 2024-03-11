#ifndef XIEITE_HEADER_STRINGS_TRIM_FRONT
#	define XIEITE_HEADER_STRINGS_TRIM_FRONT

#	include <cstddef>
#	include <string_view>
#	include "../concepts/string_view.hpp"

namespace xieite::strings {
	template<xieite::concepts::StringView StringView = std::string_view>
	[[nodiscard]] constexpr Stringview trimFront(const StringView string, const StringView characters) noexcept {
		const std::size_t start = string.find_first_not_of(characters);
		return (start == StringView::npos) ? "" : string.substr(start);
	}

	template<xieite::concepts::StringView StringView = std::string_view>
	[[nodiscard]] constexpr StringView trimFront(const StringView string, const typename StringView::value_type character) noexcept {
		const std::size_t start = string.find_first_not_of(character);
		return (start == StringView::npos) ? "" : string.substr(start);
	}
}

#endif
