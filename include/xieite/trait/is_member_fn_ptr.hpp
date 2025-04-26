#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_MEMBER_FN_PTR
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_MEMBER_FN_PTR
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_member_fn_ptr = std::is_member_function_pointer_v<T>;
}

#endif
