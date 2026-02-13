#ifndef DETAIL_XTE_HEADER_TRAIT_IS_SAME_ANY
#	define DETAIL_XTE_HEADER_TRAIT_IS_SAME_ANY
#
#	include <concepts>

namespace xte {
	template<typename T, typename... Us>
	concept is_same_any = (... || std::same_as<T, Us>);
}

#endif
