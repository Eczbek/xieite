#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_BASE
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_BASE
#
#	include <concepts>

namespace xieite {
	template<typename T, typename... Us>
	concept is_base = (... && std::derived_from<Us, T>);
}

#endif
