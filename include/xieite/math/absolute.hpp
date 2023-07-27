#ifndef XIEITE_HEADER_MATH_ABSOLUTE
#	define XIEITE_HEADER_MATH_ABSOLUTE

#	include "../concepts/Arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]]
	constexpr Arithmetic absolute(const Arithmetic value) noexcept {
		return (value * ((value >= 0.0) * 2 - 1));
	}
}

#endif
