#ifndef XIEITE_HEADER_TRAITS_IS_DECAYED
#	define XIEITE_HEADER_TRAITS_IS_DECAYED

#	include <type_traits>
#	include "../concepts/decayed.hpp"

namespace xieite::traits {
	template<typename Type_>
	struct IsDecayed
	: std::bool_constant<xieite::concepts::Decayed<Type_>> {};
}

#endif
