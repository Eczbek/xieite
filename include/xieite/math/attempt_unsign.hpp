#ifndef XIEITE_HEADER__MATH__ATTEMPT_UNSIGN
#	define XIEITE_HEADER__MATH__ATTEMPT_UNSIGN

#	include <concepts>
#	include <type_traits>

namespace xieite::math {
	template<typename Type>
	using AttemptUnsign = std::conditional_t<std::signed_integral<Type>, std::make_unsigned<Type>, std::type_identity<Type>>::type;
}

#endif
