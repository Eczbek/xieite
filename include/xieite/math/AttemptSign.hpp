#ifndef XIEITE_HEADER__MATH__ATTEMPT_SIGN
#	define XIEITE_HEADER__MATH__ATTEMPT_SIGN

#	include <concepts>
#	include <type_traits>

namespace xieite::math {
	template<typename Any>
	using AttemptSign = std::conditional_t<std::unsigned_integral<Any>, std::make_signed<Any>, std::type_identity<Any>>::type;
}

#endif
