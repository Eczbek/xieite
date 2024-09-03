export module xieite:strings.after;

import std;

export namespace xieite::strings {
	[[nodiscard]] constexpr std::string_view after(const std::string_view string, const std::string_view start) noexcept {
		const std::size_t index = string.find(start);
		return (index == std::string_view::npos) ? "" : string.substr(index + start.size());
	}

	[[nodiscard]] constexpr std::string_view after(const std::string_view string, const char start) noexcept {
		const std::size_t index = string.find(start);
		return (index == std::string_view::npos) ? "" : string.substr(index + 1);
	}
}
