#ifndef XIEITE_HEADER__STRINGS__TRIM
#	define XIEITE_HEADER__STRINGS__TRIM

#	include <cstddef>
#	include <string_view>

namespace xieite::strings {
	constexpr std::string_view trim(const std::string_view string, const char character) noexcept {
		const std::size_t start = string.find_first_not_of(character);
		return (start == std::string_view::npos) ? "" : string.substr(start, string.find_last_not_of(character) - start + 1);
	}

	constexpr std::string_view trim(const std::string_view string, const std::string_view characters) noexcept {
		const std::size_t start = string.find_first_not_of(characters);
		return (start == std::string_view::npos) ? "" : string.substr(start, string.find_last_not_of(characters) - start + 1);
	}
}

#endif
