#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_UNSCOPED_ENUM
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_UNSCOPED_ENUM
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_unscoped_enum = std::is_enum_v<T> && !std::is_scoped_enum_v<T>;
}

#endif
