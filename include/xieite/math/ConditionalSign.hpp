#ifndef XIEITE_HEADER__MATH__CONDITIONAL_SIGN
#	define XIEITE_HEADER__MATH__CONDITIONAL_SIGN

#	include <concepts>
#	include <type_traits>

namespace xieite::math {
	template<std::integral Integral, bool sign>
	using ConditionalSign = std::conditional_t<sign, std::make_signed_t<Integral>, std::make_unsigned_t<Integral>>;
}

#endif
