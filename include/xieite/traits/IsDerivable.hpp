#ifndef XIEITE_HEADER__TRAITS__IS_DERIVABLE
#	define XIEITE_HEADER__TRAITS__IS_DERIVABLE

#	include <type_traits>
#	include "../concepts/Derivable.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsDerivable
	: std::bool_constant<xieite::concepts::Derivable<Type>> {};
}

#endif
