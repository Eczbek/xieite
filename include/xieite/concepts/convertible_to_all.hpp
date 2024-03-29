#ifndef XIEITE_HEADER_CONCEPTS_CONVERTIBLE_TO_ALL
#	define XIEITE_HEADER_CONCEPTS_CONVERTIBLE_TO_ALL

#	include <concepts>

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept ConvertibleToAll = (... && std::convertible_to<Source, Targets>);
}

#endif
