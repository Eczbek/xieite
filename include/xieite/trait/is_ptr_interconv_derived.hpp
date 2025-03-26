#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_PTR_INTERCONV_DERIVED
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_PTR_INTERCONV_DERIVED
#
#	include "../trait/is_ptr_interconv_base.hpp"

namespace xieite {
	template<typename T, typename U>
	concept is_ptr_interconv_derived = xieite::is_ptr_interconv_base<U, T>;
}

#endif
