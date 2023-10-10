#ifndef XIEITE_HEADER__CONCEPTS__NOT_ALL
#	define XIEITE_HEADER__CONCEPTS__NOT_ALL

#	include "../concepts/all.hpp"

namespace xieite::concepts {
	template<typename Type, template<typename> typename... Traits>
	concept NotAll = !xieite::concepts::All<Type, Traits...>;
}

#endif
