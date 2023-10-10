#ifndef XIEITE_HEADER__CONCEPTS__CONVERTIBLE_TO_NONE
#	define XIEITE_HEADER__CONCEPTS__CONVERTIBLE_TO_NONE

#	include "../concepts/convertible_to_any.hpp"

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept ConvertibleToNone = !xieite::concepts::ConvertibleToAny<Source, Targets...>;
}

#endif
