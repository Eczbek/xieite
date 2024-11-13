export module xieite:str_after;

import std;
import :chv;
import :end;
import :id;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>, xieite::end...,
		typename StrV = std::basic_string_view<Ch, Traits>>
	[[nodiscard]] constexpr StrV str_after(StrV str, xieite::id<xieite::chv<Ch, Traits>> start) noexcept {
		const std::size_t idx = str.find(start);
		return (idx == std::string::npos) ? "" : str.substr(idx + start.size());
	}
}
