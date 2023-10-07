#ifndef XIEITE_HEADER__MATH__NEGATIVE
#	define XIEITE_HEADER__MATH__NEGATIVE

#	include <concepts>
#	include "../concepts/Arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr bool negative(const Arithmetic value) noexcept {
		if constexpr (!std::unsigned_integral<Arithmetic>) {
			return value < 0;
		}
		return false;
	}
}

#endif
