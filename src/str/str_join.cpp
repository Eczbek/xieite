export module xieite:str_join;

import std;
import :chv;
import :end;
import :id;

export namespace xieite {
	template<std::ranges::input_range R, typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>,
		xieite::end...,
		typename Str = std::basic_string<Ch, Traits, Alloc>,
		typename ChV = xieite::chv<Ch, Traits>>
	requires(std::constructible_from<Str, std::ranges::range_common_reference_t<R>>)
	[[nodiscard]] constexpr Str str_join(R&& range, ChV delim = "", xieite::id<ChV> pfx = "", xieite::id<ChV> sfx = "") noexcept {
		auto iterator = std::ranges::begin(range);
		const auto end = std::ranges::end(range);
		if (iterator == end) {
			return "";
		}
		auto result = Str(*iterator);
		while (++iterator != end) {
			result += delim;
			result += Str(*iterator);
		}
		return pfx + result + sfx;
	}
}
