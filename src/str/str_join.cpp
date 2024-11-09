export module xieite:str_join;

import std;
import :sv;

export namespace xieite {
	template<std::ranges::input_range R, typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	requires(std::constructible_from<std::basic_string<Ch, Traits, Alloc>, std::ranges::range_common_reference_t<R>>)
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> str_join(R&& range, xieite::sv<Ch, Traits> delim = "", xieite::sv<Ch, Traits> pfx = "", xieite::sv<Ch, Traits> sfx = "") noexcept {
		auto iterator = std::ranges::begin(range);
		const auto end = std::ranges::end(range);
		if (iterator == end) {
			return "";
		}
		auto result = std::basic_string<Ch, Traits, Alloc>(*iterator);
		while (++iterator != end) {
			result += delim;
			result += std::basic_string<Ch, Traits, Alloc>(*iterator);
		}
		return pfx + result + sfx;
	}
}
