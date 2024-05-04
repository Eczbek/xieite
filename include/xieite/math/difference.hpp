#ifndef XIEITE_HEADER_MATH_DIFFERENCE
#	define XIEITE_HEADER_MATH_DIFFERENCE

#	include <type_traits>
#	include "../concepts/arithmetic.hpp"
#	include "../types/try_unsigned.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr xieite::types::TryUnsigned<Arithmetic_> difference(const Arithmetic_ value1, const Arithmetic_ value2) noexcept {
		return (value1 > value2) ? (static_cast<xieite::types::TryUnsigned<Arithmetic_>>(value1) - static_cast<xieite::types::TryUnsigned<Arithmetic_>>(value2)) : (static_cast<xieite::types::TryUnsigned<Arithmetic_>>(value2) - static_cast<xieite::types::TryUnsigned<Arithmetic_>>(value1));
	}
}

#endif
