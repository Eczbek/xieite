#ifndef XIEITE_HEADER_CONCEPTS_NO_THROW_CONVERTIBLE_TO_NOT_ALL
#	define XIEITE_HEADER_CONCEPTS_NO_THROW_CONVERTIBLE_TO_NOT_ALL

#	include "../concepts/no_throw_convertible_to_all.hpp"

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept NoThrowConvertibleToNotAll = !xieite::concepts::NoThrowConvertibleToAll<Source, Targets...>;
}

#endif
