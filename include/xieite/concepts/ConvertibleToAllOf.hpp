#ifndef XIEITE_HEADER__CONCEPTS__CONVERTIBLE_TO_ALL_OF
#	define XIEITE_HEADER__CONCEPTS__CONVERTIBLE_TO_ALL_OF

#	include <concepts>

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept ConvertibleToAllOf = (std::convertible_to<Source, Targets> && ...);
}

#endif
