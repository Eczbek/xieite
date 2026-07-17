#ifndef DETAIL_XTE_HEADER_TRAIT_IS_REF
#	define DETAIL_XTE_HEADER_TRAIT_IS_REF
#
#	include "../trait/is_lvalue_ref.hpp"
#	include "../trait/is_rvalue_ref.hpp"

namespace xte {
	template<typename T>
	concept is_ref = xte::is_lvalue_ref<T> || xte::is_rvalue_ref<T>;
}

#endif
