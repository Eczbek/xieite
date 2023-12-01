#ifndef XIEITE_HEADER_TRAITS_IS_ALL
#	define XIEITE_HEADER_TRAITS_IS_ALL

#	include <type_traits>
#	include "../concepts/all.hpp"

namespace xieite::traits {
	template<typename Type, template<typename> typename... Traits>
	struct IsAll
	: std::bool_constant<xieite::concepts::All<Type, Traits...>> {};
}

#endif
