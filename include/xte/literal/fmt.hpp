#ifndef DETAIL_XTE_HEADER_LITERAL_FMT
#	define DETAIL_XTE_HEADER_LITERAL_FMT
#
#	include "../data/static_string_view.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/returns.hpp"
#	include <format>

namespace xte::literal::fmt {
	template<xte::static_string_view string>
	[[nodiscard]] consteval auto operator""_fmt() noexcept {
		return [](auto&&... args) XTE_RETURNS(
			std::format(string.c_str(), FWD(args)...)
		);
	}
}

#endif
