export module xieite:str_after;

import std;
import :sv;

export namespace xieite {
	[[nodiscard]] constexpr std::string_view str_after(std::string_view str, xieite::sv<> start) noexcept {
		const std::size_t idx = str.find(start);
		return (idx == std::string::npos) ? "" : str.substr(idx + start.size());
	}
}
