export module xieite:trim_front;

import std;
import :chv;
import :end;
import :id;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>,
		xieite::end...,
		typename StrV = std::basic_string_view<Ch, Traits>>
	[[nodiscard]] constexpr StrV trim_front(StrV str, xieite::id<xieite::chv<Ch, Traits>> chars) noexcept {
		const std::size_t start = str.find_first_not_of(chars);
		return (start == std::string::npos) ? "" : str.substr(start);
	}
}
