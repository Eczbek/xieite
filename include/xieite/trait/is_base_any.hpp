#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_BASE_ANY
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_BASE_ANY
#
#	include "../trait/is_base.hpp"

namespace xieite {
	template<typename T, typename... Us>
	concept is_base_any = (... || xieite::is_base<T, Us>);
}

#endif
