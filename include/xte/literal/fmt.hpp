#ifndef DETAIL_XTE_HEADER_LITERAL_FMT
#	define DETAIL_XTE_HEADER_LITERAL_FMT
#
#	include "../preproc/fwd.hpp"
#	include "../preproc/returns.hpp"
#	include "../static_string_view.hpp"
#	include <format>
#	include <meta>

namespace xte::literal::fmt {
	template<xte::static_string_view string>
	[[nodiscard]] consteval auto operator""_fmt() noexcept(false) {
		return [](auto&&... args) XTE_RETURNS(
			std::format(std::define_static_string(string), XTE_FWD(args)...)
		);
	}
}

#endif
