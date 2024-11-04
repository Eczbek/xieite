export module xieite:str_between;

import std;
import :str_after;
import :str_before;
import :sv;

export namespace xieite {
	template<typename C = char, typename Traits = std::char_traits<C>>
	[[nodiscard]] constexpr std::basic_string_view<C, Traits> str_between(std::basic_string_view<C, Traits> str, xieite::sv<C, Traits> start, xieite::sv<C, Traits> end) noexcept {
		return xieite::str_before(xieite::str_after(str, start), end);
	}
}
