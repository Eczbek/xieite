#ifndef XIEITE_HEADER__MATH__INTERVAL
#	define XIEITE_HEADER__MATH__INTERVAL

#	include "../concepts/Arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	struct Interval {
		Arithmetic start;
		Arithmetic end;

		constexpr Interval(const Arithmetic start, const Arithmetic end) noexcept
		: start(start), end(end) {}
	};
}

#endif
