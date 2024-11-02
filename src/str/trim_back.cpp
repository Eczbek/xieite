export module xieite:trim_back;

import std;
import :sv;

export namespace xieite {
	[[nodiscard]] constexpr std::string_view trim_back(std::string_view str, xieite::sv<> chars) noexcept {
		const std::size_t end = str.find_last_not_of(chars);
		return (end == std::string::npos) ? "" : str.substr(0, end + 1);
	}
}
