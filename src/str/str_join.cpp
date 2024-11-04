export module xieite:str_join;

import std;
import :sv;

export namespace xieite {
	template<std::ranges::input_range R, typename C = char, typename Traits = std::char_traits<C>, typename Alloc = std::allocator<C>>
	requires(std::constructible_from<std::basic_string<C, Traits, Alloc>, std::ranges::range_common_reference_t<R>>)
	[[nodiscard]] constexpr std::basic_string<C, Traits, Alloc> str_join(R&& range, xieite::sv<C, Traits> delim = "", xieite::sv<C, Traits> pfx = "", xieite::sv<C, Traits>> sfx = "") noexcept {
		auto iterator = std::ranges::begin(range);
		const auto end = std::ranges::end(range);
		if (iterator == end) {
			return "";
		}
		auto result = std::basic_string<C, Traits, Alloc>(*iterator);
		while (++iterator != end) {
			result += delim;
			result += std::basic_string<C, Traits, Alloc>(*iterator);
		}
		return pfx + result + sfx;
	}
}
