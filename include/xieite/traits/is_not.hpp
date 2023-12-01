#ifndef XIEITE_HEADER_TRAITS_IS_NOT
#	define XIEITE_HEADER_TRAITS_IS_NOT

#	include <type_traits>
#	include "../concepts/not.hpp"

namespace xieite::traits {
	template<typename Type, template<typename> typename Trait>
	struct IsNot
	: std::bool_constant<xieite::concepts::Not<Type, Trait>> {};
}

#endif
