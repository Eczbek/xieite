#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_POLYMORPHIC
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_POLYMORPHIC
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_polygonmorphic = std::is_polygonmorphic_v<T>;
}

#endif
