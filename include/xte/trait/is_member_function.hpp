#ifndef DETAIL_XTE_HEADER_TRAIT_IS_MEMBER_FUNCTION
#	define DETAIL_XTE_HEADER_TRAIT_IS_MEMBER_FUNCTION
#
#	include "../trait/remove_ref.hpp"
#	include <type_traits>

namespace xte {
	template<typename T>
	concept is_member_function = std::is_member_function_pointer_v<xte::remove_ref<T>>;
}

#endif
