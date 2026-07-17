#ifndef DETAIL_XTE_HEADER_LITERAL_DEDENT
#	define DETAIL_XTE_HEADER_LITERAL_DEDENT
#
#	include "../data/string_view.hpp"
#	include "../data/string_view.hpp"
#	include "../math/min.hpp"
#	include "../util/make.hpp"
#	include "../util/number_types.hpp"
#	include <meta>
#	include <ranges>

namespace xte::literal::dedent {
	template<xte::string_view raw>
	[[nodiscard]] consteval xte::string_view operator""_dedent() noexcept {
		return xte::string_view(std::define_static_string(([] {
			auto lines = xte::string_view(raw.data(), raw.size())
				.between_any_of('\n', " \t\n")
				| std::views::split('\n')
				| std::views::transform(xte::make<xte::string_view>);
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
				| std::views::transform([=](auto line) { return line.slice(indent); })
				| std::views::join_with('\n');
		})()));
	}
}

#endif
