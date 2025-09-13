#ifndef DETAIL_XIEITE_HEADER_DATA_INTERSPERSE
#	define DETAIL_XIEITE_HEADER_DATA_INTERSPERSE
#
#	include <format>
#	include <iterator>
#	include <string>
#	include "../data/fixed_str.hpp"
#	include "../data/fmt_join.hpp"
#	include "../pp/fwd.hpp"

namespace xieite {
	template<xieite::fixed_str delim = " ", typename... Args>
	[[nodiscard]] constexpr std::string intersperse(Args&&... args) noexcept {
		return std::format(xieite::fmt_join<delim, Args...>, XIEITE_FWD(args)...);
	}

	template<xieite::fixed_str delim = " ", std::output_iterator<const char&> Iter, typename... Args>
	[[nodiscard]] constexpr Iter intersperse_to(Iter iter, Args&&... args) noexcept {
		std::format_to(iter, xieite::fmt_join<delim, Args...>, XIEITE_FWD(args)...);
		return iter;
	}
}

#endif
