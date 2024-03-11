#ifndef XIEITE_HEADER_STRINGS_TRIM_BACK
#	define XIEITE_HEADER_STRINGS_TRIM_BACK

#	include <cstddef>
#	include <string_view>
#	include "../concepts/string_view.hpp"

namespace xieite::strings {
	template<xieite::concepts::StringView StringView = std::string_view>
	[[nodiscard]] constexpr StringView trimBack(const StringView string, const StringView characters) noexcept {
		const std::size_t end = string.find_last_not_of(characters);
		return (end == StringView::npos) ? "" : string.substr(0, end + 1);
	}

	template<xieite::concepts::StringView StringView = std::string_view>
	[[nodiscard]] constexpr StringView trimBack(const StringView string, const typename StringView::value_type character) noexcept {
		const std::size_t end = string.find_last_not_of(character);
		return (end == StringView::npos) ? "" : string.substr(0, end + 1);
	}
}

#endif
