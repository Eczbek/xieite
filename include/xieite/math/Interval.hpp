#ifndef XIEITE_HEADER__MATH__INTERVAL
#	define XIEITE_HEADER__MATH__INTERVAL

#	include "../concepts/Numeric.hpp"

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
