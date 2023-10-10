#ifndef XIEITE_HEADER__TRAITS___ANY
#	define XIEITE_HEADER__TRAITS___ANY

#	include <type_traits>
#	include "../concepts/any.hpp"

namespace xieite::traits {
	template<typename Type, template<typename> typename... Traits>
	struct Any
	: std::bool_constant<xieite::concepts::Any<Type, Traits...>> {};
}

#endif
