#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_OBJ
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_OBJ
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_obj = std::is_object_v<T>;
}

#endif
