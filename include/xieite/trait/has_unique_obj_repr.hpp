#ifndef DETAIL_XIEITE_HEADER_TRAIT_HAS_UNIQUE_OBJ_REPR
#	define DETAIL_XIEITE_HEADER_TRAIT_HAS_UNIQUE_OBJ_REPR
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept has_unique_obj_repr = std::has_unique_object_representations_v<T>;
}

#endif
