export module xieite:str_join;

import std;
import :sv;

export namespace xieite {
	template<std::ranges::input_range R>
	requires(std::constructible_from<std::string, std::ranges::range_common_reference_t<R>>)
	[[nodiscard]] constexpr std::string str_join(R&& range, xieite::sv<> delim = "", xieite::sv<> pfx = "", xieite::sv<> sfx = "") noexcept {
		auto iterator = std::ranges::begin(range);
		const auto end = std::ranges::end(range);
		if (iterator == end) {
			return "";
		}
		std::string result = std::string(*iterator);
		while (++iterator != end) {
			result += delim;
			result += std::string(*iterator);
		}
		return pfx + result + sfx;
	}
}
