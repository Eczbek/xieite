#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_SAME
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_SAME
#
#	include <concepts>

namespace xieite {
	template<typename... Ts>
	concept is_same = (... && std::same_as<Ts...[0], Ts>);
}

#endif
