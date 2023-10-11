#ifndef XIEITE_HEADER_TRAITS_NUMERIC
#	define XIEITE_HEADER_TRAITS_NUMERIC

#	include <type_traits>
#	include "../concepts/numeric.hpp"

namespace xieite::traits {
	template<typename Type>
	struct Numeric
	: std::bool_constant<xieite::concepts::Numeric<Type>> {};
}

#endif
