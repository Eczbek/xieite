#ifndef XIEITE_HEADER__CONCEPTS__DERIVABLE
#	define XIEITE_HEADER__CONCEPTS__DERIVABLE

#	include "../traits/IsDerivable.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept Derivable = xieite::traits::IsDerivable<Type>::value;
}

#endif
