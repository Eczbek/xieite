#ifndef DETAIL_XTE_HEADER_META_TYPE_COUNTER
#	define DETAIL_XTE_HEADER_META_TYPE_COUNTER
#
#	include "../meta/state.hpp"
#	include "../util/types.hpp"

namespace DETAIL_XTE {
	inline constexpr auto type_counter = xte::state<>.set<0uz>;
}

namespace xte {
	template<typename>
	constexpr xte::uz type_counter = DETAIL_XTE::type_counter.set<-~DETAIL_XTE::type_counter.get<[] {}>>.template get<> - 1;
}

#endif
