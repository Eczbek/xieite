#ifndef XIEITE_HEADER_TRAITS_IS_NUMERIC
#	define XIEITE_HEADER_TRAITS_IS_NUMERIC

#	include <type_traits>
#	include "../concepts/numeric.hpp"

namespace xieite::traits {
	template<typename Type_>
	struct IsNumeric
	: std::bool_constant<xieite::concepts::Numeric<Type_>> {};
}

#endif
