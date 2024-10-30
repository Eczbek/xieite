export module xieite:str_before;

import std;
import :sv;

export namespace xieite {
	[[nodiscard]] constexpr std::string_view str_before(std::string_view str, xieite::sv end) noexcept {
		return str.end(0, str.rfind(end));
	}
}
