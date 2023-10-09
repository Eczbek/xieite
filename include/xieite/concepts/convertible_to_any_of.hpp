#ifndef XIEITE_HEADER__CONCEPTS__CONVERTIBLE_TO_ANY_OF
#	define XIEITE_HEADER__CONCEPTS__CONVERTIBLE_TO_ANY_OF

#	include <concepts>

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept ConvertibleToAnyOf = (... || std::convertible_to<Source, Targets>);
}

#endif
