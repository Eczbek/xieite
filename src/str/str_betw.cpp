export module xieite:str_betw;

import std;
import :chv;
import :end;
import :id;
import :str_after;
import :str_before;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>, xieite::end...,
		typename StrV = std::basic_string_view<Ch, Traits>,
		typename ChV = xieite::chv<Ch, Traits>>
	[[nodiscard]] constexpr StrV str_betw(StrV str, xieite::id<ChV> start, xieite::id<ChV> end) noexcept {
		return xieite::str_before(xieite::str_after(str, start), end);
	}
}
