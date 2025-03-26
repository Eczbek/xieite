#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_ENUM
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_ENUM
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_enum = std::is_enum_v<T>;
}

#endif
