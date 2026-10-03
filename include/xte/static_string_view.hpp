#ifndef DETAIL_XTE_HEADER_STATIC_STRING_VIEW
#	define DETAIL_XTE_HEADER_STATIC_STRING_VIEW
#
#	include "./class_traits.hpp"
#	include "./macros.hpp"
#	include "./string_view.hpp"
#	include "./qual_traits.hpp"
#	include <meta>
#	include <ranges>
#	include <string_view>

namespace xte {
	struct static_string_view : xte::string_view {
		[[nodiscard]] constexpr explicit(false) static_string_view() noexcept = default;

		template<std::ranges::contiguous_range range_type>
		requires(xte::is_same<std::ranges::range_value_t<range_type>, char>)
		[[nodiscard]] explicit(false) consteval static_string_view(std::from_range_t, range_type const& range) XTE_CONSTRUCTS(
			((xte::string_view),(std::define_static_string(range), std::ranges::size(range)))
		)

		[[nodiscard]] constexpr explicit(false) static_string_view(auto const& range) XTE_CONSTRUCTS(
			((xte::static_string_view),(std::from_range, range))
		)

		[[nodiscard]] explicit consteval static_string_view(xte::is_implicitly_convertible_noex<char const*> auto const& range) noexcept
		: xte::static_string_view(xte::string_view(range)) {}

		[[nodiscard]] consteval static_string_view(char const* data, xte::uz size) noexcept
		: xte::static_string_view(xte::string_view(data, size)) {}
	};
}

template<>
struct std::formatter<xte::static_string_view> : std::formatter<std::string_view> {
	[[nodiscard]] constexpr auto parse(std::format_parse_context& ctx) noexcept {
		return std::formatter<std::string_view>::parse(ctx);
	}

	[[nodiscard]] auto format(xte::static_string_view string, std::format_context& ctx) const noexcept(false) {
		return std::formatter<std::string_view>::format(std::string_view(string), ctx);
	}
};

#endif
