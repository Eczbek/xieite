#ifndef XIEITE_HEADER_CONCEPTS_NO_THROW_CONVERTIBLE_TO_ANY
#	define XIEITE_HEADER_CONCEPTS_NO_THROW_CONVERTIBLE_TO_ANY

#	include <type_traits>

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept NoThrowConvertibleToAny = (... || std::is_nothrow_convertible_v<Source, Targets>);
}

#endif
