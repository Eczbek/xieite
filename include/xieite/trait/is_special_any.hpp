#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_SPECIAL_ANY
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_SPECIAL_ANY
#
#	include "../trait/is_special.hpp"

namespace xieite {
	template<typename T, template<typename...> typename... Templates>
	concept is_special_any = (... || xieite::is_special<T, Templates>);
}

#endif
