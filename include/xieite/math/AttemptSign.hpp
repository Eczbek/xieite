#ifndef XIEITE_HEADER__MATH__ATTEMPT_SIGN
#	define XIEITE_HEADER__MATH__ATTEMPT_SIGN

#	include <concepts>
#	include <type_traits>

namespace xieite::math {
	template<typename Type>
	using AttemptSign = std::conditional_t<std::unsigned_integral<Type>, std::make_signed<Type>, std::type_identity<Type>>::type;
}

#endif
