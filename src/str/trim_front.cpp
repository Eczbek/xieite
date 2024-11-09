export module xieite:trim_front;

import std;
import :sv;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr std::basic_string_view<Ch, Traits> trim_front(std::basic_string_view<Ch, Traits> str, xieite::sv<Ch, Traits> chars) noexcept {
		const std::size_t start = str.find_first_not_of(chars);
		return (start == std::string::npos) ? "" : str.substr(start);
	}
}
