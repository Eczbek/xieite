#ifndef DETAIL_XTE_HEADER_LITERAL_FMT
#	define DETAIL_XTE_HEADER_LITERAL_FMT
#
#	include "../data/fixed_string.hpp"
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include <format>

namespace xte::literal::fmt {
	template<xte::fixed_string string>
	[[nodiscard]] consteval auto operator""_fmt() noexcept {
		return [](auto&&... args) XTE_ARROW(
			std::format(string.data(), FWD(args)...)
		);
	}
}

#endif
