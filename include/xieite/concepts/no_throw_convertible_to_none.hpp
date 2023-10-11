#ifndef XIEITE_HEADER_CONCEPTS_NO_THROW_CONVERTIBLE_TO_NONE
#	define XIEITE_HEADER_CONCEPTS_NO_THROW_CONVERTIBLE_TO_NONE

#	include "../concepts/no_throw_convertible_to_any.hpp"

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept NoThrowConvertibleToNone = !xieite::concepts::NoThrowConvertibleToAny<Source, Targets...>;
}

#endif