#ifndef XIEITE_HEADER_CONCEPTS_NOT_ALL
#	define XIEITE_HEADER_CONCEPTS_NOT_ALL

#	include "../concepts/all.hpp"

namespace xieite::concepts {
	template<typename Type, template<typename> typename... Traits>
	concept NotAll = !xieite::concepts::All<Type, Traits...>;
}

#endif
