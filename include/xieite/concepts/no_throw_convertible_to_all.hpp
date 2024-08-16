#ifndef XIEITE_HEADER_CONCEPTS_NO_THROW_CONVERTIBLE_TO_ALL
#	define XIEITE_HEADER_CONCEPTS_NO_THROW_CONVERTIBLE_TO_ALL

#	include "../concepts/no_throw_convertible_to.hpp"

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept NoThrowConvertibleToAll = (... && xieite::concepts::NoThrowConvertibleTo<Source, Targets>);
}

#endif
