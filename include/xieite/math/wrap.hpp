#ifndef XIEITE_HEADER_MATH_WRAP
#	define XIEITE_HEADER_MATH_WRAP

#	include <algorithm>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"
#	include "../math/modulo.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic wrap(const Arithmetic value, const Arithmetic limit1, const Arithmetic limit2) noexcept {
		const Arithmetic minimum = std::min(limit1, limit2);
		return xieite::math::modulo(value - minimum, std::max(limit1, limit2) - minimum + 1) + minimum;
	}
}

#endif
