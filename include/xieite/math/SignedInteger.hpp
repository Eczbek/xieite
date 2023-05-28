#ifndef XIEITE_HEADER_MATH_SIGNEDINTEGER
#	define XIEITE_HEADER_MATH_SIGNEDINTEGER

#	include <concepts>
#	include <type_traits>

namespace xieite::math {
	template<std::integral Integral, bool sign>
	using SignedInteger = std::conditional_t<sign, std::make_signed_t<Integral>, std::make_unsigned_t<Integral>>;
}

#endif
