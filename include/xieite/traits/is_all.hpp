#ifndef XIEITE_HEADER_TRAITS_IS_ALL
#	define XIEITE_HEADER_TRAITS_IS_ALL

#	include <type_traits>
#	include "../concepts/all.hpp"

namespace xieite::traits {
	template<typename Type_, template<typename> typename... Traits_>
	struct IsAll
	: std::bool_constant<xieite::concepts::All<Type_, Traits_...>> {};
}

#endif
