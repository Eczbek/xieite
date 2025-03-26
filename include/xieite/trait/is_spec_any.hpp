#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_SPEC_ANY
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_SPEC_ANY
#
#	include "../trait/is_spec.hpp"

namespace xieite {
	template<typename T, template<typename...> typename... Ms>
	concept is_spec_any = (... || xieite::is_spec<T, Ms>);
}

#endif
