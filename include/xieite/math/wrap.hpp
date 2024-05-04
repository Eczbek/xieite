#ifndef XIEITE_HEADER_MATH_WRAP
#	define XIEITE_HEADER_MATH_WRAP

#	include <algorithm>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"
#	include "../math/modulo.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr Arithmetic_ wrap(const Arithmetic_ value, const Arithmetic_ limit1, const Arithmetic_ limit2) noexcept {
		const Arithmetic_ minimum = std::min(limit1, limit2);
		return xieite::math::modulo(value - minimum, std::max(limit1, limit2) - minimum + 1) + minimum;
	}
}

#endif
