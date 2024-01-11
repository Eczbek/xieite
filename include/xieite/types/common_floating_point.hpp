#ifndef XIEITE_HEADER_TYPES_COMMON_FLOATING_POINT
#	define XIEITE_HEADER_TYPES_COMMON_FLOATING_POINT

#	include <type_traits>
#	include "../concepts/arithmetic.hpp"
#	include "../concepts/same_as_all.hpp"
#	include "../concepts/same_as_any.hpp"

namespace xieite::types {
	template<xieite::concepts::Arithmetic... Numbers>
	using CommonFloatingPoint = std::conditional_t<xieite::concepts::SameAsAny<long double, Numbers...>, long double, std::conditional_t<xieite::concepts::SameAsAll<float, Numbers...>, float, double>>;
}

#endif
