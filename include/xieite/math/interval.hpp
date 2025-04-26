#ifndef DETAIL_XIEITE_HEADER_MATH_INTERVAL
#	define DETAIL_XIEITE_HEADER_MATH_INTERVAL
#
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	struct interval {
		Arith start;
		Arith end;

		[[nodiscard]] constexpr interval(Arith start, Arith end) noexcept
		: start(start), end(end) {}
	};
}

#endif
