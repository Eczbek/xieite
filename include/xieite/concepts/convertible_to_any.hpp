#ifndef XIEITE_HEADER__CONCEPTS__CONVERTIBLE_TO_ANY
#	define XIEITE_HEADER__CONCEPTS__CONVERTIBLE_TO_ANY

#	include <concepts>

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept ConvertibleToAny = (... || std::convertible_to<Source, Targets>);
}

#endif
