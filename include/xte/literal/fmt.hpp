#ifndef DETAIL_XTE_HEADER_LITERAL_FMT
#	define DETAIL_XTE_HEADER_LITERAL_FMT
#
#	include "../data/string_view.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/returns.hpp"
#	include <format>

namespace xte::literal::fmt {
	template<xte::string_view string>
	[[nodiscard]] consteval auto operator""_fmt() noexcept {
		return [](auto&&... args) XTE_RETURNS(
			std::format(string.data(), FWD(args)...)
		);
	}
}

#endif
