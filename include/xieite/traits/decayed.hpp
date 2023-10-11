#ifndef XIEITE_HEADER_TRAITS_DECAYED
#	define XIEITE_HEADER_TRAITS_DECAYED

#	include <type_traits>
#	include "../concepts/decayed.hpp"

namespace xieite::traits {
	template<typename Type>
	struct Decayed
	: std::bool_constant<xieite::concepts::Decayed<Type>> {};
}

#endif
