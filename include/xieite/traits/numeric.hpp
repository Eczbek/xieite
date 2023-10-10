#ifndef XIEITE_HEADER__TRAITS___NUMERIC
#	define XIEITE_HEADER__TRAITS___NUMERIC

#	include <type_traits>
#	include "../concepts/numeric.hpp"

namespace xieite::traits {
	template<typename Type>
	struct Numeric
	: std::bool_constant<xieite::concepts::Numeric<Type>> {};
}

#endif
