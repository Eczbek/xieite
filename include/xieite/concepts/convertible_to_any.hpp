#ifndef XIEITE_HEADER_CONCEPTS_CONVERTIBLE_TO_ANY
#	define XIEITE_HEADER_CONCEPTS_CONVERTIBLE_TO_ANY

#	include <concepts>

namespace xieite::concepts {
	template<typename Source_, typename... Targets_>
	concept ConvertibleToAny = (... || std::convertible_to<Source_, Targets_>);
}

#endif
