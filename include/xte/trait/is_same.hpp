#ifndef DETAIL_XTE_HEADER_TRAIT_IS_SAME
#	define DETAIL_XTE_HEADER_TRAIT_IS_SAME
#
#	include <concepts>

namespace xte {
	template<typename T, typename... Us>
	concept is_same = (... && std::same_as<T, Us>);
}

#endif
