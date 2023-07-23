#ifndef XIEITE_HEADER_MATH_ATTEMPTUNSIGN
#	define XIEITE_HEADER_MATH_ATTEMPTUNSIGN

#	include <concepts>
#	include <type_traits>

namespace xieite::math {
	template<typename Any>
	using AttemptUnsign = std::conditional_t<std::signed_integral<Any>, std::make_unsigned<Any>, std::type_identity<Any>>::type;
}

#endif
