#ifndef DETAIL_XTE_HEADER_LITERAL_DEDENT
#	define DETAIL_XTE_HEADER_LITERAL_DEDENT
#
#	include "../data/fixed_string.hpp"
#	include "../data/string.hpp"
#	include "../data/string_view.hpp"
#	include "../math/min.hpp"
#	include "../util/as.hpp"
#	include "../util/types.hpp"
#	include <meta>
#	include <ranges>

namespace xte::literal::dedent {
	template<xte::fixed_string raw>
	[[nodiscard]] consteval xte::string_view operator""_dedent() noexcept {
		return xte::string_view(std::define_static_string(([] {
			auto lines = xte::string_view(raw.data(), raw.size())
				.between_any_of('\n', " \t\n")
				| std::views::split('\n')
				| std::views::transform(xte::as<xte::string_view>);
			auto first = lines.front();
			xte::uz indent = first.find_not_of(" \t");
			for (xte::string_view line : lines | std::views::drop(1)) {
				for (xte::uz i : std::views::indices(xte::min(indent * !!~indent, line.size()))) {
					if (first[i] != line[i]) {
						indent = i;
						break;
					}
				}
			}
			return lines
				| std::views::transform([=](auto line) { return line.substr(indent); })
				| std::views::join_with('\n')
				| std::ranges::to<xte::string>();
		})()));
	}
}

#endif
