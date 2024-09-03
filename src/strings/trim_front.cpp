export module xieite:strings.trimFront;

import std;

export namespace xieite::strings {
	[[nodiscard]] constexpr std::string_view trimFront(const std::string_view string, const std::string_view characters) noexcept {
		const std::size_t start = string.find_first_not_of(characters);
		return (start == std::string_view::npos) ? "" : string.substr(start);
	}

	[[nodiscard]] constexpr std::string_view trimFront(const std::string_view string, const char character) noexcept {
		return xieite::strings::trimFront(string, std::string_view(&character, 1));
	}
}
