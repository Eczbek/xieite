#ifndef XIEITE_HEADER_MATH_RESULT
#	define XIEITE_HEADER_MATH_RESULT

#	include <type_traits>
#	include "../concepts/Arithmetic.hpp"
#	include "../concepts/SameAs.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic... Arithmetics>
	using Result = std::conditional_t<xieite::concepts::SameAs<long double, Arithmetics...>, long double, double>;
}

#endif
