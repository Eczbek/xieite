#ifndef XIEITE_HEADER_STRINGS_TRIM_BACK
#	define XIEITE_HEADER_STRINGS_TRIM_BACK

#	include <cstddef>
#	include <string_view>

namespace xieite::strings {
	[[nodiscard]] constexpr std::string_view trimBack(const std::string_view string, const std::string_view characters) noexcept {
		const std::size_t end = string.find_last_not_of(characters);
		return (end == std::string_view::npos) ? "" : string.substr(0, end + 1);
	}

	[[nodiscard]] constexpr std::string_view trimBack(const std::string_view string, const char character) noexcept {
		return xieite::strings::trimBack(string, std::string_view(&character, 1));
	}
}

#endif
