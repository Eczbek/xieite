#ifndef XIEITE_HEADER__MATH__DIFFERENCE
#	define XIEITE_HEADER__MATH__DIFFERENCE

#	include <type_traits>
#	include "../concepts/Arithmetic.hpp"
#	include "../math/AttemptUnsign.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr xieite::math::AttemptUnsign<Arithmetic> difference(const Arithmetic value1, const Arithmetic value2) noexcept {
		return (value1 > value2) ? (static_cast<xieite::math::AttemptUnsign<Arithmetic>>(value1) - static_cast<xieite::math::AttemptUnsign<Arithmetic>>(value2)) : (static_cast<xieite::math::AttemptUnsign<Arithmetic>>(value2) - static_cast<xieite::math::AttemptUnsign<Arithmetic>>(value1));
	}
}

#endif
