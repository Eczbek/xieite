#ifndef XIEITE_HEADER_MATH_RESULT
#	define XIEITE_HEADER_MATH_RESULT

#	include <type_traits>
#	include "../concepts/arithmetic.hpp"
#	include "../concepts/same_as_all.hpp"
#	include "../concepts/same_as_any.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic... Numbers>
	using Result = std::conditional_t<xieite::concepts::SameAsAny<long double, Numbers...>, long double, std::conditional_t<xieite::concepts::SameAsAll<float, Numbers...>, float, double>>;
}

#endif
