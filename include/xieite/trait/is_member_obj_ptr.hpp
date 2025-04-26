#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_MEMBER_OBJ_PTR
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_MEMBER_OBJ_PTR
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_member_obj_ptr = std::is_member_object_pointer_v<T>;
}

#endif
