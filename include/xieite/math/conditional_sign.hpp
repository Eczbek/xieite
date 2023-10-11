#ifndef XIEITE_HEADER_MATH_CONDITIONAL_SIGN
#	define XIEITE_HEADER_MATH_CONDITIONAL_SIGN

#	include <type_traits>
#	include "../concepts/integer.hpp"

namespace xieite::math {
	template<xieite::concepts::Integer Integer, bool sign>
	using ConditionalSign = std::conditional_t<sign, std::make_signed_t<Integer>, std::make_unsigned_t<Integer>>;
}

#endif
