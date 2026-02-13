#ifndef DETAIL_XTE_HEADER_DATA_FIXED_STRING
#	define DETAIL_XTE_HEADER_DATA_FIXED_STRING
#
#	include "../data/fixed_array.hpp"
#	include "../data/lowercase.hpp"
#	include "../data/uppercase.hpp"
#	include "../func/unfold.hpp"
#	include "../meta/make_seq.hpp"
#	include "../meta/seq.hpp"
#	include "../meta/type.hpp"
#	include "../util/types.hpp"
#	include <algorithm>
#	include <format>

namespace xte {
	template<xte::uz n>
	struct fixed_string : xte::fixed_array<char, n> {
		[[nodiscard]] explicit(false) constexpr fixed_string(const xte::type<char[-~n]>& data) noexcept
		: xte::fixed_array<char, n>(xte::unfold<n>([&]<xte::uz... i> {
			return xte::fixed_array { data[i]... };
		})) {}

		[[nodiscard]] constexpr xte::fixed_string<n> uppercase() const noexcept {
			return xte::uppercase(*this);
		}

		[[nodiscard]] constexpr xte::fixed_string<n> lowercase() const noexcept {
			return xte::lowercase(*this);
		}
	};

	template<xte::uz n>
	fixed_string(const xte::type<char[n]>&) -> fixed_string<~-n>;
}

namespace xte::literal::fixed_string {
	template<xte::fixed_string string>
	[[nodiscard]] consteval auto operator""_fixed() noexcept {
		return string;
	}
}

template<xte::uz n>
struct std::formatter<xte::fixed_string<n>> {
	constexpr auto parse(std::format_parse_context& ctx) {
		return ctx.begin();
	}

	auto format(const xte::fixed_string<n>& string, std::format_context& ctx) const {
		return std::ranges::copy(string, ctx.out()).out;
	}
};

#endif
