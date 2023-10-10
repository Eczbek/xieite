#ifndef XIEITE_HEADER__TRAITS___NOT_ALL
#	define XIEITE_HEADER__TRAITS___NOT_ALL

#	include <type_traits>
#	include "../concepts/none.hpp"

namespace xieite::traits {
	template<typename Type, template<typename> typename... Traits>
	struct NotAll
	: std::bool_constant<xieite::concepts::NotAll<Type, Traits...>> {};
}

#endif
