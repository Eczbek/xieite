#ifndef XIEITE_HEADER__TRAITS__IS_DECAYED
#	define XIEITE_HEADER__TRAITS__IS_DECAYED

#	include <type_traits>
#	include "../concepts/Decayed.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsDecayed
	: std::bool_constant<xieite::concepts::Decayed<Type>> {};
}

#endif
