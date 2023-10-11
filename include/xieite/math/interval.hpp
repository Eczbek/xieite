#ifndef XIEITE_HEADER_MATH_INTERVAL
#	define XIEITE_HEADER_MATH_INTERVAL

#	include "../concepts/numeric.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric Number>
	struct Interval {
		Number start;
		Number end;

		constexpr Interval(const Number start, const Number end) noexcept
		: start(start), end(end) {}
	};
}

#endif
