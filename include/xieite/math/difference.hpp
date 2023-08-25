#ifndef XIEITE_HEADER__MATH__DIFFERENCE
#	define XIEITE_HEADER__MATH__DIFFERENCE

#	include <type_traits>
#	include "../concepts/Arithmetic.hpp"
#	include "../math/AttemptUnsign.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic1, xieite::concepts::Arithmetic Arithmetic2>
	constexpr xieite::math::AttemptUnsign<std::common_type_t<Arithmetic1, Arithmetic2>> difference(const Arithmetic1 a, const Arithmetic2 b) noexcept {
		using Result = xieite::math::AttemptUnsign<std::common_type_t<Arithmetic1, Arithmetic2>>;
		return (a > b) ? (static_cast<Result>(a) - static_cast<Result>(b)) : (static_cast<Result>(b) - static_cast<Result>(a));
	}
}

#endif
