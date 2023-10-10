#ifndef XIEITE_HEADER__MATH__RESULT
#	define XIEITE_HEADER__MATH__RESULT

#	include <type_traits>
#	include "../concepts/numeric.hpp"
#	include "../concepts/same_as_all.hpp"
#	include "../concepts/same_as_any.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric... Numbers>
	using Result = std::conditional_t<xieite::concepts::SameAsAny<long double, Numbers...>, long double, std::conditional_t<xieite::concepts::SameAsAll<float, Numbers...>, float, double>>;
}

#endif
