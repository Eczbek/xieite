#ifndef XIEITE_HEADER_MATH_INTERVAL
#	define XIEITE_HEADER_MATH_INTERVAL

#	include <xieite/concepts/Arithmetic.hpp>

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
