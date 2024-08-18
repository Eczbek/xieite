#ifndef XIEITE_HEADER_CONCEPTS_NO_THROW_CONVERTIBLE_TO_ALL
#	define XIEITE_HEADER_CONCEPTS_NO_THROW_CONVERTIBLE_TO_ALL

#	include <type_traits>

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept NoThrowConvertibleToAll = (... && std::is_nothrow_convertible_v<Source, Targets>);
}

#endif
