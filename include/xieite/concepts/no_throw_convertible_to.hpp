#ifndef XIEITE_HEADER_CONCEPTS_NO_THROW_CONVERTIBLE_TO
#	define XIEITE_HEADER_CONCEPTS_NO_THROW_CONVERTIBLE_TO

#	include <type_traits>

namespace xieite::concepts {
	template<typename Source, typename Target>
	concept NoThrowConvertibleTo = std::is_nothrow_convertible_v<Source, Target>;
}

#endif
