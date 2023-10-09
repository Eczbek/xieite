#ifndef XIEITE_HEADER__TRAITS__IS_NO_THROW_CONVERTIBLE_TO_ALL_OF
#	define XIEITE_HEADER__TRAITS__IS_NO_THROW_CONVERTIBLE_TO_ALL_OF

#	include <type_traits>
#	include "../concepts/no_throw_convertible_to_all_of.hpp"

namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct IsNoThrowConvertibleToAllOf
	: std::bool_constant<xieite::concepts::NoThrowConvertibleToAllOf<Source, Targets...>> {};
}

#endif
