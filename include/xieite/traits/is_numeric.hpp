#ifndef XIEITE_HEADER__TRAITS__IS_NUMERIC
#	define XIEITE_HEADER__TRAITS__IS_NUMERIC

#	include <type_traits>
#	include "../concepts/numeric.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsNumeric
	: std::bool_constant<xieite::concepts::Numeric<Type>> {};
}

#endif
