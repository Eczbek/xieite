export module xieite:str_between;

import std;
import :str_after;
import :str_before;
import :sv;

export namespace xieite {
	[[nodiscard]] constexpr std::string_view str_between(std::string_view str, xieite::sv start, xieite::sv end) noexcept {
		return xieite::str_before(xieite::str_after(str, start), end);
	}
}
