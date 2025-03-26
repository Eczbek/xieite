#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_DERIVED_FROM
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_DERIVED_FROM
#
#	include <concepts>

namespace xieite {
	template<typename T, typename... Us>
	concept is_derived_from = (... && std::derived_from<T, Us>);
}

#endif
