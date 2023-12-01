#ifndef XIEITE_HEADER_TRAITS_IS_DERIVABLE
#	define XIEITE_HEADER_TRAITS_IS_DERIVABLE

#	include <type_traits>
#	include "../concepts/derivable.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsDerivable
	: std::bool_constant<xieite::concepts::Derivable<Type>> {};
}

#endif
