#ifndef XIEITE_HEADER__CONCEPTS__NONE
#	define XIEITE_HEADER__CONCEPTS__NONE

#	include "../concepts/any.hpp"

namespace xieite::concepts {
	template<typename Type, template<typename> typename... Traits>
	concept None = !xieite::concepts::Any<Type, Traits...>;
}

#endif
