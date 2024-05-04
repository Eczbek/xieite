#ifndef XIEITE_HEADER_TRAITS_IS_NOT_ALL
#	define XIEITE_HEADER_TRAITS_IS_NOT_ALL

#	include <type_traits>
#	include "../concepts/not_all.hpp"

namespace xieite::traits {
	template<typename Type_, template<typename> typename... Traits_>
	struct IsNotAll
	: std::bool_constant<xieite::concepts::NotAll<Type_, Traits_...>> {};
}

#endif
