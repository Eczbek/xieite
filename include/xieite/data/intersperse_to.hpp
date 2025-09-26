#ifndef DETAIL_XIEITE_HEADER_DATA_INTERSPERSE_TO
#	define DETAIL_XIEITE_HEADER_DATA_INTERSPERSE_TO
#
#	include <format>
#	include <iterator>
#	include "../data/fixed_str.hpp"
#	include "../data/fmt_join.hpp"
#	include "../pp/fwd.hpp"

namespace xieite {
	template<
		xieite::fixed_str delim = " ",
		std::output_iterator<const char&> Iter,
		typename... Args
	> [[nodiscard]] constexpr Iter intersperse_to(
		Iter iter,
		Args&&... args
	) noexcept {
		std::format_to(
			iter,
			xieite::fmt_join<delim, Args...>,
			XIEITE_FWD(args)...
		);
		return iter;
	}
}

#endif
