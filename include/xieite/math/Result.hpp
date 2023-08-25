#ifndef XIEITE_HEADER__MATH__RESULT
#	define XIEITE_HEADER__MATH__RESULT

#	include <type_traits>
#	include "../concepts/Numeric.hpp"
#	include "../concepts/SameAsAllOf.hpp"
#	include "../concepts/SameAsAnyOf.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric... Numbers>
	using Result = std::conditional_t<xieite::concepts::SameAsAnyOf<long double, Numbers...>, long double, std::conditional_t<xieite::concepts::SameAsAllOf<float, Numbers...>, float, double>>;
}

#endif
