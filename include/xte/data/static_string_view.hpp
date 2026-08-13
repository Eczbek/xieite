#ifndef DETAIL_XTE_HEADER_DATA_STATIC_STRING
#	define DETAIL_XTE_HEADER_DATA_STATIC_STRING
#
#	include "../data/string_view.hpp"
#	include "../preproc/constructs.hpp"
#	include "../preproc/fwd.hpp"
#	include "../trait/is_castable_implicit_noex.hpp"
#	include "../trait/is_same.hpp"
#	include <meta>
#	include <ranges>
#	include <string_view>

namespace xte {
	struct static_string_view : xte::string_view {
		template<std::ranges::contiguous_range range_type>
		requires(xte::is_same<std::ranges::range_value_t<range_type>, char>)
		[[nodiscard]] explicit(false) consteval static_string_view(const range_type& range) noexcept
		: xte::string_view(std::define_static_string(range), std::ranges::size(range)) {}

		[[nodiscard]] explicit consteval static_string_view(const xte::is_castable_implicit_noex<const char*> auto& range) noexcept
		: xte::static_string_view(xte::string_view(range)) {}

		[[nodiscard]] consteval static_string_view(const char* data, xte::uz size) noexcept
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
