export module xieite:trim_front;

import std;
import :sv;

export namespace xieite {
	template<typename C = char, typename Traits = std::char_traits<C>>
	[[nodiscard]] constexpr std::basic_string_view<C, Traits> trim_front(std::basic_string_view<C, Traits> str, xieite::sv<C, Traits> chars) noexcept {
		const std::size_t start = str.find_first_not_of(chars);
		return (start == std::string::npos) ? "" : str.substr(start);
	}
}
