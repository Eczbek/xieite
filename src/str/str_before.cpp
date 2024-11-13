export module xieite:str_before;

import std;
import :chv;
import :end;
import :id;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>,
		xieite::end...,
		typename StrV = std::basic_string_view<Ch, Traits>>
	[[nodiscard]] constexpr StrV str_before(StrV str, xieite::id<xieite::chv<Ch, Traits>> end) noexcept {
		return str.substr(0, str.rfind(end));
	}
}
