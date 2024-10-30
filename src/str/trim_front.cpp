export module xieite:trim_front;

import std;
import :sv;

export namespace xieite {
	[[nodiscard]] constexpr std::string_view trim_front(std::string_view str, xieite::sv chars) noexcept {
		const std::size_t start = str.find_first_not_of(chars);
		return (start == std::string::npos) ? "" : str.substr(start);
	}
}
