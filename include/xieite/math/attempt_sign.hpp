#ifndef XIEITE_HEADER_MATH_ATTEMPT_SIGN
#	define XIEITE_HEADER_MATH_ATTEMPT_SIGN

#	include <type_traits>
#	include "../concepts/unsigned_integer.hpp"

namespace xieite::math {
	template<typename Type>
	using AttemptSign = std::conditional_t<xieite::concepts::UnsignedInteger<Type>, std::make_signed<Type>, std::type_identity<Type>>::type;
}

#endif
