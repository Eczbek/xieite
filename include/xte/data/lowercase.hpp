#ifndef DETAIL_XTE_HEADER_MATH_LOWERCASE
#	define DETAIL_XTE_HEADER_MATH_LOWERCASE
#
#	include "../data/string.hpp"
#	include "../data/string_view.hpp"
#	include "../trait/is_noex_range.hpp"
#	include "../trait/is_same.hpp"
#	include "../util/assign.hpp"
#	include "../util/cast.hpp"
#	include "../util/like.hpp"
#	include <ranges>

namespace xte {
	[[nodiscard]] constexpr char lowercase(char c) noexcept {
		return (c >= 'A' && c <= 'Z') ? static_cast<char>(c - ('A' - 'a')) : c;
	}

	[[nodiscard]] constexpr xte::string lowercase(xte::string_view string) noexcept(false) {
		auto result = xte::string(string);
		for (char& c : result) {
			c = xte::lowercase(c);
		}
		return result;
	}

	template<std::ranges::input_range Range>
	[[nodiscard]] constexpr Range lowercase(Range range)
	noexcept(xte::is_noex_range<Range>
		&& requires (std::ranges::range_value_t<Range> x) { { xte::assign(x, xte::lowercase(xte::cast<char>(xte::like<Range>(x)))) } noexcept; })
	requires(requires (std::ranges::range_value_t<Range> x) { xte::assign(x, xte::lowercase(xte::cast<char>(xte::like<Range>(x)))); }) {
		for (auto& c : range) {
			xte::assign(c, xte::lowercase(xte::cast<char>(xte::like<Range>(c))));
		}
		return range;
	}
}

#endif
