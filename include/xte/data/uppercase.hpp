#ifndef DETAIL_XTE_HEADER_MATH_UPPERCASE
#	define DETAIL_XTE_HEADER_MATH_UPPERCASE
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
	[[nodiscard]] constexpr char uppercase(char c) noexcept {
		return (c >= 'a' && c <= 'z') ? static_cast<char>(c - ('a' - 'A')) : c;
	}

	[[nodiscard]] constexpr xte::string uppercase(xte::string_view string) noexcept(false) {
		auto result = xte::string(string);
		for (char& c : result) {
			c = xte::uppercase(c);
		}
		return result;
	}

	template<std::ranges::input_range Range>
	[[nodiscard]] constexpr Range uppercase(Range range)
	noexcept(xte::is_noex_range<Range>
		&& requires (std::ranges::range_value_t<Range> x) { { xte::assign(x, xte::uppercase(xte::cast<char>(xte::like<Range>(x)))) } noexcept; })
	requires(requires (std::ranges::range_value_t<Range> x) { xte::assign(x, xte::uppercase(xte::cast<char>(xte::like<Range>(x)))); }) {
		for (auto& c : range) {
			xte::assign(c, xte::uppercase(xte::cast<char>(xte::like<Range>(c))));
		}
		return range;
	}
}

#endif
