#ifndef DETAIL_XIEITE_HEADER_DATA_INTERSPERSE
#	define DETAIL_XIEITE_HEADER_DATA_INTERSPERSE
#
#	include <format>
#	include <string>
#	include "../data/fixed_str.hpp"
#	include "../data/fmt_join.hpp"
#	include "../pp/fwd.hpp"

namespace xieite {
	template<xieite::fixed_str delim = " ", typename... Args>
	[[nodiscard]] constexpr std::string intersperse(Args&&... args) noexcept {
		return std::format(xieite::fmt_join<delim, Args...>, XIEITE_FWD(args)...);
	}
}

#endif
