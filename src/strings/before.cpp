export module xieite:strings.before;

import std;

export namespace xieite::strings {
	[[nodiscard]] constexpr std::string_view before(const std::string_view string, const std::string_view end) noexcept {
		return string.substr(0, string.rfind(end));
	}

	[[nodiscard]] constexpr std::string_view before(const std::string_view string, const char end) noexcept {
		return string.substr(0, string.rfind(end));
	}
}
