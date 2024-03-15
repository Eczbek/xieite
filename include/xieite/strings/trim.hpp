#ifndef XIEITE_HEADER_STRINGS_TRIM
#	define XIEITE_HEADER_STRINGS_TRIM

#	include <cstddef>
#	include <string_view>

namespace xieite::strings {
	[[nodiscard]] constexpr std::string_view trim(const std::string_view string, const std::string_view characters) noexcept {
		const std::size_t start = string.find_first_not_of(characters);
		return (start == std::string_view::npos) ? "" : string.substr(start, string.find_last_not_of(characters) - start + 1);
	}

	[[nodiscard]] constexpr std::string_view trim(const std::string_view string, const char character) noexcept {
		return xieite::strings::trim(string, std::string_view(&character, 1));
	}
}

#endif
