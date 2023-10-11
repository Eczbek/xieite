#ifndef XIEITE_HEADER_CONCEPTS_NONE
#	define XIEITE_HEADER_CONCEPTS_NONE

#	include "../concepts/any.hpp"

namespace xieite::concepts {
	template<typename Type, template<typename> typename... Traits>
	concept None = !xieite::concepts::Any<Type, Traits...>;
}

#endif
