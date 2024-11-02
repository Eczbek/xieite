export module xieite:trim;

import std;
import :sv;

export namespace xieite {
	[[nodiscard]] constexpr std::string_view trim(std::string_view str, xieite::sv<> chars) noexcept {
		const std::size_t start = str.find_first_not_of(chars);
		return (start == std::string::npos) ? "" : str.substr(start, str.find_last_not_of(chars) - start + 1);
	}
}
