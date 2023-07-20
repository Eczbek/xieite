#ifndef XIEITE_HEADER_MATH_CONDITIONALSIGN
#	define XIEITE_HEADER_MATH_CONDITIONALSIGN

#	include <concepts>
#	include <type_traits>

namespace xieite::math {
	template<std::integral Integral, bool sign>
	using ConditionalSign = std::conditional_t<sign, std::make_signed_t<Integral>, std::make_unsigned_t<Integral>>;
}

#endif
