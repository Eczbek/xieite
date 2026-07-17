#ifndef DETAIL_XTE_HEADER_META_TYPE_COUNTER
#	define DETAIL_XTE_HEADER_META_TYPE_COUNTER
#
#	include "../meta/state.hpp"
#	include "../util/number_types.hpp"

namespace DETAIL_XTE::type_counter {
	inline constexpr auto impl = xte::state<>.set<0uz>;
}

namespace xte {
	template<typename>
	constexpr xte::uz type_counter = DETAIL_XTE::type_counter::impl.set<(DETAIL_XTE::type_counter::impl.get<[]{}> + 1)>.template get<> - 1;
}

#endif
