#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_SCOPED_ENUM
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_SCOPED_ENUM
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_scoped_enum = std::is_scoped_enum_v<T>;
}

#endif
